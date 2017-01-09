#include <avr/io.h> //define pins, ports, etc
#include <util/delay.h>

static inline void initADC0(void) {

  ADMUX  |= (1 << REFS0); //ref. voltage on AVCC
  ADCSRA |= (1 << ADPS1)| (1<<ADPS0); //ADC clock prescaler.
  ADCSRA |= (1 << ADEN); //enables the ADC

}

int main (void) {

  uint16_t pMeterValue;
  uint16_t thresholdLevel;
  thresholdLevel = 0b10000000;
  DDRB |= (1 << PB0); //write a one to pin B0 via the data direction register

  initADC0();

  while(1){

    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
    pMeterValue=ADC;
  
    if (pMeterValue > thresholdLevel) {
      PORTB = 0b00000001;
    }

    else {
      PORTB = 0b00000000;
    }
  return (0);
  }
}


