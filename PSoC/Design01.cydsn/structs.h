#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <project.h>
typedef struct MPU_9150_Acc_config_s {
    uint8_t accConfigData;
    uint8_t sampleRateDividerData;
    uint8_t fifoData;
    uint8_t powerManagement;
}MPU_9150_Acc_config_s;

typedef struct movement_XY_s {
    uint8 countx,county;
    
    int16 AccErrorX, AccErrorY;
    
    int16 acceleration_x[2];
    int16 acceleration_y[2];
    int16 velocity_x[2]; 
    int16 velocity_y[2];   
    int16 position_x[2];
    int16 position_y[2];
}movement_XY_s;




#endif // _STRUCTS_H_