/* Standard Parralax Servo on Timer 1*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "USART.h"

#define PULSE_MIN 	800
#define PULSE_MID       2300
#define PULSE_MAX       4100

static inline uint16_t getNumber16(void);

static inline void initTimer1Servo(void){
	//set up Timer 1 to send a pulse once every 20ms
		//use fast pwm, counter max in ICR1
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12)|(1 << WGM13);
  TCCR1B |= (1 << CS11);	/* 16m/8/50 = 40thou prescaler counting in milliseconds */
  ICR1 = 40000;			//top value = 20ms
  TCCR1A |= (1 << COM1A1);	//direct output PB1/OC1A
  DDRB |= (1 << PB1);		//PB1 set as output
}
static inline void showOff(void) {

  printString("Center\r\n");
  OCR1A = PULSE_MID;
  _delay_ms(1500);

  printString("Max Clockwiser\n");
  OCR1A = PULSE_MIN;
  _delay_ms(1500);

  printString("Max Counter Clockwise\r\n");
  OCR1A = PULSE_MAX;
  _delay_ms(1500);
      
  printString("Center\r\n");
  OCR1A = PULSE_MID;
  _delay_ms(1500);

}

int main(void) {

  // -------- Inits --------- //
  uint16_t servoPulseLength;
  
  OCR1A = PULSE_MID;
  initTimer1Servo();

  initUSART();
  printString("\r\nWelcome To The Servo Demo\r\n");
  showOff();

  // ------ Event loop ------ //
  while (1) {

    printString("Enter a four digit pulse length:\r\n");
    servoPulseLength = getNumber16();
    DDRB |= (1 << PB1);
    printString("On my way...\r\n");
    OCR1A = servoPulseLength;
    _delay_ms(1000);
    printString("Releasing...\r\n");
    while (TCNT1 < 3000){;
    }
    DDRB &= ~(1 << PB1);

  }                                                  /* End event loop */
  return 0;
}

static inline uint16_t getNumber16(void) {
  //gets a pwn value from the serial port
  //in character out number
  char thousands = '0';
  char hundreds = '0';
  char tens = '0';
  char ones = '0'; 
  char thisChar = '0';


  do {
    thousands = hundreds;
    hundreds = tens;
    tens = ones;
    ones = thisChar;

    thisChar = receiveByte();
    transmitByte(thisChar);
  }  while (thisChar != '\r');

  transmitByte('\n');
  return (1000 * (thousands - '0') + 100 * (hundreds - '0' ) + 10 * (tens - '0') 
  + ones - '0');
}
