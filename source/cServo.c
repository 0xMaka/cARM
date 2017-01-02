#include <avr/io.h> 
#include <util/delay.h>
//#include <avr/interupt.h>

#define PULSE_MIN	750
#define PULSE_MAX	2250
#define PULSE_MID	1500

static inline void initTimer1Servo(void)
{

  TCCR1A |= (1 << WGM11); 
  TCCR1B |= (1 << WGM12)|(1 << WGM13); 
  TCCR1B |= (1 << CS10); /* /1 prescaling --counting ms */
  ICR1 = 20000 ; // TOP value ms
  TCCR1A |= (1 << COM1A1); //direct out on PB1/OC1A
  DDRB |= (1 << PB1); // set pin B1 as output

}

static inline void showOff(void) {

  OCR1A  |= PULSE_MID;
  _delay_ms(1500);

  OCR1A  |= PULSE_MIN;
  _delay_ms(1500);

  OCR1A  |= PULSE_MAX;
  _delay_ms(1500);

  OCR1A  |= PULSE_MID;
  _delay_ms(1500);

}

int main (void) {
  initTimer1Servo();
  while(1)
  {
    showOff();
  }
}
