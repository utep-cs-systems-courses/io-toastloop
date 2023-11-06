#include <msp430.h>
#include "switch.h"

/**
 * The function initializes a switch structure with the specified port and pin values.
 * 
 * @param port The "port" parameter is an unsigned char that represents the port number of the
 * microcontroller. It can be either 1 or 2, where 1 corresponds to port P1 and 2 corresponds to port
 * P2.
 * @param pin The "pin" parameter is an unsigned char that represents the pin number of the switch. It
 * is used to determine which specific pin of the specified port to initialize the switch on.
 * 
 * @return a pointer to a switch_t structure.
 */
switch_t *switch_init(pin_t *pin) {

    /* This code is allocating memory for a switch object and initializing its members. */
    switch_t *sw = malloc(sizeof(switch_t));

    sw->pin = &pin;
    sw->state = 0;
    sw->lastState = 0;
    sw->debounce = 0;
    sw->debounceCount = 0;

    return sw;

}

/**
 * The function updates the state of a switch and handles debounce logic.
 * 
 * @param sw The parameter "sw" is a pointer to a structure of type "switch_t".
 */
void switch_update(switch_t *sw) {

    *sw->pin->port->out |= *sw->pin->port->in;

    sw->lastState = sw->state;
    sw->state = *(sw->pin->port->in) & sw->pin->pin;

    if (sw->state != sw->lastState) {
        sw->debounceCount++;
        if (sw->debounceCount > 10) {
            sw->debounceCount = 0;
            sw->debounce = sw->state;
        }
    }

}

/**
 * The function "switch_close" frees the memory allocated for a switch object.
 * 
 * @param sw The parameter "sw" is a pointer to a switch_t structure.
 */
void switch_close(switch_t *sw) {

    free(sw);

}