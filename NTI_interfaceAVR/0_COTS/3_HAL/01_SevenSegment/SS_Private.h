/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :      DIO      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef SS_PRIVATE_H
#define SS_PRIVATE_H
/*********************************************************************************/
/************************						**********************************/
/************************		  OBJECTS		**********************************/
/************************						**********************************/
/*********************************************************************************/


/*  array that carry the PORTS sequential with decoder that converted to number        */
#define SS_Au8_EN_PORTS   		{SS_u8_EN_PORT_SS1,SS_u8_EN_PORT_SS2,SS_u8_EN_PORT_SS3,SS_u8_EN_PORT_SS4}
/*  array that carry the PINS sequential with decoder that converted to number         */
#define SS_Au8_EN_PINS			{SS_u8_EN_PIN_SS1,SS_u8_EN_PIN_SS2,SS_u8_EN_PIN_SS3,SS_u8_EN_PIN_SS4}
	
/*  array that carry the PORTS sequential with decoder that used to enable or disable   */
#define SS_Au8_PORTS   			{SS_u8_PORT_OF_PIN1,SS_u8_PORT_OF_PIN2,SS_u8_PORT_OF_PIN3,SS_u8_PORT_OF_PIN4}
/*  array that carry the PINS sequential with decoder that used to enable or disable    */
#define SS_Au8_PINS				{SS_u8_PIN_OF_PORT1,SS_u8_PIN_OF_PORT2,SS_u8_PIN_OF_PORT3,SS_u8_PIN_OF_PORT4}

#endif