/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   15/6/2023       ******************/
/**********************  SWC     :     KEYPAD        ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/
/*File guard*/
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define KPD_u8_KEY_NOT_PRESSED		0xff


/*********************************************************************************/
/* Function: KEYPAD_u8GetKeyPressed	                        				    **/
/* I/P Parameters: Copy_pu8ReturnedKey					          			    **/
/* Returns:it returns u8 error state                          				    **/
/* Desc:This Function give presed key in ascII code in Copy_pu8ReturnedKey		**/
/*********************************************************************************/
/* Copy_pu8ReturnedKey Options: user pointer of variable that store the pressed  */
/* key in ascII code 			 												 */
/*********************************************************************************/
u8 KPD_u8GetPressedKey(u8* Copy_pu8ReturnedKey);
#endif