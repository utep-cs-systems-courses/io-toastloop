#include <msp430.h>
#include "led.h"
#include "switch.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

}
void __interrupt_vec(PORT1_VECTOR) Port_1(){
    switch(__even_in_range(P1IV,16))
    {
        case 0: break; // No Interrupt
        case 2: break; // P1.0
        case 4: break; // P1.1
        case 6: break; // P1.2
        case 8: break; // P1.3
        case 10: break; // P1.4
        case 12: break; // P1.5
        case 14: break; // P1.6
        case 16: break; // P1.7
    }
}
