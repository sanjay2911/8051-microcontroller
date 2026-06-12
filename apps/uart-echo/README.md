# Example: UART Echo

This example demonstrates bidirectional UART communication by receiving characters from a serial terminal and immediately transmitting them back.

## Functionality

The application initializes the UART peripheral and waits for incoming characters.

Whenever a character is received:

1. The character is read from the UART receive buffer.
2. The same character is immediately transmitted back.

This behavior is commonly referred to as an **echo server**.

## Hardware

### UART Connections

| MCU Pin | Function |
|----------|----------|
| P3.0 | RXD (Receive Data) |
| P3.1 | TXD (Transmit Data) |

### Serial Settings

| Parameter | Value |
|------------|--------|
| Baud Rate | 9600 |
| Data Bits | 8 |
| Parity | None |
| Stop Bits | 1 |

### Clock Requirement

This example assumes an **11.0592 MHz crystal oscillator**, which allows generation of an accurate 9600 baud rate using Timer 1.

## Expected Behavior

After reset, the following message is displayed:

```text
UART Echo Example
Type a character and it will be echoed back.
```

Example interaction:

```text
Input : A
Output: A

Input : Hello
Output: Hello
```

Each received character is transmitted back immediately.

## Learning Objectives

This example demonstrates:

- UART initialization
- UART reception
- UART transmission
- Polling-based serial communication
- Echo application design

## Notes

- UART operates in Mode 1 (8-bit UART).
- Reception is implemented using polling.
- Characters are echoed one at a time.
- This example forms the foundation for command-line interfaces and serial debugging tools.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-uart-echo
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-uart-echo
   ```