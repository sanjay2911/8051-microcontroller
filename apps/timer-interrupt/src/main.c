#include "timer_interrupt.h"

/*----------------------------------------------------------
 * Timer Configuration
 *---------------------------------------------------------*/

/*
 * 1 ms timer period
 * Crystal: 11.0592 MHz
 *
 * 65536 - 922 = 64614 = 0xFC66
 */

#define TIMER0_RELOAD_HIGH   0xFCU
#define TIMER0_RELOAD_LOW    0x66U

/*----------------------------------------------------------
 * Global Variables
 *---------------------------------------------------------*/

volatile unsigned long system_ticks = 0UL;

/*----------------------------------------------------------
 * Local Function Prototypes
 *---------------------------------------------------------*/

static void led_toggle(void);

/*----------------------------------------------------------
 * Timer0 Interrupt Service Routine
 *---------------------------------------------------------*/

void timer0_isr(void) __interrupt(1)
{
    TH0 = TIMER0_RELOAD_HIGH;
    TL0 = TIMER0_RELOAD_LOW;

    system_ticks++;
}

/*----------------------------------------------------------
 * Timer Initialization
 *---------------------------------------------------------*/

void timer0_init(void)
{
    TMOD &= 0xF0U;
    TMOD |= 0x01U;

    TH0 = TIMER0_RELOAD_HIGH;
    TL0 = TIMER0_RELOAD_LOW;

    ET0 = 1U;    /* Enable Timer0 interrupt */
    EA  = 1U;    /* Global interrupt enable */

    TR0 = 1U;    /* Start timer */
}

/*----------------------------------------------------------
 * Main Application
 *---------------------------------------------------------*/

void main(void)
{
    unsigned long last_toggle = 0UL;

    timer0_init();

    while (1)
    {
        if ((system_ticks - last_toggle) >= 1000UL)
        {
            last_toggle = system_ticks;
            led_toggle();
        }
    }
}

/*----------------------------------------------------------
 * LED Functions
 *---------------------------------------------------------*/

static void led_toggle(void)
{
    P0 ^= LED_PIN_MASK;
}