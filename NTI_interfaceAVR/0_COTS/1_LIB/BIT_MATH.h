/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   12/6/2023       ******************/
/**********************  SWC     :   STD_TYPES       ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/************** BIT MANUPLATION *********************/
#define SET_BIT(REG,BitNo) REG |= (1<<BitNo)
#define CLR_BIT(REG,BitNo) REG &= (~(1<<BitNo))
#define TOG_BIT(REG,BitNo) REG ^= (1<<BitNo)
#define GET_BIT(REG,BitNo) ((REG>>BitNo) & 0x01)

/************** FUNCTION CONCATENATION *********************/
#define CONC(P7,P6,P5,P4,P3,P2,P1,P0)       CONC_HELP(P7,P6,P5,P4,P3,P2,P1,P0)
#define CONC_HELP(P7,P6,P5,P4,P3,P2,P1,P0)  P7##P6##P5##P4##P3##P2##P1##P0

#endif