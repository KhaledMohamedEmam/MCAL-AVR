#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include "ADC_confg.h"
#include "ADC_int.h"
#include "ADC_priv.h"
#include "ADC_reg.h"
void M_ADC_vINIt()
{
	//choose the refrence voltage
	ADMUX=((ADMUX)&~(RefrenceMask))|RefrecneSelection;
	//choose adjust
	ADMUX=(ADMUX&~(AdjustMask))|AdjustDirection;
	//choose the prescaler
	ADCSRA=(ADCSRA&~(PrescalerMask))|PrescalerSelection;
	//enable the adc
	SET_BIT(ADCSRA,ADEN);

}
u16 M_ADC_u16ReadDigital(u8 A_u8ChannelId)
{
//choose channel
	ADMUX=(ADMUX&~(ChannelMask))|A_u8ChannelId;
	// start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait untill conversion is done
	while(GET_BIT(ADCSRA,ADIF)==0)
	{

	}
	//get the digital value
	return ADCHL;
}
