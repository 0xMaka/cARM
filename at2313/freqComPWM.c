#include<avr/io.h>
#include <util/delay.h>

void initPWM(void){
  /* Set OC1A/OC1B on Compare Match when up-counting. 
  Clear OC1A/OC1B on Compare Match when downcounting. */
  TCCR1A |= 1<<COM1A1 | 1<<COM1B1 | 1<<COM1A0 | 1<<COM1B0;

  /* PWM, Phase and Frequency Correct 
  TOP=ICR1 | Update of OCR1 x at BOTTOM | TOV1 Flag on BOTTOM */
  TCCR1B |= 1<<WGM13|/**/1<<CS11;//Prescaler 8. 
  
  ICR1 = 9999;//(20ms/8/0.00025ms /10000 -1) (Doing this right?)
}

void rampUP(void) {
  int i, p;//iteration, pulse
  p = 800;
  for (i=10;i>=i;--i) {
    p = p + 100;
    OCR1A = ICR1-p;
    OCR1B = ICR1-p;
    _delay_ms(2000);
  }
}

int main (void) {

  DDRB |= 0xFF; 
  initPWM();
  while(1) {
    rampUP();
  }
  return(0);
}

