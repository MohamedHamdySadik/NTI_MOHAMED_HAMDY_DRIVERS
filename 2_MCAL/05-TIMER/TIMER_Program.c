/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   19/6/2023       ******************/
/**********************  SWC     :     TIMER      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*********************************************************************************/
/************************						**********************************/
/************************	  	 INCLUDE		**********************************/
/************************						**********************************/
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_Interface.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"


static void (* TIMER_pvTimer0NotificationFunction[2])(void) = {NULL,NULL};
void (* TIMER_pvICUNotificationFunction)(void) = NULL;


/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
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
void TIMER_voidTimer0Init(void)
{
	#if TIMER_u8_TIMER0_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS0_NORMAL_MODE
	/*Set Timer 0 in NORMAL_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

	#elif TIMER_u8_TIMER0_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS0_PWM_OR_PHASE_COTROL
	/*Set Timer 0 in PWM_OR_PHASE_COTROL Mode*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case PHASE_PWM_CLEAR_OC0_ON_COMPARE_MATCH:					/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case PHASE_PWM_SET_OC0_ON_COMPARE_MATCH:					/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		default: break;
	}

	#elif TIMER_u8_TIMER0_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS0_CTC_MODE
	/*Set Timer 0 in CTC_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION:				/*Normal Port Operation*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH:	        /*Toggle OC0 on Compare Match*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	        /*Clear OC0 on Compare Match*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case NON_PWM_SET_OC0_ON_COMPARE_MATCH:	            /*Set OC0 on Compare Match*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		default: break;
	}

	#elif TIMER_u8_TIMER0_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS0_FAST_PWM_MODE
	/*Set Timer 0 in FAST_PWM_MODE*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
		CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		case FAST_PWM_SET_OC0_ON_COMPARE_MATCH:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
		default: break;
	}
	#endif

	/*Set The Prescaler to be 8*/
	TIM0_u8_TCCR0_REG &= PRESCALER_MASK;
	TIM0_u8_TCCR0_REG |= PRESCALER_TYPE;
}


/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue)
{
	/*Set The Compare Value to the OCR0 Register*/
	TIM0_u8_OCR0_REG = Copy_u8CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCallBack		               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of Timer0							  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/* Copy_u8Timer0Index: TIMER_u8_TIMER0CM , TIMER_u8_TIMER0OV					**/
/*********************************************************************************/
void TIMER_voidTimer0SetCallBackOV(void (*Copy_pvNotificationFunction)(void),u8 Copy_u8Timer0Index)
{
	/*Assign the function address to the global pointer to function*/
	TIMER_pvTimer0NotificationFunction[Copy_u8Timer0Index] = Copy_pvNotificationFunction;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer0EnableInt			               				    **/
/* I/P Parameters: Copy_u8InterruptType								   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets Interrupt Of Overflow And Compare Match				**/
/* NOTE THAT: ENABLE THE GIE before using the interrupt 						**/
/*********************************************************************************/
/* Copy_u8InterruptType Options:  TIMER_u8_OVERFLOW_INT  , TIMER_u8_COMPARE_INT **/
/*********************************************************************************/
void TIMER_voidTimer0EnableInt(u8 Copy_u8InterruptType)
{
	switch(Copy_u8InterruptType)
	{
		case TIMER_u8_OVERFLOW_INT:
		SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_TOIE0);
		break;
		case TIMER_u8_COMPARE_INT:
		SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_OCIE0);
		break;
		default:break;
	}
	
}
/*********************************************************************************/
/* Function: TIMER_voidTimer0DisableInt		               				   		**/
/* I/P Parameters: Copy_u8InterruptType								   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Clears Interrupt Of Overflow And Compare Match			**/
/*********************************************************************************/
/* Copy_u8InterruptType Options: TIMER_u8_OVERFLOW_INT  , TIMER_u8_COMPARE_INT	**/
/*********************************************************************************/
void TIMER_voidTimer0DisableInt(u8 Copy_u8InterruptType)
{
	switch(Copy_u8InterruptType)
	{
		case TIMER_u8_OVERFLOW_INT:
		CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_TOIE0);
		break;
		case TIMER_u8_COMPARE_INT:
		CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TIMSK_OCIE0);
		break;
		default:
		break;
	}
	
	
}

