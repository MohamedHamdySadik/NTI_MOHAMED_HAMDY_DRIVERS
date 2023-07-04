/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :      DIO          ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef SS_CONFIG_H
#define SS_CONFIG_H
/*********************************************************************************/
/************************						**********************************/
/************************		  OBJECTS		**********************************/
/************************						**********************************/
/*********************************************************************************/

/*   number of PORTS and PINS that will be connected by decoder  */
#define SS_u8_PORTS_NUM			4
#define SS_u8_PINS_NUM			4

/*THE PORT and PIN that connected with decoder in (a) or in first bit that weight 1 to converted to number */
#define SS_u8_PORT_OF_PIN1		DIO_u8_PORTB	
#define SS_u8_PIN_OF_PORT1		DIO_u8_PIN0	
/*THE PORT and PIN that connected with decoder in (b) or in first bit that weight 2 to converted to number */
#define SS_u8_PORT_OF_PIN2		DIO_u8_PORTB
#define SS_u8_PIN_OF_PORT2		DIO_u8_PIN1
/*THE PORT and PIN that connected with decoder in (c) or in first bit that weight 4 to converted to number */
#define SS_u8_PORT_OF_PIN3		DIO_u8_PORTB
#define SS_u8_PIN_OF_PORT3		DIO_u8_PIN2
/*THE PORT and PIN that connected with decoder in (d) or in first bit that weight 8 to converted to number */
#define SS_u8_PORT_OF_PIN4		DIO_u8_PORTB
#define SS_u8_PIN_OF_PORT4		DIO_u8_PIN4


/* number of seven segment that connected with decoder  */
#define SS_u8_SS_NUM			4
/* THE PORT and PIN that connected with SS number 1     */
#define SS_u8_EN_PORT_SS1		DIO_u8_PORTA
#define SS_u8_EN_PIN_SS1		DIO_u8_PIN3
/* THE PORT and PIN that connected with SS number 2     */
#define SS_u8_EN_PORT_SS2		DIO_u8_PORTA
#define SS_u8_EN_PIN_SS2		DIO_u8_PIN2
/* THE PORT and PIN that connected with SS number 3     */
#define SS_u8_EN_PORT_SS3		DIO_u8_PORTB
#define SS_u8_EN_PIN_SS3		DIO_u8_PIN5
/* THE PORT and PIN that connected with SS number 4     */
#define SS_u8_EN_PORT_SS4		DIO_u8_PORTB
#define SS_u8_EN_PIN_SS4		DIO_u8_PIN6



#endif