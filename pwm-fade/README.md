# Example: Software PWM LED Fading

This example demonstrates how to generate a Pulse Width Modulation (PWM) signal in software to create a "breathing" or fading effect on an LED.

## Functionality

The 8051 microcontroller does not have built-in hardware for PWM. This code emulates the functionality using a timer interrupt.

1.  **Timer 0** is configured to trigger an interrupt at a high frequency.
2.  The **Interrupt Service Routine (ISR)** for Timer 0 acts as the PWM engine. It keeps a counter and compares it to a global `duty_cycle` variable.
3.  Based on the comparison, the ISR sets the output pin `P2.0` to HIGH or LOW, creating the PWM signal.
4.  The `main` loop continuously modifies the `duty_cycle` variable up and down, which causes the LED's brightness to ramp up and down smoothly.

## Hardware

-   An LED is connected to pin **P2.0**.
-   For a standard LED setup, the pin drives the LED HIGH (`1`) to turn it ON. You do not need inverted logic for this effect.

## How to Build and Flash

You can build and flash this example in two ways:

1.  **From the example directory:**
    ```sh
    cd pwm-fade
    make flash
    ```

2.  **From the project root directory:**
    ```sh
    make flash EXAMPLE=pwm-fade
    ```
