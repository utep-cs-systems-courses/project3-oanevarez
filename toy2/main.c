//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "../timerLib/libTimer.h"
//#include "led.h"  
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

#define LED BIT6    

short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short redrawScreen =1;
//u_int fontFgColor = COLOR_WHITE;
//short velocity[2]={3,8}, limits[2] = {screenWidth-35, screenHeight-8};


char state=1;
void wdt_c_handler()
{
  static int secCount = 0;
  secCount ++;
  if (secCount == 76) {
    secCount = 0;
    switch(state){
    case 1: move_up(3); state++; break;
    case 2: move_down(3); state++; break;
    case 3: move_left(3); state++; break;
    case 4: move_right(3); state++; break;
    default: state =1; break;
    }
  }
}

int main(void) {

 

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  //led_init(); 
  switch_init();
  buzzer_init();
  buzzer_set_period(0);
  lcd_init();
  
  enableWDTInterrupts();
  or_sr(0x8);

  P1DIR |= LED;
  P1OUT |= LED;
  
  //drawing 
  clearScreen(COLOR_GREEN);
  while(1){
    if(redrawScreen){
      redrawScreen=0;
      and_sr(~8);//disable interrupt
      clearScreen(COLOR_GREEN);
      drawString5x7(drawPos[0], drawPos[1], "TOY2", COLOR_BLUE, COLOR_GREEN);
      a_shape(COLOR_WHITE);
      or_sr(8);
    }
    //and_sr(~8); //disable interupt GIE off
    
    P1OUT &= ~LED;//tur led off
    or_sr(0x10);//cpu off
    P1OUT |= LED;
  }
}
