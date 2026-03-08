#include "mcal_gpio.h"

#define GPIO_BASE 0x40020000

volatile uint32_t *GPIO_DIR = (uint32_t*)(GPIO_BASE + 0x00);
volatile uint32_t *GPIO_OUT = (uint32_t*)(GPIO_BASE + 0x04);
volatile uint32_t *GPIO_IN  = (uint32_t*)(GPIO_BASE + 0x08);

void GPIO_SetPinDirection(uint8_t pin, uint8_t dir)
{
    if(dir == GPIO_OUTPUT)
        *GPIO_DIR |= (1 << pin);
    else
        *GPIO_DIR &= ~(1 << pin);
}

void GPIO_WritePin(uint8_t pin, uint8_t value)
{
    if(value)
        *GPIO_OUT |= (1 << pin);
    else
        *GPIO_OUT &= ~(1 << pin);
}

uint8_t GPIO_ReadPin(uint8_t pin)
{
    return ((*GPIO_IN >> pin) & 1);
}
