//quick and dirty serial com functions

#include <avr/io.h>
#include "USART.h"
#include <util/setbaud.h>

void initUSART(void) { //requires buad
  UBRR0H = UBRRH_VALUE; //defined in setbaud.h
  UBRR0L = UBRRL_VALUE;
 #if USE_2X
   UCSR0A |= (1 << U2X0);
 #else
   UCSR0A &=~(1 << U2X0);
#endif
	//enable usart tansmitter/receiver
  UCSR0B = (1 << TXEN0)| (1 << RXEN0);
  UCSR0C = (1 << UCSZ01)| (1 << UCSZ00); //8 data bits, 1 stop bit
}

void transmitByte(uint8_t data) {
	//wait for empty transmitter buffer
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = data; //..send data
}

uint8_t receiveByte(void){
  loop_until_bit_is_set(UCSR0A, RXC0); //wait for incoming data
  return UDR0; //return register value
}

	//useful printing commands
void printString (const char myString[]){
  uint8_t i = 0;
  while (myString[i]) {
    transmitByte(myString[i]);
    i++;
  }
}

void readString(char myString[], uint8_t maxLength) {
  char response;
  uint8_t i;
  i = 0;
  while (i < (maxLength -1)) { //prevent over runs
    response = receiveByte();
    transmitByte(response); //echo

    if (response == '\r') { //enter marks the end
      break;
    }
    else {
      myString[i] = response; //add in a letter
      i++;
    }
  }
  myString[i] = 0; //terminate null character
}


void printByte(uint8_t byte) {
	//converts byte to a string of decimal text, sends it
  transmitByte('0' + (byte / 100));//hundreds
  transmitByte('0' + ((byte / 10) % 10)); //tens
  transmitByte('0' + (byte % 10)); //ones
}
void printWord(uint16_t word) {
  transmitByte('0' + (word / 10000)); //ten thousands
  transmitByte('0' + ((word / 1000) % 10)); //thousands
  transmitByte('0' + ((word / 100) %10)); //hundreds
  transmitByte('0' + ((word / 10) % 10)); //tens
  transmitByte('0' + (word % 10)); //ones
}
void printBinaryByte(uint8_t byte) {
	//prints a byte out in 1s and 0s
  uint8_t bit;
  for (bit = 7; bit < 255; bit --) {
    if (bit_is_set(byte, bit ))
    transmitByte('1');
  else
    transmitByte('0');
  }
}

//char nibbleToHex(uint8_t nibble);

char nibbleToHexCharacter(uint8_t nibble) {
	//converts 4 bits into hexadecimal
  if (nibble < 10) {
    return ('0' + nibble);
  }
  else {
    return ('A' + nibble - 10);
  }
}

void printHexByte(uint8_t byte) {
	//prints a byte out in hexadecimal
  uint8_t nibble;
  nibble = (byte & 0b11110000) >> 4;
  transmitByte(nibbleToHexCharacter(nibble));
  nibble = byte & 0b00001111;
  transmitByte(nibbleToHexCharacter(nibble));
}

uint8_t getNumber(void) {
	//gets a num 0-255 from the serial port
	//converts from string to number
  char hundreds = '0';
  char tens = '0';
  char ones = '0';
  char thisChar = '0';
  do { //shift over
    hundreds = tens;
    tens = ones;
    ones = thisChar;
    thisChar = receiveByte(); //get new char
    transmitByte(thisChar); //echo
  }
  while (thisChar != '\r'); //until type return
  return (100 * (hundreds -'0') + 10 * (tens - '0') + ones - '0');
}
