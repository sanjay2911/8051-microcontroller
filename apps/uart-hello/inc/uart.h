#ifndef __UART_H
#define __UART_H

void uart_init(void);
void uart_transmit_char(char c);
void uart_transmit_string(const char* str);

#endif //__UART_H