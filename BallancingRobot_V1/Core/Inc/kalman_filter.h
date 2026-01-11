/*
 * kalman_filter.h
 *
 *  Created on: Jan 11, 2026
 *      Author: dryla
 */

#ifndef INC_KALMAN_FILTER_H_
#define INC_KALMAN_FILTER_H_

typedef struct {
    float Q_angle;   // Szum procesu (dla kąta) - jak bardzo ufamy matematyce
    float Q_bias;    // Szum procesu (dla biasu żyroskopu)
    float R_measure; // Szum pomiaru - jak bardzo NIE ufamy akcelerometrowi (wibracje)

    float angle;     // Obliczony kąt (wynik)
    float bias;      // Obliczony dryft żyroskopu
    float rate;      // Prędkość kątowa bez dryftu

    float P[2][2];   // Macierz kowariancji błędu
} Kalman_t;

float Kalman_GetAngle(Kalman_t *kalman, float newAngle, float newRate, float dt);
void Kalman_Init(Kalman_t *kalman);



#endif /* INC_KALMAN_FILTER_H_ */
