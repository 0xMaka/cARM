//usart header file
#ifndef BAUD //incase undefined in Makefile
#define BAUD 9600 //safe baud rate
#endif
	//these are defined for convenience
#define USART_HAS_DATA 	bit_is_set(UCSR0A, RXC0)
#define USART_READY 	bit_is_set(UCSR0A, UDRE0)
	/* takes the defined baud rate and f_cpu,
	calculates the bit clock multiplier,
	and configures the hardware usart */
void initUSART(void);
	/* blocking transmit and recieve functions.
	When you call receiveByte() your program
	will hang until data comes through.
	we'll improve on this later */
void transmitByte(uint8_t data);
uint8_t receiveByte(void);

void printString (const char myString[]);
	//utility function to transmit an entire string from ram
void readString(char myString[], uint8_t maxLength);
	/* define a string variable, pass it to this
	function.
	The string will contain whatever you typed over the serial. */

void printByte(uint8_t byte);
	//print a byte out as it's 3 digit ascii equivalant
void printWord(uint16_t word);
        //print a word (16-bits) out as it's 5 digit ascii equivalant

void printBinaryByte(uint8_t byte);
	//prints a byte out in 1s and 0s

char nibbleToHex(uint8_t nibble);
char nibbleToHexCharacter(uint8_t nibble);
void printHexByte(uint8_t byte);
	//prints a byte out in hexidecimal

uint8_t getNumber(void);
	//takes up to 3 ascii digit, converts 'em to a byte
