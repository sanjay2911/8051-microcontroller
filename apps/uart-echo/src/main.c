#include "uart.h"

/*----------------------------------------------------------
 * Main Application
 *---------------------------------------------------------*/

void main(void)
{
    char received_char;

    uart_init();

    uart_transmit_string("\r\nUART Echo Example\r\n");
    uart_transmit_string("Type a character and it will be echoed back.\r\n");

    while (1)
    {
        received_char = uart_receive_char();
        uart_transmit_char(received_char);
    }
}