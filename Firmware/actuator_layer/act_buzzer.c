#include "act_buzzer.h"

#include "mcal_gpio.h"

#define BUZZER_PIN 8

void BUZZER_Init(void)
{
    GPIO_SetPinDirection(BUZZER_PIN, GPIO_OUTPUT);
}

void BUZZER_On(void)
{
    GPIO_WritePin(BUZZER_PIN, 1);
}

void BUZZER_Off(void)
{
    GPIO_WritePin(BUZZER_PIN, 0);
}
