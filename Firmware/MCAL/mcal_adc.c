#include "mcal_adc.h"

#define ADC_BASE 0x40022000

volatile uint32_t *ADC_CTRL = (uint32_t*)(ADC_BASE + 0x00);
volatile uint32_t *ADC_DATA = (uint32_t*)(ADC_BASE + 0x04);

void ADC_Init(void)
{
    *ADC_CTRL = 1;
}

uint16_t ADC_ReadChannel(uint8_t channel)
{
    *ADC_CTRL = (1 << 1) | channel;

    while(!(*ADC_CTRL & (1 << 2)));

    return (uint16_t)(*ADC_DATA & 0x3FF);
}
