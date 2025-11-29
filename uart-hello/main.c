#include <8051.h>

void uart_init(void);
void uart_transmit_char(char c);
void uart_transmit_string(const char* str);

void main(void) {
    uart_init(); // Initialize the UART

    while(1) {
        uart_transmit_string("Hello World!\r\n");
        
        // Simple delay loop
        for(long i = 0; i < 50000; i++);
    }
}

// Initialize UART for 9600 baud rate at 11.0592MHz crystal
void uart_init(void) {
    TMOD = 0x20; // Timer 1, Mode 2 (8-bit auto-reload)
    SCON = 0x50; // UART Mode 1 (8-bit UART), enable receiver
    TH1 = 0xFD;  // Reload value for 9600 baud rate
    TR1 = 1;     // Start Timer 1
}

// Function to transmit a single character
void uart_transmit_char(char c) {
    SBUF = c;    // Load character into the buffer
    while(TI == 0); // Wait until transmission is complete
    TI = 0;      // Clear transmission flag
}

// Function to transmit a string
void uart_transmit_string(const char* str) {
    while(*str) {
        uart_transmit_char(*str++);
    }
}
