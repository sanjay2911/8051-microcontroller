#include "pwm.h"

#define PWM_WIDTH  100U

volatile unsigned char pwm_duty = 0;

void pwm_init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;

    TH0 = 0xFF;
    TL0 = 0x9C;

    ET0 = 1;
    TR0 = 1;
}

void pwm_set_duty(unsigned char duty)
{
    if (duty > PWM_WIDTH)
    {
        duty = PWM_WIDTH;
    }

    pwm_duty = duty;
}

void timer0_isr(void) __interrupt(1)
{
    static unsigned char counter = 0;

    TH0 = 0xFF;
    TL0 = 0x9C;

    if (counter < pwm_duty)
    {
        PWM_PIN = 1;
    }
    else
    {
        PWM_PIN = 0;
    }

    counter++;

    if (counter >= PWM_WIDTH)
    {
        counter = 0;
    }
}