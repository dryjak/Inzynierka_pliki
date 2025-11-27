/*
 * state_mashine.h
 *
 *  Created on: Nov 24, 2025
 *      Author: dryla
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

typedef enum{
		IDLE = 0,
		DEBOUNCE,
		PRESSED,
		REPEAT,
		RELEASE
}ButtonState;

typedef struct{
	ButtonState 	State;

	GPIO_TypeDef 	*GpioPort;
	uint16_t 		GpioPin;

	uint32_t 		TimerLongPress;
	uint32_t 		TimerRepeat;
	uint32_t		TimerDebounce;
	uint32_t 		LastTick;

	void (*ButtonPressed)	(void);
	void (*ButtonRepeat)	(void);
	void (*ButtonLongPress)	(void);
	void (*ButtonRelease)	(void);
}Button_t;

void Button_Init(Button_t *Button, GPIO_TypeDef *GpioPort, uint16_t GpioPin, uint32_t TimerDebounce, uint32_t TimerRepeat,
		uint32_t TimerLongPress);

void Button_RegisterPressCallback(Button_t *Button, void(*Callback)());
void Button_RegisterLongPressCallback(Button_t *Button, void(*Callback)());
void Button_RegisterRepeatCallback(Button_t *Button, void(*Callback)());

void ButtonTasks(Button_t *Button);
void Button_SetDebounceTimer(Button_t *Button, uint32_t Milliseconds);
void Button_SetLongPressTimer(Button_t *Button, uint32_t Milliseconds);
void Button_SetRepeatTimer(Button_t *Button, uint32_t Milliseconds);


#endif /* INC_BUTTON_H_ */

