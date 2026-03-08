#include "act_servo.h"

#include "mcal_pwm.h"

#define SERVO_PWM_CHANNEL 1

static int16_t current_angle = 0;

void Servo_Init(void)
{
    PWM_Init(SERVO_PWM_CHANNEL);
}

void Servo_SetAngle(int16_t angle)
{
    if(angle > 45)
        angle = 45;

    if(angle < -45)
        angle = -45;

    current_angle = angle;

    /* convert angle to PWM duty */
    uint16_t duty = 7 + angle / 10;

    PWM_SetDuty(SERVO_PWM_CHANNEL, duty);
}
