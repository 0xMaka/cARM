//simple dirty analogue to digital conversion
#include<avr/io.h>
#include<util/delay.h>

static void inita2d(void){	//set up analogue to digital conversion
  ADMUX	 |=  (1 << REFS1);	//use internal 1.1V Voltage Reference
  ADMUX	 |=  (1 << ADLAR);	//left justify result, only need to read ADCH
  ADMUX	 |=  (1 << MUX0) | (1 << MUX1); //sensor on P3

  ADCSRA |=  (1 << ADEN);	//enable ADC
  ADCSRA |=  (1 << ADSC);	//start conversion
}

void initLed(void) {    	//set up led
  DDRB  |= (1 << PB0);  	//set port as output
  PORTB |= (1 << PB0);
}

void main (void) {
  unsigned int a2dc; //*
  inita2d();
  initLed();
  while(ADCSRA |=  (1 << ADSC)) { //wait for conversion to complete
    a2dc = ADCW; //*store a2d conversion value
    if (a2dc < 500) {
      PORTB |= (1 << PB0);
    }
    else {
      PORTB &= ~(1 << PB0);
    }
  }
}
	    

