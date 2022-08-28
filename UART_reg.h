#define UCSRA *(((volatile u8*)0x2B))
#define UCSRB *(((volatile u8*)0x2A))
#define UCSRC *(((volatile u8*)0x40))
#define UBRRL *(((volatile u8*)0x29))
#define UDR *(((volatile u8*)0x2C))
#define RXC  DIO_PIN7 //UCSRA
#define TXC  DIO_PIN6
#define UDRE DIO_PIN5
#define FE  DIO_PIN4
#define DOR  DIO_PIN3
#define PE  DIO_PIN2
#define U2X  DIO_PIN1
#define MPCM  DIO_PIN0
#define TXB8  DIO_PIN0 //UCSRB
#define RXB8  DIO_PIN1
#define UCSZ2 DIO_PIN2
#define TXEN  DIO_PIN3
#define RXEN  DIO_PIN4
#define UDRIE DIO_PIN5
#define TXCIE DIO_PIN6
#define RXCIE  DIO_PIN7
#define UCPOL  DIO_PIN0 //UCSRC
#define UCSZ0  DIO_PIN1
#define UCSZ1  DIO_PIN2
#define USBS  DIO_PIN3
#define UPM0  DIO_PIN4
#define UPM1  DIO_PIN5
#define UMSEL  DIO_PIN6
#define URSEL  DIO_PIN7
