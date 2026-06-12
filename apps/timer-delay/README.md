# Example: Timer Delay

This example demonstrates how to generate delays using the 8051/8052 Timer0 peripheral instead of software delay loops.

## Functionality

The application configures Timer0 in 16-bit mode and uses timer overflow events to generate accurate delays.

An LED connected to **P0.0** is toggled every second.

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
| Mode | Mode 1 |
| Width | 16-bit |
| Clock | 11.0592 MHz |

The timer generates approximately 50 ms delays.

Twenty timer periods are combined to create a delay of approximately one second.

## Expected Behavior

After reset:

- Timer0 starts generating delay intervals.
- The LED toggles every second.
- No software delay loops are used.

## Learning Objectives

This example demonstrates:

- Timer0 initialization
- Timer0 Mode 1 operation
- Timer overflow detection
- Hardware-based delays
- LED control using timer events

## Notes

- Timer0 is polled using the TF0 overflow flag.
- Interrupts are not used in this example.
- Hardware timers provide more accurate timing than software delay loops.
- Timer interrupts will be introduced in a later example.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-timer-delay
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-timer-delay
   ```