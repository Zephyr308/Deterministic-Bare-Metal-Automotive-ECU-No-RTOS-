#include "sens_ultrasonic.h"

#include "mcal_gpio.h"
#include "mcal_timer.h"

#define TRIG_PIN 5
#define ECHO_PIN 6

static uint16_t distance_cm = 0;

void ULTRASONIC_Init(void)
{
    GPIO_SetPinDirection(TRIG_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(ECHO_PIN, GPIO_INPUT);
}

void ULTRASONIC_Trigger(void)
{
    GPIO_WritePin(TRIG_PIN, 1);

    TIMER_DelayUs(10);

    GPIO_WritePin(TRIG_PIN, 0);
}

uint16_t ULTRASONIC_GetDistance(void)
{
    /* In real implementation this comes from echo timing */
    return distance_cm;
}
