
//define registers
#define ADMUX *(((volatile u8*)0x27))
#define ADCSRA *(((u8*)0x26))
#define ADCHL *(((u16*)0x24))
#define SFIOR *(((u8*)0x50))
//define pins
//bits for ADMUX:
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7
//bits for ACSRA
#define  ADPS0 0
#define  ADPS1 1
#define  ADPS2 2
#define  ADIE 3
#define  ADIF 4
#define  ADATE 5
#define  ADSC 6
#define  ADEN 7
//bits for SFIOR
#define PSR10 0
#define PSR2 1
#define PUD 2
#define ACME 3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7
