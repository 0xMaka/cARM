#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
   DDRB  |= (1 << PB0);
   PORTB |= (1 << PB0);
   DDRB  &= ~(1 << PB2); 
   PORTB |= (1 << PB2);

   while(1)
   {
     if ((PINB & (1 << 2)) == 0){
       PORTB |= (1 << PB0);
     }
     else {
       PORTB &= ~(1 << PB0);
     }
   }
}
