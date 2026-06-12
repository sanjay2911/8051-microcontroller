#ifndef TIMER_H
#define TIMER_H

#include <8052.h>

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

void timer_init(void);
void timer_delay_ms(unsigned int ms);

#endif /* TIMER_H */