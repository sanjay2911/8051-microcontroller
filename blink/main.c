#include <8051.h>

// --- Function Prototypes ---
void delay_ms(unsigned int ms);

// --- Main Function ---
void main(void) {
    // Set Port 2 to be an output port.
    // With inverted logic, 0xFF means all LEDs are OFF.
    P2 = 0xFF;

    while(1) {
        P2 = 0xFE; // Turn ON LED at P2.0 (~0x01)
        delay_ms(500);
        P2 = 0xFF; // Turn OFF LED at P2.0
        delay_ms(500);
    }
}

// --- Basic Delay Function ---
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++); // Approximate delay for 11.0592 MHz crystal
    }
}