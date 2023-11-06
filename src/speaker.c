#include <msp430.h>
#include "speaker.h"

/**
 * The function initializes a speaker structure with the specified port and pin values.
 * 
 * @param port The "port" parameter is an unsigned char that represents the port number of the
 * microcontroller. It can be either 1 or 2, where 1 corresponds to port P1 and 2 corresponds to port
 * P2.
 * @param pin The "pin" parameter is an unsigned char that represents the pin number of the speaker. It
 * is used to determine which specific pin of the specified port to initialize the speaker on.
 * 
 * @return a pointer to a speaker_t structure.
 */
speaker_t *speaker_init(pin_t pin_in, pin_t pin_out){

    speaker_t *sp = malloc(sizeof(speaker_t));

    sp->pin_in = pin_in;
    sp->pin_out = pin_out;

    sp->state = 0;
    sp->lastState = 0;

    return sp;

}

/**
 * The function "speaker_close" frees the memory allocated for a speaker object.
 * 
 * @param sp The parameter "sp" is a pointer to a structure of type "speaker_t".
 */
void speaker_close(speaker_t *sp){
    free(sp);
}