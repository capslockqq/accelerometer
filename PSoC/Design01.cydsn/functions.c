#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <mpu_register_address.h>

void sys_init () {
    //Internal pull-up resistors for I2C line
    I2C_1_scl_SetDriveMode(I2C_1_scl_DM_RES_UP); 
    I2C_1_sda_SetDriveMode(I2C_1_sda_DM_RES_UP);
    
    //Uart activated
    
    PC_PSoC_UART_Start();
    //I2C activated
    I2C_1_Start();
    
    
    // Add additional initialization code as desired
}


void mpu_init(struct MPU_9150_config *configObj) {
    configObj->accConfigData = 0b00001100;
    configObj->sampleRateDividerData = 0x08;
    configObj->fifoData = 0b00001000;
    configObj->powerManagement = 0b00000001;
}


uint32_t WriteI2CData(uint8_t mpu_register, uint8_t Data) {
    uint8_t buffer[2] = {mpu_register, Data};
    uint32_t status = TRANSFER_ERROR;
    uint8_t I2CMode;
    

    /* Initialize buffer with packet */
    (void) I2C_1_I2CMasterWriteBuf(I2C_SLAVE_ADDR, buffer, BUFFER_SIZE, \
                                  I2C_1_I2C_MODE_COMPLETE_XFER);
    while (0u == (I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_WR_CMPLT))
    {
    }
    
    //(void) I2C_1_I2CMasterClearStatus();
    return (status);
}


int32_t ReadI2CData(uint8_t mpu_register) {
    uint8_t buffer[1] = {mpu_register};
    (void) I2C_1_I2CMasterWriteBuf(I2C_SLAVE_ADDR, buffer, 1, \
                                  I2C_1_I2C_MODE_NO_STOP);
    while (0u == (I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_WR_CMPLT))
    {
    }
    uint8_t rbuffer[1];
    int32_t status;
    I2C_1_I2CMasterReadBuf(I2C_SLAVE_ADDR, rbuffer, 1, \
        I2C_1_I2C_MODE_REPEAT_START);

    /* Waits until master complete read transfer */
    while (0u == (I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_RD_CMPLT))
    {
    }
    
    if (0u == (I2C_1_I2C_MSTAT_ERR_XFER & I2C_1_I2CMasterStatus())) {
        status = rbuffer[0];
    }
    else {
        status = -1;   
    }
    
    I2C_1_I2CMasterClearStatus();
    return status;
    
}

void ReadI2CBytes(uint8_t numberOfBytes, uint8_t mpu_register, int8_t *Data) {
    int i = 0;
    for (i = 0; i < numberOfBytes; i++) {
        Data[i] = ReadI2CData(mpu_register);
    }

}

int16_t calibrateX() {
    int16_t error = 0;
    int16_t i;
    int16_t acc_x_H, acc_x_L, acc_x_total = 0;
    for (i = 0; i < 100; i++) {
        //CyDelay(1);
        acc_x_H = ReadI2CData(ACCEL_XOUT_H);
        acc_x_L = ReadI2CData(ACCEL_XOUT_L);
        acc_x_total += (acc_x_H << 8) + acc_x_L;   
    }
    acc_x_total = acc_x_total/100;
    error = acc_x_total;
    return error;
}

void calibrateMPU9150(int32_t *correctionError) {
    int32_t error[3] = {0,0,0}; //Fejl data fra x,y,z (ACC)
    int32_t error_reg[3] = {0,0,0};
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
    uint16_t accelSensitivity = 16384;
    
    WriteI2CData(INT_ENABLE, 0x00); //Disabler alle interrupts
    WriteI2CData(FIFO_EN, 0x00); //Disabler FIFO'en
    WriteI2CData(PWR_MGMT_1, 0x00); //Tænder for intern clock
    WriteI2CData(I2C_MST_CTRL, 0x00); //Disabler I2C master
    WriteI2CData(USER_CTRL, 0x0C); //Resetter FIFO og DMP
    CyDelay(15); //Sætter delay på 15 ms

    //Omsætning af acc
    WriteI2CData(CONFIG, 0x01); //Sætter båndbredde til 184 for acc og 188 for gyro
    WriteI2CData(SAMPLE_RATE_DIVIDER, 0x00); //Sætter samplerate til 1kHz
    WriteI2CData(ACC_CONFIG, 0b00001100); //Sætter acc til 2g, dette er maksimum følsomhed

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
        correctionError[j] = error[j];        
    }
}
