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

void Linear_Equation(u16 Copy_u16Y2,u16 Copy_u16Y1 ,u16 Copy_u16X2,u16 Copy_u16X1, u16 Copy_u16YGiven, u32* Copy_u16_LinearResult);
int main(void)
{
	/************************************************************************/
	/*                 SET Ports direction and values                       */
	/************************************************************************/
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_INPUT);
	/* initialization the variable and LCD and ADC */
	u16 ADC_read =0;
	u16 ReadToTemp =0;
	u32 ReadAfterLinearFunction=0;
	LCD_voidInit();
	LCD_voidGotoXY(1,0);
	LCD_voidSendString("VOlte=");
	LCD_voidGotoXY(2,0);
	LCD_voidSendString("Ohm  =");
	ADC_voidInit();
	
	while (1)
	{
		/* start convertion of ADC to ger the read*/
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_4,&ADC_read);
		LCD_voidGotoXY(1,7);
		/* make the calculation to convert it to celacuis (1C change = 100mV change )*/
		ReadToTemp= ((ADC_read * 5000UL)/1023);
		/* represent the read on LCD */
		LCD_VoidNumToString(ReadToTemp);
		LCD_voidSendString("  mV ");
		/* make delay to be cleary to see it*/
		//_delay_ms(500);.
		LCD_voidGotoXY(2,7);
		Linear_Equation(5000,0,10000,0,ReadToTemp,&ReadAfterLinearFunction);
		LCD_VoidNumToString(ReadAfterLinearFunction);
		LCD_voidGotoXY(2,13);
		LCD_voidSendString("ohm");
	}
	
}
/* it must put in the servies layer */
void Linear_Equation(u16 Copy_u16Y2,u16 Copy_u16Y1 ,u16 Copy_u16X2,u16 Copy_u16X1, u16 Copy_u16YGiven, u32* Copy_u16_LinearResult)
{
	/* Linear Equation (y2 -y1)/(x2-x1)=(y-y1)/(x-x1) */
	/*((Copy_u16X2-Copy_u16X1)*(Copy_u16YGiven-Copy_u16Y1))/(Copy_u16Y2-Copy_u16Y1))+Copy_u16X1*/
	long long int x =Copy_u16Y2-Copy_u16Y1;
	long long int y =Copy_u16X2- Copy_u16X1 ;
	long long int z =Copy_u16YGiven-Copy_u16Y1;
	*Copy_u16_LinearResult =((y*z)/x)+Copy_u16X1;
	

}