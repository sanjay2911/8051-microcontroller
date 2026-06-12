#include "blink.h"
#include "timer.h"

static void led_on(void);
static void led_off(void);

void main(void)
{
    timer_init();

    while (1)
    {
        led_on();
        timer_delay_ms(500U);

        led_off();
        timer_delay_ms(500U);
    }
}

static void led_on(void)
{
    P0 |= LED_PIN_MASK;
}

static void led_off(void)
{
    P0 &= (unsigned char)(~LED_PIN_MASK);
}