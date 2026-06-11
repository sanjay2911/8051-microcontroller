#include <uart.h>

void main(void) {
    uart_init(); // Initialize the UART

    while(1) {
        uart_transmit_string("Hello World!\r\n");
        
        // Simple delay loop
        for(long i = 0; i < 50000; i++);
    }
}
