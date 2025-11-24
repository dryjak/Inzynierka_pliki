/*
 * state_mashine.c
 *
 *  Created on: Nov 24, 2025
 *      Author: dryla
 */

#include <main.h>
#include <state_mashine.h>

void Button_Init(Button_t *Button, GPIO_TypeDef *GpioPort, uint16_t GpioPin, uint32_t TimerDebounce)
{
	Button->GpioPort = GpioPort;
	Button->GpioPin = GpioPin;

	Button->TimerDebounce = TimerDebounce;

	Button->State = IDLE;
}
