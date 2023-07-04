/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :      CALC   		 ******************/
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


#define MAX_NUM_ENTER  999999999

int main(void)
{
	KPD_voidInti();
	LCD_voidInit();
	u8 Local_u8KYPRead;
	u32 Local_u32Num1=0;
	u32 Local_u32Num2 =0;
	u8  Local_u8Opreation=0;
	u8	Local_u8FlagOpration =0;
	u8	Local_u8FlagLocal_u32Num1 =0;
	u8	Local_u8FlagLocal_u32Num2 =0;
	u16 Local_u16DivisionRemaind=0;
	u64 Local_u64Refrance =0;
	while (1)
	{

		KPD_u8GetPressedKey(&Local_u8KYPRead);
		if (Local_u8KYPRead != KPD_u8_KEY_NOT_PRESSED)
		{
			if(Local_u8KYPRead >= '0' && Local_u8KYPRead <= '9')
			{
				
				if (Local_u8FlagOpration == 0)
				{
					
					LCD_voidClearDisplay();
					Local_u8FlagLocal_u32Num1 =1;
					Local_u32Num1 =((Local_u32Num1*10) + (Local_u8KYPRead-'0'));
					LCD_voidGotoXY(1,0);
					if (Local_u32Num1 <= MAX_NUM_ENTER)
					{
						LCD_VoidNumToString(Local_u32Num1);
					}
					else
					{
						LCD_voidSendString(" Invalid number ");
						Local_u32Num1 =0;
						Local_u32Num2 =0;
						Local_u8FlagOpration =0;
						Local_u8FlagLocal_u32Num1 =0;
						Local_u8FlagLocal_u32Num2 =0;
						Local_u8Opreation =0;
					}
				}
				else if (Local_u8FlagOpration == 1 )
				{
					Local_u8FlagLocal_u32Num2 =1;
					Local_u32Num2 =((Local_u32Num2*10) + (Local_u8KYPRead-'0'));
					LCD_voidGotoXY(3,0);
					if (Local_u32Num2 <= MAX_NUM_ENTER)
					{
						LCD_VoidNumToString(Local_u32Num2);
					}
					else
					{
						LCD_voidSendString(" Invalid number ");
						
						Local_u32Num1 =0;
						Local_u32Num2 =0;
						Local_u8FlagOpration =0;
						Local_u8FlagLocal_u32Num1 =0;
						Local_u8FlagLocal_u32Num2 =0;
						Local_u8Opreation =0;
						
					}
				}
				
			}
			else if ((Local_u8KYPRead == '-' || Local_u8KYPRead == '+' || Local_u8KYPRead == '*'|| Local_u8KYPRead == '/' ) && Local_u8FlagLocal_u32Num1 == 1)
			{
				Local_u8FlagOpration =1;
				Local_u8Opreation = Local_u8KYPRead;
				LCD_voidGotoXY(2,0);
				LCD_voidWriteChar(Local_u8Opreation);
				
				
			}
			else if ((Local_u8KYPRead == '=') && (Local_u8FlagLocal_u32Num2 ==1) )
			{
				LCD_voidGotoXY(4,0);
				switch (Local_u8Opreation)
				{
					case '+':
					LCD_VoidNumToString( Local_u32Num1 + Local_u32Num2); break;
					
					case '-':
					if (Local_u32Num1>= Local_u32Num2)
					{
						LCD_VoidNumToString( Local_u32Num1 - Local_u32Num2);
					}
					else
					{
						LCD_voidWriteChar('-');
						LCD_VoidNumToString( Local_u32Num2 - Local_u32Num1);
					}
					break;
					
					case '*':
					
					Local_u64Refrance = (u64)Local_u32Num1 * (u64)Local_u32Num2;
					if (Local_u64Refrance > 4294967296)
					{
						LCD_voidSendString(" Invalid number ");
						Local_u32Num1 =0;
						Local_u32Num2 =0;
						Local_u8FlagOpration =0;
						Local_u8FlagLocal_u32Num1 =0;
						Local_u8Opreation =0;
						Local_u64Refrance =0;
					}
					else
					{
						LCD_VoidNumToString((u32)Local_u64Refrance);
					}
					
					break;
					
					case '/':
					
					if (Local_u32Num2 != 0)
					{
						LCD_VoidNumToString( Local_u32Num1 / Local_u32Num2);
						if (( Local_u32Num1 > Local_u32Num2) && (Local_u32Num1 % Local_u32Num2 > 0))
						{
							Local_u16DivisionRemaind = Local_u32Num1 % Local_u32Num2;
							Local_u16DivisionRemaind *=100;
							LCD_voidWriteChar('.');
							LCD_VoidNumToString(Local_u16DivisionRemaind / Local_u32Num2);
							
						}
						else if (( (Local_u32Num1*10) >= Local_u32Num2) && (Local_u32Num1 % Local_u32Num2 > 0))
						{
							Local_u16DivisionRemaind = Local_u32Num1 % Local_u32Num2;
							Local_u16DivisionRemaind *=100;
							LCD_voidWriteChar('.');
							LCD_VoidNumToString(Local_u16DivisionRemaind / Local_u32Num2);
							
						}
						else if ( (Local_u32Num1*10) < Local_u32Num2 && (Local_u32Num1 % Local_u32Num2 > 0))
						{
							Local_u16DivisionRemaind = Local_u32Num1 % Local_u32Num2;
							Local_u16DivisionRemaind *=100;
							LCD_voidWriteChar('.');
							LCD_voidWriteChar('0');
							LCD_VoidNumToString(Local_u16DivisionRemaind / Local_u32Num2);
						}
					}
					else
					{
						LCD_voidSendString(" MATH ERROR ");
					}
					break;
					default:LCD_voidSendString(" Error ");break;
				}
				
				Local_u32Num1 =0;
				Local_u32Num2 =0;
				Local_u8FlagOpration =0;
				Local_u8FlagLocal_u32Num1 =0;
				Local_u8FlagLocal_u32Num2 =0;
				Local_u8Opreation =0;
			}
			
			else if (Local_u8KYPRead == '%')
			{
				LCD_voidClearDisplay();
				Local_u32Num1 =0;
				Local_u32Num2 =0;
				Local_u8FlagOpration =0;
				Local_u8FlagLocal_u32Num1 =0;
				Local_u8FlagLocal_u32Num2 =0;
				Local_u8Opreation =0;
			}
			
		}
	}
	return 0;
}

