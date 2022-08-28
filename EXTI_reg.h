//define registers
#define MCUCR *((u8*)0x55)
#define GICR *((u8*)0x5B)
#define GIFR *((u8*)0x5A)
#define MCUCSR *((u8*)0x54)
//define bits for MCUCR
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
//define bits for GICR
#define INT2 5
#define INT0 6
#define INT1 7
//define bits for GIFR
#define INTF2 5
#define INTF0 6
#define INTF1 7
//define bits for MCUCSR
#define ISC2

