# Example: UART Transmit

This example demonstrates basic UART communication using the 8051/8052 serial peripheral.

## Functionality

The application initializes the UART peripheral and continuously transmits a text message over the serial interface.

The following message is sent once per second:

```text
Hello World!
```

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

After reset, the microcontroller repeatedly transmits:

```text
Hello World!
```

with approximately one second between messages.

## Learning Objectives

This example demonstrates:

- UART peripheral initialization
- Timer 1 baud rate generation
- Character transmission
- String transmission
- Serial terminal communication

## Notes

- UART is configured in Mode 1 (8-bit UART).
- Receiver is enabled although reception is not used in this example.
- A USB-to-UART adapter can be connected to TXD (P3.1) to observe the output.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-uart
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-uart
   ```