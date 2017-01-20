
#include <avr/io.h>
#include <util/delay.h>
#include "servoFunctions.h"
#define SHORT_DELAY 	750
int main (void) {

  initPWM();
  while(1) {

    sweepRightLeft();
    _delay_ms(SHORT_DELAY);
    sweepLeftRight();
    _delay_ms(SHORT_DELAY);
    sweepRightCenter();
    _delay_ms(SHORT_DELAY);
    sweepLeftCenter();
    _delay_ms(SHORT_DELAY);
    scanRightLeft();
    _delay_ms(SHORT_DELAY);
    scanLeftRight();
    _delay_ms(SHORT_DELAY);
    center();
    _delay_ms(SHORT_DELAY);
  }
}
