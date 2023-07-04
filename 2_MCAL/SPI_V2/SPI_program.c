/******************************************************************/
/******************************************************************/
/******************************************************************/
/*********		Author: Amgad Samir			***********************/
/*********		Component: SPI				***********************/
/*********		Layer: MCAL					***********************/
/*********		Version: 1.00				***********************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"

void SPI_voidInitMaster(void)
{
	/*Set master node*/
	SET_BIT(SPCR,SPCR_MSTR);
	
	/*clock speed: system frequency divided by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);

	/*SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Set Salve node*/
	CLR_BIT(SPCR,SPCR_MSTR);
	
	/*SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send the data*/
	SPDR = Copy_u8Data;
	
	/*wait until transfer is complete*/
	while((GET_BIT(SPSR,SPSR_SPIF))==0);

	/*return the received data*/
	return SPDR;
}
