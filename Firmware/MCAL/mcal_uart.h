#ifndef MCAL_UART_H
#define MCAL_UART_H

void UART_Init(void);

void UART_SendChar(char c);

void UART_SendString(const char *str);

#endif
