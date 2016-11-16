#include <functions.h>

void sys_init() {
     //Internal pull-up resistors for I2C line
    I2C_1_scl_SetDriveMode(I2C_1_scl_DM_RES_UP); 
    I2C_1_sda_SetDriveMode(I2C_1_sda_DM_RES_UP);
    
    //Uart activated
    
    PC_PSoC_UART_Start();
    //I2C activated
    I2C_1_Start();
}

void struct_init (MPU_9150_Acc_config_s *accInit, movement_XY_s *movementInit) {
    mpu_init(accInit);
    movement_init(movementInit);
    //calibrateMPU9150(accInit, movementInit);

}



uint32_t WriteI2CData(uint8_t mpu_register, uint8_t Data) {
    uint8_t buffer[2] = {mpu_register, Data};
    uint32_t status = TRANSFER_ERROR;

    

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



