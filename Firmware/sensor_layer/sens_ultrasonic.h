#ifndef SENS_ULTRASONIC_H
#define SENS_ULTRASONIC_H

#include <stdint.h>

void ULTRASONIC_Init(void);

void ULTRASONIC_Trigger(void);

uint16_t ULTRASONIC_GetDistance(void);

#endif
