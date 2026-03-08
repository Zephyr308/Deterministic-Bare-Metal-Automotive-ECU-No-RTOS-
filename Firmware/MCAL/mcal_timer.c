#include "mcal_timer.h"

#define TIMER_BASE 0x40023000

volatile uint32_t *TIMER_CTRL = (uint32_t*)(TIMER_BASE + 0x00);
volatile uint32_t *TIMER_CNT  = (uint32_t*)(TIMER_BASE + 0x04);

void TIMER_Init(void)
{
    *TIMER_CTRL = 1;
}

void TIMER_DelayUs(uint32_t us)
{
    *TIMER_CNT = 0;

    while(*TIMER_CNT < us);
}
