#ifndef ACT_MOTOR_H
#define ACT_MOTOR_H

#include <stdint.h>

void Motor_Init(void);

void Motor_SetSpeed(int16_t speed);

void Motor_Stop(void);

#endif
