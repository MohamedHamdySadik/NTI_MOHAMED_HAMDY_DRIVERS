/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :      LCD          ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*********************************************************************************/
/************************						**********************************/
/************************		  OBJECTS		**********************************/
/************************						**********************************/
/*********************************************************************************/

/* set the Mood of data will send */
/* option: 4 , 8                  */
#define LCD_u8Mood			4

#define LCD_u8CtrlPort		DIO_u8_PORTA
#define LCD_u8DataPort      DIO_u8_PORTB
							
#define LCD_u8RSPin         DIO_u8_PIN3
#define LCD_u8ENPin         DIO_u8_PIN2
//#define LCD_u8RWPin			DIO_u8_PIN?
        
#define LCD_u8D4Pin         DIO_u8_PIN0
#define LCD_u8D5Pin         DIO_u8_PIN1
#define LCD_u8D6Pin         DIO_u8_PIN2
#define LCD_u8D7Pin         DIO_u8_PIN4


	#if (LCD_u8Mood == 8)
	
		#define LCD_u8D0Pin         DIO_u8_PIN5
		#define LCD_u8D1Pin         DIO_u8_PIN6
		#define LCD_u8D2Pin         DIO_u8_PIN7
		#define LCD_u8D3Pin 		DIO_u8_PIN0	
			
	#endif
	
#define LCD_Au8_CUSTOM_CHARACTAR  {0x0E,\
								   0x0E,\
								   0x04,\
								   0x04,\
								   0x0E,\
								   0x15,\
								   0x0A,\
								   0x0A,\
								   0x0E,\
								   0x0E,\
								   0x04,\
								   0x15,\
								   0x0E,\
								   0x04,\
								   0x0A,\
								   0x11}

#endif