#define USART_BAUDRATE 9600
#define UBBR_VALUE (((F_CPU / (USART_BAUDRATE * 16 ))) - 1)

//FOSCI/16/BAUD-1

void USART_Init (uint8_t UBBR_VALUE)
{
	//Set baud rate
	UBRR0H = (uint8_t(UBBR_VALUE>>8);
	UBRR0L = (uint8_t) UBBR_VALUE;
	
	UBBR0 = UBBR_VALUE;

	//Enable Receiver and Transmitter
	UCSRB  = (1<<RXEN) | (1<<TXEN);
	//Set frame format, 8 data, no parity, 1 stop bit
	UCSRC  = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
}

//Sending frames
void USART_Transmit(uint8_t u8data)
{
	//Wait for empty Transmit buffer
	while ( !(UCSRA & (1<<UDRE)) );
	//Put data into buffer
	UDR = u8data;
}

//Receiving frames
uint8_t USART_Recieve (void)
{
	while ( !(UCSRA & (1<<RXE)) );
	//Get and return recieved data from buffer
	return UDR;
}

int main () {
	while (1) {

	//Recieve data
	u8TempData = USARTRecieveByte();
	//Increment recieved data
	u8TempData++;
	//Send back to terminal
	USARTSendByte(u8TempData);
	}
}


