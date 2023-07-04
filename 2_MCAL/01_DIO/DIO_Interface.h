/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :      DIO          ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
/*********************************************************************************/
/************************						**********************************/
/************************		  OBJECTS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*Registers macros*/
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3
/*PINS macros*/
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7
/* micros used with functions:DIO_u8SetPinValue  			*/					  
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1
/* micros used with functions:1-DIO_u8SetPinDirection
							  2-DIO_voidSetPortDirection	*/
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1



/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: DIO_voidSetPinValue	                        				    **/
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		    **/
/* Returns:it returns u8                                      				    **/
/* Desc:This Function Sets the Value of a specific pin				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_LOW, DIO_u8_HIGH                               **/
/*********************************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);




/*********************************************************************************/
/* Function: DIO_voidSetPinDirection	                        				**/
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8Direction  			    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function Sets the Direction of a specific pin     		       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Direction  Options: DIO_u8_INPUT, DIO_u8_OUTPUT                       **/
/*********************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);





/*********************************************************************************/
/* Function: DIO_voidGetPinValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, Copy_u8PinId				          		    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function gets the Value of a given pin					       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_pu8ReturnedPinValue Options: Pointer of variable thet carry the value   **/
/*********************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_pu8ReturnedPinValue);





/*********************************************************************************/
/* Function: DIO_voidSetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Value                               **/
/* Returns:it returns u8 the error state                     				    **/
/* Desc:This Function Sets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);





/*********************************************************************************/
/* Function: DIO_voidSetPortDirection                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Direction                           **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Direction of a specific port			       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options: DIO_u8_INPUT, DIO_u8_OUTPUT                           **/
/*********************************************************************************/
u8 DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);





/*********************************************************************************/
/* Function: DIO_voidGetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId                                                **/
/* Returns:it returns   u8                                     				    **/
/* Desc:This Function Sets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId, u8* Copy_pu8PortValue);


/*********************************************************************************/
/* Function: DIO_voidInit	                      			  				    **/
/* I/P Parameters: NO THING                  	                                **/
/* Returns:it returns NO THING RETURNED                                         **/
/* Desc:This Function to intialization all ports directions and values    	    **/
/*********************************************************************************/
void DIO_voidInit(void);

#endif
