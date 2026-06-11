#include <led-pattern.h>

// --- Function Prototypes ---
void delay_ms(unsigned int ms);

// --- Main Function ---
void main(void) {
    int i; // Loop variable for patterns

    // Set Port 0 to be an output port.
    // With inverted logic, 0xFF means all LEDs are OFF.
    LED_PORT = 0xFF;

    while(1) {
        // --- Pattern 1: Knight Rider Scanner (Inverted Logic) ---
        // NOTE: Port 0 on the 8051 needs external pull-up resistors.
        // A '0' turns the LED ON.
        
        // Move light from left to right (P2.0 to P2.7)
        for (i = 0; i < 8; i++) {
            LED_PORT = ~(1 << i); // Invert the bit, sending a '0' to one pin
            delay_ms(120);
        }
        // Move light from right to left (P2.6 to P2.1)
        for (i = 7; i >= 0; i--) {
            LED_PORT = ~(1 << i);
            delay_ms(120);
        }

        LED_PORT = 0xFF; // Turn all LEDs off
        delay_ms(200); // Pause between patterns

        // --- Pattern 2: Converge & Diverge (Inverted Logic) ---
        // Lights move from the outside ends to the center
        for (i = 0; i < 4; i++) {
            // Invert the bits to turn on two LEDs with a '0'
            LED_PORT = ~((0x80 >> i) | (0x01 << i));
            delay_ms(160);
        }
        // Lights move from the center to the outside ends
        for (i = 3; i >= 0; i--) {
            LED_PORT = ~((0x80 >> i) | (0x01 << i));
            delay_ms(160);
        }

        LED_PORT = 0xFF; // Turn all LEDs off
        delay_ms(200); // Pause between patterns
    }
}

// --- Basic Delay Function ---
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++); // Approximate delay for 11.0592 MHz crystal
    }
}