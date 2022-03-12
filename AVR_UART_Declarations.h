
#ifndef AVR_UART_DECLARATIONS_H_
#define AVR_UART_DECLARATIONS_H_

#include <avr/io.h>
#include "AVR_UART_User_Selection.h"

#define MyUBRR ((FOSC/16)/BAUD)-1

void UART_INT(void);
unsigned char UART_Receive(void);
void UART_Transmit(unsigned char data);
void UART_Transmit_String(char * str);

#endif /* AVR_UART_DECLARATIONS_H_ */