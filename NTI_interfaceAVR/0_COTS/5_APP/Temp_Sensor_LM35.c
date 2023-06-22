/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   21/6/2023       ******************/
/**********************  SWC     :  TEMP Sensor   	 ******************/
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


int main(void)
{
	/************************************************************************/
	/*                 SET Ports direction and values                       */
	/************************************************************************/
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_INPUT);
	/* initialization the variable and LCD and ADC */
	u16 ADC_read =0;
	u16 ReadToTemp =0;
	LCD_voidInit();
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("TEMP=");
	ADC_voidInit();
	
    while (1) 
    {
		/* start convertion of ADC to ger the read*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_1,&ADC_read);
		LCD_voidGotoXY(1,7);
		/* make the calculation to convert it to celacuis (1C change = 100mV change )*/
		ReadToTemp= ((ADC_read * 500UL)/1023);
		/* represent the read on LCD */
		LCD_VoidNumToString(ReadToTemp);
		LCD_voidSendString("  c ");
		/* make delay to be cleary to see it*/
		_delay_ms(500);
    }
	
}

