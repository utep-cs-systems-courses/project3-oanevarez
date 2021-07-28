#ifndef stateMachine_included
#define stateMachine_included

#define LED BIT6

static char interrupt;
static char ext_opt;

static short drawPos[2] = {10,10}, controlPos[2] = {10,10};
//static short velocity[2] ={3,8}, limits[2] = {screenWidth-35, screenHeight-8};
static short redrawScreen =1;





void turn_red();
void turn_redOff();
void turn_green();
void turn_greenOff();
void sound_on();

#endif 
