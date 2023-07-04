/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :    LCD20x4    	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/


/*********************************************************************************/
/************************						**********************************/
/************************	  	 INCLUDE		**********************************/
/************************						**********************************/
/*********************************************************************************/
#define  F_CPU 8000000
#include  <util/delay.h>

/* Lib layer */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/* MCAL */
#include "../../MCAL/DIO/DIO_Interface.h"


#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
/* Global array that will store the custom charactars */
const u8 Copy_u8Pattern[] = LCD_Au8_CUSTOM_CHARACTAR ;

/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: LCD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize LCD								       	    **/
/*********************************************************************************/
void LCD_voidInit(void)
{
	_delay_ms(40);
	/* set the RS pin as output */
	DIO_u8SetPinDirection(LCD_u8CtrlPort,LCD_u8RSPin,DIO_u8_OUTPUT);
	/* set the RW pin as output */
	#ifdef LCD_u8RWPin
	DIO_u8SetPinDirection(LCD_u8CtrlPort,LCD_u8RWPin,DIO_u8_OUTPUT);
	#endif
	/* set the EN pin as output */
	DIO_u8SetPinDirection(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_OUTPUT);
	/* set the direction of data pins of the upper 4  */
	#if (LCD_u8Mood==4)
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D4Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D5Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D6Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D7Pin,DIO_u8_OUTPUT);
		LCD_voidSendInstruction(LCD_u8_FOUR_BITS_MODE);
		LCD_voidSendInstruction(LCD_u8_TOW_LINES_4BIT);
	#elif (LCD_u8Mood==8)
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D1Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D2Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D3Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D4Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D4Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D5Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D6Pin,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(LCD_u8DataPort,LCD_u8D7Pin,DIO_u8_OUTPUT);
		LCD_voidSendInstruction(LCD_u8_TOW_LINES_8BIT);
	#endif
	LCD_voidSendInstruction(LCD_u8_CLEAR_CLEAR);
	LCD_voidSendInstruction(LCD_u8_CRUSER_OFF);
	
	
	
}

/*********************************************************************************/
/* Function: LCD_voidSendInstruction                        				    **/
/* I/P Parameters: Copy_u8instruction						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Send a command "an instruction" to LCD			       	**/
/*********************************************************************************/
/* Copy_u8instruction Options: Instruction value assigned directly				**/
/*********************************************************************************/
void LCD_voidSendInstruction(u8 Copy_u8instruction)
{
	/*steps to send instruction*/
	/* 1_ make RS =0 */
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8RSPin,DIO_u8_LOW);
	/* 2_ set RW =0  but there are not RW in NTI kit*/
	#ifdef LCD_u8RWPin
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8RWPin,DIO_u8_LOW);
	#endif
	/* 3_ send the instruction to LCD*/
	
		/* send the First part of instruction */
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8instruction,4));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D5Pin,GET_BIT(Copy_u8instruction,5));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D6Pin,GET_BIT(Copy_u8instruction,6));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D7Pin,GET_BIT(Copy_u8instruction,7));
	#if (LCD_u8Mood==8)
		/* send the data at ones*/
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D1Pin,GET_BIT(Copy_u8instruction,0));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D2Pin,GET_BIT(Copy_u8instruction,1));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D3Pin,GET_BIT(Copy_u8instruction,2));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8instruction,3));
	#endif
	/* 4_SET EN = 1*/
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_HIGH);
	/*delay for processing Tdsw = 100ns*/
	_delay_us(1);
	/* 5_SET EN = 0*/
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_LOW);
	#if (LCD_u8Mood==4)
		/* send the second part of instruction */
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8instruction,0));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D5Pin,GET_BIT(Copy_u8instruction,1));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D6Pin,GET_BIT(Copy_u8instruction,2));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D7Pin,GET_BIT(Copy_u8instruction,3));
		/*SET EN = 1 to send the second part of instruction*/
		DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_HIGH);
		/*delay for processing Tdsw = 100ns*/
		_delay_us(1);
		/* 5_SET EN = 0*/
		DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_LOW);
		_delay_ms(2);
	#endif

	
	
}

