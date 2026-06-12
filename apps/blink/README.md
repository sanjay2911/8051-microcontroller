# Example: Blink LED

This example demonstrates the most basic operation of a microcontroller: blinking an LED at a fixed interval.

## Functionality

The application continuously turns an LED ON and OFF with a fixed delay between state changes, creating a visible blinking effect.

## Hardware

- LED connected to **P0.0**.
- The LED is configured as **active-high**:
  - `1` → LED ON
  - `0` → LED OFF

### Example Circuit

```text
P0.0 ---- LED ---- GND
```

## Expected Behavior

After reset, the LED continuously blinks with a fixed interval.

## Learning Objectives

This example demonstrates:

- GPIO output control
- Active-high LED operation
- Basic embedded application structure
- Software-based timing delays
- Port 0 usage on 8051/8052 devices

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-blink
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-blink
   ```
