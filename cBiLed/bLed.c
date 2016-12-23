#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main (void) {

  /*set pins 1/2 of portb for output*/
  DDRB |= _BV(DDB1);
  DDRB |= _BV(DDB2);

  while(1) {
  /*set pin1 high to turn led on*/
  PORTB |= _BV(DDB1);

  _delay_ms(BLINK_DELAY_MS);

  PORTB |= _BV(DDB2);

  _delay_ms(BLINK_DELAY_MS);


  /*set pin5 low to turn led off*/
  PORTB &= ~_BV(DDB1);

  _delay_ms(BLINK_DELAY_MS);
  
  PORTB &= ~_BV(DDB2);

  _delay_ms(BLINK_DELAY_MS);
  
  }
}
  
