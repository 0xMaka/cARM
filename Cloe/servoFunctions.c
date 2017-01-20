/* Servo Functions --- needs improvement */

// --- Preamble --- //
#include <avr/io.h>
#include <util/delay.h>

// --- Defines --- //
#define SHORT_WAIT 	50
#define PULSE_MIN 	800
#define PULSE_MID       2400
#define PULSE_MAX       4000

// --- Init --- //
int i, p;
void initPWM(void){
  DDRB |= 1 << PB1;
  TCCR1A |= 1<<WGM11 | 1<<COM1A1| 1<<COM1A0;
  /* 16m/8/50 = 40thou prescaler counting in milliseconds */ 
  TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS11; 
  ICR1 = 39999;
  OCR1A = ICR1 - 2000; //37999
}

void sweepRightLeft(void) {
  p = 4000;
  for (i=14; i>0; i--){ 
    p = p - 200;
    OCR1A = ICR1-p;
    _delay_ms(50);
  }
}
void sweepLeftRight(void) {
  p = 800;
  for (i=14; i>0; i--){ 
    p = p + 200;
    OCR1A = ICR1-p;
    _delay_ms(50);
  }
}
void sweepRightCenter(void) {
  p = 4000;
  for (i=8; i>0; i--){ 
    p = p - 200;
    OCR1A = ICR1-p;
    _delay_ms(50);
  }
}

void sweepLeftCenter(void) {
  p = 800;
  for (i=8; i>0; i--){ 
    p = p + 200;
    OCR1A = ICR1-p;
    _delay_ms(50);
  }
}

void scanRightLeft(void) {
  p = 4000;
  for (i=15; i>0; i--){ 
    p = p - 200;
    OCR1A = ICR1-p;
    _delay_ms(500);
  }
}
void scanLeftRight(void) {
  p = 800;
  for (i=15; i>0; i--){ 
    p = p + 200;
    OCR1A = ICR1-p;
    _delay_ms(500);
  }
}

void center(void) {
  OCR1A = ICR1-2400;
}
 
