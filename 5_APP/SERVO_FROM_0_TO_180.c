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

#define SERVO_MIN		999
#define SERVO_MAX		4999

int main(void)
{
	unsigned short int i =0;
	TIMER_voidTimer1Init();
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT);
	TIMER_voidTimer1SetInputCaptureValue(40000);
	TIMER_voidTimer1ASetCompareValue(SERVO_MAX);
	_delay_ms(1000);
	TIMER_voidTimer1ASetCompareValue(SERVO_MIN);
	
	while (1)
	{
		for (i=999;i<4999;i+=200)
		{
			
			TIMER_voidTimer1ASetCompareValue(i);
			_delay_ms(750);

		}
	}
	return 0;
}


