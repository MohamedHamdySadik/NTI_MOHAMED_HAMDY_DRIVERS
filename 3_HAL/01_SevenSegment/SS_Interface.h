/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :      DIO          ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

/*File guard*/
#ifndef SS_INTERFACE_H
#define SS_INTERFACE_H
/*********************************************************************************/
/************************						**********************************/
/************************		  OBJECTS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/* Number of seven segment */
#define SS_u8_SS_NUM_1			0
#define SS_u8_SS_NUM_2			1
#define SS_u8_SS_NUM_3			2
#define SS_u8_SS_NUM_4			3
/*********************************************************************************/
/************************						**********************************/
/************************		FUNCTIONS		**********************************/
/************************						**********************************/
/*********************************************************************************/
/*********************************************************************************/
/* Function: SS_u8DisplayNum	                        					     */
/* I/P Parameters: Copy_u8Num				          		  				     */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8Num Options:0,1,2,3,4,5,6,7,8,9 										 */
/*********************************************************************************/
u8 SS_u8DisplayNum(u8 Copy_u8Num);

/*********************************************************************************/
/* Function: SS_u8Intial	                        						     */
/* I/P Parameters: Nothing				          		  					     */
/* Returns:it returns Nothing  			                          				 */
/* Desc:This Function intialization seven segment				      		     */
/*********************************************************************************/
void SS_u8Intial(void);

/*********************************************************************************/
/* Function: SS_u8Enable	                        					   		 */
/* I/P Parameters: Copy_u8SS_ENABLE_Num				          		  			 */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8SS_ENABLE_Num Options:  SS_u8_SS_NUM_1							  	 */
/*								  SS_u8_SS_NUM_2							  	 */
/*								  SS_u8_SS_NUM_3							  	 */
/*								  SS_u8_SS_NUM_4							  	 */
/*********************************************************************************/
u8 SS_u8Enable(u8 Copy_u8SS_ENABLE_Num);

/*********************************************************************************/
/* Function: SS_u8Disable	                        					  	     */
/* I/P Parameters: Copy_u8SS_DISABLE_Num				          		  		 */
/* Returns:it returns u8 Error state                                   			 */
/* Desc:This Function display the number on Seven Segment				         */
/*********************************************************************************/
/* Copy_u8SS_DISABLE_Num Options:  SS_u8_SS_NUM_1								 */
/*								   SS_u8_SS_NUM_2								 */
/*								   SS_u8_SS_NUM_3								 */
/*								   SS_u8_SS_NUM_4								 */
/*********************************************************************************/
u8 SS_u8Disable(u8 Copy_u8SS_DISABLE_Num);

#endif
