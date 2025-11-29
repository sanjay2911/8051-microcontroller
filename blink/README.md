# Example: Blink LED

This example demonstrates the most basic "Hello, World!" of microcontrollers: blinking a single LED.

## Functionality

The code continuously toggles a single pin, `P2.0`, on and off with a 500ms delay, causing a connected LED to blink.

## Hardware

-   An LED is connected to pin **P2.0**.
-   This example assumes **inverted logic** (common anode LED), where a `0` turns the LED ON and a `1` turns it OFF.
-   **Pull-up resistors** are required on Port 2 if the LEDs are to be driven correctly in this configuration.

## How to Build and Flash

You can build and flash this example in two ways:

1.  **From the example directory:**
    ```sh
    cd blink
    make flash
    ```

2.  **From the project root directory:**
    ```sh
    make flash EXAMPLE=blink
    ```
