/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   14/6/2023       ******************/
/**********************  SWC     :      EXIT      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/*********************************************************************************/
/* Function: EXTI_voidEXTIEnable	                        				    **/
/* I/P Parameters: Copy_u8EXTINo, u8 Copy_u8EXTISense		          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables a specific EXTI Peripheral				       	**/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*  Copy_u8EXTISense Options:                                                   **/
/*  EXTI_u8_LOW_LEVEL , EXTI_u8_ANY_LOGICAL_CHANGE,                             **/
/*  EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE									**/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense);



/*********************************************************************************/
/* Function: EXTI_voidEXTIDisable	                        				    **/
/* I/P Parameters: Copy_u8EXTINo 							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables a specific EXTI Peripheral				       	**/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo);


/*********************************************************************************/
/* Function: EXTI_voidSetCallBack	                        				    **/
/* I/P Parameters: void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex    		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the global pointer to function with passed function  **/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex);


/*********************************************************************************/
/* Function: EXTi_voidGetFlag	                        				   		**/
/* I/P Parameters: u8 Copy_u8EXTIFlage    		 								**/
/* Returns:it returns u8		                               				    **/
/* Desc:This Function get the flag of EXTI 										**/
/*********************************************************************************/
/*  Copy_u8EXTIFlage Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2       **/
/*                                                                              **/
/*********************************************************************************/
u8 EXTi_voidGetFlag(u8 Copy_u8EXTIFlage);

#endif
