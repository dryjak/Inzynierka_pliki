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

void My_SmartDelay(uint32_t delay_ms)
{
    uint32_t startTick = HAL_GetTick(); // Pobierz aktualny czas

    // Pętla wykonuje się dopóki nie minie zadany czas
    while ((HAL_GetTick() - startTick) < delay_ms)
    {
        // W czasie czekania sprawdzamy, czy trzeba coś wysłać!
        Check_And_Report();
    }
}




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
            SetAngle_WithGlobalUpdate(i, 1);
        }
    }
    else
    {
        // Ruch w dół
        for (uint16_t i = startAngle; i >= endAngle; i--)
        {
            SetAngle(i, 1);
            SetAngle_WithGlobalUpdate(i, 1);
        }
    }
}
// --- 2. Sinusoida ---
void Motion_SineHalf(uint8_t speedDelay) {
    float x;
    uint16_t amplitude = 300;

    for(x = 0; x <= 3.14; x += 0.05) {
        float sinVal = sin(x);
        uint16_t pos = (uint16_t)(sinVal * amplitude);

        SetAngle_WithGlobalUpdate(pos, 1);

        // Tutaj też używamy SmartDelay, żeby nie gubić próbek
        // przy wolnym ruchu
        My_SmartDelay(speedDelay);
    }

    SetAngle_WithGlobalUpdate(0, 1);
    My_SmartDelay(500);
}
