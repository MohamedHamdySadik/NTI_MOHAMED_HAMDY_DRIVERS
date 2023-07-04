/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   15/6/2023       ******************/
/**********************  SWC     :     KEYPAD        ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/***********************************************************************/
/************************						************************/
/************************	  	 INCLUDE		************************/
/************************						************************/
/***********************************************************************/
/* include delay function and define the crystal to used it */
#define F_CPU 8000000UL
#include <util/delay.h>

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO/DIO_interface.h"

/* HAL */
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

/***********************************************************************/
/************************						************************/
/************************	 GLOBAL VARIABLE	************************/
/************************						************************/
/***********************************************************************/
u8 KEYPAD_Au8Keys[KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM]= KEYPAD_Au8_KEYS;
u8 KEYPAD_Au8RowsPins[KEYPAD_u8_ROW_NUM] = {KYP_ROW_PIN1,KYP_ROW_PIN2,KYP_ROW_PIN3,KYP_ROW_PIN4};
u8 KEYPAD_Au8ColsPins[KEYPAD_u8_COL_NUM] = {KYP_CLM_PIN1,KYP_CLM_PIN2,KYP_CLM_PIN3,KYP_CLM_PIN4};

/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/** Function: KEYPAD_u8GetKeyPressed	                        				**/
/** I/P Parameters: Copy_pu8ReturnedKey					          			    **/
/** Returns:it returns u8 error state                          				    **/
/** Desc:This Function give presed key in ascII code in Copy_pu8ReturnedKey		**/
/*********************************************************************************/
/** Copy_pu8ReturnedKey Options: user pointer of variable that store  			**/
/** 1_the pressed key in ascII code												**/
/** 2_KEYPAD_NOT_PRESSED	 													**/
/*********************************************************************************/
u8 KPD_u8GetPressedKey(u8* Copy_pu8ReturnedKey)
{
	/* deceleration error state and give it state OK 							 */
	u8 LocalErrorState = STD_TYPES_OK;
	/* deceleration local_u8ColCounter : that carry the variable of columns 		 */
	/* deceleration local_u8RowCounter : that carry the variable of ROWS 		 */
	/* deceleration local_u8PinValue   : that carry the pin value that will measure*/
	/* deceleration local_u8Flag       : this flag is used to  break for loop     */
	u8 local_u8ColCounter,local_u8RowCounter,local_u8PinValue,local_u8Flag=0;
	
	/* cheek that if Copy_pu8ReturnedKey carry the address of variable. 			 */
	if(Copy_pu8ReturnedKey != NULL)
	{
		/* Copy_pu8ReturnedKey give it value that indication that key not pressed   */
		*Copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/* iteration on the columns to activate it sequential order */
		for(local_u8ColCounter=0;local_u8ColCounter<KEYPAD_u8_COL_NUM;local_u8ColCounter++)
		{
			/* activation the column by set it low */
			DIO_u8SetPinValue(KPD_u8_COLS_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter],DIO_u8_LOW);
			/* iteration on the rows to find which is activate in sequential order */
			for(local_u8RowCounter=0;local_u8RowCounter<KEYPAD_u8_ROW_NUM;local_u8RowCounter++)
			{
				/* local_u8PinValue will be carry the indication value of that row activate */
				DIO_u8GetPinValue(KPD_u8_ROWs_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],&local_u8PinValue);
				/* fine which the row active */
				if(local_u8PinValue == DIO_u8_LOW )
				{
					/* delay for Debouncing  */
					_delay_ms(20);
					/* update local_u8PinValue will be carry the indication value of which row activate */
					DIO_u8GetPinValue(KPD_u8_ROWs_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],&local_u8PinValue);
					/* cheek if key still pressed */
					while (local_u8PinValue == DIO_u8_LOW )
					{
						/* update local_u8PinValue will be carry the indication value of which row activate */
						DIO_u8GetPinValue(KPD_u8_ROWs_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],&local_u8PinValue);
					}
					/* Copy_pu8ReturnedKey will carry the ASCII code of pressed key from the Array index */
					*Copy_pu8ReturnedKey=KEYPAD_Au8Keys[local_u8ColCounter][local_u8RowCounter];
					/* set flag by 1 for get break from the outer for loop */
					local_u8Flag =1;
					/*if i get key pressed break from  the inner for loop */
					break;
				}
			}
			/* deactivation the column by set it HIGH */
			DIO_u8SetPinValue(KPD_u8_COLS_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter],DIO_u8_HIGH);
			/*if i get key pressed break from  the outer for loop */
			if (local_u8Flag == 1)
			{
				/*break from  the outer for loop */
				break;
			}
		}
	}
	/* if the Copy_pu8ReturnedKey equal NUll the indication  error  */
	else
	{
		/* LocalErrorState set it to not ok */
		LocalErrorState = STD_TYPES_NOK;
	}
	/* return the local error state */
	return LocalErrorState;
}