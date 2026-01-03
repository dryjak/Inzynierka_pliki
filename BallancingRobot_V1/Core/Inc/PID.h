/*
 * PID.h
 *
 *  Created on: Oct 12, 2025
 *      Author: jakub
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "main.h"
#include "math.h"

// PID Controller Structure
typedef struct
{
	float P;				// Proportional Gain (Kp)
	float I;				// Integral Gain (Ki)
	float D;				// Derivative Gain (Kd)

	float SampleTime;		// Loop time in seconds [s]
	float MaxValue;			// Maximum Output Limit (Saturation)
	float MinValue;			// Minimum Output Limit (Saturation)

	float Integrator;		// Integral sum
	float LastError;		// Previous Error
	float LastMeasurement;	// Previous Measurement

	uint8_t Clamp;			// Anti-windup flag
}PID_t;

//Initializes the PID controller parameters
void PID_Init(PID_t *Pid, float P, float I, float D, float SampleTime, float MaxValue, float MinValue);

//Computes the PID output
float PID_Compute(PID_t *Pid, float MeasuredValue, float SetValue);

//Helper function to determine the sign of a variable
int8_t Signum(float Value);


#endif /* INC_PID_H_ */
