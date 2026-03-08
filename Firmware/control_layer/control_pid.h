#ifndef CONTROL_PID_H
#define CONTROL_PID_H

#include <stdint.h>

void PID_Init(void);

int16_t PID_Compute(int16_t target);

#endif
