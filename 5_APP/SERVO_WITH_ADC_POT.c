/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  SWC     :     SERVO   		 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#define  F_CPU 16000000
#include <util/delay.h>

/* Lib layer */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/* MCAL */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
/* HAL */
#include "HAL/KYP/KEYPAD_Interface.h"
#include "HAL/SS/SS_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

#define SERVO_u16_MIN				999
#define SERVO_u16_MAX				4999
#define ADC_u16_REG_RESLUTION		1024

int main(void)
{

	u16 Local_u16ADCPotRead= 0;
	u32 Local_u16LinearEquation =0;
	ADC_voidInit();
	TIMER_voidTimer1Init();
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT);
	TIMER_voidTimer1SetInputCaptureValue(40000);

	
	while (1)
	{
		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_1,&Local_u16ADCPotRead);
		Local_u16LinearEquation = ((( (u32)Local_u16ADCPotRead * (SERVO_u16_MAX- SERVO_u16_MIN) ) / (u32) ADC_u16_REG_RESLUTION) + (u32)999 );
		TIMER_voidTimer1ASetCompareValue(Local_u16LinearEquation);
		_delay_ms(50);
	}
	return 0;
}


