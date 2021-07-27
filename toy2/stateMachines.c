#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void turn_red() //button s1 turns on red led, and makes buzz noise
{
    red_on=1;
    led_changed=1;
    led_update();
}

void turn_green() //button s2 turns on green led, and makes buzz noise
{
  green_on=1;
  led_changed=1;
  led_update();
}

void turn_greenOff(){
  green_on =0;
  led_changed =1;
  led_update();
}

void turn_redOff(){
  red_on =0;
  led_changed =1;
  led_update();
}


void sound_on(){
  if(switch_state_down_1){
    interrupt =0;
    buzzer_set_period(2109);
    turn_red();

  }else if(switch_state_down_2){
    interrupt =3; //dim
    buzzer_set_period(1674);
    turn_green();

  }else if(switch_state_down_3){
    interrupt =0;
    buzzer_set_period(1408);
    turn_green();
    turn_greenOff(); //full dim

  }else if(switch_state_down_4){
    interrupt =200;
    ext_opt =1;
    buzzer_set_period(0);
    static char state =0;
    switch(state){
    case 0: buzzer_set_period(592); red_on =0; green_on=0; state++; break;
    case 1: buzzer_set_period(790); red_on =1; green_on=0; state++; break;
    case 2: buzzer_set_period(418); red_on =0; green_on=1; state++; break;
    case 3: buzzer_set_period(939); red_on =1; green_on=1; state =0; break;
    default: state =0;
    }
    led_changed =1;
    led_update();

  }else{
    ext_opt=0;
    buzzer_set_period(0);
    turn_redOff();
    turn_greenOff();
  }
  //buzzer_set_period(0);
}
