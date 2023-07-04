/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   21/6/2023       ******************/
/**********************  SWC     :  LDR Sensor   	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#define  F_CPU 16000000
#include <util/delay.h>

/* Lib layer */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/* MCAL */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
/* HAL */
#include "HAL/KYP/KEYPAD_Interface.h"
#include "HAL/SS/SS_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

/* Global array that will store the custom charactars */
 extern u8 Copy_u8Pattern[];
int main(void)
{
	/************************************************************************/
	/*                 SET Ports direction and values                       */
	/************************************************************************/
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_INPUT);
	/* initialization the variable and LCD and ADC */
	u16 ADC_read =0;
	u16 ReadToTemp =0;
	LCD_voidInit();
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("LDR =");
	ADC_voidInit();
	
    while (1) 
    {
		/* start convertion of ADC to ger the read*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&ADC_read);
		ReadToTemp= (ADC_read);
		/* by try the highest value if it cleary dark = 860*/
		if (ReadToTemp >800)
		{
			LCD_voidGotoXY(2,7);
			LCD_voidSendString("Dark  ");
			LCD_voidWriteSpecialChar(Copy_u8Pattern,0,2,13);
		}
		else
		{
			/* by try the lowest value if it directly exposed to light  = 140*/
			LCD_voidGotoXY(2,7);
			LCD_voidSendString("Light");
			LCD_voidWriteSpecialChar(Copy_u8Pattern,1,2,13);
		}
		/* make delay to be cleary to see it*/
		_delay_ms(500);
    }
	
}

