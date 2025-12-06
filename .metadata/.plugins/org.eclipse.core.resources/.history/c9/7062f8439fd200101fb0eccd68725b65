/*
 * SerwoSimple.c
 *
 *  Created on: Nov 6, 2025
 *      Author: dryla
 */


#include "SerwoSimple.h"
#include "tim.h"

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

void Servo_MoveSlowly(uint16_t startAngle, uint16_t endAngle, uint8_t speedDelay)
{
    if (startAngle < endAngle)
    {
        // Ruch w górę
        for (uint16_t i = startAngle; i <= endAngle; i++)
        {
            SetAngle(i, 1);       // Ustaw mały krok
            HAL_Delay(speedDelay); // Czekaj (im dłużej, tym wolniejszy ruch)
        }
    }
    else
    {
        // Ruch w dół
        for (uint16_t i = startAngle; i >= endAngle; i--)
        {
            SetAngle(i, 1);
            HAL_Delay(speedDelay);
        }
    }
}

