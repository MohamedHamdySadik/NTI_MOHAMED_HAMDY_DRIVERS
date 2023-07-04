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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: DIO_voidSetPinValue	                        				    **/
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Value of a specific pin				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_LOW, DIO_u8_HIGH                               **/
/*********************************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && (Copy_u8Value == DIO_u8_LOW || Copy_u8Value == DIO_u8_HIGH) )
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8Value)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
				case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId); break;
			}
			break;
			
			case DIO_u8_PORTB:
			switch(Copy_u8Value)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId); break;
				case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId); break;
			}
			break;
			
			case DIO_u8_PORTC:
			switch(Copy_u8Value)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId); break;
				case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId); break;
			}
			break;
			
			case DIO_u8_PORTD:
			switch(Copy_u8Value)
			{
				case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId); break;
				case DIO_u8_LOW:  CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId); break;
			}
			break;	
		}	
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
		
	}
	return Local_u8ErrorState;
}

/*********************************************************************************/
/* Function: DIO_voidSetPinDirection	                        				**/
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8Direction  			    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function Sets the Direction of a specific pin     		       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Direction  Options: DIO_u8_INPUT, DIO_u8_OUTPUT                       **/
/*********************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && (Copy_u8Direction == DIO_u8_INPUT || Copy_u8Direction == DIO_u8_OUTPUT) )
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
				switch(Copy_u8Direction)
				{
					case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId); break;
					case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId); break;
				}
			break;
			
			case DIO_u8_PORTB:
			switch(Copy_u8Direction)
			{
				case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId); break;
				case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId); break;
			}
			break;
			
			case DIO_u8_PORTC:
			switch(Copy_u8Direction)
			{
				case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId); break;
				case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId); break;
			}
			break;
			
			case DIO_u8_PORTD:
			switch(Copy_u8Direction)
			{
				case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId); break;
				case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId); break;
			}
			break;	
		}	
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
		
	}
	return Local_u8ErrorState;
	
}





/*********************************************************************************/
/* Function: DIO_voidGetPinValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, Copy_u8PinId				          		    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function gets the Value of a given pin					       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_pu8ReturnedPinValue Options: The variable that store the pin value      **/
/*********************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_pu8ReturnedPinValue)
{
		u8 Local_u8ErrorState = STD_TYPES_OK;
		u8 Local_u8PinValue;
		if (Copy_u8PortId <= DIO_u8_PORTD && Copy_u8PinId <= DIO_u8_PIN7 && Copy_pu8ReturnedPinValue!= NULL)
		{
			switch(Copy_u8PortId)
			{
				case DIO_u8_PORTA: Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId); break;
				case DIO_u8_PORTB: Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId); break;
				case DIO_u8_PORTC: Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId); break;
				case DIO_u8_PORTD: Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId); break;
			}
			if (Local_u8PinValue == 0)
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_LOW;
			}
			else
			{
				*Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
			}
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		
		return Local_u8ErrorState;
	
}




/*********************************************************************************/
/* Function: DIO_voidSetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Value                               **/
/* Returns:it returns u8 the error state                     				    **/
/* Desc:This Function Sets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;
	switch(Copy_u8PortId)
	{
		case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8Value;break;
		case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8Value;break;
		case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8Value;break;
		case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8Value;break;
		default:Local_u8ErrorState =STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
	
}




/*********************************************************************************/
/* Function: DIO_voidSetPortDirection                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Direction                           **/
/* Returns:it returns u8 Error state                           				    **/
/* Desc:This Function Sets the Direction of a specific port			       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  DIO_u8_OUTPUT, DIO_u8_INPUT                          **/
/*********************************************************************************/
u8 DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u8PortId <= DIO_u8_PORTD && (Copy_u8Direction == DIO_u8_OUTPUT || Copy_u8Direction == DIO_u8_INPUT))
	{
		switch(Copy_u8PortId)
		{
				case DIO_u8_PORTA:
				switch(Copy_u8Direction)
				{
					case DIO_u8_OUTPUT: DIO_u8_DDRA_REG=0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRA_REG=0x00; break;
				}
				break;
				
				case DIO_u8_PORTB:
				switch(Copy_u8Direction)
				{
					case DIO_u8_OUTPUT: DIO_u8_DDRB_REG=0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRB_REG=0x00; break;
				}
				break;
				
				case DIO_u8_PORTC:
				switch(Copy_u8Direction)
				{
					case DIO_u8_OUTPUT: DIO_u8_DDRC_REG=0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRC_REG=0x00; break;
				}
				break;
				
				case DIO_u8_PORTD:
				switch(Copy_u8Direction)
				{
					case DIO_u8_OUTPUT: DIO_u8_DDRD_REG=0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRD_REG=0x00; break;
				}
				break;
		}
	}
	else 
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}




/*********************************************************************************/
/* Function: DIO_voidGetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId                                                **/
/* Returns:it returns u8 of value if the port                                   **/
/* Desc:This Function gets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId, u8* Copy_pu8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_pu8PortValue != NULL)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA: *Copy_pu8PortValue=DIO_u8_PINA_REG; break;
			case DIO_u8_PORTB: *Copy_pu8PortValue=DIO_u8_PINB_REG; break;
			case DIO_u8_PORTC: *Copy_pu8PortValue=DIO_u8_PINC_REG; break;
			case DIO_u8_PORTD: *Copy_pu8PortValue=DIO_u8_PIND_REG; break;
			default: Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
	
}

/*********************************************************************************/
/* Function: DIO_voidInit	                      			  				    **/
/* I/P Parameters: NO THING                  	                                **/
/* Returns:it returns NO THING RETURNED                                         **/
/* Desc:This Function to intialization all ports directions and values    	    **/
/*********************************************************************************/

void DIO_voidInit(void)
{
	DIO_u8_DDRA_REG = CONC(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);
	DIO_u8_DDRB_REG = CONC(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION); 
	DIO_u8_DDRC_REG = CONC(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);
	DIO_u8_DDRD_REG = CONC(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);
	DIO_u8_PORTA_REG =CONC(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);
	DIO_u8_PORTB_REG =CONC(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
	DIO_u8_PORTC_REG =CONC(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);
	DIO_u8_PORTD_REG =CONC(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}	
	