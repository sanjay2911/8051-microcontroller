#include <8051.h>

#define PWM_PIN P2_0

// Global variables for PWM
unsigned char pwm_width = 100; // Total width of the PWM period (0-255)
volatile unsigned char duty_cycle = 0; // Current duty cycle (0 to pwm_width)

void timer0_init(void);
void delay_ms(unsigned int ms);

void main(void) {
    unsigned char fade_direction = 1; // 1 for increasing, 0 for decreasing

    timer0_init(); // Initialize Timer 0 and its interrupt

    EA = 1; // Enable global interrupts

    while(1) {
        // --- Breathing Effect Logic ---
        if (fade_direction) {
            duty_cycle++;
            if (duty_cycle >= pwm_width) {
                fade_direction = 0; // Change direction to fade out
            }
        } else {
            duty_cycle--;
            if (duty_cycle == 0) {
                fade_direction = 1; // Change direction to fade in
            }
        }
        delay_ms(10); // Slow down the fading effect
    }
}

// Initialize Timer 0 for PWM generation
void timer0_init(void) {
    TMOD = (TMOD & 0xF0) | 0x01; // Timer 0, Mode 1 (16-bit timer)
    TH0 = 0xFF; // Load a high value for a short overflow period
    TL0 = 0x9C; 
    ET0 = 1;    // Enable Timer 0 interrupt
    TR0 = 1;    // Start Timer 0
}

// Timer 0 Interrupt Service Routine (ISR)
void timer0_isr(void) __interrupt(1) {
    static unsigned char pwm_counter = 0;
    
    // Reload timer for the next cycle
    TH0 = 0xFF;
    TL0 = 0x9C;

    if(pwm_counter < duty_cycle) {
        PWM_PIN = 1; // Set pin HIGH
    } else {
        PWM_PIN = 0; // Set pin LOW
    }

    pwm_counter++;
    if(pwm_counter >= pwm_width) {
        pwm_counter = 0; // Reset counter for the next PWM period
    }
}

// Basic delay function
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++);
    }
}
