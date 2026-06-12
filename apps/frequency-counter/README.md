# Example: Frequency Counter

This example demonstrates how to measure the frequency of an external digital signal using the 8051/8052 external interrupt and Timer0 interrupt peripherals.

## Functionality

The application counts pulses arriving on the **INT0** input pin and periodically reports the measured frequency over UART.

The implementation uses:

- **INT0 (External Interrupt 0)** to count incoming pulses.
- **Timer0 Interrupt** to create a measurement interval.
- **UART** to display the measured frequency.

At the end of each measurement interval:

1. The current pulse count is captured.
2. The pulse counter is reset.
3. The measured value is transmitted over UART.

## Hardware

### Frequency Input

| Pin | Function |
|------|----------|
| P3.2 | INT0 Frequency Input |

### UART Connections

| Pin | Function |
|------|----------|
| P3.0 | RXD |
| P3.1 | TXD |

### Example Connection

```text
                 +----------------+
Signal Source -->| P3.2 (INT0)    |
                 |                |
USB-UART RX  <---| P3.1 (TXD)     |
USB-UART TX  --->| P3.0 (RXD)     |
                 +----------------+
```

## Timer Configuration

Timer0 is configured in:

| Parameter | Value |
|------------|--------|
| Timer | Timer0 |
| Mode | Mode 1 (16-bit) |
| Interrupt Source | Overflow Interrupt |

The timer generates periodic interrupts that define the frequency measurement window.

## External Interrupt Configuration

INT0 is configured as:

| Parameter | Value |
|------------|--------|
| Interrupt | INT0 |
| Pin | P3.2 |
| Trigger Mode | Falling Edge |

Each falling edge increments the pulse counter.

## UART Configuration

| Parameter | Value |
|------------|--------|
| Baud Rate | 9600 |
| Data Bits | 8 |
| Parity | None |
| Stop Bits | 1 |
| Crystal Frequency | 11.0592 MHz |

## Expected Output

After reset:

```text
Frequency Counter Started
```

The measured frequency is then periodically reported:

```text
Frequency: 1000 Hz
Frequency: 1002 Hz
Frequency: 999 Hz
Frequency: 1001 Hz
```

## How It Works

### Pulse Counting

Every falling edge on INT0 triggers:

```c
void ext0_isr(void) __interrupt(0)
{
    pulse_count++;
}
```

### Measurement Window

Timer0 periodically generates interrupts:

```c
void timer0_isr(void) __interrupt(1)
{
    ...
}
```

When the configured interval expires:

- `pulse_count` is copied to `frequency`
- `pulse_count` is reset
- A flag is set for the main application

### UART Reporting

The main loop waits for a completed measurement and prints the result:

```c
sprintf(buffer,
        "Frequency: %d Hz\r\n",
        frequency);

uart_transmit_string(buffer);
```

## Learning Objectives

This example demonstrates:

- External Interrupts (INT0)
- Timer Interrupts
- Event Counting
- Frequency Measurement
- UART Communication
- Interrupt Service Routines (ISR)
- Shared Data Between ISR and Main Loop
- Embedded Event Processing

## Notes

- INT0 is edge-triggered using the falling edge.
- The pulse counter is updated entirely inside the interrupt handler.
- UART transmission is performed in the main loop rather than inside an ISR.
- `volatile` variables are used because they are accessed by both interrupt and application code.
- This example provides the foundation for:
  - RPM Meters
  - Tachometers
  - Flow Sensors
  - Pulse Counters
  - Digital Frequency Meters

## Limitations

- Maximum measurable frequency depends on:
  - CPU clock frequency
  - Interrupt latency
  - ISR execution time

- Very high input frequencies may exceed the capability of interrupt-based counting.

- For higher-frequency signals, hardware counters or Timer Counter mode should be used instead of interrupt counting.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-frequency-counter
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-frequency-counter
   ```