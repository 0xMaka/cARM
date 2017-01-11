#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

int main(void) {

// -------- Inits --------- //
  DDRB = 0xff;                            /* set up LEDs for output */
  initUSART();
  printString("Hello World!\r\n"); 

  void printByte("0b00111111");
}
