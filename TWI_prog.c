#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"TWI_int.h"
#include"TWI_priv.h"
#include"TWI_reg.h"
void MTWI_vInit(void)
{
// interrupt enable or disable
	CLR_BIT(TWCR,TWIE);
//bit rate
    TWBR=10;
}
u8 MTWI_u8SendStartCondition(void)
{
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
	return (TWSR&0xf8);
}
u8 MTWI_u8SendRepeatedStartCondition(void)
{
	SET_BIT(TWCR,TWINT);
		SET_BIT(TWCR,TWSTA);
		SET_BIT(TWCR,TWEN);
		while(GET_BIT(TWCR,TWINT)==0);
		return (TWSR&0xf8);
}
u8 MTWI_u8SendSlaveAddressRW(u8 A_u8sla,u8 A_u8RW)
{
TWDR=(A_u8sla<<1)|(A_u8RW);
SET_BIT(TWCR,TWEN);
SET_BIT(TWCR,TWINT);
CLR_BIT(TWCR,TWSTA);
while(GET_BIT(TWCR,TWINT)==0);
	return (TWSR&0xf8);
}
u8 MTWI_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	switch(A_u8Ack)
	{
	case TWI_ACK:
		SET_BIT(TWCR,TWEA);
		break;
	case TWI_NACK:
		CLR_BIT(TWCR,TWEA);
		break;
	}
	while(GET_BIT(TWCR,TWINT)==0);
	*A_pu8Byte=TWDR;
	return (TWSR&0xf8);
}
u8 MTWI_u8SendByte(u8 A_u8Byte)
{
TWDR=A_u8Byte;
SET_BIT(TWCR,TWEN);
SET_BIT(TWCR,TWINT);
SET_BIT(TWCR,TWSTO);
while(GET_BIT(TWCR,TWINT)==0);
	return (TWSR&0xf8);

}
u8 MTWI_u8SendStopCondition(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTO);
	return (TWSR&0xf8);

}
u8 MTWI_u8GetStatus(void)
{
	return (TWSR&0xf8);
}
