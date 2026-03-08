#include "mcal_uart.h"

#define UART_BASE 0x40024000

volatile uint32_t *UART_CTRL = (uint32_t*)(UART_BASE + 0x00);
volatile uint32_t *UART_TX   = (uint32_t*)(UART_BASE + 0x04);
volatile uint32_t *UART_STAT = (uint32_t*)(UART_BASE + 0x08);

void UART_Init(void)
{
    *UART_CTRL = 1;
}

void UART_SendChar(char c)
{
    while(!(*UART_STAT & 1));

    *UART_TX = c;
}

void UART_SendString(const char *str)
{
    while(*str)
    {
        UART_SendChar(*str);
        str++;
    }
}
