/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   WATCH_ALARM   	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

//#define  F_CPU 8000000
//#include <util/delay.h>

/* Lib layer */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/* MCAL */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/UART/UART_Interface.h"

/* HAL */
#include "HAL/KYP/KEYPAD_Interface.h"
#include "HAL/SS/SS_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

void APP_voidAlarmWatch(void);
u16 Global_u16Time;
int main(void)
{
	DIO_u8SetPinDirection(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_OUTPUT);
	TIMER_voidTimer1Init();
	TIMER_voidTimer1ASetCompareValue(62500);
	LCD_voidInit();
	KPD_voidInti();
	u8 Local_u8keyread=0;
	u16 Global_u16Time =0;
	u8 Local_u8Flag =0;
	while (1)
	{	
	
		KPD_u8GetPressedKey(&Local_u8keyread);
		if (Local_u8keyread != KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_voidGotoXY(1,0);
			LCD_voidSendString("ENTER THE TIME");
			if ((Local_u8keyread >= '0') && (Local_u8keyread <= '9')  )
			{
				Local_u8Flag =1;
				DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_LOW);
				Global_u16Time = (Global_u16Time*10) + (Local_u8keyread- '0');
				LCD_voidGotoXY(2,0);
				LCD_VoidNumToString((u32)Global_u16Time);
			}
			else if ((Local_u8keyread == '=') && (Local_u8Flag == 1) )
			{
				Local_u8Flag =0;
				TIMER_voidTimer1SetCallBack(& APP_voidWatchAlarm,TIMER_u8_TIMER1A_CM);
				TIMER_voidTimer1EnableInt(TIMER_u8_TIMER1A_CM);
				
			}
		}
	}
	return 0;
}

void APP_voidWatchAlarm(void)
{
	Global_u16Time--;
	if (Global_u16Time <= 0)
	{
		/* Bazzer on */
		DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
		LCD_voidClearDisplay();
		LCD_voidGotoXY(1,0);
		LCD_voidSendString("TIME OUT");
		Global_u16Time=0;
	}
}
