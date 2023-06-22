/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   15/6/2023       ******************/
/**********************  SWC     :     KEYPAD        ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KPD_u8_COLS_PORT			 DIO_u8_PORTD
#define KPD_u8_ROWs_PORT             DIO_u8_PORTC

#define KEYPAD_Au8_KEYS 	   {{'1','2','3','+'},\
								{'4','5','6','-'},\
								{'7','8','9','*'},\
								{'/','0','%','='}}


#define KYP_CLM_PIN1			DIO_u8_PIN7
#define KYP_CLM_PIN2			DIO_u8_PIN6
#define KYP_CLM_PIN3			DIO_u8_PIN5
#define KYP_CLM_PIN4			DIO_u8_PIN3

#define KYP_ROW_PIN1			DIO_u8_PIN5
#define KYP_ROW_PIN2			DIO_u8_PIN4
#define KYP_ROW_PIN3			DIO_u8_PIN3
#define KYP_ROW_PIN4			DIO_u8_PIN2

#define KEYPAD_u8_ROW_NUM		4
#define KEYPAD_u8_COL_NUM		4

#endif