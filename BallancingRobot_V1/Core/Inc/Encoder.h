/*
 * Encoder.h
 *
 *  Created on: Oct 4, 2025
 *      Author: jakub
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "main.h"

typedef struct
{
	TIM_HandleTypeDef *Tim;
	uint16_t PulsesPerRevolution;	//number of pulses per one motor revolution
	float SampleTime;				//e.g. 0.01 for 100hz

	uint32_t LastCounterValue;

	volatile int64_t TotalPulses;
	float AngularVelocity;
	float Angle;

}Encoder_t;

void Encoder_Init(Encoder_t *Encoder, TIM_HandleTypeDef *Tim, uint16_t PulsesPerRevolution, float SampleTime);
void Encoder_Update(Encoder_t *Encoder);


#endif /* INC_ENCODER_H_ */
