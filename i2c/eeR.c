// ---- Preamble ---- //
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include "USART.h"
#include "i2c.h"

// ---- Defines ---- //
#define eepromAddressWrite	0b10100000
#define eepromAddressRead      	0b10100001
#define eepromFirstWordAddress	0b00000001
#define eepromSecondWordAddress 0b00000011

// ---- Functions ---- //
int main (void) {
  uint8_t tempHighByte, tempLowByte;
  // ---- Inits ---- //
  clock_prescale_set(clock_div_1);
  initUSART();
  initI2C();
  printString("\r\n --- We're up and running, baby! --- \r\n");

  i2cStart();
  printString("\r\n --- Sending Dummy EEPROM Address + Write Bit --- \r\n");
  
  i2cSend(eepromAddressWrite);
  printString("\r\n --- Sending First Word Address --- \r\n");
  i2cSend(eepromFirstWordAddress);
  printString("\r\n --- Sending Second Word Address --- \r\n");
  i2cSend(eepromSecondWordAddress);
  
  i2cStart();
  printString("\r\n --- Started Read --- \r\n");

  printString("\r\n --- Sending EEPROM Address + Read Bit --- \r\n");
  i2cSend(eepromAddressRead);
    
  printString("\r\n --- Store High and Low Bytes --- \r\n");
  tempHighByte = i2cReadAck();
  tempLowByte = i2cReadNoAck();

  i2cStop();
  printString("\r\n --- Done --- \r\n");

  printString("\r\nHigh Byte: ");
  
  printByte(tempHighByte);
  
  if (tempLowByte & _BV(7)){
    printString(".S\r\n");
  }
  else {
    printString(".0\r\n");
  }
  // ---- Loop ---- //
  while(1) {
  }
  return(0);
}

