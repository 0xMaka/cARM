#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main (void) {

  /*set pin 5 of portb for output*/
  DDRB |= _BV(DDB5);

  while(1) {
  /*set pin5 high to turn led on*/
  PORTB |= _BV(DDB5);
  _delay_ms(BLINK_DELAY_MS);

  /*set pin5 high to turn led off*/
  PORTB &= ~_BV(DDB5);
  _delay_ms(BLINK_DELAY_MS);

  }
}
  
