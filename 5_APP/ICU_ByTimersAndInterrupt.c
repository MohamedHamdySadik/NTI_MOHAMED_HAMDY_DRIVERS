/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  SWF     :      ICU   		 ******************/
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
#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/TIMER/TIMER_Private.h"
/* HAL */
#include "HAL/KYP/KEYPAD_Interface.h"
#include "HAL/SS/SS_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

void APP_ICU_ByInterruptAndTimers (void);
 u8 counter ;
 u16 Time_of_high_perioud;
 u16 Time_of_low_perioud;  
 
 
 
int main(void)
{
	u16 ADC_READ=0;

	 GIE_voidEnable();
	 DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_OUTPUT);
	 TIMER_voidTimer0Init();
	 LCD_voidInit();
	 ADC_voidInit();
	
	 TIMER_voidTimer1Init();
	  LCD_voidGotoXY(1,0);
	  LCD_voidSendString("Duty=");
	  LCD_voidGotoXY(2,0);
	  LCD_voidSendString("Freq=");



	
	
	while (1)
	{
		 ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&ADC_READ);
		 TIMER_voidTimer0SetCompareValue(ADC_READ/4);
			EXTI_voidEXTIEnable( EXTI_u8_EXTI0 , EXTI_u8_RISING_EDGE);
			EXTI_voidSetCallBack( &APP_ICU_ByInterruptAndTimers, EXTI_u8_EXTI0 );
			 LCD_voidGotoXY(1,6);
			 LCD_VoidNumToString((Time_of_high_perioud*100)/Time_of_low_perioud);
			 LCD_voidGotoXY(1,9);
			 LCD_voidSendString("%");
			 LCD_voidGotoXY(2,6);
			 LCD_VoidNumToString((Time_of_low_perioud*100)/Time_of_low_perioud);
			 LCD_voidGotoXY(2,10);
			 LCD_voidSendString("KHZ");
			   _delay_ms(500);
	}
	
}




void APP_ICU_ByInterruptAndTimers (void)
{

	counter ++;
	
	if (counter == 1)
	{
			TIM1_u16_TCNT1_REG =0;
			EXTI_voidEXTIEnable( EXTI_u8_EXTI0 , EXTI_u8_FALLING_EDGE);
	}
	 if(counter ==2)
	{
		Time_of_high_perioud =TIM1_u16_TCNT1_REG;
		EXTI_voidEXTIEnable( EXTI_u8_EXTI0 , EXTI_u8_RISING_EDGE);
	}
	 if(counter ==3)
	{
		Time_of_low_perioud=TIM1_u16_TCNT1_REG;
		counter =0;
	}

	

}
