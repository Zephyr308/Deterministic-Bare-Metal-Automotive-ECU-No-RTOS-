#include "svc_scheduler.h"

#include "svc_timebase.h"
#include "svc_safety.h"

#include "app_modes.h"
#include "control_interface.h"

static uint32_t last_tick = 0;

void SCHEDULER_Init(void)
{
    last_tick = TIMEBASE_GetTicks();
}

void SCHEDULER_Run(void)
{
    uint32_t now;

    now = TIMEBASE_GetTicks();

    if ((now - last_tick) >= 10)
    {
        last_tick = now;

        SAFETY_Check();

        APP_Modes_Run();

        CONTROL_Update();
    }
}
