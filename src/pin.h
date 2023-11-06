#IFNDEF __PIN_H__
#DEFINE __PIN_H__

#include <msp430.h>
#include "port.h"

typedef struct {

    port_t *port;
    unsigned char pin;

} pin_t;

#ENDIF // __PIN_H__