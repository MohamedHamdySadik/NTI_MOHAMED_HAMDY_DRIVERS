/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   14/6/2023       ******************/
/**********************  SWC     :      EXIT      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/
/**********************************************************************/
/*********************************************************************************/
/************************						**********************************/
/************************	  	 INCLUDE		**********************************/
/************************						**********************************/
/*********************************************************************************/
/* Lib layer */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/* MCAL */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/EXTI/EXTI_private.h"
#include "MCAL/EXTI/EXTI_Config.h"

/**Array of pointers to function**/
static void (*pf[3]) (void)={NULL,NULL,NULL};


/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
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

void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense)
{
    //Input Validation
    if( (Copy_u8EXTINo > EXTI_u8_EXTI2) || (Copy_u8EXTISense > EXTI_u8_RISING_EDGE) )
    {
        
    }
    else if ((Copy_u8EXTINo == EXTI_u8_EXTI2) && (Copy_u8EXTISense < 2))
	{

	}
    else
    {
        switch(Copy_u8EXTINo)
        {
            case EXTI_u8_EXTI0: SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT0);
                                switch(Copy_u8EXTISense)
                                {
                                    case EXTI_u8_LOW_LEVEL:             CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
                                                                        CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
                                                                        break;
                                    case EXTI_u8_ANY_LOGICAL_CHANGE:    SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
                                                                        CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
                                                                        break;
                                    case EXTI_u8_FALLING_EDGE:          CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
                                                                        SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
                                                                        break;
                                    case EXTI_u8_RISING_EDGE:           SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
                                                                        SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
                                                                        break;
                                }
                                break;
            case EXTI_u8_EXTI1: SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT1);
                                switch(Copy_u8EXTISense)
                                {
                                    case EXTI_u8_LOW_LEVEL:             CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
                                                                        CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
                                                                        break;
                                    case EXTI_u8_ANY_LOGICAL_CHANGE:    SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
                                                                        CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
                                                                        break;
                                    case EXTI_u8_FALLING_EDGE:          CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
                                                                        SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
                                                                        break;
                                    case EXTI_u8_RISING_EDGE:           SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
                                                                        SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
                                                                        break;
                                }
                                break;
            case EXTI_u8_EXTI2: SET_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT2);
                                switch(Copy_u8EXTISense)
                                {
                                    case EXTI_u8_FALLING_EDGE:          CLR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);     break;
                                    case EXTI_u8_RISING_EDGE:           SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);     break;
                                }
                                break;
        }
    }
}

/*********************************************************************************/
/* Function: EXTI_voidEXTIDisable	                        				    **/
/* I/P Parameters: Copy_u8EXTINo 							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables a specific EXTI Peripheral				       	**/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo)
{
    //Input Validation
    if( (Copy_u8EXTINo > EXTI_u8_EXTI2))
    {
        
    }
    else
    {
        switch(Copy_u8EXTINo)
        {
            case EXTI_u8_EXTI0: CLR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT0);       break;                 
            case EXTI_u8_EXTI1: CLR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT1);       break;
            case EXTI_u8_EXTI2: CLR_BIT(EXTI_u8_GICR_REG, EXTI_u8_GICR_INT2);       break;
        }
    }
}

/*********************************************************************************/
/* Function: EXTI_voidSetCallBack	                        				    **/
/* I/P Parameters: void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex    		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the global pointer to function with passed function  **/
/*********************************************************************************/
/*  Copy_u8EXTINo Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2          **/
/*                                                                              **/
/*********************************************************************************/
void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex)
{
    pf[Copy_u8EXTIIndex] = Copy_PtrToFunc;
}

/*********************************************************************************/
/* Function: EXTi_voidGetFlag	                        				   		**/
/* I/P Parameters: u8 Copy_u8EXTIFlage    		 								**/
/* Returns:it returns u8		                              				    **/
/* Desc:This Function get the flag of EXTI 										**/
/*********************************************************************************/
/*  Copy_u8EXTIFlage Options: EXTI_u8_EXTI0, EXTI_u8_EXTI1, EXTI_u8_EXTI2       **/
/*                                                                              **/
/*********************************************************************************/
u8 EXTi_voidGetFlag(u8 Copy_u8EXTIFlage)
{
	u8 Local_u8FlagRead;
	if(Copy_u8EXTIFlage > EXTI_u8_EXTI2)
	{
		/* Warning Invaled entry */
	}
	else
	{
		switch(Copy_u8EXTIFlage)
		{
			case EXTI_u8_EXTI0:
			Local_u8FlagRead = GET_BIT(EXTI_u8_GIFR_REG,EXTI_u8_GIFR_INTF0);
			break;
			
			case EXTI_u8_EXTI1:
			Local_u8FlagRead = GET_BIT(EXTI_u8_GIFR_REG,EXTI_u8_GIFR_INTF1);
			break;
			
			case EXTI_u8_EXTI2:
			Local_u8FlagRead = GET_BIT(EXTI_u8_GIFR_REG,EXTI_u8_GIFR_INTF2);
			break;
			default:
			break;
			
		}
	}
	return Local_u8FlagRead;
}



void GIE_voidDisable()
{
	
	/***********************************************************/	
	/** !comment : From Data Sheet : To Disable GIE you must   */
	/**            cleare Bit Number 7 in SREG REGISTER by 0   */
	/***********************************************************/
	
	CLEAR_BIT(SREG , 7);
	
}
void GIE_voidEnable()
{
	
	/***********************************************************/	
	/** !comment : From Data Sheet : To Enable GIE you must	   */
	/**            set Bit Number 7 in SREG REGISTER by 1      */
	/***********************************************************/

	SET_BIT(SREG , 7);
	
}

/***********************************EXTI0 ISR***********************************/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)   
{
    if(pf[EXTI_u8_EXTI0] != NULL)
    {
        pf[EXTI_u8_EXTI0]();
    }
}

/***********************************EXTI1 ISR***********************************/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)   
{
    if(pf[EXTI_u8_EXTI1] != NULL)
    {
        pf[EXTI_u8_EXTI1]();
    }
}

/***********************************EXTI2 ISR***********************************/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)   
{
    if(pf[EXTI_u8_EXTI2] != NULL)
    {
        pf[EXTI_u8_EXTI2]();
    }
}