/*********************************************************************************/
/* Function: LCD_voidWriteChar		                        				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a character "data" on LCD					       	**/
/*********************************************************************************/
/* Copy_u8Data Options: Character assigned directly								**/
/*********************************************************************************/
void LCD_voidWriteChar(u8 Copy_u8Data)
{
	/*steps to send instruction*/
	/* 1_ make RS =1 */
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8RSPin,DIO_u8_HIGH);
	/* 2_ set RW =0  but there are not RW in NTI kit*/
	#ifdef LCD_u8RWPin
	DIO_u8SetPinDirection(LCD_u8CtrlPort,LCD_u8RWPin,DIO_u8_LOW);
	#endif
	/* 3_ send the instruction to LCD*/
	#if (LCD_u8Mood==4)
		/* send the First part of instruction */
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8Data,4));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D5Pin,GET_BIT(Copy_u8Data,5));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D6Pin,GET_BIT(Copy_u8Data,6));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D7Pin,GET_BIT(Copy_u8Data,7));
	#elif (LCD_u8Mood==8)
		/* send the data at ones*/
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D1Pin,GET_BIT(Copy_u8Data,0));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D2Pin,GET_BIT(Copy_u8Data,1));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D3Pin,GET_BIT(Copy_u8Data,2));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8Data,3));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8Data,4));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D5Pin,GET_BIT(Copy_u8Data,5));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D6Pin,GET_BIT(Copy_u8Data,6));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D7Pin,GET_BIT(Copy_u8Data,7));
	#endif
	/* 4_SET EN = 1*/
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_HIGH);
	/*delay for processing Tdsw = 100ns*/
	_delay_us(1);
	/* 5_SET EN = 0*/
	DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_LOW);
	#if (LCD_u8Mood==4)
		/* send the second part of instruction */
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D4Pin,GET_BIT(Copy_u8Data,0));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D5Pin,GET_BIT(Copy_u8Data,1));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D6Pin,GET_BIT(Copy_u8Data,2));
		DIO_u8SetPinValue(LCD_u8DataPort,LCD_u8D7Pin,GET_BIT(Copy_u8Data,3));
		/*SET EN = 1 to send the second part of instruction*/
		DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_HIGH);
		/*delay for processing Tdsw = 100ns*/
		_delay_us(1);
		/* 5_SET EN = 0*/
		DIO_u8SetPinValue(LCD_u8CtrlPort,LCD_u8ENPin,DIO_u8_LOW);
		_delay_ms(2);
	#endif
}

/*********************************************************************************/
/* Function: LCD_voidWriteString	                        				    **/
/* I/P Parameters: *Copy_u8String, Copy_u8Size				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a string "array of characters" on LCD		       	**/
/*********************************************************************************/
/* *Copy_u8String Options: Passing the name of the Array directly				**/
/* Copy_u8Size Options: Size of the passed array								**/
/*********************************************************************************/
void LCD_voidSendString(char *Copy_u8String)
{
	u8 i =0;
	while( Copy_u8String[i] != '\0' )
	{
		LCD_voidWriteChar(Copy_u8String[i]);
		i++;
	}
}

