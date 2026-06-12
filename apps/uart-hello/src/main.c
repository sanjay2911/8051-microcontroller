#include "uart.h"

/*----------------------------------------------------------
 * Local Function Prototypes
 *---------------------------------------------------------*/

static void delay_ms(unsigned int ms);

/*----------------------------------------------------------
 * Main Application
 *---------------------------------------------------------*/

void main(void)
{
    uart_init();

    while (1)
    {
        uart_transmit_string("Hello World!\r\n");

        delay_ms(1000U);
    }
}

/*----------------------------------------------------------
 * Delay Function
 *---------------------------------------------------------*/

static void delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;

    for (i = 0U; i < ms; i++)
    {
        for (j = 0U; j < 120U; j++)
        {
            /* Intentional empty loop */
        }
    }
}