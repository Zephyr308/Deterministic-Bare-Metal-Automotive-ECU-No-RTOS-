#include "svc_timebase.h"

static volatile uint32_t system_ticks = 0;

void TIMEBASE_Init(void)
{
    system_ticks = 0;
}

void TIMEBASE_Tick(void)
{
    system_ticks++;
}

uint32_t TIMEBASE_GetTicks(void)
{
    return system_ticks;
}
