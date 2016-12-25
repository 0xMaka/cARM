//blinks all three colours of a bi-LED connected to pins 
//B1/B2 on Atmega328-PU

#include <avr/io.h>
#include <util/delay.h>

#define intDelay 1000

int main (void) {

  //set pins 1/2 of portB for OUTput
  DDRB |= _BV(DDB1);    //Data Direction Register B port B1
  DDRB |= _BV(DDB2);    //Data Direction Register B port B2

  while(1) {
  
  PORTB |= _BV(DDB1);  //set pin B1 HIGH 
 					//GREEN 	- B1 HIGH B2 LOW
  _delay_ms(intDelay); //wait
  
  PORTB |= _BV(DDB2);  //set pin B2 HIGH
  					//YELLOW	- B1 HIGH B2 HIGH
  _delay_ms(intDelay); //wait

  PORTB &= ~_BV(DDB1); //set pin B1 LOW
 					//RED		- B1 LOW B2 HIGH
  _delay_ms(intDelay); //wait
  
  PORTB &= ~_BV(DDB2); // set pin B2 LOW
					//OFF   	- B1 LOW B2 LOW
  _delay_ms(intDelay); //wait
  
  }
}
  
