#include <avr/io.h> //Defines pins, ports, etc.
#include <util/delay.h>

static inline void initADC0(void) {
ADMUX |= (1 << REFS0); //reference voltage on AVCC
ADCSRA |= (1 << ADPS1) | (1 << ADPS0); //ADC clock prescaler /8
ADCSRA |= (1 << ADEN); //enables the ADC
}

int main(void) {
uint16_t photoresistorValue;
uint16_t threshold_level;
threshold_level= 0b1011001100;
DDRB |= (1 << PB0); //Data Direction Register B: writing a 1 to the bit enables output

initADC0();

while (1) {
ADCSRA |= (1 << ADSC); //start ADC conversion
loop_until_bit_is_clear(ADCSRA, ADSC); //wait until ADC conversion is done
photoresistorValue= ADC; //read ADC value in

if (photoresistorValue > threshold_level) {
PORTB= 0b00000001; //turn on LED attached to port PB0
}
else {
PORTB= 0b00000000; //turn off LED attached to port PB0
} return (0);//this line is never actually reached
}
}

