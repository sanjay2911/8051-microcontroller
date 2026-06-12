# Example: Button Controlled LED

This example demonstrates how to read a digital input and control an LED based on the state of a push button.

## Functionality

The application continuously monitors a push button connected to **P0.1**.

- When the button is pressed, the LED turns ON.
- When the button is released, the LED turns OFF.

## Hardware

### LED

- LED connected to **P0.0**
- Configured as **active-high**
  - `1` → LED ON
  - `0` → LED OFF

### Push Button

- Push button connected to **P0.1**
- Configured as **active-low**
  - `0` → Button Pressed
  - `1` → Button Released

### Example Circuit

```text
P0.0 ---- LED ---- GND

P0.1 ---- Push Button ---- GND
```

## Expected Behavior

| Button State | LED State |
|--------------|-----------|
| Released     | OFF |
| Pressed      | ON  |

## Learning Objectives

This example demonstrates:

- GPIO input reading
- GPIO output control
- Digital input polling
- Active-low button handling
- Active-high LED control
- Bit masking techniques

## Notes

- The button is continuously polled inside the main loop.
- No software debouncing is implemented.
- Mechanical button bounce will be addressed in a later example.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-button
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-button
   ```
