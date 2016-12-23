#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main () {

  DDRD &=~ _BV(DDD3);
  DDRB |= _BV(DDB5);

// val = PIND & _BV(PD3);

  while (1) {

  PIND & _BV(PD3);
  PORTB |= _BV(DDB5);
  _delay_ms(BLINK_DELAY_MS);
  PORTB &= ~_BV(DDB5);
  _delay_ms(BLINK_DELAY_MS);
  }
}

