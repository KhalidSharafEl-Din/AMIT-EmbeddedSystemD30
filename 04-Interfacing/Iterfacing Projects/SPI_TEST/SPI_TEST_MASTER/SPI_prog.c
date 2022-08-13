#include "STD_types.h"
#include "BIT_Math.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_int.h"

void SPI_voidInit(void)
{
	// master
	SET_BIT(SPCR , 4);
	
	//LSB
	SET_BIT(SPCR , 5);
	
	//POL Idle low
	CLEAR_BIT(SPCR , 3);
	
	//phase Leading
	CLEAR_BIT(SPCR , 2);
	
	// speed Fosc / 4
	CLEAR_BIT(SPCR , 0);
	CLEAR_BIT(SPCR , 0);
	CLEAR_BIT(SPSR , 0);
	
	// disable interrupt
	SPI_voidDisable();
	
	//enable spi
	SET_BIT(SPCR , 6);
}
u8 SPI_u8DataTransfere(u8 Local_u8Data)
{
	SPDR = Local_u8Data;
	while(GET_BIT(SPSR , 7) == 0);
	return SPDR;
}

void SPI_voidEnable(void)
{
	SET_BIT(SPCR,7);
}

void SPI_voidDisable(void)
{
	CLEAR_BIT(SPCR,7);
}