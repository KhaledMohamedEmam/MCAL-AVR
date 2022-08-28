#include"UART_int.h"
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"UART_reg.h"
#include"../DIO/DIO_int.h"
void UART_init(void)
{
	u8 y=0;
	SET_BIT(y,URSEL); // choose
	CLR_BIT(y,UMSEL);
	CLR_BIT(y,USBS);
	CLR_BIT(y,UPM0);
	CLR_BIT(y,UPM1);
	SET_BIT(y,UCSZ0);
	SET_BIT(y,UCSZ2);
	UCSRC=y;
	UBRRL=51;
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}
u16 UART_u8RseceiveSynch(void)
{
	while(GET_BIT(UCSRA,UDRE)!=1);
	return UDR;
}
void UART_voidTransmitDataSynch(u16 A_Data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=A_Data;
}
void UART_u8TransmitString(u8*string)
{
	u8 counter=0;
	while(string[counter]!='\0')
	{
		while(GET_BIT(UCSRA,UDRE)==0);
		UDR=string[counter];
		counter++;
	}
}
