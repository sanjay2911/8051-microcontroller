# Example: UART "Hello World"

This example demonstrates how to configure and use the 8051's built-in UART (Universal Asynchronous Receiver/Transmitter) to send a string.

## Functionality

The code initializes the 8051's UART to operate at a **9600 baud rate**, assuming a crystal frequency of 11.0592MHz.

It then enters an infinite loop and continuously transmits the string "Hello World!" followed by a carriage return and newline `(\\r\\n)`.

## Hardware

-   The 8051's `TXD` (Transmit Data) pin should be connected to the `RXD` (Receive Data) pin of a USB-to-TTL serial adapter or another serial device.
-   The microcontroller's ground (`GND`) must be connected to the serial adapter's ground.

You can view the output using a serial terminal program (like PuTTY, Tera Term, or the Arduino IDE's Serial Monitor) configured for 9600 baud, 8 data bits, no parity, and 1 stop bit (8N1).

## How to Build and Flash

You can build and flash this example in two ways:

1.  **From the example directory:**
    ```sh
    cd uart-hello
    make flash
    ```

2.  **From the project root directory:**
    ```sh
    make flash EXAMPLE=uart-hello
    ```
