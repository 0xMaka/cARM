// ---- Preamble ---- //

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

static inline void initTimers (void) {
  // Timer 1 A,B
  TCCR1A  |=  ( 1 << WGM10 );	//fast pwm mode, 8 bit
  TCCR1B  |=  ( 1 << WGM12 );	//fast pwm mode, pt.2
  TCCR1B  |=  ( 1 << CS11  );	//pwm freq = fcpu/8/256
  TCCR1A  |=  ( 1 << COM1A1);	//output on OCR1A
  TCCR1A  |=  ( 1 << COM1B1);	//output on OCR1B
  
  // Timer 2
  TCCR2A  |=  ( 1 << WGM20 );	//fast pwm mde
  TCCR2A  |=  ( 1 << WGM21 );	//fast pwm mode, pt.2//fast pwm mode, pt.2
  TCCR2B  |=  ( 1 << CS21  );	//pwm freq = fcpu/8/256
  TCCR2A  |=  ( 1 << COM2A1);	//output on OCR2A
}


int main(void) {

  uint8_t brightness;

  // ---- Init ---- //
  initTimers();
  initUSART();
  printString("--LED PWM Demo --\r\n");

	//enable output on LED pins, triggered by PWM hardware
  DDRB |= ( 1 << PB0 );
  DDRB |= ( 1 << PB1 );
  DDRB |= ( 1 << PB2 );

  // ---- Event loop ---- //
  while (1) {

    printString("\r\n Enter (0 - 255) for PWM duty cycle: ");
    brightness = getNumber();

    OCR2A = OCR1B;
    OCR1B = OCR1A;
    OCR1A = brightness;
  }
  return (0);
}
