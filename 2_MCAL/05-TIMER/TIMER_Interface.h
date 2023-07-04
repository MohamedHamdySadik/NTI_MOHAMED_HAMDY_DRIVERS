/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   19/6/2023       ******************/
/**********************  SWC     :     TIMER      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#ifndef    TIMER_INTERFACE_H
#define    TIMER_INTERFACE_H

/*Public Macros*/
/*  Timer0 Macros */
#define    TIMER_u8_TIMERS0_NORMAL_MODE      		                0
#define    TIMER_u8_TIMERS0_PWM_OR_PHASE_COTROL                     1
#define    TIMER_u8_TIMERS0_CTC_MODE                                2
#define    TIMER_u8_TIMERS0_FAST_PWM_MODE                           3

#define    NON_PWM_NORMAL_PORT_OPRETATION                           0
#define    NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                      1
#define    NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                       2
#define    NON_PWM_SET_OC0_ON_COMPARE_MATCH						    3


#define    FAST_PWM_NORMAL_PORT_OPRETATION                          0
#define    FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH     					1
#define    FAST_PWM_SET_OC0_ON_COMPARE_MATCH	  					2

#define    PHASE_PWM_NORMAL_PORT_OPRETATION                         0
#define    PHASE_PWM_CLEAR_OC0_ON_COMPARE_MATCH     				1
#define    PHASE_PWM_SET_OC0_ON_COMPARE_MATCH	  					2


#define    CLK_DIV_BY_0										 	    1
#define    CLK_DIV_BY_8										 	    2
#define    CLK_DIV_BY_64                                            3
#define    CLK_DIV_BY_256                                           4
#define    CLK_DIV_BY_1024                                          5
#define    ECS_ON_T0_FALLING_EDGE      								6
#define    ECS_ON_T0_RISING_EDGE       								7

#define	   RISING_EDGE												0
#define	   FALLING_EDGE												1

#define    TIMER_u8_OVERFLOW_INT									0
#define    TIMER_u8_COMPARE_INT										1

#define    TIMER_u8_OVERFLOW_FLAG									0
#define    TIMER_u8_COMPARE_FLAG										1

#define    TIMER_u8_TIMER0OV										0
#define    TIMER_u8_TIMER0CM										1

/* Timer1 Macros */

#define 	TIMER_u8_TIMERS1_NORMAL									0
#define 	TIMER_u8_TIMERS1_PWM_8BIT                               1
#define 	TIMER_u8_TIMERS1_PWM_9BIT                               2
#define 	TIMER_u8_TIMERS1_PWM_10BIT                              3
#define 	TIMER_u8_TIMERS1_CTC_OCR1A                              4
#define 	TIMER_u8_TIMERS1_FAST_PWM_8BIT                          5
#define 	TIMER_u8_TIMERS1_FAST_PWM_9BIT                          6
#define 	TIMER_u8_TIMERS1_FAST_PWM_10BIT                         7
#define 	TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_ICR1                  8
#define 	TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_OCR1A                 9
#define 	TIMER_u8_TIMERS1_PWM_ICR1                               10
#define 	TIMER_u8_TIMERS1_PWM_OCR1A                              11
#define 	TIMER_u8_TIMERS1_CTC_ICR1                               12
#define 	TIMER_u8_TIMERS1_FAST_PWM_ICR1                          13
#define 	TIMER_u8_TIMERS1_FAST_PWM_OCR1A                         14

#define     NON_PWM_NORMAL_PORT_OPRETATION	                        0
#define     NON_PWM_TOOGLE_ON_COMPARE_MATCH							1
#define     NON_PWM_CLEAR_ON_COMPARE_MATCH	                        2
#define     NON_PWM_SET_ON_COMPARE_MATCH		                    3

#define		FAST_PWM_NORMAL_PORT_OPRETATION                         0
#define     FAST_PWM_TOGGLE_ON_COMPARE_MATCH                        1
#define     FAST_PWM_CLEAR_ON_COMPARE_MATCH                         2
#define     FAST_PWM_SET_ON_COMPARE_MATCH	                        3


#define     PHASE_PWM_NORMAL_PORT_OPRETATION                        0
#define     PHASE_PWM_TOGGLE_ON_COMPARE_MATCH                       1
#define     PHASE_PWM_CLEAR_ON_COMPARE_MATCH                        2
#define     PHASE_PWM_SET_ON_COMPARE_MATCH	                        3



/*********************************************************************************/
/*************************Public Functions Prototypes*****************************/
/*********************************************************************************/

/*********************************************************************************/
/********************************* TIMERR 0 **************************************/
/*********************************************************************************/

/*********************************************************************************/
/* Function: TIMER_voidTimer0Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer0							       	    **/
/*********************************************************************************/
void TIMER_voidTimer0Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCallBack		               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of Timer0							  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/* Copy_u8Timer0Index: TIMER_u8_TIMER0CM , TIMER_u8_TIMER0OV					**/
/*********************************************************************************/
void TIMER_voidTimer0SetCallBackOV(void (*Copy_pvNotificationFunction)(void),u8 Copy_u8Timer0Index);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCallBack		               				    **/
/* I/P Parameters: Copy_u8InterruptType								   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets Interrupt Of Overflow And Compare Match				**/
/* NOTE THAT: ENABLE THE GIE before using the interrupt 						**/
/*********************************************************************************/
/* Copy_u8InterruptType Options:  TIMER_u8_OVERFLOW_INT  , TIMER_u8_COMPARE_INT **/
/*********************************************************************************/
void TIMER_voidTimer0EnableInt(u8 Copy_u8InterruptType);

/*********************************************************************************/
/* Function: TIMER_voidTimer0DisableInt		               				   		**/
/* I/P Parameters: Copy_u8InterruptType								   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Clears Interrupt Of Overflow And Compare Match			**/
/*********************************************************************************/
/* Copy_u8InterruptType Options: TIMER_u8_OVERFLOW_INT  , TIMER_u8_COMPARE_INT	**/
/*********************************************************************************/
void TIMER_voidTimer0DisableInt(u8 Copy_u8InterruptType);

/*********************************************************************************/
/* Function: TIMER_voidTimer0ReadFlag		               				   		**/
/* I/P Parameters: Copy_u8FlagType								   			    **/
/* Returns:it returns  u8                                					    **/
/* Desc:This Function reads The Flag Of Overflow Or Compare Match				**/
/*********************************************************************************/
/* Copy_u8InterruptType Options: TIMER_u8_OVERFLOW_FLAG , TIMER_u8_COMPARE_FLAG **/
/*********************************************************************************/
u8 TIMER_voidTimer0ReadFlag(u8 Copy_u8FlagType);




/*********************************************************************************/
/*******************************   TIMERR 1   ************************************/
/*********************************************************************************/


/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1							       	    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly (OCR1A)		**/
/*********************************************************************************/
void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly (OCR1B)		**/
/*********************************************************************************/
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/
/* Copy_u16CaptureValue Options: Capture value assigned directly (ICR1)			**/
/*********************************************************************************/
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue);

/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/* NOTE THAT: ENABLE THE GIE before using the interrupt 						**/
/*********************************************************************************/
void ICU_voidInit(void);

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/*********************************************************************************/
u16 ICU_u16ReadInputCapture(void);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void);

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void));

#endif
