COMMON_OBJECTS  = test.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include 
CC              = msp430-elf-gcc
AS              = msp430-elf-as
all: test.elf
test.elf: ${COMMON_OBJECTS}
    ${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
load: test.elf
    msp430loader.sh  $^
clean: $^
    rm -f .o.elf