//
#include <avr/io.h>

int main (void) {

  DDRB |= (1<<5); //Set the Data Direction Register for the LED to output
  DDRC &=~(1<<3); //Set the Data Direction Register for the switch to input
  PORTC|= (1<<3); //Enable the pullup resistor for the switch
   
  while (1) {
    if (PINC & (1<<3))
      PORTB |= (1<<5);
    else
      PORTB &=~(1<<5);
  }
}
