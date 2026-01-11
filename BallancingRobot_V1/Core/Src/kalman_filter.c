/*
 * kalman_filter.c
 *
 *  Created on: Jan 11, 2026
 *      Author: dryla
 */

#include "kalman_filter.h"

// newAngle = Kąt z akcelerometru (np. z atan2)
// newRate  = Prędkość z żyroskopu (w stopniach na sekundę!)
// dt       = Czas cyklu w sekundach (np. 0.005f)
float Kalman_GetAngle(Kalman_t *kalman, float newAngle, float newRate, float dt)
{
    // KROK 1: PREDYKCJA (Na podstawie żyroskopu)
    kalman->rate = newRate - kalman->bias;
    kalman->angle += dt * kalman->rate;

    // Aktualizacja macierzy kowariancji (błędu szacowania)
    kalman->P[0][0] += dt * (dt * kalman->P[1][1] - kalman->P[0][1] - kalman->P[1][0] + kalman->Q_angle);
    kalman->P[0][1] -= dt * kalman->P[1][1];
    kalman->P[1][0] -= dt * kalman->P[1][1];
    kalman->P[1][1] += kalman->Q_bias * dt;

    // KROK 2: KOREKCJA (Na podstawie akcelerometru)
    float S = kalman->P[0][0] + kalman->R_measure; // Błąd całkowity
    float K[2]; // Wzmocnienie Kalmana
    K[0] = kalman->P[0][0] / S;
    K[1] = kalman->P[1][0] / S;

    float y = newAngle - kalman->angle; // Różnica między pomiarem a predykcją (Innovation)

    kalman->angle += K[0] * y;
    kalman->bias  += K[1] * y;

    // Aktualizacja macierzy kowariancji po korekcji
    float P00_temp = kalman->P[0][0];
    float P01_temp = kalman->P[0][1];

    kalman->P[0][0] -= K[0] * P00_temp;
    kalman->P[0][1] -= K[0] * P01_temp;
    kalman->P[1][0] -= K[1] * P00_temp;
    kalman->P[1][1] -= K[1] * P01_temp;

    return kalman->angle; // Zwracamy najlepszy szacowany kąt
}
void Kalman_Init(Kalman_t *kalman)
{
    // Ustawienia domyślne (możesz stroić)
    kalman->Q_angle = 0.001f;
    kalman->Q_bias  = 0.003f;
    kalman->R_measure = 0.5f; // Zwiększ, jeśli robot ma duże wibracje (np. do 0.1)

    kalman->angle = 0.0f;
    kalman->bias  = 0.0f;

    kalman->P[0][0] = 0.0f;
    kalman->P[0][1] = 0.0f;
    kalman->P[1][0] = 0.0f;
    kalman->P[1][1] = 0.0f;
}
