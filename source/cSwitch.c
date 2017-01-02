#include <avr/io.h>
#include <util/delay.h>
int main (void)

{
  PORTD|= (1<< PD2); //enable pullup
  DDRB = 0xff; //set leds for output

  while (1) { //infinate loop
    if (bit_is_clear(PIND, PD2))//if button pressed
    {
      PORTB = 0b00111111;
    }
    else {
      PORTB = 0b00000000;
    }
   
  }
  return 0;
}
