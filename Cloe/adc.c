#include <avr/io.h>
//#include <stdlib.h>
//#include <avr/interrupt.h>
#include "USART.h"

#define LTHRES 500 
#define RTHRES 500 

void initADC() {
//config ADC
  ADMUX |= (1 << REFS0);  	/*set REFS0 (1) leaving REFSO1 default (0)
  				configuring avcc with external capacitor
			 	at aref pin */
//  ADMUX |= (1 << ADLAR);	//left adjust the ADC result

  ADCSRA|= (1 << ADEN)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);//set prescaler
  				//16000000/128 = 125000
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
  uint16_t ADCResult0, ADCResult1;

  DDRB = 0x01; //led

  initUSART();
  initADC();

  while (1) {

    ADCResult0 = ADCRead(0);
    ADCResult1 = ADCRead(1);

    //condition for led to glow

    if (ADCResult0 < LTHRES && ADCResult1 < RTHRES) {
      PORTB = 0x01;
      printString("Light level below 500.\r\n");
    }
    else {
      PORTB = 0x00;
      printString("Light level above 500.\r\n");
    }  
  }
}

