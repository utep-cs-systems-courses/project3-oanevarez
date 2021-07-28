# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: blink.elf  

#additional rules for files
blink.elf: ${COMMON_OBJECTS} main.o buzzer.o switches.o p1_interrupt_handler.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a #wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: blink.elf
	msp430loader.sh blink.elf $^

clean:
	rm -f *.o *.elf *~ *# 

led.o: ledC_s.s led.h #led.c

wdInterruptHandler.o: stateMachines.h
switches.o: switches.h
buzzer.o: buzzer.h
stateMachines.o: led.h stateMachines.h
