#include <msp430.h>
#include "stateMachines.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char buzz_count =0;
  if (blink_count == interrupt){
    sound_on();
    blink_count=0;
  }else if(blink_count <= interrupt){
    if(!ext_opt){
      turn_redOff();
    }
    blink_count++;
  }

  //sound_on();
  
}
