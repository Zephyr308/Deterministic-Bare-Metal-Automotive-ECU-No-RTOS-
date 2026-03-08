#include "control_pid.h"

static float kp = 1.2f;
static float ki = 0.05f;
static float kd = 0.02f;

static float integral = 0;
static float prev_error = 0;

void PID_Init(void)
{
    integral = 0;
    prev_error = 0;
}

int16_t PID_Compute(int16_t target)
{
    float measurement = 0;   /* future encoder feedback */

    float error = target - measurement;

    integral += error;

    float derivative = error - prev_error;

    prev_error = error;

    float output =
        kp * error +
        ki * integral +
        kd * derivative;

    return (int16_t)output;
}
