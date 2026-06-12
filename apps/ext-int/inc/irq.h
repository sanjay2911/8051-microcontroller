#ifndef IRQ_H
#define IRQ_H

#include <8052.h>

/*----------------------------------------------------------
 * Types
 *---------------------------------------------------------*/

typedef void (*irq_callback_t)(void);

/*----------------------------------------------------------
 * External Interrupt IDs
 *---------------------------------------------------------*/

#define IRQ_EXT0    0U
#define IRQ_EXT1    1U

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

void irq_init(void);

void irq_register_callback(
    unsigned char irq_id,
    irq_callback_t callback);

void irq_enable(unsigned char irq_id);
void irq_disable(unsigned char irq_id);
void ext0_isr(void) __interrupt(0);
void ext1_isr(void) __interrupt(2);

#endif /* IRQ_H */