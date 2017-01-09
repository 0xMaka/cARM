//POV toy demo framework
//Preamble
#include<avr/io.h> //defines pins, ports etc
#include<util/delay.h> //functions for wasting time
//#define F_CPU 16000000UL
#define blinkDelay 350
//Functions
void POVDisplay(uint8_t oneByte) {
  PORTB = oneByte;
  _delay_ms(2);
}
int main (void) {
//Init
DDRB = 0xff; //Data Direction Register B:
		//writing a binary one to the PORT enables output on (all) bits
//Event loop
while (1) {
    POVDisplay(0b00100000); 
    POVDisplay(0b00010000);
    POVDisplay(0b00101000);
    
    POVDisplay(0b00010100);
    POVDisplay(0b00101010);
    POVDisplay(0b00010101);

    POVDisplay(0b00001010);
    POVDisplay(0b00000101);
    POVDisplay(0b00000010);

    POVDisplay(0b00000001);
    POVDisplay(0b00100000);

   PORTB = 0;
   _delay_ms(10);

  } //end loop
  return(0); //end program. This never happenes.
}

