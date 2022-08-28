#include"EXTI_confg.h"
#include"EXTI_int.h"
#include"EXTI_priv.h"
#include"EXTI_reg.h"
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
void MEXTI_Enable(u8 A_u8_IntNo)
{
	switch(A_u8_IntNo)
	{
	case INT_0:
		//choose sense mode
		MCUCR=(MCUCR&INT0_SenseMask)|INT0_sense;
		//activate the INT0
		SET_BIT(GICR,INT0);
		break;
     case INT_1:
 		//choose sense modefor INT1
 		MCUCR=(MCUCR&INT1_SenseMask)|((INT0_sense)<<2);
 		//activate the INT0
 		SET_BIT(GICR,INT1);
 		break;

    case INT_2:
		//choose sense modefor INT1
		MCUCSR=(MCUCSR&INT2_SenseMask)|INT2_sense;
		//activate the INT0
		SET_BIT(GICR,INT2);
		break;
	}
}
void MEXTI_Disable(u8 A_u8_IntNo)
{
	switch(A_u8_IntNo)
	{
	case INT_0:
		CLR_BIT(GICR,INT0);
		break;
	case INT_1:
		CLR_BIT(GICR,INT1);
		break;
	case INT_2:
		CLR_BIT(GICR,INT2);
		break;

	}
}


