
#define Channel_ID0 0
#define Channel_ID1 1
#define Channel_ID2 2
#define Channel_ID3 3
#define Channel_ID4 4
#define Channel_ID6 6
#define Channel_ID7 7

// typedef enum
// {
//	 Channel_ID0=0,
//	 Channel_ID1,
//	 Channel_ID2,
//	 Channel_ID3,
//	 Channel_ID4,
//	 Channel_ID5,
//	 Channel_ID6,
//	 Channel_ID7,
//
//
// }Chanel_t;
#define RefrenceMask 0b11000000
#define PrescalerMask 0b00000111
#define ChannelMask 0b00011111
#define AdjustMask 0b00100000
void M_ADC_vINIt();
u16 M_ADC_u16ReadDigital(u8 A_u8ChannelId);
