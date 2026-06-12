# Example: Timer Interrupt

This example demonstrates how to use Timer0 interrupts to create a periodic system tick.

## Functionality

Timer0 is configured to generate an interrupt every 1 millisecond.

Each interrupt increments a software tick counter.

The main application monitors this counter and toggles an LED every 1000 ticks (approximately one second).

## Hardware

### LED

- LED connected to **P0.0**
- Configured as **active-high**
  - `1` → LED ON
  - `0` → LED OFF

### Example Circuit

```text
P0.0 ---- LED ---- GND
```

## Timer Configuration

| Parameter | Value |
|------------|--------|
| Timer | Timer0 |
| Mode | Mode 1 (16-bit) |
| Interrupt Period | 1 ms |
| Crystal Frequency | 11.0592 MHz |

## Expected Behavior

After reset:

- Timer0 generates an interrupt every 1 ms.
- The interrupt service routine increments a software tick counter.
- The LED toggles approximately once per second.

## Learning Objectives

This example demonstrates:

- Timer0 interrupt configuration
- Interrupt Service Routines (ISR)
- Global interrupt enable
- Periodic task scheduling
- Shared variables between ISR and main code
- Software tick generation

## Notes

- The tick counter is declared as `volatile` because it is modified inside an ISR.
- The ISR performs minimal work to keep interrupt latency low.
- Application logic is executed in the main loop rather than inside the interrupt handler.
- This architecture scales well to larger embedded applications.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-timer-interrupt
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-timer-interrupt
   ```