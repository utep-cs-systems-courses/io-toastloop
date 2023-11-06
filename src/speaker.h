#IFNDEF __SPEAKER_H__
#DEFINE __SPEAKER_H__

#include <msp430.h>
#include "port.h"
#include "pin.h"

typedef struct {
    pin_t pin_in;
    pin_t pin_out;
    unsigned char state;
    unsigned char lastState;
} speaker_t;

typedef struct {
    unsigned int frequency;
    unsigned int duration;
} note_t;

speaker_t speaker_init(pin_t pin_in, pin_t pin_out);

#ENDIF // __SPEAKER_H__