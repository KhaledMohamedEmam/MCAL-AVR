/* Inclusion */
#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_int.h"

void DIO_vWrtPinDir(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinDir){
	switch (A_u8PortNo){
	case DIO_PORTA:  WRT_BIT(DDRA, A_u8PinNo, A_u8PinDir); break;
	case DIO_PORTB:  WRT_BIT(DDRB, A_u8PinNo, A_u8PinDir); break;
	case DIO_PORTC:  WRT_BIT(DDRC, A_u8PinNo, A_u8PinDir); break;
	case DIO_PORTD:  WRT_BIT(DDRD, A_u8PinNo, A_u8PinDir); break;
	default:    /* EEROR */     break;
	}
}

void DIO_vWrtPinVal(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinVal){
	switch (A_u8PortNo){
	case DIO_PORTA:  WRT_BIT(PORTA, A_u8PinNo, A_u8PinVal); break;
	case DIO_PORTB:  WRT_BIT(PORTB, A_u8PinNo, A_u8PinVal); break;
	case DIO_PORTC:  WRT_BIT(PORTC, A_u8PinNo, A_u8PinVal); break;
	case DIO_PORTD:  WRT_BIT(PORTD, A_u8PinNo, A_u8PinVal); break;
	default:    /* EEROR */     break;
	}
}

u8 DIO_u8GetPinVal(u8 A_u8PortNo, u8 A_u8PinNo){
	u8 L_u8PinValue;
	switch (A_u8PortNo){
	case DIO_PORTA: L_u8PinValue = GET_BIT(PINA, A_u8PinNo); break;
	case DIO_PORTB: L_u8PinValue = GET_BIT(PINB, A_u8PinNo); break;
	case DIO_PORTC: L_u8PinValue = GET_BIT(PINC, A_u8PinNo); break;
	case DIO_PORTD: L_u8PinValue = GET_BIT(PIND, A_u8PinNo); break;
	default:    /* EEROR */     break;
	}
	return L_u8PinValue;
}
void DIO_vWrtPortDir(u8 A_u8PortNo, u8 A_u8PortDir )
{
	switch (A_u8PortNo){
	case DIO_PORTA:  DDRA=A_u8PortDir; break;
	case DIO_PORTB: DDRB=A_u8PortDir; break;
	case DIO_PORTC: DDRC=A_u8PortDir; break;
	case DIO_PORTD: DDRD=A_u8PortDir; break;
	default:    /* EEROR */     break;
	}
}
void DIO_vWrtPortVal(u8 A_u8PortNo, u8 A_u8PortVal)
{
	switch (A_u8PortNo){
	case DIO_PORTA:  PORTA=A_u8PortVal; break;
	case DIO_PORTB: PORTB=A_u8PortVal; break;
	case DIO_PORTC: PORTC=A_u8PortVal; break;
	case DIO_PORTD: PORTD=A_u8PortVal; break;
	default:    /* EEROR */     break;
	}
}
