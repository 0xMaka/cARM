#include <avr/io.h>
void initLed(void) {	//set up led
  DDRB  |= (1 << PB0);	//set port as output
  PORTB |= (1 << PB0);
}
void initButton(void) {
  DDRB  &= ~(1 << PB2); //set input 
  PORTB |= (1 << PB2); //enable pull up resister
}
void main (void) {
  initLed();
  initButton();
  while(1) {
    if ((PINB & (1 << 2)) == 0){
      PORTB |= (1 << PB0);
    }
    else {
      PORTB &= ~(1 << PB0);
    }
  }
}
