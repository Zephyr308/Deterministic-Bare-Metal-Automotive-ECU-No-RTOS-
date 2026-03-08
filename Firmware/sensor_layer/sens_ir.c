#include "sens_ir.h"

#include "mcal_gpio.h"

#define IR_PIN 3

void IR_Init(void)
{
    GPIO_SetPinDirection(IR_PIN, GPIO_INPUT);
}

uint8_t IR_IsObjectDetected(void)
{
    return GPIO_ReadPin(IR_PIN);
}
