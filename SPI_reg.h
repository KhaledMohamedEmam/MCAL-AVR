#ifndef MCAL_SPI_MSPI_REG_H_
#define MCAL_SPI_MSPI_REG_H_
#define SPCR *(((volatile u8*)0x2D))
#define SPSR *(((volatile u8*)0x2E))
#define SPDR *(((volatile u8*)0x2F))
 #define SPIE 7     //SPCR REG,INTERRUPT ENABLE
 #define SPE 6      //if=1, spi is enabled
 #define DORD 5    //if=1,LSB is transmitted first, if 0 MSB
 #define MSTR 4    //MASTER,SLAVE SELECT. if=1 master, if=0 slave
 #define CPOL 3    //clk polarity, if=1, high in idle state
 #define CPHA 2    //msh fhma
 #define SPR1 1    //clk rate select
 #define SPR0 0
 #define SPIF 7 //SPSR, SPI interrupt flag,=1 when serial transfere is complete
 #define WCOL 6 //=1 when SPDR is beimg written during data transfer
 #define SPI2X 0 //if =1, speed is doubled
 #define MSB 7 //SPDR elbn2l 3leh el data
 #define LSB 0
#endif /* MCAL_SPI_MSPI_REG_H_ */
