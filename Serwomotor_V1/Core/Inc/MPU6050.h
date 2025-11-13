/*
 * MPU6050.h
 *
 *  Created on: Sep 6, 2025
 *      Author: jakub
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "main.h"


#define WHO_AM_I 			0x75
#define ADR0		 		0x68
#define ADR1 				0x69
#define PWR_MGMT_1			0x6B
#define GYRO_CONFIG 		0x1B
#define ACCEL_CONFIG 		0x1C

#define ACCEL_XOUT_H		0x3B
#define GYRO_XOUT_H			0x43

#define MPU6050_TIMEOUT 	500

typedef struct
{
	float X;
	float Y;
	float Z;
}Data_t;

typedef struct
{
	int16_t X;
	int16_t Y;
	int16_t Z;
}DataRaw_t;

typedef struct
{
	I2C_HandleTypeDef *hi2c;
	uint16_t address;
	Data_t AccelOffset;
	Data_t GyroOffset;
	Data_t GyroDryf;
}MPU6050_t;

typedef enum
{
	MPU6050_OK,
	MPU6050_ERROR
}MPU6050_STATE_t;

MPU6050_STATE_t MPU6050_Init(MPU6050_t *MPU6050, I2C_HandleTypeDef *Hi2c, uint16_t Address);
MPU6050_STATE_t MPU6050_WakeUp(MPU6050_t *MPU6050);
uint8_t MPU6050_WHO_AM_I (MPU6050_t *MPU6050);

//functions to read accel data
MPU6050_STATE_t MPU6050_DegFromAccel(MPU6050_t *MPU6050, float *Roll, float *Pitch);

//functions for read gyro data
MPU6050_STATE_t MPU6050_DegFromGyro(MPU6050_t *MPU6050, float *RollG, float *PitchG, float *YawG);

//Function to read final angle values
MPU6050_STATE_t MPU6050_Angle(MPU6050_t *MPU6050, float *Roll, float *Pitch, float *Yaw);


#endif /* INC_MPU6050_H_ */
