#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <mpu_register_address.h>
#include <structs.h>
#include <stdlib.h>



int main()
{
    
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    sys_init();
    char value[20];
 
    //Tjekker om slaven eksistere og kan skrive sin adresse tilbag
    
    if (ReadI2CData(WHO_AM_I) != -1) {
        
        //struct MPU_9150_config accConfig, laver pinter til struct. Allokerer plads i memory til structen
            
        
    }
    int8_t temp_acc_H[2];
    int8_t temp_acc_L[2];
    int16_t acc_total[2] = {0};
    int16_t velocity_x[2] = {0};
    int16_t position_x[2] = {0};
    MPU_9150_Acc_config_s accConfigObj;
    movement_XY_s movementData;
    kalmanFilterValues_s kalmanData;
    struct_init(&accConfigObj, &movementData, &kalmanData);
    uint8 countx = 0;
    
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

//        else {
//            countx = 0;
//            //Beregner hastighed ud fra acceleration
//            //Tager integrale af acc
//            velocity_x[1] = velocity_x[0]+acc_x_total[1]+((acc_x_total[1]+acc_x_total[0])/2);
//            
//            //Beregner position ud fra hastighed
//            //Integral af hastighed
//            position_x[1] = position_x[0]+velocity_x[1]+((velocity_x[1]+velocity_x[0])/2);
//            
//
//            
//        }
//        if (acc_x_total[0] < tolerance && acc_x_total[0] > -tolerance && acc_x_total[1] < tolerance && acc_x_total[1] > -tolerance) {
//            acc_x_total[0] = 0;
//            acc_x_total[1] = 0;
//            //Tæller count 1 op for hver gang et nul er blevet detekteret.
//            countx++;
//            
//            //Hvis data = 0 er registreret 10 gange, vil hastigheden opfattes som nul
//            if (countx >= 10) {
//                velocity_x[1] = 0;
//                velocity_x[0] = 0;
//                
//            }
//        }
//        
//        // Hvis 
//        else {
//            countx = 0;
//            //Beregner hastighed ud fra acceleration
//            //Tager integrale af acc
//            velocity_x[1] = velocity_x[0]+acc_x_total[1]+((acc_x_total[1]+acc_x_total[0])/2);
//            
//            //Beregner position ud fra hastighed
//            //Integral af hastighed
//            position_x[1] = position_x[0]+velocity_x[1]+((velocity_x[1]+velocity_x[0])/2);
//            
//
//            
////        }
//        temp_acc_H[1] = ReadI2CData(ACCEL_XOUT_H);
//        temp_acc_L[1] = ReadI2CData(ACCEL_XOUT_L);
//        acc_total[1] = ((temp_acc_H[1] << 8) + temp_acc_L[1]);
//        //Trækker x-accel fejl fra værdien
//        acc_total[1] -= movementData.AccErrorX;
//        
//       
//        if (acc_total[1] < TOLERANCE && acc_total[1] > -TOLERANCE) {
//            acc_total[1] = 0;
//            acc_total[0] = 0;
//        }
//        
//        velocity_x[1] = (velocity_x[0]/20)+acc_total[1]+((acc_total[1]+acc_total[0])/2);
//        
//        
//        if (acc_total[1] == 0) {
//            countx++;   
//            if (countx > 10) {
//             velocity_x[1] = 0;   
//            velocity_x[0] = 0;
//            }
//        }
//        else {
//            countx = 0;
//        }
//       
//        
//        position_x[1] = position_x[0]+velocity_x[1]+((velocity_x[1]+velocity_x[0])/2);
        
        setAcceleration(&movementData); 
        setVelocity(&movementData);
        setPosition(&movementData);
        kalmanFilter(&movementData,&kalmanData);
        sprintf(value,"%d_", (int)kalmanData.Estimate[1]);
        PC_PSoC_UART_UartPutString(value);
        updateMovement(&movementData);
        updateKalmanFilter(&kalmanData);
//        velocity_x[0] = velocity_x[1];
//        position_x[0] = position_x[1];
//        acc_total[0] = acc_total[1];
        CyDelay(50);
        
        
        
    }
}



