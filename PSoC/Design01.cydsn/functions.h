#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <project.h>
#include <structs.h>
#include <mpu_register_address.h>


void sys_init();
void struct_init(MPU_9150_Acc_config_s *accInit, movement_XY_s *movementInit);  


//Funktioner der bruger structs som parameter (betragtes som member funktioner)
void mpu_init(MPU_9150_Acc_config_s *);
void movement_init(movement_XY_s *);
void setAcceleration(movement_XY_s *);
void setVelocity(movement_XY_s *);
void setPosition(movement_XY_s *);
void updateMovement(movement_XY_s *);



//Funktioner der returnerer void
void ReadI2CBytes(uint8_t numberOfBytes, uint8_t mpu_register, int8_t *Data);
void calibrateMPU9150(MPU_9150_Acc_config_s *accConfig, movement_XY_s *movementData);
void setAccXOffset();


//Funktioner der returnerer int
uint32_t WriteI2CData(uint8_t, uint8_t);
int32_t ReadI2CData(uint8_t);
int16_t calibrateX();

#endif 