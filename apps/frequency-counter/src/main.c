#include <stdio.h>
#include "frequency_counter.h"
#include "uart.h"

/*----------------------------------------------------------
 * Global Variables
 *---------------------------------------------------------*/

volatile unsigned int pulse_count = 0U;
volatile unsigned int frequency = 0U;

volatile unsigned int tick_ms = 0U;
volatile __bit frequency_ready = 0;
char buffer[32] = {0};

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

static void timer0_init(void);
static void ext0_init(void);

/*----------------------------------------------------------
 * Timer0 ISR
 * 1 ms System Tick
 *---------------------------------------------------------*/

void timer0_isr(void) __interrupt(1)
{
    TH0 = TIMER0_RELOAD_H;
    TL0 = TIMER0_RELOAD_L;

    tick_ms++;

    if (tick_ms >= 20U)
    {
        tick_ms = 0U;

        frequency = pulse_count;
        pulse_count = 0U;

        frequency_ready = 1;
    }
}

/*----------------------------------------------------------
 * INT0 ISR
 * Pulse Counter
 *---------------------------------------------------------*/

void ext0_isr(void) __interrupt(0)
{
    pulse_count++;
}

/*----------------------------------------------------------
 * Main
 *---------------------------------------------------------*/

void main(void)
{
    uart_init();

    timer0_init();
    ext0_init();

    EA = 1U;

    uart_transmit_string(
        "\r\nFrequency Counter Started\r\n");

    while (1)
    {
        if (frequency_ready)
        {
            frequency_ready = 0;
            
            sprintf(buffer,"Frequency: %d Hz\r\n",frequency);
            uart_transmit_string(buffer);
        }
    }
}

/*----------------------------------------------------------
 * Timer0 Init
 *---------------------------------------------------------*/

static void timer0_init(void)
{
    TMOD &= 0xF0U;
    TMOD |= 0x01U;

    TH0 = TIMER0_RELOAD_H;
    TL0 = TIMER0_RELOAD_L;

    ET0 = 1U;
    TR0 = 1U;
}

/*----------------------------------------------------------
 * INT0 Init
 *---------------------------------------------------------*/

static void ext0_init(void)
{
    IT0 = 1U;
    EX0 = 1U;
}