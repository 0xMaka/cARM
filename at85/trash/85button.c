#include<avr/io.h>
#include<util/delay.h>

buttonSetup(){
  DDRB  |=  (1 << PB0); //set led attached to pin B0 for output.
  DDRB  &= ~(1 << PB3); //set button attached to pin B3 for input.
  PORTB |=  (1 << PB3); //set pin B3 high by enabling pull up resister.
}

int main() {
  buttonSetup();
  while(1) {
    if ((PINB & (1 << PB3)) == 1) {
      DDRB  &= ~(1 << PB0); //led off
      _delay_ms(3500); //wait
      DDRB  |= (1 << PB0); //led on
    }
    else {
      DDRB  |= (1 << PB0); //led on
    }
  }
  return(0);
}
