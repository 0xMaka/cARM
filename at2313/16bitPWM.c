#include<avr/io.h>
#include <util/delay.h>

void initPWM(void){
  /* Set OC1A/OC1B on Compare Match, clear
  OC1A/OC1B at TOP*/
  TCCR1A |= 1<<COM1A1 | 1<<COM1B1 | 1<<COM1A0 | 1<<COM1B0 | 1<<WGM10;

  /* Fast PWM 
  TOP=ICR1 | Update of OCR1 xat TOP | TOV1 Flag Set on TOP */
  TCCR1B |= 1<<WGM13|1<<WGM12|/**/1<<CS11|1<<CS10;//Prescaler 64. (62.5Khz)
  
  ICR1 = 1249;//((20ms/64/0.00025ms = 1250) -1)
}

void rampUP(void) {
    
  OCR1A = ICR1 - 93;
  OCR1B = ICR1 - 93;
  _delay_ms(2000);
  
  OCR1A = ICR1 - 46.875;
  OCR1B = ICR1 - 140.625;
  _delay_ms(2000);

  OCR1A = 93.75;
  OCR1B = 93.75;
  _delay_ms(2000);

  OCR1A = 140.625;
  OCR1B = 46.875;
  _delay_ms(2000);
     
}

int main (void) {

  DDRB |= 0xFF; 
  initPWM();
  while(1) {
    rampUP();
  }
  return(0);
}

