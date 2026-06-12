#include <8052.h>
#include "irq.h"

#define LED0_MASK   0x01U
#define LED1_MASK   0x02U
#define LED3_MASK   0x04U

void delay_ms(unsigned int ms);
void ext0_handler(void);
void ext1_handler(void);

void main(void)
{
    irq_init();
    irq_enable(IRQ_EXT0);
    irq_enable(IRQ_EXT1);

    irq_register_callback(
        IRQ_EXT0,
        ext0_handler);

    irq_register_callback(
        IRQ_EXT1,
        ext1_handler);


    while (1)
    {
        P0 ^= LED3_MASK;
        delay_ms(500);
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++);
    }
}

void ext0_handler(void)
{
    P0 ^= LED0_MASK;
}

void ext1_handler(void)
{
    P0 ^= LED1_MASK;
}