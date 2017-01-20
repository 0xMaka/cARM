#include <avr/io.h>
#include <stdlib.h>
#include "USART.h"

void initADC() {

//ADC Mux Register 
//config ADC
  ADMUX |= (1 << REFS0);  	//avcc with external capacitor at aref pin
  ADMUX |= (1 << ADLAR);	//left adjust the ADC result
  ADMUX = (1 <<MUX0); //IR on ADC1
//ADC Control Register
//  ADCSRA |= (1 << ADIE);//interupt enable
  ADCSRA |= (1 << ADEN);// ADC enable
  ADCSRA |= (1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);//set prescaler
    				//16000000/128 = 125000  
  ADCSRA |= (1 << ADSC);//start conversion
}

uint16_t ADCRead(void) {
  //start single convertion by writing ’1′ to ADSC
  ADCSRA |= (1 << ADSC);

  //wait for conversion to complete, loop till then
  while (ADCSRA & (1 << ADSC));

  return (ADC);
}

int main (void) {

  uint16_t ADCResult;
  initUSART();
  initADC();

  while(1) {
    ADCResult = ADCRead();
    printWord(ADCResult);
  }
}

