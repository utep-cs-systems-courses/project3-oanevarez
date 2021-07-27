#ifndef led_included
#define led_included

#define LED_RED BIT6  //msp430 P1.6
#define LED_GREEN BIT0  //MSP430 P1.0

#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();
void led_update();

#endif // included
