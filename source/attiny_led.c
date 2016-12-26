#include <avr/io.h>
#include <util/delay.h>

void  wait() {
  uint8_t i=0;
  for(;i<50;i++)
    _delay_loop_2(0);
}

void main () {
  DDRB=0b00000001;

  while(1)

  {
    PORTB|=0b00000001;
    wait();

    PORTB&=0b11111110;
    wait();
  }
}
	    
	        

