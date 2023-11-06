#include <msp430.h>
#include "port.h"
#include "pin.h"

pin_t *pin_init(port_t port, unsigned char pin){
    pin_t *p = malloc(sizeof(pin_t));
    p->port = port;
    p->pin = pin;
    return p;
}

void pin_close(pin_t *p){
    free(p);
}