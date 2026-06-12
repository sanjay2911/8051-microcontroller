#ifndef PWM_H
#define PWM_H

#include <8052.h>

#define PWM_PIN P0_0
void pwm_init(void);
void pwm_set_duty(unsigned char duty);
void timer0_isr(void) __interrupt(1);

#endif