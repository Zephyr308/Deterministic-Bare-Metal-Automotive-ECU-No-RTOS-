#ifndef CONTROL_INTERFACE_H
#define CONTROL_INTERFACE_H

#include <stdint.h>

void CONTROL_Update(void);

void CONTROL_SetSpeed(int16_t speed);
void CONTROL_SetSteer(int16_t angle);

void CONTROL_Stop(void);

#endif
