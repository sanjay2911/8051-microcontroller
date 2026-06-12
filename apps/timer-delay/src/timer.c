#include "timer.h"

/*----------------------------------------------------------
 * Timer Configuration
 *---------------------------------------------------------*/

#define TIMER0_RELOAD_HIGH    0xFCU
#define TIMER0_RELOAD_LOW     0x66U

/*----------------------------------------------------------
 * Timer Initialization
 *---------------------------------------------------------*/

void timer_init(void)
{
    /* Timer0 Mode 1 (16-bit timer) */
    TMOD &= 0xF0U;
    TMOD |= 0x01U;
}

/*----------------------------------------------------------
 * 1 ms Delay
 *---------------------------------------------------------*/

static void timer_delay_1ms(void)
{
    TH0 = TIMER0_RELOAD_HIGH;
    TL0 = TIMER0_RELOAD_LOW;

    TF0 = 0U;
    TR0 = 1U;

    while (TF0 == 0U)
    {
        /* Wait for overflow */
    }

    TR0 = 0U;
    TF0 = 0U;
}

/*----------------------------------------------------------
 * Delay in Milliseconds
 *---------------------------------------------------------*/

void timer_delay_ms(unsigned int ms)
{
    while (ms > 0U)
    {
        timer_delay_1ms();
        ms--;
    }
}