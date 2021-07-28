//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "led.h"  
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"




void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 75) {        /* 4/sec */
    secCount = 0;
    for (char axis = 0; axis < 2; axis++) {
      short newVal = controlPos[axis] + velocity[axis];
      if (newVal < 10 || newVal > limits[axis])
    velocity[axis] = -velocity[axis];
      else
    controlPos[axis] = newVal;
    }
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    redrawScreen = 1;
  }
}

int main(void) {

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init(); 
  switch_init();
  buzzer_init();
  buzzer_set_period(0);

  lcd_init();
  
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);/* CPU off, GIE on */
  
  //test draw

}
