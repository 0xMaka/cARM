#include <avr/io.h>
#include "i2c.h"

#define LCD_ADDRESS_W	0b01111110
#define LCD_ADDRESS_R   0b01111111
#define DISPLAY		0b00000000

int main (void) {
  initI2C();
  i2cStart();
  i2cSend(LCD_ADDRESS_W);
  i2cSend(DISPLAY);
  i2cStop();

  while(1) {
  }
  return 0;
}
