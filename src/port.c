#include <stdlib.h>
#include <msp430.h>
#include "port.h"

port_t *port_init(unsigned char port){

    port_t *p = malloc(sizeof(port_t));

    switch(port){

        case 1:
            p->port = &P1OUT;
            p->in = &P1IN;
            p->out = &P1OUT;
            p->dir = &P1DIR;
            p->ren = &P1REN;
            p->sel = &P1SEL;
            p->sel2 = &P1SEL2;
            p->ies = &P1IES;
            p->ie = &P1IE;
            p->ifg = &P1IFG;
            break;

        case 2:
            p->port = &P2OUT;
            p->in = &P2IN;
            p->out = &P2OUT;
            p->dir = &P2DIR;
            p->ren = &P2REN;
            p->sel = &P2SEL;
            p->sel2 = &P2SEL2;
            p->ies = &P2IES;
            p->ie = &P2IE;
            p->ifg = &P2IFG;
            break;

        default:
            free(p);
            return NULL;
            break;

    }

    return p;

}

void port_close(port_t *p){

    free(p);

}