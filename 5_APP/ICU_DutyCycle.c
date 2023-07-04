/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   21/6/2023       ******************/
/**********************  SWC     :   ICU & ADC   	 ******************/
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

void APP_ICU(void);
 u8 counter ;
 u32 Time_of_high_perioud;
 u32 Time_of_low_perioud;  
 
 
 
int main(void)
{
	u16 ADC_READ=0;
	 GIE_voidEnable();
	 LCD_voidInit();
	 ADC_voidInit();
	 DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_OUTPUT);
	 TIMER_voidTimer0Init();
	 TIMER_voidTimer1Init();
	  LCD_voidGotoXY(1,0);
	  LCD_voidSendString("Duty=");




	
	
	while (1)
	{
		 ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&ADC_READ);
		 TIMER_voidTimer0SetCompareValue(200);
			ICU_voidSetCallBack(&APP_ICU);
			ICU_voidInit();
			
			 if (Time_of_low_perioud>Time_of_high_perioud)
			 {
				
				  LCD_voidGotoXY(1,6);
				  LCD_VoidNumToString((Time_of_high_perioud*100)/(Time_of_low_perioud+Time_of_high_perioud));
				  LCD_voidSendString(" ");
				  LCD_voidGotoXY(2,6);
				  LCD_VoidNumToString(Time_of_low_perioud);
			 }
			
			 LCD_voidGotoXY(1,12);
			 LCD_voidSendString("%");
			 

	
			  
	}
	
}




void APP_ICU (void)
{

	counter ++;
	
	if (counter == 1)
	{
			TIM1_u16_ICR1_REG =0;
			ICU_voidSetTrigger(FALLING_EDGE);
	}
	 else if(counter ==2)
	{
		
		Time_of_high_perioud =TIM1_u16_ICR1_REG;
		TIM1_u16_ICR1_REG =0;
		ICU_voidSetTrigger(RISING_EDGE);

	}
	 else if(counter ==3)
	{
		Time_of_low_perioud=TIM1_u16_ICR1_REG;
		ICU_voidSetTrigger(FALLING_EDGE);
		counter=0;
	}

	

}
