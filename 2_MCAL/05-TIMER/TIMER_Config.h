/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   19/6/2023       ******************/
/**********************  SWC     :     TIMER      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/**************************************************************************************************/
/************************** TIMER0 WAVEFORM_GEN_MODE OPTIONS ***************************************/
/* 			  	                    0  NORMAL_MODE                                                */
/*                                  1  PWM_OR_PHASE_COTROL                                        */
/*                                  2  CTC_MODE                                                   */
/*                                  3  FAST_PWM_MODE                                              */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	  TIMER_u8_TIMER0_WAVEFORM_GEN_MODE          TIMER_u8_TIMERS0_FAST_PWM_MODE

/*********************************Control action on OC0 pin****************************************/
/**********************************for Non-PWM Mode options****************************************/
/* 	1  NON_PWM_NORMAL_PORT_OPRETATION															  */
/*	2  NON_PWM_TOOGLE_OC0_ON_COMPARE_MATCH														  */
/*	3  NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH														  */
/*	4  NON_PWM_SET_OC0_ON_COMPARE_MATCH															  */
/**************************************************************************************************/
/***********************************FAST_PWM_MODE options******************************************/
/*  0  FAST_PWM_NORMAL_PORT_OPRETATION                                                            */
/*  1  FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH    (non inverted mode)     					          */
/*  2  FAST_PWM_SET_OC0_ON_COMPARE_MATCH	   (inverted mode)        					          */
/**************************************************************************************************/
/******************************PHASE_CORRECT_PWM_MODE options**************************************/
/*  0  PHASE_PWM_NORMAL_PORT_OPRETATION                                                           */
/*  1  PHASE_PWM_CLEAR_OC0_ON_COMPARE_MATCH    (non inverted mode)          				      */
/*  2  PHASE_PWM_SET_OC0_ON_COMPARE_MATCH	   (inverted mode)          				          */
/**************************************************************************************************/

/**************************************************************************************************/
#define 	 OC0_ACTION                 FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH

/**************************************************************************************************/
/**********************************PRESCALER_TYPE options******************************************/
/* 	TIMER_COUNTER_DISABLED              No clock source (Timer/Counter stopped).                  */
/*  CLK_DIV_BY_0				        (No   prescaling)                                         */
/*  CLK_DIV_BY_8				        (From prescaler)                                          */
/*  CLK_DIV_BY_64                       (From prescaler)                                          */
/* 	CLK_DIV_BY_256                      (From prescaler)                                          */
/*  CLK_DIV_BY_1024                     (From prescaler)                                          */
/*  ECS_ON_T0_FALLING_EDGE              External clock source on T0 pin. Clock on falling edge.   */
/*  ECS_ON_T0_RISING_EDGE               External clock source on T0 pin. Clock on rising edge     */
/* 	ECS_ON_T1_FALLING_EDGE              External clock source on T1 pin. Clock on falling edge.   */
/*  ECS_ON_T1_RISING_EDGE               External clock source on T1 pin. Clock on rising edge     */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	 PRESCALER_TYPE     CLK_DIV_BY_8

#define 	 PRESCALER_MASK     0b11111000


/*****************************************Timer1***************************************************/

/***************************************************************************************************/
/************************** TIMER0 WAVEFORM_GEN_MODE OPTIONS ***************************************/
/* 			  	                  0  TIMER_u8_TIMERS1_NORMAL									   */
/*                                1  TIMER_u8_TIMERS1_PWM_8BIT               					   */
/*                                2  TIMER_u8_TIMERS1_PWM_9BIT               					   */
/*                                3  TIMER_u8_TIMERS1_PWM_10BIT                                    */
/*                                4  TIMER_u8_TIMERS1_CTC_OCR1A                                    */
/*                                5  TIMER_u8_TIMERS1_FAST_PWM_8BIT                                */
/*                                6  TIMER_u8_TIMERS1_FAST_PWM_9BIT                                */
/*                                7  TIMER_u8_TIMERS1_FAST_PWM_10BIT                               */
/*                                8  TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_ICR1                        */
/*                                9  TIMER_u8_TIMERS1_PWM_FREQ_CORRECT_OCR1A                       */
/*                                10 TIMER_u8_TIMERS1_PWM_ICR1                                     */
/*                                11 TIMER_u8_TIMERS1_PWM_OCR1A                                    */
/*                                12 TIMER_u8_TIMERS1_CTC_ICR1                                     */
/*                                13 TIMER_u8_TIMERS1_FAST_PWM_ICR1                                */
/*                                14 TIMER_u8_TIMERS1_FAST_PWM_OCR1A                               */
/*                                                                                                 */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	  TIMER_u8_TIMER1_WAVEFORM_GEN_MODE          TIMER_u8_TIMERS1_FAST_PWM_ICR1

/******************************Control action on OC1A/OC1B pin*************************************/
/**********************************for Non-PWM Mode options****************************************/
/* 	1  NON_PWM_NORMAL_PORT_OPRETATION															  */
/*	2  NON_PWM_TOOGLE_ON_COMPARE_MATCH														      */
/*	3  NON_PWM_CLEAR_ON_COMPARE_MATCH														      */
/*	4  NON_PWM_SET_ON_COMPARE_MATCH															      */
/**************************************************************************************************/
/***********************************FAST_PWM_MODE options******************************************/
/*  0  FAST_PWM_NORMAL_PORT_OPRETATION                                                            */
/*	1  FAST_PWM_TOGGLE_ON_COMPARE_MATCH                                                           */
/*  2  FAST_PWM_CLEAR_ON_COMPARE_MATCH    (non inverted mode)     					              */
/*  3  FAST_PWM_SET_ON_COMPARE_MATCH	   (inverted mode)        					              */
/**************************************************************************************************/
/******************************PHASE_CORRECT_PWM_MODE options**************************************/
/*  0  PHASE_PWM_NORMAL_PORT_OPRETATION                                                           */
/*  1  PHASE_PWM_TOGGLE_ON_COMPARE_MATCH  					          				              */
/*  2  PHASE_PWM_CLEAR_ON_COMPARE_MATCH   					       				                  */
/*  3  PHASE_PWM_SET_ON_COMPARE_MATCH	                                                          */
/**************************************************************************************************/
#define				OC1A_ACTION							FAST_PWM_CLEAR_ON_COMPARE_MATCH
#define 			OC1B_ACTION							NON_PWM_NORMAL_PORT_OPRETATION

#endif
