#include <avr/io.h>
#include<util/delay.h>
#include <avr/power.h>

#define DELAYTIME 85

#define LED_PORT	PORTB
#define LED_DDR		DDRB
int main (void) {
  clock_prescale_set(clock_div_8);
  
  uint8_t i;
  uint8_t repetitions;
  uint8_t whichLED;
  uint16_t randomNumber = 0x1234;
  
  //init
  LED_DDR = 0xff; //configure all leds pins for output

  //event loop
  while (1) { //go left
  for (i = 0; i < 8; i++) {
    LED_PORT |= (1 << i); // turn on i'th pin
    _delay_ms(DELAYTIME); // wait
  }
  for (i = 0; i < 8; i++) {
    LED_PORT &=~(1 << i); //turn off i'th pin
    _delay_ms(DELAYTIME); //wait
  }
  _delay_ms(5 *DELAYTIME);// pause
	      //go right
  for (i = 7; i < 255; i--) {
    LED_PORT |= (1 << i); // turn on i'th pin
    _delay_ms(DELAYTIME); //wait
  }
  for (i = 7; i < 255; i--) {
    LED_PORT &=~(1 << i); //turn off i'th pin
    _delay_ms(DELAYTIME); //wait
  }
  _delay_ms(5 *DELAYTIME);//pause


  // toggle *random* bits for a while
  for (repetitions = 0; repetitions < 75; repetitions++) {
    //random number generator
    randomNumber = 2053* randomNumber + 13849;
    //low three bits from high bite
    whichLED = (randomNumber >> 8) & 0b00000111;

    LED_PORT ^= (1 << whichLED); //toggle led
    _delay_ms(DELAYTIME);
  }
  LED_PORT = 0; //leds off
  _delay_ms(DELAYTIME); //pause
  }
  return (0);
}
