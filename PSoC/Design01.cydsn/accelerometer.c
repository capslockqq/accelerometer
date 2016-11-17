#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <mpu_register_address.h>

void mpu_init(MPU_9150_Acc_config_s *configObj) {
    configObj->accConfigData = 0b00010000;
    configObj->sampleRateDividerData = 0x08;
    configObj->fifoData = 0b00001000;
    configObj->powerManagement = 0b00000001;
    
    WriteI2CData(PWR_MGMT_1, configObj->powerManagement);
    //Sætter sample rate divideren på gyroscopet
    WriteI2CData(SAMPLE_RATE_DIVIDER, configObj->sampleRateDividerData); 
    WriteI2CData(ACC_CONFIG, configObj->accConfigData);
}

void movement_init(movement_XY_s *init) {
    uint8 i;
    for (i = 0; i < 2; i++) {
        init->acceleration_x[i] = 0;
        init->acceleration_y[i] = 0;
        init->velocity_x[i] = 0; 
        init->velocity_y[i] = 0;   
        init->position_x[i] = 0;
        init->position_y[i] = 0;
    }
    init->countx = 0;
    init->county = 0;
    init->AccErrorX = 0;
       
}


void setAcceleration(movement_XY_s *movementData) {
    int8_t temp_acc_H[2];
    int8_t temp_acc_L[2];
    int16_t acc_total[2];
    
    //Variable til for løkke

   
        temp_acc_H[1] = ReadI2CData(ACCEL_XOUT_H);
        temp_acc_L[1] = ReadI2CData(ACCEL_XOUT_L);
        acc_total[1] = ((temp_acc_H[1] << 8) + temp_acc_L[1]);
        //Trækker x-accel fejl fra værdien
        acc_total[1] -= movementData->AccErrorX;
        //Checker om accelerationen skal betragted som 0
        if (acc_total[1] < TOLERANCE && acc_total[1] > -TOLERANCE) {
            acc_total[1] = 0;

        }
        movementData->acceleration_x[1] = acc_total[1];  
    

  
}

void setVelocity(movement_XY_s *movementData) {
    if (movementData->acceleration_x[1] == 0) {
        movementData->countx++;
        if (movementData->countx > 5) {
            movementData->velocity_x[1] = 0;   
            movementData->velocity_x[0] = 0;  
        }
    }
    else {
        movementData->countx = 0; 
        //Tager integrale af x-acceleration for at finde hastighed
        movementData->velocity_x[1] = movementData->velocity_x[0]+movementData->acceleration_x[0]+((movementData->acceleration_x[1]-movementData->acceleration_x[0])/2);
        //Tager integrale af y-acceleration for at finde hastighed
        movementData->velocity_y[1] = movementData->velocity_y[0]+movementData->acceleration_y[1]+((movementData->acceleration_y[1]+movementData->acceleration_y[0])/2);
    }
    
    
    
}

void setPosition(movement_XY_s *movementData) {
    //Tager integrale af x-acceleration for at finde hastighed
    movementData->position_x[1] = movementData->position_x[0]+movementData->velocity_x[0]+((movementData->velocity_x[1]-movementData->velocity_x[0])/2);
    //Tager integrale af y-acceleration for at finde hastighed
    movementData->position_y[1] = movementData->position_y[0]+movementData->velocity_y[1]+((movementData->velocity_y[1]-movementData->velocity_x[0])/2);
    
}

void updateMovement(movement_XY_s *movementData) {
    movementData->acceleration_x[0] =  movementData->acceleration_x[1];
    movementData->velocity_x[0] =  movementData->velocity_x[1];
    movementData->position_x[0] =  movementData->position_x[1];
    
    movementData->acceleration_y[0] =  movementData->acceleration_y[1];
    movementData->velocity_y[0] =  movementData->velocity_y[1];
    movementData->position_y[0] =  movementData->position_y[1];
    
}



void calibrateMPU9150(MPU_9150_Acc_config_s *accConfig, movement_XY_s *movementData) {
    int32_t error[3] = {0,0,0}; //Fejl data fra x,y,z (ACC)
    int8_t data[6] = {0,0,0,0,0,0}; //data fra FIFO 
    int16_t acc_temp[3] = {0,0,0}; //Midlertidig acc data
    uint16_t fifo_count; //Tæller hvor mange bytes der ligger i FIFO'en
    uint8_t i,j = 0; //For loop counter
    uint16_t packetCount;
    
    /*
    AFS_SEL Full Scale Range LSB Sensitivity
        ±2g 16384 LSB/mg
        ±4g 8192 LSB/mg
        ±8g 4096 LSB/mg
        ±16g 2048 LSB/mg
    */
    
    WriteI2CData(CONFIG, 0x01); //Sætter båndbredde til 184 for acc og 188 for gyro
    WriteI2CData(SAMPLE_RATE_DIVIDER, 0x00); //Sætter samplerate til 1kHz
    WriteI2CData(ACC_CONFIG, accConfig->accConfigData); //Sætter acc til 2g, dette er maksimum følsomhed

    //Opsætning af FIFO
    WriteI2CData(USER_CTRL, 0x40); //Sætter bit 7 til høj; FIFO er enabled
    WriteI2CData(FIFO_EN, 0x08); //Sætter ACC registrene vil blive placeret i FIFO'en
    //Laver delay på 80 ms, således der bliver foretaget 80 samples
    // 80*3 = 240*2 = 480 bytes i bufferen.
    CyDelay(80); 
    WriteI2CData(FIFO_EN, 0x00); // Disabler FIFO (bevarer eksisterende data)
    fifo_count = (ReadI2CData(FIFO_COUNTH) << 8) + ReadI2CData(FIFO_COUNTL);
    
      
    //Dividerer med 2 da brugbar data er 16 bits lang(2bytes) der er 3 akser
    //Derfor 2*3 = 6.
    packetCount = fifo_count / 6; 


    for(i = 0; i < packetCount; i++) {
        ReadI2CBytes(6, FIFO_R_W, data);
        acc_temp[0] = (data[0] << 8) + data[1];
        acc_temp[1] = (data[2] << 8) + data[3];
        acc_temp[2] = (data[4] << 8) + data[5];

        error[0] += acc_temp[0];
        error[1] += acc_temp[1];
        error[2] += acc_temp[2];
    
    }

    
    for (j = 0; j < 3; j++) {
        //Finder gennemsnitsfejl
        error[j]  = error[j] / packetCount; 
            
    }
    movementData->AccErrorX = error[0];
    movementData->AccErrorY = error[1];
}