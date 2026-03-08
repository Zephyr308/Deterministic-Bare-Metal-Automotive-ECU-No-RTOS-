#ifndef MCAL_PWM_H
#define MCAL_PWM_H

#include <stdint.h>

void PWM_Init(uint8_t channel);

void PWM_SetDuty(uint8_t channel, uint16_t duty);

#endif