/*********************************************************************************/
/* Function: TIMER_voidTimer0ReadFlag		               				   		**/
/* I/P Parameters: Copy_u8FlagType								   			    **/
/* Returns:it returns  u8                                					    **/
/* Desc:This Function reads The Flag Of Overflow Or Compare Match				**/
/*********************************************************************************/
/* Copy_u8InterruptType Options: TIMER_u8_OVERFLOW_FLAG , TIMER_u8_COMPARE_FLAG **/
/*********************************************************************************/
u8 TIMER_voidTimer0ReadFlag(u8 Copy_u8FlagType)
{
	u8 Local_u8flagCarry=0;
	switch(Copy_u8FlagType)
	{
		case TIMER_u8_OVERFLOW_FLAG:
		Local_u8flagCarry = GET_BIT(TIM0_u8_TIFR_REG,TIM0_u8_TIFR_TOV0);
		break;
		
		case TIMER_u8_COMPARE_FLAG:
		Local_u8flagCarry = GET_BIT(TIM0_u8_TIFR_REG,TIM0_u8_TIFR_OCF0);
		break;
		
		default:
		break;
	}
	
	return Local_u8flagCarry;
}



/*********************************************************************************/
/********************************* TIMERR 1 **************************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1 									    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void)
{
	
	#if TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_NORMAL
	/*Select The Normal Mode*/
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	
	
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_8BIT
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	
	
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_9BIT
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	
	
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_10BIT
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_CTC_OCR1A
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_TOOGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_TOOGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_FAST_PWM_8BIT
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_FAST_PWM_9BIT
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}

	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_FAST_PWM_10BIT
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_ICR1
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_OCR1A
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_ICR1
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_PWM_OCR1A
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case PHASE_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case PHASE_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_CTC_ICR1
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_TOOGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case NON_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_TOOGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case NON_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_FAST_PWM_ICR1
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#elif TIMER_u8_TIMER1_WAVEFORM_GEN_MODE == TIMER_u8_TIMERS1_FAST_PWM_OCR1A
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);
	switch (OC1A_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1A1);
		break;
		
		
	}
	switch (OC1B_ACTION)
	{
		case FAST_PWM_NORMAL_PORT_OPRETATION :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_TOGGLE_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_CLEAR_ON_COMPARE_MATCH :
		
		CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		case FAST_PWM_SET_ON_COMPARE_MATCH :
		
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B0);
		SET_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_COM1B1);
		break;
		
		
	}
	#endif
	
	
	
	/*Set Prescaler to be 8*/
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS10);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS12);
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel A Register*/
	TIM1_u16_OCR1A_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel B Register*/
	TIM1_u16_OCR1B_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/
/* Copy_u16CaptureValue Options: Capture value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue)
{
	/*Set The Input Capture Value to ICR1 Register*/
	TIM1_u16_ICR1_REG = Copy_u16CaptureValue;
}

/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/* NOTE THAT: ENABLE THE GIE before using the interrupt 						**/
/*********************************************************************************/
void ICU_voidInit(void)
{
	/*Set Trigger to rising edge initially*/
	SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_TCCR1B_ICES1);

	/*Enable The ICU Interrupt*/
	SET_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource)
{
	switch(Copy_u8TriggerSource)
	{
		case RISING_EDGE:
		/*Set The Rising Edge to be the trigger source*/
		SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
		break;
		case FALLING_EDGE:
		/*Set The Falling Edge to be the trigger source*/
		CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
		break;
		default:
		break;
	}
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/*********************************************************************************/
u16 ICU_u16ReadInputCapture(void)
{
	/*Get The Captured Value From ICR1 Register*/
	return TIM1_u16_ICR1_REG;
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void)
{
	/*Disable The ICU Interrupt*/
	CLR_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	TIMER_pvICUNotificationFunction = Copy_pvNotificationFunction;
}






/***********************************Timer0 ISR forCompare Match Event***********************************/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	/*Check if the global pointer to function is changed or not*/
	if(TIMER_pvTimer0NotificationFunction[TIMER_u8_TIMER0CM] != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvTimer0NotificationFunction[TIMER_u8_TIMER0CM]();
	}
}
/***********************************Timer0 ISR for OVERFLOW Event***********************************/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	/*Check if the global pointer to function is changed or not*/
	if(TIMER_pvTimer0NotificationFunction[TIMER_u8_TIMER0OV] != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvTimer0NotificationFunction[TIMER_u8_TIMER0OV]();
	}
}

/***********************************ISR for ICU Capture Event***********************************/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER_pvICUNotificationFunction != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvICUNotificationFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}
