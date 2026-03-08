#include "mcal_pwm.h"

#define PWM_BASE 0x40021000

volatile uint32_t *PWM_CTRL = (uint32_t*)(PWM_BASE + 0x00);
volatile uint32_t *PWM_DUTY = (uint32_t*)(PWM_BASE + 0x10);

void PWM_Init(uint8_t channel)
{
    *PWM_CTRL |= (1 << channel);
}

void PWM_SetDuty(uint8_t channel, uint16_t duty)
{
    PWM_DUTY[channel] = duty;
}
