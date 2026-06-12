#include "button.h"

/*----------------------------------------------------------
 * Local Function Prototypes
 *---------------------------------------------------------*/

static void led_on(void);
static void led_off(void);

/*----------------------------------------------------------
 * Main Application
 *---------------------------------------------------------*/

void main(void)
{
    led_off();

    while (1)
    {
        if (button_is_pressed())
        {
            led_on();
        }
        else
        {
            led_off();
        }
    }
}

/*----------------------------------------------------------
 * Button Functions
 *---------------------------------------------------------*/

unsigned char button_is_pressed(void)
{
    return ((IO_PORT & BUTTON_PIN_MASK) == 0U);
}

/*----------------------------------------------------------
 * LED Functions
 *---------------------------------------------------------*/

static void led_on(void)
{
    IO_PORT |= LED_PIN_MASK;
}

static void led_off(void)
{
    IO_PORT &= (unsigned char)(~LED_PIN_MASK);
}