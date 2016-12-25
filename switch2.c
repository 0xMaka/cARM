//
#include <avr/io.h>

int main (void) {

  DDRB |= (1<<5); //Set the Data Direction Register for the LED to output
  DDRC &=~(1<<3); //Set the Data Direction Register for the switch to input
  PORTC|= (1<<3); //Enable the pullup resistor for the switch
  
  uint8_t oldc=PINC; ////Enable the pullup resistor for the switch
  
  while (1) {
    if ((oldc & (1<<3)) != (PINC & (1<<3)) )  {
      PORTB ^= (1<<5); ////Switch LED
      oldc=PINC; ////Save new state
    }
  }
}
