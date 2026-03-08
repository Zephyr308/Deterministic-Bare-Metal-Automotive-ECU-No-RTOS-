#ifndef SVC_TIMEBASE_H
#define SVC_TIMEBASE_H

#include <stdint.h>

void TIMEBASE_Init(void);

void TIMEBASE_Tick(void);

uint32_t TIMEBASE_GetTicks(void);

#endif
