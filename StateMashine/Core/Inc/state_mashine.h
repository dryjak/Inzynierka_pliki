/*
 * state_mashine.h
 *
 *  Created on: Nov 24, 2025
 *      Author: dryla
 */

#ifndef INC_STATE_MASHINE_H_
#define INC_STATE_MASHINE_H_

typedef enum{
		IDLE = 0,
		DEBOUNCE,
		PRESSED
}ButtonState;

struct{
	ButtonState 	State;

	GPIO_TypeDef 	*ButtonPort;
	uint16_t 		ButtonPin;

	uint32_t		TimerDebounce;
	uint32_t 		LastTick;

	void (*Callback)(void);
}Button_t;

#endif /* INC_STATE_MASHINE_H_ */
