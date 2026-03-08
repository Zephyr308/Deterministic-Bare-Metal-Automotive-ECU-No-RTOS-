#include "svc_safety.h"

#include "control_interface.h"

static int safety_flag = 0;

void SAFETY_Init(void)
{
    safety_flag = 0;
}

void SAFETY_Check(void)
{
    if (safety_flag)
    {
        CONTROL_Stop();
    }
}

void SAFETY_Trigger(void)
{
    safety_flag = 1;
}

int SAFETY_IsTriggered(void)
{
    return safety_flag;
}
