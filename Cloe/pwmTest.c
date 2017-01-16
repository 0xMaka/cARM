#include <avr/io.h>
#include <util/delay.h>

#define PULSE_MIN 	750
#define PULSE_MID       1500
#define PULSE_MAX       2250


int main(void)
{
  DDRB |= 0xFF;
  //fast pwm
  TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A1| 1<<COM1A0; 
  TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS11;
  ICR1 = 39999;

  OCR1A = ICR1 - 2000; //37999
  int i, p;
  while (1) {
  p = 4000;
    for (i=14; i>0; i--){ 
      p = p - 200;
      OCR1A = ICR1-p;
      _delay_ms(50);
    }
  p = 800;
    for (i=14; i>0; i--){ 
      p = p + 200;
      OCR1A = ICR1-p;
      _delay_ms(50);
    }
   
/*
  OCR1A = ICR1 - 2500;
  _delay_ms(1500);
  OCR1A = ICR1 - 2700;
  _delay_ms(1500);
  OCR1A = ICR1 - 2900;
  _delay_ms(1500);
  OCR1A = ICR1 - 2700;
  _delay_ms(1500);
  OCR1A = ICR1 - 2500;
  _delay_ms(1500);
  OCR1A = ICR1 - 2300;
  _delay_ms(1500);
  OCR1A = ICR1 - 2100;
  _delay_ms(1500);
  OCR1A = ICR1 - 1900;
  _delay_ms(1500);
  OCR1A = ICR1 - 1700;
  _delay_ms(1500);
  OCR1A = ICR1 - 1900;
  _delay_ms(1500);
  OCR1A = ICR1 - 2100;
  _delay_ms(1500);
*/
  }
} 
