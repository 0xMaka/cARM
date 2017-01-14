#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<avr/power.h>
#include"USART.h"
#define SENSE_TIME 200
#define THRESHOLD 12000

// ---- Global Variables ---- //

volatile uint16_t chargeCycleCount;

// ---- Functions ---- //

void intPinChangeInterrupt(void){
  PCICR |= (1 << PCIE1); //enable pin change interrupt (1 bank c)
  PCMSK1|= (1 << PC1); 	//enable specific interrupt for PIN C1
}

ISR(PCINT1_vect) {
  chargeCycleCount ++;	//count this change
  DDRC |= (1 << PC1);	//cap sensor attached to PIN C1 / output
  _delay_us(1);		//charge delay

  DDRC &= ~(1 << PC1);   //cap sensor  input
  PCIFR |= (1 << PCIF1); //clear pin change interrupt 
}
int main(void) {

// ---- Init ---- //

  clock_prescale_set(clock_div_1);

  initUSART();	//full speed
  printString("==[ Cap Sensor ]==\r\n\r\n");
  
  DDRB = 0xff;
  MCUCR |= (1 << PUD);	//disable interrupts

  PORTC |= (1 << DDRC); //sensor port, sensor / we can leave as output
  intPinChangeInterrupt();

  // ---- Event Loop ---- //
  
  while(1) {
    chargeCycleCount = 0;	//reset counter
    PORTC |= (1 << DDRC); //start with cap high
    
    sei();	//set enable interrupt
    _delay_ms(SENSE_TIME);
    cli();

    if (chargeCycleCount < THRESHOLD) {
      DDRB = 0xff;
    }
    else {
      DDRB = 0;
    }
    printWord(chargeCycleCount);
    printString("\r\n");
  }
  return(0);
}


