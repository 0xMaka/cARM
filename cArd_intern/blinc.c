#include <avr/io.h>
#include <util/delay.h>

#define blinkDelay 1000

int main (void) {

  long i; //for a 32 bit value used as a counter to store delay.
  DDRB = 1<<5; //set PB5/D13 as an output by shifting binary 1, 5 places.

  while(1) {
    PORTB = 1<<5; //LED on
    
    _delay_ms(blinkDelay);
  //  for(i = 0; i < 100000; i++); //delay
   _delay_ms(blinkDelay);
    PORTB = 0<<5; //LED off
    
  //  for(i = 0; i < 100000; i++); //delay
  }
}



