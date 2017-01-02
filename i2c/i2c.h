//functions for i2c communication
#include<avr/io.h>
void initI2C(void);
  //sets pullups and initialises bus speed

void i2cWaitForComplete(void);
  //waits until the hardware sets TWINT flag

void i2cStart(void);
  //send a start codition (sets TWISTA)

void i2cStop(void);
  //sends a stop condition (sets TWSTO)

void i2cSend(uint8_t data);
  //loads data, sends it, waiting for competion

uint8_t i2cReadAck(void);
  //read in from slave sending ACK when done (sets TWEA)

uint8_t i2cReadNoAck(void);
  //read in from slave sending NOACK when done (no TWEA)


