//For nedenstående register adresser, se side 6 - 8 i 
//dokumentationen MPU-6050

#ifndef _MPU_REGISTER_ADDRESS_H_
#define _MPU_REGISTER_ADDRESS_H_
    
#define I2C_SLAVE_ADDR  		0x69
#define WHO_AM_I 				0x75
#define XA_OFFSET_H      		0x06 // User-defined trim values for accelerometer
#define XA_OFFSET_L   			0x07
#define YA_OFFSET_H  			0x08
#define YA_OFFSET_L 			0x09
#define ZA_OFFSET_H      		0x0A
#define ZA_OFFSET_L_TC   		0x0B
#define SAMPLE_RATE_DIVIDER 	0x19
#define CONFIG 					0x1A
#define GYRO_CONFIG 			0x1B
#define ACC_CONFIG 				0x1C
#define FIFO_EN 				0x23
#define I2C_MST_CTRL 			0x24
#define I2C_SLV0_ADDR 			0x25
#define I2C_SLV0_REG 			0x26
#define I2C_SLV0_CTRL
#define INT_ENABLE 				0x38
#define INT_STATUS 				0x3A
#define ACCEL_XOUT_H 			0x3B
#define ACCEL_XOUT_L 			0x3C
#define ACCEL_YOUT_H 			0x3D
#define ACCEL_YOUT_L 			0x3E
#define ACCEL_ZOUT_H 			0x3F
#define ACCEL_ZOUT_L 			0x40
#define USER_CTRL 				0x6A
#define PWR_MGMT_1 				0x6B //Device is default sleep mode
#define FIFO_COUNTH 			0x72
#define FIFO_COUNTL 			0x73
#define FIFO_R_W 				0x74
    
    
#define BUFFER_SIZE     (2u)
#define PACKET_SIZE     (BUFFER_SIZE)
#define TRANSFER_ERROR    (0xFFu)

#endif
//Hej med dig frederik
//skdcjhaskjdhasdkjah