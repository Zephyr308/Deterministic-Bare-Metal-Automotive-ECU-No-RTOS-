#include "app_modes.h"

#include "sens_ultrasonic.h"
#include "sens_ir.h"
#include "control_interface.h"

static app_mode_t current_mode;

void APP_Init(void)
{
    current_mode = MODE_INIT;
}

void APP_Task1ms(void)
{
    /* control loop */
    CONTROL_Update();
}

void APP_Task10ms(void)
{
    uint32_t distance;
    uint8_t rear_detect;

    distance = SENS_Ultrasonic_Read();
    rear_detect = SENS_IR_Read();

    switch(current_mode)
    {

        case MODE_INIT:

            current_mode = MODE_IDLE;

        break;


        case MODE_IDLE:

            CONTROL_Stop();

            if(distance < 80)
            {
                current_mode = MODE_ACTIVE;
            }

        break;


        case MODE_ACTIVE:

            CONTROL_SetSpeed(50);
            CONTROL_SetSteer(0);

            if(distance < 30)
            {
                current_mode = MODE_AVOID;
            }

        break;


        case MODE_AVOID:

            CONTROL_SetSpeed(-40);

            if(rear_detect)
            {
                current_mode = MODE_ESCAPE;
            }
            else
            {
                current_mode = MODE_IDLE;
            }

        break;


        case MODE_ESCAPE:

            CONTROL_SetSpeed(60);
            CONTROL_SetSteer(40);

            if(distance > 80)
            {
                current_mode = MODE_IDLE;
            }

        break;


        case MODE_SAFE:

            CONTROL_Stop();

        break;

    }
}

void APP_Task100ms(void)
{

}
