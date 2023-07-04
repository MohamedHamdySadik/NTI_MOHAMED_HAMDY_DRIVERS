/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   14/6/2023       ******************/
/**********************  SWC     :      GPI      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*********************************************************************************/
/************************						**********************************/
/************************	  	 INCLUDE		**********************************/
/************************						**********************************/
/*********************************************************************************/
/* Lib layer */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/* MCAL */
#include "MCAL/GPI/GPI_Interface.h"
#include "MCAL/GPI/GPI_Private.h"
#include "MCAL/GPI/GPI_Config.h"

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize General Interrupt Enable			       	    **/
/*********************************************************************************/
void GPI_voidInit   (void)
{
	#if GPI_u8_MODE == GPI_u8_ENABLE
		SET_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #else
		CLR_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #endif
}

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidEnable (void)
{
	SET_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidDisable(void)
{
	CLR_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}
