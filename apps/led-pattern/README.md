# Example: LED Patterns

This example demonstrates a collection of LED animation patterns using eight LEDs connected to a single GPIO port.

## Functionality

The application continuously displays multiple LED patterns on Port 2.

The implemented patterns include:

1. Left Shift
2. Right Shift
3. Knight Rider
4. Converge
5. Diverge
6. Alternate LEDs
7. Binary Counter
8. Fill Up
9. Empty Down
10. Blink All

Each pattern runs for a short duration before automatically transitioning to the next pattern.

## Hardware

### LED Connections

Eight LEDs connected to Port 2:

| Pin | LED |
|------|------|
| P2.0 | LED0 |
| P2.1 | LED1 |
| P2.2 | LED2 |
| P2.3 | LED3 |
| P2.4 | LED4 |
| P2.5 | LED5 |
| P2.6 | LED6 |
| P2.7 | LED7 |

### Example Circuit

```text
P2.0 ---- LED0 ---- GND
P2.1 ---- LED1 ---- GND
P2.2 ---- LED2 ---- GND
P2.3 ---- LED3 ---- GND
P2.4 ---- LED4 ---- GND
P2.5 ---- LED5 ---- GND
P2.6 ---- LED6 ---- GND
P2.7 ---- LED7 ---- GND
```

### LED Logic

- Active-high configuration
  - `1` → LED ON
  - `0` → LED OFF

## Expected Behavior

After reset:

- LEDs begin displaying animation patterns.
- Patterns execute sequentially.
- The sequence repeats indefinitely.

## Learning Objectives

This example demonstrates:

- GPIO output control
- Bit manipulation
- Bit shifting operations
- Pattern generation
- Sequential LED animations
- Multi-LED control techniques

## Notes

- Timing is generated using software delays.
- Pattern complexity increases progressively throughout the example.
- This example serves as a foundation for more advanced display and animation projects.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-led-pattern
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-led-pattern
   ```