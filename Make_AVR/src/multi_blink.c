//Preamble
#include<avr/io.h> //defines pins, ports etc
#include<util/delay.h> //functions for wasting time
//#define F_CPU 16000000UL
#define blinkDelay 350
int main (void) {
//init
DDRB = 0xff; //Data Direction Register B:
		//writing a one to the bit enables output
//Event loop
while (1) {
  PORTB = 0b00100000; //turn on first LED bit/pin in PORT B
  _delay_ms (blinkDelay); //wait

  PORTB = 0b00010000; //turn off all bits/pins on PB    
  _delay_ms (blinkDelay); //wait

  PORTB = 0b00001000; //turn on first LED bit/pin in PORT B
  _delay_ms (blinkDelay); //wait

  PORTB = 0b00000100; //turn off all bits/pins on PB    
  _delay_ms (blinkDelay); //wait
 
  PORTB = 0b00000010; //turn on first LED bit/pin in PORT B
  _delay_ms (blinkDelay); //wait

  PORTB = 0b00000001; //turn off all bits/pins on PB    
  _delay_ms (blinkDelay); //wait
	 
  } //end loop
  return(0); //end program. This never happenes.
}

