# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink.elf  

#additional rules for files
blink.elf: ${COMMON_OBJECTS} main.o buzzer.o switches.o p1_interrupt_handler.o stateMachines.o led.o wdInterruptHandler.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blink.elf
	msp430loader.sh blink.elf

clean:
	rm -f *.o *.elf *~

led.o: ledC_s.s led.h #led.c

wdInterruptHandler.o: stateMachines.h
switches.o: switches.h
buzzer.o: buzzer.h
stateMachines.o: led.h stateMachines.h
