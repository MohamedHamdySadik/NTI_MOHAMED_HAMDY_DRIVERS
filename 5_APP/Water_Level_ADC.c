/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   21/6/2023       ******************/
/**********************  SWC     :  WATER LEVEL    	 ******************/
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
 /* the ADC read that if adc read less that it will mean that take the actions*/
 #define Rang   700

int main(void)
{
	/************************************************************************/
	/*                 SET Ports direction and values                       */
	/************************************************************************/
	/* the output pin that will put in the buttom of the water level set it output and low */
	DIO_u8SetPinDirection(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_LOW);
	/* the Bazzer om the bourd is connected to c6*/
	DIO_u8SetPinDirection(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_OUTPUT);
	/* set the pins of the ADC */
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_INPUT);
	
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
	/* initialization the variable and LCD and ADC */
	u16 ADC_read =0;
	u16 ReadToTemp =0;
	LCD_voidInit();
	ADC_voidInit();
	/* Put the basic words on LCD to display */
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("LEVEL1=");
	LCD_voidGotoXY(2,0);
	LCD_voidSendString("LEVEL2=");
	LCD_voidGotoXY(3,0);
	LCD_voidSendString("LEVEL3=");
	
    while (1) 
    {
	

		/* read from channel 0 (water level number 1 )*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&ADC_read);
		ReadToTemp = ADC_read;
		if(ReadToTemp<Rang)
		{
			LCD_voidGotoXY(1,7);
			LCD_voidSendString("Water reached");
		}
		else
		{
			LCD_voidGotoXY(1,7);
			LCD_voidSendString("             ");
		}
		
			/* read from channel 1 (water level number 2 )*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_1,&ADC_read);
		ReadToTemp = ADC_read;
	
		if(ReadToTemp <Rang)
		{
			LCD_voidGotoXY(2,7);
			LCD_voidSendString("Water reached");
		}
		else
		{
			LCD_voidGotoXY(2,7);
			LCD_voidSendString("             ");
		}
		
		
		/* read from channel 4 (water level number 3 max )*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_4,&ADC_read);
		ReadToTemp = ADC_read;
		if(ReadToTemp <Rang)
		{
			LCD_voidGotoXY(3,7);
			LCD_voidSendString("Water reached");
			/* Buzzer will be active */
			DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
			
		}
		
		else
		{
			LCD_voidGotoXY(3,7);
			LCD_voidSendString("             ");
			/* Buzzer will be deactive */
			DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_LOW);
		}
		_delay_ms(500);
    }
	
}

