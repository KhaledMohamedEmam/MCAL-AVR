#include"../../LIB/STD_TYPES.h"
#include"GIE_Ref.h"
#include"../../LIB/BIT_MATH.h"
void GIE_voidEnable()
{
	SET_BIT(SREG,GIE);
}
void GIE_voidDis()
{
	CLR_BIT(SREG,GIE);
}
