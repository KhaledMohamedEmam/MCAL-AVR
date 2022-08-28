
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"timer0_reg.h"
#include"timer_priv.h"
#include"timer_confg.h"
#include"timer_int.h"
#include"util/delay.h"
void (*Callback_T0_Normal)(void)=(void*)0;
void (*Callback_T0_CTC)(void)=(void*)0;
void(*icu_func)(void)=(void*)0;
void Timer0_voidInit()
{
	//select mode
TCCR0=(TCCR0&Mode_Mask)|Timer0_PreScaler;
//enable interrupt
#if (Timer0_Mode==Normal)
SET_BIT(TIMSK,TOIE0);
CLR_BIT(TIMSK,OCIE0);
#elif (Timer0_Mode==CTC)
SET_BIT(TIMSK,OCIE0);
CLR_BIT(TIMSK,TOIE0);
#endif
// set presercaler
TCCR0=(TCCR0&ps_Mask)|Timer0_PreScaler;
}

void Timer0Normal_voidGetFunc(void(*Argument)(void))
{

	Callback_T0_Normal=Argument;
}
void Timer0_Preload(u8 A_u8PreloadValue)
{
TCNT0=A_u8PreloadValue;
}
void Timer1_Preload(u8 A_u8PreloadValue)
{
	TCNT1=A_u8PreloadValue;
}
void Timer0_set_ocr(u8 A_u8SetValue)
{
OCR0=A_u8SetValue;
}

void Timer0CTC_voidGetFunc(void(*Argument)(void))
{
Callback_T0_CTC=Argument;
}

void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{

	Callback_T0_Normal();
}
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{

	Callback_T0_CTC();
}
void Timer1_FPWM_vInit()
{
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);
	//select mode
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//select prescaler
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}
void Set_Ocr1A(u16 A_u16Value)
{
	OCR1A=A_u16Value;
}
void Set_ICR1(u16 A_u16Value)
{
	ICR1=A_u16Value;
}
void servo_rotate(u16 angle)
{
	Set_Ocr1A((((1000*angle)/180)+999));

}
void timer0_FPWMInit()
{
 //set fpwm
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// set on top compare on match
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	//set timer0 pres
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}
void timer1_Normal_init(void)
{
	//select normal mode
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	//select prescaler
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

}
u16 getTimer1Count(void)
{
	return TCNT1;
}
void Timer1_ICU_Init(void)
{
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
//set rising edge
	SET_BIT(TCCR1B,ICES1);
//enable icu interrupt
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_SetEdge(u8 triger)
{
if(triger==rising)
{
	SET_BIT(TCCR1B,ICES1);
}
else if(triger==falling)
{
	CLR_BIT(TCCR1B,ICES1);
}
}
void Timer1_ICUDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
u16 getIcrValue(void)
{
	return ICR1;
}
void IcuEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void SetIcrCallBack(void*(funccc)(void))
{
icu_func=funccc;
}
void __vector_6(void) __attribute__ ((signal));
void __vector_6(void)
{

	icu_func();
}

