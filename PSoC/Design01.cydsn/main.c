/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <mpu_register_address.h>
#include <structs.h>
#include <stdlib.h>

#define BUFFER_SIZE     (2u)
#define PACKET_SIZE     (BUFFER_SIZE)
#define TRANSFER_ERROR    (0xFFu)

int main()
{
    
    CyGlobalIntEnable;      /* Enable global interrupts */
    sys_init();
   
    char *p1;
    char *p2;
    char *p3;
    char *p4;
    char *p5;
    char *p6;
    
    char value[20];
    char nylinje[] = "\n\r";
    
    uint8_t Data = 0x3b;
    int8_t acc_x_H[2];
    int8_t acc_x_L[2];
    int8_t acc_y_H;
    int8_t acc_y_L;
    int8_t acc_z_H;
    int8_t acc_z_L;
    
    int16_t acc_x_total[2];
    int16_t temp_acc_x[AVGFILTER_M];
    int16_t acc_y_total;
    int16_t acc_z_total;
    
    int32_t error[3];
    p1 = "I2C connection established \n\r";
    p2 = value;
    p3 = nylinje;
    //Tjekker om slaven eksistere og kan skrive sin adresse tilbage
    if (ReadI2CData(WHO_AM_I) != -1) {
        
        //struct MPU_9150_config accConfig, laver pinter til struct. Allokerer plads i memory til structen
           
        struct MPU_9150_config *accConfigObj = malloc(sizeof(struct MPU_9150_config));

        mpu_init(accConfigObj);
        WriteI2CData(PWR_MGMT_1, accConfigObj->powerManagement);
        //Sætter sample rate divideren på gyroscopet
        WriteI2CData(SAMPLE_RATE_DIVIDER, accConfigObj->sampleRateDividerData); 
        WriteI2CData(ACC_CONFIG, accConfigObj->accConfigData);
        CyDelay(20);
        int16_t data[1];
        calibrateMPU9150(error);   
        
    }
    
    
    int enteredForLoop = 0;
    for(;;) // endless loop
    {
        /*MatLab UART*/
//        CyDelay(100);
//        acc_x_H = ReadI2CData(ACCEL_XOUT_H);
//        acc_x_L = ReadI2CData(ACCEL_XOUT_L);
//        acc_x_total = (acc_x_H << 8) + acc_x_L;
//        
//        sprintf(value,"%d_",acc_x_total-error[0]);
//        PC_PSoC_UART_UartPutString(value);
        
        /*PSoC code*/
        acc_x_H[0] = ReadI2CData(ACCEL_XOUT_H);
        acc_x_L[0] = ReadI2CData(ACCEL_XOUT_L);
        /*Venter til at sample igen fra acc.
        Samplings hastighed fra ACC = 1kHz derfor ventes
        Der 2us*/
        CyDelay(2);
        acc_x_H[1] = ReadI2CData(ACCEL_XOUT_H);
        acc_x_L[1] = ReadI2CData(ACCEL_XOUT_L);
        for (int i = 0; i < 2; i++) {
         temp_acc_x[i] = (acc_x_H[i] << 8) + acc_x_L[i]; 
         
        }
        
        /*Midlings filter*/
        
    }
}



