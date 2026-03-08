#include "svc_diagnostics.h"

#include <stdio.h>

void DIAG_Init(void)
{

}

void DIAG_Log(const char *msg)
{
    printf("%s\n", msg);
}
