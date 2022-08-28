#include"../../LIB/STD_TYPES.h"
void UART_init(void);
u16 UART_u8RseceiveSynch(void);
void UART_voidTransmitDataSynch(u16 A_Data);
void UART_u8TransmitString(u8*string);
