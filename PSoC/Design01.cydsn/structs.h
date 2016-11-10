#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <project.h>
struct MPU_9150_config {
    uint8_t accConfigData;
    uint8_t sampleRateDividerData;
    uint8_t fifoData;
    uint8_t powerManagement;
};

#endif // _STRUCTS_H_