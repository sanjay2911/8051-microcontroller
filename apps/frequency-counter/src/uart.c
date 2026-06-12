#include "uart.h"

/*----------------------------------------------------------
 * UART Initialization
 *---------------------------------------------------------*/

void uart_init(void)
{
    /* Timer1 Mode2: 8-bit auto reload */
    TMOD &= 0x0FU;
    TMOD |= 0x20U;

    /* UART Mode1, Receiver Enabled */
    SCON = 0x50U;

    /* 9600 baud @ 11.0592 MHz */
    TH1 = UART_BAUD_9600_RELOAD;
    TL1 = UART_BAUD_9600_RELOAD;

    TR1 = 1U;
    TI  = 1U;
}

/*----------------------------------------------------------
 * UART Transmit Character
 *---------------------------------------------------------*/

void uart_transmit_char(char c)
{
    SBUF = c;

    while (TI == 0U)
    {
        /* Wait for transmission complete */
    }

    TI = 0U;
}

/*----------------------------------------------------------
 * UART Transmit String
 *---------------------------------------------------------*/

void uart_transmit_string(const char *str)
{
    while (*str != '\0')
    {
        uart_transmit_char(*str++);
    }
}