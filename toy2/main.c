//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "led.h"  
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

int main(void) {

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init(); 
  switch_init();
  buzzer_init();
  buzzer_set_period(0);

  lcd_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}
