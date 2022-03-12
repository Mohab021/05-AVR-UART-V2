
#include "AVR_UART_Declarations.h"

void UART_INT()
{
	//My_UBRR is Integer (16-bits) so we want to cast it as a 2 char(s) of 8-bits for each to store in UBRR(Low & High - 1 byte(8-bits) for each)
	UBRRL = (unsigned char) (MyUBRR); //store the low 8-bits of the MyUBRR in UBRR-LOW
	UBRRH = (unsigned char) (MyUBRR>>8); //store the high 4-bits of the MyUBRR in UBRR-HIGH (the last 4-bits are reserved)
	UCSRB |= (1<<3) | (1<<4); //Enable transmit and enable RXENn TXENn
	UCSRC |= (1<<1) | (1<<2); //Frame with 8-bit data (UCSZn0 UCSZn1), 1 stop bit, No parity, ASynchronous mode 
}

unsigned char UART_Receive()
{
	while( !(UCSRA & (1<<7)) ) ;	//Wait until the Receive Buffer is full (RXCn), it has to equal 1
	return UDR; //we read the data from UDR
}

void UART_Transmit(unsigned char data)
{
	while( !(UCSRA & (1<<5)) ) ;	//Wait until the Transmit Buffer is empty (UDREn), it has to equal 1
	UDR = data; //we store the data in UDR
}

void UART_Transmit_String(char * str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		UART_Transmit(str[i]);
		i++;
	}
}
