#include <msp430.h>
#include "switch.h"

char sw_one = 0x04;
char switches = (sw_one);

void switch_init(char sw_in){
    P1REN |= sw_in;
    P1OUT |= sw_in;
    P1DIR &= ~sw_in;
}
void switch_close(char sw_in){
    P1REN &= ~sw_in;
    P1OUT &= ~sw_in;
    P1DIR |= sw_in;
}
void switch_enable_ie(char sw_in){
    P1IE |= sw_in;
}
void switch_disable_ie(char sw_in){
    P1IE &= ~sw_in;
}
char switch_status(char sw_in){
    return (P1IN & sw_in) | (p1val | ~sw_in);
}
