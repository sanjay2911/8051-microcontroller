#ifndef UART_H
#define UART_H

#include <8052.h>

/*----------------------------------------------------------
 * UART Configuration
 *---------------------------------------------------------*/

#define UART_BAUD_9600_RELOAD    0xFDU

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

void uart_init(void);
void uart_transmit_char(char c);
void uart_transmit_string(const char *str);

#endif /* UART_H */