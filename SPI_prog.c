#include"SPI_int.h"
#include"../DIO/DIO_int.h"
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"SPI_reg.h"
void SPI_vidMasterInit()
{
// select prescaler by 4
CLR_BIT(SPCR,SPR0);
CLR_BIT(SPCR,SPR1);
//select data order
CLR_BIT(SPCR,DORD);
//master/slave slect
SET_BIT(SPCR,MSTR);
//select clock polarity
CLR_BIT(SPCR,CPOL);
//set clock phase
CLR_BIT(SPCR,CPHA);
//enable the spi
SET_BIT(SPCR,SPE);
}
void SPI_vidSlvInit()
{
	//select clock polarity
	CLR_BIT(SPCR,CPOL);
	//set clock phase
	CLR_BIT(SPCR,CPHA);
	//select data order
	CLR_BIT(SPCR,DORD);
	//master/slave slect
	CLR_BIT(SPCR,MSTR);
	//enable the spi
	SET_BIT(SPCR,SPE);
}
u8 SPI_vidTranrecive(u8 copy_u8Data)
{

	SPDR=copy_u8Data;
	while(GET_BIT(SPSR,SPIF)==0);
return SPDR;
}
void SPI_vidTranrecive_String(u8*ptr_in,u8*ptr_out)
{
	u8 counter=0;
	while(ptr_in[counter]!='/0')
	{
		ptr_out[counter]=SPI_vidTranrecive(ptr_in[counter]);
	}
}
