#IFNDEF __PORT_H__
#DEFINE __PORT_H__

#include <msp430.h>

typedef struct {

    unsigned char *port;
    unsigned short *in;
    unsigned short *out;
    unsigned short *dir;
    unsigned short *ren;
    unsigned short *sel;
    unsigned short *sel2;
    unsigned short *ies;
    unsigned short *ie;
    unsigned short *ifg;

} port_t;

#ENDIF // __PORT_H__