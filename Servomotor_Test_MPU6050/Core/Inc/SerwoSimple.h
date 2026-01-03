/*
 * SerwoSimple.h
 *
 *  Created on: Nov 6, 2025
 *      Author: dryla
 */

#ifndef INC_SERWOSIMPLE_H_
#define INC_SERWOSIMPLE_H_

#include "stdint.h"

// Timer configuration
#define WhichTimer htim2
#define TimerChannel TIM_CHANNEL_1

// Calibrated Servo Values
// AngleMin/Max (0-900 for 0-90 degrees)
#define AngleMin 0		//offsets
#define AngleMax 900
#define PWM_Min  900
#define PWM_Max  1900

// Macro mapping step (Scaling factor)
#define STEP ((1000 * (PWM_Max - PWM_Min)) / (AngleMax - AngleMin))

void SetAngle(uint16_t Angle, uint8_t Mode);

#endif /* INC_SERWOSIMPLE_H_ */
