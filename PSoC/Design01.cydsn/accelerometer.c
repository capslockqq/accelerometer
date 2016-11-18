#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <mpu_register_address.h>


/************************************************************************************/
/********************************Init funktioner*************************************/
/************************************************************************************/
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

void kalmanFilter_init(kalmanFilterValues_s *init) {
    init->Estimate[1] = 0;
    init->Estimate[0] = 0;
    init->Error_Estimate[1] = 5;
    init->Error_Estimate[0] = 5;
    init->KG = 0;
}

/************************************************************************************/
/********************************Set funktioner**************************************/
/************************************************************************************/

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

void kalmanFilter(movement_XY_s *movementData, kalmanFilterValues_s *kalmanData) {
    kalmanData->KG = (kalmanData->Error_Estimate[1])/(kalmanData->Error_Estimate[1]+movementData->AccErrorX*2);
    kalmanData->Estimate[1] = kalmanData->Estimate[0] + kalmanData->KG*(movementData->acceleration_x[1]-kalmanData->Error_Estimate[0]);
    kalmanData->Error_Estimate[1] = (1-kalmanData->KG)*kalmanData->Error_Estimate[0];
}

void updateKalmanFilter(kalmanFilterValues_s *kalmanData) {
    kalmanData->Error_Estimate[0] = kalmanData->Error_Estimate[1];
    kalmanData->Estimate[0] = kalmanData->Estimate[1];
}



void calibrateMPU9150(MPU_9150_Acc_config_s *accConfig, movement_XY_s *movementData) {
    uint8 i;
    int32 temp_acc = 0;
    for (i = 0; i < 64;  i++) {
       setAcceleration(movementData); 
       temp_acc += movementData->acceleration_x[1];
    }
    temp_acc = temp_acc >> 6;
    movementData->AccErrorX = temp_acc;
    
    
}