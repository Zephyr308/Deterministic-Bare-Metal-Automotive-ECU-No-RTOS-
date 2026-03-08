#ifndef APP_MODES_H
#define APP_MODES_H

#include <stdint.h>

typedef enum
{
    MODE_INIT = 0,
    MODE_IDLE,
    MODE_ACTIVE,
    MODE_AVOID,
    MODE_ESCAPE,
    MODE_SAFE

} app_mode_t;

void APP_Init(void);

void APP_Task1ms(void);
void APP_Task10ms(void);
void APP_Task100ms(void);

#endif
