#include"../../LIB/STD_TYPES.h"
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_HIGH   1
#define DIO_LOW    0

void DIO_vWrtPinDir(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinDir);

void DIO_vWrtPinVal(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinVal);

u8 DIO_u8GetPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

void DIO_vWrtPortDir(u8 A_u8PortNo, u8 A_u8PortDir );

void DIO_vWrtPortVal(u8 A_u8PortNo, u8 A_u8PortVal);




#endif /* MCAL_DIO_DIO_INT_H_ */
