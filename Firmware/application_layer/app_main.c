#include "app_modes.h"

#include "svc_scheduler.h"
#include "svc_timebase.h"
#include "svc_safety.h"
#include "svc_diagnostics.h"

int main(void)
{

    Timebase_Init();

    Scheduler_Init();
    Safety_Init();
    Diagnostics_Init();

    APP_Init();

    while(1)
    {
        Scheduler_Run();

        Safety_Service();
        Diagnostics_Run();
    }

}
