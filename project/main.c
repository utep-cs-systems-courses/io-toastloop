#include <msp430.h>
#include "led.h"
#include "switch.h"
#include "buzzer.h"
#include "interrupt.h"

int main(void) {
    configureClocks();
    enableWDTInterrupts();
    or_sr(0x18);
}
