//Preamble
#include<avr/io.h> //defines pins, ports etc
#include<util/delay.h> //functions for wasting time
#define delayTime 85
#define led_port  PORTB
#define led_pin   PINB
#define led_ddr   DDRB
int main (void) {
//Init
uint8_t i;
led_ddr = 0xff; //set all
//Event loop
while (1) {
  while (i < 5) {
    led_port = ~(1 << i);
    _delay_ms (delayTime);
    i = i + 1; 
    }
    while (i > 0) {
      led_port = ~(1 << i);
      _delay_ms (delayTime);
      i = i - 1;
    }
  } //end loop
  return(0); //end program. This never happenes.
}

