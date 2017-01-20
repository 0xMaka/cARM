//LEDs on PB0-7

#include<avr/io.h>
#include<util/delay.h>

void ledinit(void) {
  DDRB =  0xff;
}

int main(void) {

  ledinit();

  while(1) {
    PORTB = 0b10101010;
    _delay_ms(500);
    PORTB = 0b01010101;
    _delay_ms(500);
  }
}
