#include

#define MYUBBR FOSCI/16/BAUD-1

int main(void) {
	...
	USART_Init(MYUBBR)
	...

void USART_Init (unsigned int ubbr)
{
	//Set baud rate
	UBRR0H = (unsigned char) (ubrr>>8);
	UBRR0L = (unsigned char)  ubrr;
	//Enable Receiver and Transmitter
	UCSRB  = (1<<RXEN) | (1<<TXEN);
	//Set frame format, 8data, 2stop bit
	UCSRC  = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
}
//Sending frames
void USART_Transmit(unsigned char data)
{
	//Wait for empty Transmit buffer
	while ( !(UCSRA & (1<<UDRE)) );
	//Put data into buffer
	UDR = data;
}

//Receiving frames
unsigned char USART_Recieve (void)
{
	while ( !(UCSRA & (1<<RXE)) );
	//Get and return recieved data from buffer
	return UDR;

}
}