/*********************************************************************************/
/* Function: LCD_VoidNumToString			                        			**/
/* I/P Parameters: Copy_u32Number				          					    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function turn the number to string to diplay on LCD			    **/
/*********************************************************************************/
/* Copy_u32Number Options: 0  _  4,294,967,295									**/
/*********************************************************************************/
void LCD_VoidNumToString(u32 Copy_u32Number)
{
	s8  Local_u8Counter =0;
	s8  Local_Au8Buffer[10]={0};
	u32 Local_u32CopyOfNum = Copy_u32Number;
	 do
	 {
		 	Local_u8Counter++;
			Local_Au8Buffer[Local_u8Counter]= (char)(Local_u32CopyOfNum % 10) ;
			Local_u32CopyOfNum /= 10;
		
	 }while  (Local_u32CopyOfNum > 0);
	for (;Local_u8Counter>0;Local_u8Counter--)
	{
		LCD_voidWriteChar(Local_Au8Buffer[Local_u8Counter] + '0');
	}

}
/*********************************************************************************/
/* Function: LCD_voidGotoXY			                        				    **/
/* I/P Parameters: Copy_u8Row, Copy_u8Column				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Goes to a specific location (r,c) on LCD			       	**/
/*********************************************************************************/
/* Copy_u8Row Options: 1 - 2 - 3 - 4												**/
/* Copy_u8Column Options: 0 --> 20												**/
/*********************************************************************************/
void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	if( (Copy_u8Row == 1) && (Copy_u8Column < 20) )		//Writing on Any grid resides on the 1st row
	{
		LCD_voidSendInstruction(0x80 + Copy_u8Column);	//0x80 is the address of the 1st location in the 1st row
	}
	else if ( (Copy_u8Row == 3) && (Copy_u8Column < 20) )
	{
		LCD_voidSendInstruction(0x80 + Copy_u8Column + 20 );
	}
	else if( (Copy_u8Row == 2) && (Copy_u8Column < 20) )//Writing on Any grid resides on the 2nd row
	{
		LCD_voidSendInstruction(0xC0 + Copy_u8Column);	//0xC0 is the address of the 1st location in the 1st row
	}
	else if ( (Copy_u8Row == 4) && (Copy_u8Column < 20) )
	{
		LCD_voidSendInstruction(0xC0 + Copy_u8Column + 20);
	}
	else
	{
		//Do Nothing
	}
}

/*********************************************************************************/
/* Function: LCD_voidClearDisplay	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                                				    **/
/* Desc:This Function Clears the whole LCD display						       	**/
/*********************************************************************************/
void LCD_voidClearDisplay()
{
	LCD_voidSendInstruction(0b00000001);	//sending Instruction to clear the whole display
}

/***********************************************************************************/
/* Function: LCD_voidWriteSpecialChar                        				      **/
/* I/P Parameters: *Copy_u8Pattern, Copy_u8PatternNumber ,Copy_u8Row,Copy_u8Column**/
/* Returns:it returns No thing                                				      **/
/* Desc:This Function writes a custom character on LCD					       	  **/
/***********************************************************************************/
/* Copy_u8Pattern Options: Character Pattern array								  **/
/* Copy_u8PatternNumber Options: Num of Pattern to be displayed					  **/
/* Copy_u8Row Options: 1 --> 4													  **/
/* Copy_u8Column Options: 0 --> 20												  **/
/***********************************************************************************/
void LCD_voidWriteSpecialChar(const u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column)
{
	/*Set CGRAM address */
	/*calculate the CGRAM address*/
	u8 Local_u8Adress=(Copy_u8PatternNumber*8);
	LCD_voidSendInstruction(Local_u8Adress+64);
	//                       address    +64th bit

	/*save the pattern in CGRAM address */
	/* or Write data to CGRAM or DDRAM */
	for (u8 i=0 ;i<8 ;i++)
	{
		LCD_voidWriteChar(Copy_u8Pattern[i+(Copy_u8PatternNumber*8)]);
		//the address counter counter AC will auto increment the next address
	}

	/*Set DDRAM Address */
	/*or go back to DDRAM to display the pattern*/
	LCD_voidGotoXY(Copy_u8Row ,Copy_u8Column );

	/* Read data from CGRAM or DDRAM*/
	/*or display the pattern*/
	LCD_voidWriteChar(Copy_u8PatternNumber); //instead of ASCII letter in CGROM
}
