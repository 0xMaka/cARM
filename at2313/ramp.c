//8 Bit Timer
#include <avr/io.h>
#include <util/delay.h>

void initPWM (void) {
  TCCR0A |= 1<<COM0A1; /*Clear OC1A/OC1B on Compare Match*/
  TCCR0A |= 1<<WGM00 | 1<<WGM01; /*fast pwm*/ 
  TCCR0B |= 1<<CS10|1<<CS11; /*64 Prescaler*/
  ICR1 = 1249;
  OCR0A= ICR1 - 2000; //17999
}

int main () {
  initPWM();
  DDRB |= 0xFF;
  int i, p;

  while (1) {
    p = 1249;
    for (i=10; i>0; i--){ 
      p = p - 100;
      OCR0A = ICR1-p;
      _delay_ms(1000);
    }
    p = 0;
    for (i=10; i>0; i--){ 
      p = p + 100;
      OCR0A = ICR1-p;
      _delay_ms(500);
    }
  }
}
