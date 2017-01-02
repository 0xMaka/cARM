#include <avr/io.h>
#include "i2c.h"

#define LCD_ADDRESS_W	0b01001110
#define LCD_ADDRESS_R   0b01001111
#define DISPLAY		0b00000000

int main (void) {
  initI2C();

  while(1) {
    i2cStart();
    i2cSend(LCD_ADDRESS_W);
    i2cSend(DISPLAY);
    i2cStop();

  }
  return 0;
}
