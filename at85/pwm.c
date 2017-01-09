//pwm test
#include <avr/io.h>
#include <util/delay.h>
/*Parallax Standard Servo (#900-00005)
Communication: Pulse-width modulation, 0.75–2.25  
ms high pulse, 20 ms intervals 
*/
//set up pwm
pwminit(){
  TCCR1A |= (1 << WGM11) | (1 << COM1A1)| (1 << COM1A0);
  TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS10);
  ICR1A = 19,999 //f_cpu/servos acceptable hz value

  DDRB |= 0xFF;
  0CR1A = ICR1 - 2000; //18000
}

int main(){
  pwminit();
  while(1) {
    0CR1A = ICR1 - 800;
    _delay_ms(100);
    0CR1A = ICR1 - 2200;
    _delay_ms(100);
  }
}


