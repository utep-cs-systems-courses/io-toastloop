#IFNDEF __SWITCH_H__
#DEFINE __SWITCH_H__

#include <msp430.h>
#include "port.h"
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
    port_t port;
    pin_t pin;
    unsigned char state;
    unsigned char lastState;
    unsigned char debounce;
    unsigned char debounceCount;
} switch_t;

switch_t *switchInit(unsigned char port, unsigned char pin);
void switchUpdate(switch_t *sw);

#ENDIF // __SWITCH_H__