//testing servo
#include<avr/io.h>
int main(void) {
  DDRD|=(1 << PD6);
  0CR0A =128;
  TCCR0A |= (1 << COM0A1);
  TCCR0A |= (1 << WGM01)|(1 << WGM00);
  TCCR0B |= (1 << CS01);
  while(1) {

  }
}

