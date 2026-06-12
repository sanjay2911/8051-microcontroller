# Example: PWM LED Fade

This example demonstrates how to generate a software PWM signal using Timer0 interrupts and use it to create a smooth LED fading (breathing) effect.

## Functionality

The application uses Timer0 to generate a PWM waveform on a GPIO pin.

The PWM duty cycle is gradually increased and decreased, causing the LED brightness to smoothly transition between OFF and ON states.

This creates a breathing effect commonly used in embedded systems to indicate system activity, standby mode, or status.

## Hardware

### LED Connection

| Pin | Function |
|------|----------|
| P1.0 | PWM Output |

### Example Circuit

```text
P1.0 ---- 330Ω ---- LED ---- GND
```

### LED Logic

- Active-high configuration
  - `1` → LED ON
  - `0` → LED OFF

## PWM Configuration

| Parameter | Value |
|------------|--------|
| Timer | Timer0 |
| Mode | Mode 1 (16-bit) |
| PWM Resolution | 100 Steps |
| Duty Cycle Range | 0% - 100% |
| PWM Generation | Software PWM |

The PWM signal is generated entirely in software using a periodic Timer0 interrupt.

## Expected Behavior

After reset:

1. LED brightness gradually increases.
2. LED reaches full brightness.
3. LED brightness gradually decreases.
4. The sequence repeats continuously.

Visual effect:

```text
OFF → Dim → Medium → Bright → Medium → Dim → OFF
```

## Project Structure

```text
.
├── inc
│   └── pwm.h
├── src
│   ├── pwm.c
│   └── main.c
└── README.md
```

### PWM Driver

The PWM driver provides:

```c
void pwm_init(void);
void pwm_set_duty(unsigned char duty);
```

### Application

The application periodically updates the PWM duty cycle to generate the breathing effect.

## Learning Objectives

This example demonstrates:

- Timer0 interrupt configuration
- Interrupt Service Routines (ISR)
- Software PWM generation
- Duty cycle control
- LED brightness control
- Driver and application separation

## Notes

- PWM is generated in software using Timer0 interrupts.
- The PWM duty cycle is updated from the main application loop.
- The interrupt handler is responsible only for generating the PWM waveform.
- This design allows the same PWM driver to be reused for:
  - RGB LEDs
  - Servo motors
  - DC motor speed control
  - Buzzer tone generation

## Limitations

- Software PWM consumes CPU time.
- PWM frequency depends on Timer0 configuration and system clock.
- Higher PWM resolutions require more interrupt processing.

## How to Build and Flash

You can build and flash this example in two ways:

1. **From the example directory:**
   ```sh
   cmake --build build --target flash-pwm-fade
   ```

2. **From the project root directory:**
   ```sh
   cmake --build build --target flash-pwm-fade
   ```