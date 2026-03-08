# Robot ECU Firmware – Deterministic Autonomous System

This repository contains a **layered ECU-style firmware** for an autonomous obstacle-avoidance robot built on the **ARM Cortex-M TM4C123 microcontroller**. It demonstrates how a hobby robot project can be re-architected with **industry-grade embedded system design principles**.

---

## Key Features

- **Layered Architecture**:  
  Application → Control → Service → Sensor → Actuator → MCAL  
  Each layer is independently testable, maintainable, and scalable.

- **Behavior Modes**:  
  - `MODE_IDLE` – Robot waits for input or timeout  
  - `MODE_ACTIVE` – Play behavior with randomized movements  
  - `MODE_AVOID` – Shy/avoid obstacles  
  - `MODE_ESCAPE` – Evade detected obstacles using reactive maneuvers  

- **Real-Time Scheduling**:  
  Deterministic task execution with **MCAL timers**, supporting concurrent sensor acquisition, actuator control, and behavior transitions.

- **Safety & Diagnostics**:  
  - Watchdog-triggered **failsafe state**  
  - UART-based **event logging** for traceability  
  - Latency measurement for each behavior transition

- **Hardware Abstraction (MCAL)**:  
  - GPIO, PWM, ADC, Timers, UART  
  - Separates hardware-specific register-level code from application logic  

- **Control & Motion**:  
  - Servo and motor drivers with real-time constraints  
  - Optional PID-based control for future automotive adaptation

---

## Folder Structure
```
robot_ecu_firmware/
│
├── app/ # Application layer – modes and main loop
├── control/ # Motion & control algorithms
├── service/ # Scheduler, safety, diagnostics, timebase
├── sensor/ # Ultrasonic, IR, battery monitoring
├── actuator/ # Motor, servo, optional buzzer
├── mcal/ # Hardware abstraction layer (GPIO, PWM, UART, Timer)
├── include/ # MCU headers and common definitions
├── README.md
└── LICENSE
```

---

## Build & Run

1. Use **ARM GCC Toolchain** (e.g., `arm-none-eabi-gcc`) or **TI Code Composer Studio**.  
2. Include `include/` folder in the build path.  
3. Compile all `.c` files from the layered structure.  
4. Flash the resulting binary to the **TM4C123GH6PM MCU**.  

---

## Potential Extensions

- Add **power management, watchdog enhancements, or redundant sensor checks**  
- Implement **PID loops for precise servo/motor control**  
- Port firmware to **automotive ECU platforms** for advanced embedded applications  

---

## About

This project shows the transition from a hobbyist robot to a **deterministic bare-metal embedded system**, emphasizing:

- Layered architecture  
- Real-time scheduling  
- Hardware abstraction  
- Safety and diagnostics  

It can serve as a foundation for **automotive-grade embedded system design**.
