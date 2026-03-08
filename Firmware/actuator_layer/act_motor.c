#include "act_motor.h"

#include "mcal_pwm.h"
#include "mcal_gpio.h"

#define MOTOR_PWM_CHANNEL 0
#define MOTOR_DIR_PIN 7

void Motor_Init(void)
{
    GPIO_SetPinDirection(MOTOR_DIR_PIN, GPIO_OUTPUT);

    PWM_Init(MOTOR_PWM_CHANNEL);
}

void Motor_SetSpeed(int16_t speed)
{
    if(speed >= 0)
    {
        GPIO_WritePin(MOTOR_DIR_PIN, 1);
    }
    else
    {
        GPIO_WritePin(MOTOR_DIR_PIN, 0);
        speed = -speed;
    }

    if(speed > 100)
        speed = 100;

    PWM_SetDuty(MOTOR_PWM_CHANNEL, speed);
}

void Motor_Stop(void)
{
    PWM_SetDuty(MOTOR_PWM_CHANNEL, 0);
}
