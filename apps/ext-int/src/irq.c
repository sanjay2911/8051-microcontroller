#include "irq.h"

/*----------------------------------------------------------
 * Private Data
 *---------------------------------------------------------*/

static irq_callback_t ext0_callback = 0;
static irq_callback_t ext1_callback = 0;

/*----------------------------------------------------------
 * Initialization
 *---------------------------------------------------------*/

void irq_init(void)
{
    EA = 1U;

    /*
     * Edge-triggered mode
     */
    IT0 = 1U;
    IT1 = 1U;
}

/*----------------------------------------------------------
 * Callback Registration
 *---------------------------------------------------------*/

void irq_register_callback(
    unsigned char irq_id,
    irq_callback_t callback)
{
    switch (irq_id)
    {
        case IRQ_EXT0:
            ext0_callback = callback;
            break;

        case IRQ_EXT1:
            ext1_callback = callback;
            break;

        default:
            break;
    }
}

/*----------------------------------------------------------
 * Interrupt Control
 *---------------------------------------------------------*/

void irq_enable(unsigned char irq_id)
{

    switch (irq_id)
    {
        case IRQ_EXT0:
            EX0 = 1U;
            break;

        case IRQ_EXT1:
            EX1 = 1U;
            break;

        default:
            break;
    }
}

void irq_disable(unsigned char irq_id)
{
    switch (irq_id)
    {
        case IRQ_EXT0:
            EX0 = 0U;
            break;

        case IRQ_EXT1:
            EX1 = 0U;
            break;

        default:
            break;
    }
}

/*----------------------------------------------------------
 * ISR - External Interrupt 0
 *---------------------------------------------------------*/

void ext0_isr(void) __interrupt(0)
{
    if (ext0_callback != 0)
    {
        ext0_callback();
    }
}

/*----------------------------------------------------------
 * ISR - External Interrupt 1
 *---------------------------------------------------------*/

void ext1_isr(void) __interrupt(2)
{
    if (ext1_callback != 0)
    {
        ext1_callback();
    }
}