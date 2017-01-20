#include <avr/io.h>
#include <stdlib.h>
//#include <avr/interrupt.h>
#include "USART.h" 
#define RES  	24000
void initADC() {

//ADC Mux Register 
//config ADC
  ADMUX |= (1 << REFS0);  	/*set REFS0 (1) leaving REFSO1 default (0)
  				configuring avcc with external capacitor
			 	at aref pin */
  ADMUX |= (1 << ADLAR);	//left adjust the ADC result

//ADC Control Register
//  ADCSRA |= (1 << ADIE);//interupt enable
  ADCSRA |= (1 << ADEN);// ADC enable
  ADCSRA |= (1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);//set prescaler
    				//16000000/128 = 125000
//  sei(); //init interupt
  
  ADCSRA |= (1 << ADSC);//start conversion
}

uint16_t ADCRead(uint8_t ch)
{
  /*select the corresponding channel 0~7
  ANDing with ’7′ will always keep the value
  of ‘ch’ between 0 and 7 */
  ch &= 0b00000111;   // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch; //clears the bottom 3 bits before ORing

  //start single convertion by writing ’1′ to ADSC
  ADCSRA |= (1 << ADSC);

  //wait for conversion to complete, loop till then
  while (ADCSRA & (1 << ADSC));

  return (ADC);
}

int main (void) {

//  sei();
  char adcResult;
  uint16_t ADCResult1;

  DDRB = 1 << PB0; //led

  initUSART();
  initADC();

  while (1) {

    ADCResult1 = ADCRead(1);

    //condition for led to glow

    if (ADCResult1 < RES) {
      PORTB = 1 << PB0;
      printString(" - ");
      printWord(ADCResult1);
    }
    else {
      PORTB &= ~1 << PB0;
      printString(" - ");
      printWord(ADCResult1);
    }  
  }
}

