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
speaker_t speaker_init(unsigned char port, unsigned char pin){
    speaker_t *sp = malloc(sizeof(speaker_t));
    sp->pin = pin;
    sp->state = 0;
    sp->lastState = 0;
    return sp;
}

/**
 * The function `speaker_play` plays a sound on a speaker using the specified frequency and rate.
 * 
 * @param sp A pointer to a structure representing the speaker. The structure contains the following
 * members:
 * @param freq The "freq" parameter represents the frequency of the sound that will be played by the
 * speaker.
 * @param rate The "rate" parameter in the "speaker_play" function represents the rate at which the
 * sound is played. It determines the duration of each sound wave or frequency. The value of "rate" is
 * used to calculate the delay between each sound wave using the "__delay_cycles" function.
 */
void speaker_play(speaker_t *sp, short freq, short rate){
    short OUT = (sp->port == 1) ? P1OUT : P2OUT;
    short DIR = (sp->port == 1) ? P1DIR : P2DIR;
    short SEL = (sp->port == 1) ? P1SEL : P2SEL;
    short SEL2 = (sp->port == 1) ? P1SEL2 : P2SEL2;
    short BIT = (sp->pin == 0) ? BIT0 : 
                (sp->pin == 1) ? BIT1 : 
                (sp->pin == 2) ? BIT2 : 
                (sp->pin == 3) ? BIT3 : 
                (sp->pin == 4) ? BIT4 : 
                (sp->pin == 5) ? BIT5 : 
                (sp->pin == 6) ? BIT6 : 
                BIT7;
    OUT |= BIT;
    DIR |= BIT;
    SEL |= BIT;
    SEL2 &= ~BIT;
    TA0CCR0 = freq;
    TA0CCR1 = freq >> 1;
    TA0CTL = TASSEL_2 + MC_1;
    TA0CCTL1 = OUTMOD_3;
    __delay_cycles(1000000 / rate);
    TA0CTL = MC_0;
    OUT &= ~BIT;
    DIR &= ~BIT;
    SEL &= ~BIT;
    SEL2 &= ~BIT;
}

/**
 * The function `speaker_stop` stops the speaker by clearing the corresponding pin's output, direction,
 * and select registers.
 * 
 * @param sp The parameter `sp` is a pointer to a structure of type `speaker_t`.
 */
void speaker_stop(speaker_t *sp){
    short OUT = (sp->port == 1) ? P1OUT : P2OUT;
    short DIR = (sp->port == 1) ? P1DIR : P2DIR;
    short SEL = (sp->port == 1) ? P1SEL : P2SEL;
    short SEL2 = (sp->port == 1) ? P1SEL2 : P2SEL2;
    short BIT = (sp->pin == 0) ? BIT0 : 
                (sp->pin == 1) ? BIT1 : 
                (sp->pin == 2) ? BIT2 : 
                (sp->pin == 3) ? BIT3 : 
                (sp->pin == 4) ? BIT4 : 
                (sp->pin == 5) ? BIT5 : 
                (sp->pin == 6) ? BIT6 : 
                BIT7;
    OUT &= ~BIT;
    DIR &= ~BIT;
    SEL &= ~BIT;
    SEL2 &= ~BIT;
}

/**
 * The function "speaker_close" frees the memory allocated for a speaker object.
 * 
 * @param sp The parameter "sp" is a pointer to a structure of type "speaker_t".
 */
void speaker_close(speaker_t *sp){
    free(sp);
}