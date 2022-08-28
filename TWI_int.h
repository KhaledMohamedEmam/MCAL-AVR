#define TWI_Write 0
#define TWI_Read  1
#define TWI_ACK 1
#define TWI_NACK 0
void MTWI_vInit(void);
u8 MTWI_u8SendStartCondition(void);
u8 MTWI_u8SendSlaveAddressRW(u8 A_u8sla,u8 A_u8RW);
u8 MTWI_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack);
u8 MTWI_u8SendByte(u8 A_u8Byte);
u8 MTWI_u8SendStopCondition(void);
u8 MTWI_u8GetStatus(void);
void MTWI_vSetBitRate(u32 A_u32BitRate);
void MTWI_vSetSlaveAddress(u8 A_A_u8OwnSla);
u8 MTWI_u8SendRepeatedStartCondition(void);
