//8 Bit Timer
#include <avr/io.h>
#include <util/delay.h>

void initPWM (void) {
  TCCR0A |= 1<<COM0A1; /*Clear OC1A/OC1B on Compare Match*/
  TCCR0A |= 1<<WGM00 | 1<<WGM02; /*phase correct*/ 
  TCCR0B |= 1<<CS00; /*No Prescaler*/
  ICR1 = 19999;
  OCR0A= ICR1 - 2000; //17999
}

int main () {
  initPWM();
  DDRB |= 0xFF;
  int i, p;

  while (1) {
    p = 4000;
    for (i=14; i>0; i--){ 
      p = p - 200;
      OCR0A = ICR1-p;
      _delay_ms(500);
    }
    p = 800;
    for (i=14; i>0; i--){ 
      p = p + 200;
      OCR0A = ICR1-p;
      _delay_ms(500);
    }
  }
}
