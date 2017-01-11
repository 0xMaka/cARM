//free running AVR/ADC oscilloscope
// ---- preamble ---- //
#include<avr/io.h>
#include<util/delay.h>
#include"USART.h"
#define SAMPLE_DELAY 20 //*ms, controls scroll speed of scope
// ---- functions ---- //
static inline void initFreerunningADC(void) {
  ADMUX  |=  (1 << REFS0);	//AVCC with external capacitor at AREF pin
  ADMUX  |=  (1 << MUX0); 	// sensor on PC1
  ADCSRA |=  (1 << ADPS1) | (1 << ADPS2);	//precaler /64  
  ADCSRA |=  (1 << ADLAR);			//left justify
  ADCSRA |=  (1 << ADEN);			//enable ADC
  ADCSRA |=  (1 << ADATE);			//auto trigger enable
  ADCSRA |=  (1 << ADSC);			//start first conversion
}
int main (void) {
// ---- init ---- //
  initUSART();
  initFreerunningADC();
// ---- event loop ---- //
  while (1) {
    transmitByte(ADCH); // transmit the high bit, left adjusted
    _delay_ms(SAMPLE_DELAY);
  }
  return (1);
}
