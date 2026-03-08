#ifndef MCAL_GPIO_H
#define MCAL_GPIO_H

#include <stdint.h>

#define GPIO_INPUT  0
#define GPIO_OUTPUT 1

void GPIO_SetPinDirection(uint8_t pin, uint8_t dir);

void GPIO_WritePin(uint8_t pin, uint8_t value);

uint8_t GPIO_ReadPin(uint8_t pin);

#endif
