# Example: LED Patterns

This example demonstrates several more complex visual patterns on a set of 8 LEDs.

## Functionality

The code runs an infinite loop that cycles through a sequence of three different patterns:

1.  **Knight Rider:** A single light scans back and forth.
2.  **Converge:** Two lights start at the ends and move towards the center.
3.  **Diverge:** Two lights start in the center and move out towards the ends.

## Hardware

-   8 LEDs are connected to **Port 2 (P2.0 to P2.7)**.
-   This example assumes **inverted logic** (common anode LEDs), where a `0` turns an LED ON and a `1` turns it OFF.
-   **Pull-up resistors** are required on Port 2 for the LEDs to be driven correctly.

## How to Build and Flash

You can build and flash this example in two ways:

1.  **From the example directory:**
    ```sh
    cd led-pattern
    make flash
    ```

2.  **From the project root directory:**
    ```sh
    make flash EXAMPLE=led-pattern
    ```
