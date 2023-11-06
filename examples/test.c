#include <msp430.h>
static char play = 0;
static short freq = 0x1000;
static short rate = 0x100;
static char led = BIT0;
/**
 * The main function sets up various configurations for the MSP430 microcontroller and enters low power
 * mode 4.
 * 
 * @return The main function is returning 0.
 */
int main(void) {
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | 1;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    BCSCTL2 &= ~(SELS);
    BCSCTL2 |= DIVS_3;
    TA0CCR0 = 0;
    TA0CCR1 = 0; 
    TA0CCTL1 = OUTMOD_3;
    TACTL = TASSEL_2 + MC_1;   
    P1DIR |= (BIT0 | BIT6);
    P1DIR &= ~BIT3;
    P1OUT |= (BIT0 | BIT3 | BIT6);
    P1SEL &= BIT3;
    P1SEL2 &= ~BIT3;
    P1REN |= BIT3;
    P1IE |= BIT3;
    P1IES |= BIT3;
    P1IFG &= ~BIT3;
    IE1 |= WDTIE;
    P2DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    P2DIR |= BIT6;
    P2OUT |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2REN |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IE |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IES |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IFG &= (~BIT0 | ~BIT1 | ~BIT2 | ~BIT3);
    P2SEL &= (BIT6 | ~BIT7);
    P2SEL2 &= ~(BIT6 | BIT7);
    __bis_SR_register(LPM4 | GIE);
    return 0;
}
/**
 * The function toggles the state of an LED connected to pin P1.0 and P1.6 when an interrupt is
 * triggered by pin P1.3.
 */
void __interrupt_vec(PORT1_VECTOR) Port_1(){
    if (P1IFG & BIT3) {
        P1IFG &= ~BIT3;
        if(led == BIT0) {
            led = BIT6;
            P1OUT |= BIT0;
        } else {
            led = BIT0;
            P1OUT |= BIT6;
        }
        __delay_cycles(20000);
    }
}
/**
 * The above function is an interrupt service routine that handles interrupts from Port 2 and performs
 * certain actions based on the interrupt source.
 */
void __interrupt_vec(PORT2_VECTOR) Port_2(){
    if (P2IFG & BIT0) {
        P2IFG &= ~BIT0;
        play = !play;
    }
    if(P2IFG & BIT1) {
        P2IFG &= ~BIT1;
        if(freq > 0x100)
        freq = freq >> 1;
        if(rate > 0x10)
        rate = rate >> 1;
    }
    if(P2IFG & BIT2) {
        P2IFG &= ~BIT2;
        if(freq < 0x4000)
        freq = freq << 1;
        if(rate < 0x400)
        rate = rate << 1;
    }
    if(P2IFG & BIT3) {
        P2IFG &= ~BIT3;
        freq = 0x1000;
        rate = 0x100;
    }
    __delay_cycles(20000);
}
/**
 * The function is an interrupt service routine that toggles an LED and sets the frequency of a timer
 * based on certain conditions.
 */
void __interrupt_vec(WDT_VECTOR) WDT(){
    static char blink_count = 0;
    if (++blink_count == (rate/2)) {
        P1OUT ^= led;
        blink_count = 0;
    }
    if (play) {
        CCR0 = freq; 
        CCR1 = freq >> 1;
    } else {
        CCR0 = 0; 
        CCR1 = 0 >> 1;
    }
}