/*
 * SerwoSimple.c
 *
 *  Created on: Nov 6, 2025
 *      Author: dryla
 */


#include "SerwoSimple.h"
#include "tim.h"
#include <math.h>

#define PI 3.14159265

void SetAngle(uint16_t Angle, uint8_t Mode)
{
	uint16_t Tmp;

	if(Angle < AngleMin)
	{
		Angle = AngleMin;
	}
	else if(Angle > AngleMax)
	{
		Angle = AngleMax;
	}

	if(Mode)
	{
		Tmp = (PWM_Min + ((Angle - AngleMin) * STEP) / 1000);
	}
	else
	{
		Tmp = (PWM_Max - ((Angle - AngleMin) * STEP) / 1000);
	}

	__HAL_TIM_SET_COMPARE(&WhichTimer, TimerChannel,Tmp);
}
