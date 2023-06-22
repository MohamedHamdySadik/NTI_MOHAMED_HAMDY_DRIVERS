/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   14/6/2023       ******************/
/**********************  SWC     :      GPI      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#ifndef GPI_PRIVATE_H_
#define GPI_PRIVATE_H_

/*Registers and their bits Macros*/
#define GPI_u8_SREG  *((volatile u8 *)0x5f)

#define GPI_u8_INTERRUPT_ENABLE_BIT   7

/*Other private macros*/
#define GPI_u8_ENABLE   1
#define GPI_u8_DISABLE  0

#endif /* GPI_PRIVATE_H_ */
