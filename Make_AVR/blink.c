//Preamble
#include <avr/io.h> //defines pins, ports etc
#include<util/delay.h> //functions for wasting time

int main (void) {
//init
DDRB |= (1<<PB0); //Data Direction Register B:
		//writing a one to the bit enables output
//Event loop
while (1) {
  PORTB = 0b00000001; //turn on first LED bit/pin in PORT B
  _delay_ms (1000); //wait

  PORTB = 0b00000000; //turn off all bits/pins on PB    
  _delay_ms (1000); //wait
  } //end loop
  return(0); //end program. This never happenes.
}

