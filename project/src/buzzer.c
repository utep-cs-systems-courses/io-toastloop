#include <msp430.h>
#include "buzzer.h"

char buzzer_in = BIT1;
char buzzer_out = BIT6;
char buzzer = (buzzer_in | buzzer_out);

void buzzer_init(){
    P2SEL2 &= ~buzzer;
    P2SEL &= ~buzzer_out;
    P2SEL |= buzzer_in;
    P2DIR |= buzzer_in;
    timerAUpmode();
}
void buzzer_period(short cycles){
    CCR0 = cycles;
    CCR1 = cycles >> 1;
}
