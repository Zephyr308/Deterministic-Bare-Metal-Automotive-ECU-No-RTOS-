#include "sens_battery.h"

#include "mcal_adc.h"

#define BATTERY_ADC_CHANNEL 0

void BATTERY_Init(void)
{
    ADC_Init();
}

float BATTERY_GetVoltage(void)
{
    uint16_t raw;

    raw = ADC_ReadChannel(BATTERY_ADC_CHANNEL);

    float voltage = (raw * 5.0f) / 1023.0f;

    return voltage * 2.0f; /* voltage divider */
}
