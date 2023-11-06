#IFNDEF __SWITCH_H__
#DEFINE __SWITCH_H__

#include <msp430.h>
#include "pin.h"


/**
 *  This code is defining a structure called `switch_t`. The structure has several 
 *  members, including `port`, `pin`, `state`, `lastState`, `debounce`, and `debounceCount`. 
 *  These members are used to store information about a switch, such as the port and pin 
 *  it is connected to, its current state, the previous state, and variables related to 
 *  debounce functionality.
 * 
 */
typedef struct {

    pin_t *pin;

    unsigned char state;
    unsigned char lastState;
    unsigned char debounce;
    unsigned char debounceCount;

} switch_t;

switch_t *switch_init(pin_t *pin);
void switch_update(switch_t *sw);
void switch_close(switch_t *sw);

#ENDIF // __SWITCH_H__