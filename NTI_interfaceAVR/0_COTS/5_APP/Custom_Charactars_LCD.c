
/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   21/6/2023       ******************/
/**********************  SWC     :    HAMOKSHA   	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/
#define  F_CPU 16000000
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "HAL/KYP/KEYPAD_Interface.h"
#include "HAL/SS/SS_Interface.h"
#include "HAL/LCD/LCD_Interface.h"


/* custom characture in array  pattarn 1_ HAMOKSHA RISE HAND 
									   2_ HAMOKSHA LOW HAND 
									   3_ CHEAK 
									   4_SKULL

*/
 const u8 Copy_u8Pattern[]={0x0E,
                            0x04,
                            0x04,
                            0x0E,
                            0x15,
                            0x0A,
                            0x0A,
                            0x0E,
                            0x0E,
                            0x04,
                            0x15,
                            0x0E,
                            0x04,
                            0x0A,
                            0x11,
                            0x00,
                            0x01,
                            0x03,
                            0x16,
                            0x1C,
                            0x08,
                            0x00,
                            0x00,
                            0x00,
                            0x0E,
                            0x15,
                            0x1B,
                            0x0E,
                            0x0E,
                            0x00,
                            0x00}
 
 
 

int main(void)
{

//	u16 ADC_read =0;
	//u16 ReadToTemp =0;
	LCD_voidInit();
//ADC_voidInit();
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,1,0);
	LCD_voidGotoXY(1,1);
	LCD_voidSendString("HAMOKSHA WAS A GOOD ");
	LCD_voidGotoXY(2,0);
	LCD_voidSendString("PLAYER FOODBALL");
	LCD_voidWriteSpecialChar(Copy_u8Pattern,2,2,18);
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,1,1,0);
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,1,0);
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,1,1,0);
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,0,1,0);
	_delay_ms(200);
	LCD_voidClearDisplay();
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("BUT SUDDENLY HE DEAD ");
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,0);
	_delay_ms(50);							
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,2);
	_delay_ms(50);							  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,4);
	_delay_ms(50);							  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,6);
	_delay_ms(50);							  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,8);
	_delay_ms(50);					  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,10);
	_delay_ms(50);						  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,12);
	_delay_ms(50);						  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,14);
	_delay_ms(50);						  
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,16);
	_delay_ms(50);
	LCD_voidWriteSpecialChar(Copy_u8Pattern,3,2,18);
    while (1) 
    {
		
    }
	
}

