#include <avr/io.h>
#include <util/delay.h>

static inline void initADC0(void) {

  ADMUX  |= (1 << REFS0); //ref. voltage on AVCC
  ADCSRA |= (1 << ADPS1)| (1<<ADPS0); //ADC clock prescaler.
  ADCSRA |= (1 << ADEN); //enables the ADC

}

int main (void) {

  uint16_t pResValue;
  uint16_t thresholdLevel;

  thresholdLevel = 0b1011001100;

  DDRB |=(1 << PB0); //set output

  initADC0();

  while(1){

    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
    pResValue=ADC;
  
    if (pResValue > thresholdLevel) {
      PORTB = 0b00000001;
    }

    else {
      PORTB = 0b00000000;
    }
  return (0);
  }

}


