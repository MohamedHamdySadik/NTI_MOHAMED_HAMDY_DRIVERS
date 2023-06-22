/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :   DIO_PROGRAM     ******************/
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
#include "DIO/DIO_Interface.h"

/* MCAL */
#include "SS/SS_Interface.h"
#include "SS/SS_Config.h"
#include "SS/SS_Private.h"

/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: SS_u8DisplayNum	                        					     */
/* I/P Parameters: Copy_u8Num				          		  				     */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8Num Options:0,1,2,3,4,5,6,7,8,9 										 */
/*********************************************************************************/
u8 SS_u8DisplayNum(u8 Copy_u8Num)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_Au8SSPorts [SS_u8_PORTS_NUM]=SS_Au8_PORTS;
	u8 Local_Au8SSPins [SS_u8_PINS_NUM]= SS_Au8_PINS;
	u8 Local_u8Counter;
	if (Copy_u8Num <= 9)
	{
		for(Local_u8Counter=0;Local_u8Counter<SS_u8_PORTS_NUM;Local_u8Counter++)
		{
			DIO_u8SetPinValue(Local_Au8SSPorts[Local_u8Counter],Local_Au8SSPins[Local_u8Counter],GET_BIT(Copy_u8Num,Local_u8Counter) );
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
}

/*********************************************************************************/
/* Function: SS_u8Intial	                        						     */
/* I/P Parameters: Nothing				          		  					     */
/* Returns:it returns Nothing  			                          				 */
/* Desc:This Function initialization seven segment				      		     */
/*********************************************************************************/
void SS_u8Intial(void)
{
	u8 Local_Au8SSPorts [SS_u8_PORTS_NUM]=SS_Au8_PORTS;
	u8 Local_Au8SSPins [SS_u8_PINS_NUM]= SS_Au8_PINS;
	u8 Local_Au8_SSENPorts[SS_u8_SS_NUM] =SS_Au8_EN_PORTS;
	u8 Local_Au8_SSENPins[SS_u8_SS_NUM] =SS_Au8_EN_PINS;
	u8 Local_u8Counter;
	for(Local_u8Counter=0;Local_u8Counter<SS_u8_PORTS_NUM;Local_u8Counter++)
	{
		DIO_u8SetPinDirection(Local_Au8SSPorts[Local_u8Counter],Local_Au8SSPins[Local_u8Counter],DIO_u8_OUTPUT );
		
	}
	for(Local_u8Counter=0;Local_u8Counter<SS_u8_SS_NUM;Local_u8Counter++)
	{
		DIO_u8SetPinDirection(Local_Au8_SSENPorts[Local_u8Counter],Local_Au8_SSENPins[Local_u8Counter],DIO_u8_OUTPUT);	
		DIO_u8SetPinValue(Local_Au8_SSENPorts[Local_u8Counter],Local_Au8_SSENPins[Local_u8Counter],DIO_u8_HIGH);
	}
	
}

/*********************************************************************************/
/* Function: SS_u8Enable	                        					   		 */
/* I/P Parameters: Copy_u8SS_ENABLE_Num				          		  			 */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8SS_ENABLE_Num Options: MAX Number of seven segment in system 			 */
/*********************************************************************************/
u8 SS_u8Enable(u8 Copy_u8SS_ENABLE_Num)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_Au8_SSENPorts[SS_u8_SS_NUM] =SS_Au8_EN_PORTS;
	u8 Local_Au8_SSENPins[SS_u8_SS_NUM] =SS_Au8_EN_PINS;
	if (Copy_u8SS_ENABLE_Num <= SS_u8_SS_NUM)
	{
		DIO_u8SetPinValue(Local_Au8_SSENPorts[Copy_u8SS_ENABLE_Num],Local_Au8_SSENPins[Copy_u8SS_ENABLE_Num],DIO_u8_LOW);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

/*********************************************************************************/
/* Function: SS_u8Disable	                        					  	     */
/* I/P Parameters: Copy_u8SS_DISABLE_Num				          		  		 */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8SS_DISABLE_Num Options:MAX Number of seven segment in system  		 */
/*********************************************************************************/
u8 SS_u8Disable(u8 Copy_u8SS_DISABLE_Num)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_Au8_SSENPorts[SS_u8_SS_NUM] =SS_Au8_EN_PORTS;
	u8 Local_Au8_SSENPins[SS_u8_SS_NUM] =SS_Au8_EN_PINS;
	if (Copy_u8SS_DISABLE_Num <= SS_u8_SS_NUM)
	{
		DIO_u8SetPinValue(Local_Au8_SSENPorts[Copy_u8SS_DISABLE_Num],Local_Au8_SSENPins[Copy_u8SS_DISABLE_Num],DIO_u8_HIGH);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
}