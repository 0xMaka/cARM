//blinks all three colours of a bi-LED connected to pins 
//D1/D2 on Atmega328-PU

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main (void) {

  //set pins 1/2 of portb for output
  DDRB |= _BV(DDB1);
  DDRB |= _BV(DDB2);

  while(1) {
  //set pin1 high to turn led on
  PORTB |= _BV(DDB1);
  //wait
  _delay_ms(BLINK_DELAY_MS);
  //set pin 2 high
  PORTB |= _BV(DDB2);
  //wait
  _delay_ms(BLINK_DELAY_MS);

  //set pin1 low to turn led off.. etc
  PORTB &= ~_BV(DDB1);
 
  _delay_ms(BLINK_DELAY_MS);
  
  PORTB &= ~_BV(DDB2);

  _delay_ms(BLINK_DELAY_MS);
  
  }
}
  
