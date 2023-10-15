#include <msp430.h>
#include "led.h"

char green  =   BIT0;
char red    =   BIT5;
char leds   =   (red | green);

void led_init(char LED){
    P1DIR |= LED;
}

void led_close(char LED){
    P1DIR &= ~LED;
}

void led_on(char LED){
    P1OUT |= LED;
}

void led_off(char LED){
    P1OUT &= ~LED;
}

void led_toggle(char LED){
    P1OUT ^= LED;
}

char led_status(char LED){
    return P1VAL & (P1OUT & LED);
}
