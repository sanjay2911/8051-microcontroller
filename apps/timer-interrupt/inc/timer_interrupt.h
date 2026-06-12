#ifndef TIMER_INTERRUPT_H
#define TIMER_INTERRUPT_H

#include <8052.h>

/*----------------------------------------------------------
 * Hardware Mapping
 *---------------------------------------------------------*/

#define LED_PIN_MASK   0x01U

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

void timer0_init(void);

#endif /* TIMER_INTERRUPT_H */