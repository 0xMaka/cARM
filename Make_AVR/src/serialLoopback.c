#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"
int main (void) {
  char serialCharacter;
  initUSART();
  printString("Hello World!\r\n");

  while (1) {

  serialCharacter = recieveByte();
  transmitByte(serialCharacter);

  }
  return (0);
}
