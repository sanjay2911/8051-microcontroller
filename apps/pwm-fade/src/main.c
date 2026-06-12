#include "pwm.h"

void delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++);
    }
}

void main(void)
{
    unsigned char duty = 0;
    __bit increasing = 1;

    pwm_init();

    EA = 1;

    while (1)
    {
        pwm_set_duty(duty);

        if (increasing)
        {
            duty++;

            if (duty >= 100)
            {
                increasing = 0;
            }
        }
        else
        {
            duty--;

            if (duty == 0)
            {
                increasing = 1;
            }
        }

        delay_ms(10);
    }
}