#ifndef MCAL_ADC_H
#define MCAL_ADC_H

#include <stdint.h>

void ADC_Init(void);

uint16_t ADC_ReadChannel(uint8_t channel);

#endif
