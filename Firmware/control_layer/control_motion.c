#include "control_interface.h"

#include "control_pid.h"

#include "act_motor.h"
#include "act_servo.h"

static int16_t target_speed;
static int16_t target_angle;

void CONTROL_SetSpeed(int16_t speed)
{
    target_speed = speed;
}

void CONTROL_SetSteer(int16_t angle)
{
    target_angle = angle;
}

void CONTROL_Stop(void)
{
    target_speed = 0;
}

void CONTROL_Update(void)
{
    int16_t pwm_output;

    pwm_output = PID_Compute(target_speed);

    Motor_SetSpeed(pwm_output);

    Servo_SetAngle(target_angle);
}
