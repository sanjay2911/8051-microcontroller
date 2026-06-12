#ifndef BUTTON_H
#define BUTTON_H

#include <8052.h>

/*----------------------------------------------------------
 * Hardware Mapping
 *---------------------------------------------------------*/
#define IO_PORT             P0
#define LED_PIN_MASK        0x01U
#define BUTTON_PIN_MASK     0x02U

/*----------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------*/

unsigned char button_is_pressed(void);

#endif /* BUTTON_H */