#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <project.h>
#include <structs.h>


void sys_init();  
void mpu_init(struct MPU_9150_Acc_config *);

uint32_t WriteI2CData(uint8_t, uint8_t);
int32_t ReadI2CData(uint8_t);
void ReadI2CBytes(uint8_t numberOfBytes, uint8_t mpu_register, int8_t *Data);
void calibrateMPU9150(int32_t *correctionError);
int16_t calibrateX();
void setAccXOffset();



#endif 