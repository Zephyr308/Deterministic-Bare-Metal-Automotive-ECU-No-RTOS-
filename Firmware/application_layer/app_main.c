#include "app_modes.h"
#include "svc_scheduler.h"
#include "svc_safety.h"
#include "svc_timebase.h"
#include "svc_diagnostics.h"
#include "sens_ultrasonic.h"
#include "sens_ir.h"
#include "act_motor.h"
#include "act_servo.h"
#include "mcal_gpio.h"
#include "mcal_pwm.h"
#include "mcal_timer.h"
#include "mcal_uart.h"

/** @brief System initialization and main loop */
int main(void)
{
    // --- MCAL Initialization ---
    GPIO_Init();        // Configure pins
    PWM_Init();         // Motors & servo
    TIMER_Init();       // System timebase
    UART_Init();        // Diagnostics/logging
    ADC_Init();         // Battery monitoring

    // --- Sensor/Actuator Initialization ---
    Ultrasonic_Init();
    IR_Init();
    Motor_Init();
    Servo_Init();

    // --- Service Layer Initialization ---
    Diagnostics_Init();
    Safety_Init();
    Scheduler_Init();
    Timebase_Init();

    // --- Application Layer Initialization ---
    AppModes_Init();    // Define modes: IDLE, ACTIVE, AVOID, ESCAPE

    // Enable global interrupts (if used)
    __enable_irq();

    // --- Main Scheduler Loop ---
    while(1)
    {
        // Run scheduler tick
        Scheduler_Run();

        // Check safety
        if(Safety_CheckFail())
        {
            AppModes_EnterSafeState(); // Safe shutdown
        }

        // Run current behavior mode
        AppModes_RunCurrentMode();
    }

    return 0;
}
