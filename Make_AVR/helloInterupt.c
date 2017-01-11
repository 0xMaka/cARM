//Preamble
#include <avr/io.h> 	//defines pins, ports etc
#include<util/delay.h> 	//functions for wasting time
#include <avr/interrupt.h>

ISR(INT0_vect) {	//run every time there is a change on button
  if (bit_is_set(PIND, PD2)) { 	//button
    PORTB |= (1 << PB1); 	//led on
  }
  else {
    PORTB &= ~(1 << PB1); 	//led off
  }
}
void initInterrupt0(void) {
  EIMSK |= (1 << INT0);
  EICRA |= (1 << ISC00);
  sei();
}

int main (void) {
//init
  DDRB |= 0xff;
  PORTD |= (1 << PD2);
  initInterrupt0();

//Event loop
  while (1) {
    _delay_ms(200);
    PORTB ^= (1 << PB0);	//toggle led
  }
}
