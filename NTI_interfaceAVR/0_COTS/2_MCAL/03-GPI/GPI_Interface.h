/**********************************************************************/
/**********************  NAME    : MOHAMED HAMDY     ******************/
/**********************  DATE    :   14/6/2023       ******************/
/**********************  SWC     :      GPI      	 ******************/
/**********************  VERSION :      1.0          ******************/
/**********************************************************************/

#ifndef GPI_INTERFACE_H_
#define GPI_INTERFACE_H_


/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize General Interrupt Enable			       	    **/
/*********************************************************************************/
void GPI_voidInit   (void);

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function enables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidEnable (void);

/*********************************************************************************/
/* Function: GPI_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function disables General Interrupt Enable (GIE)		       	    **/
/*********************************************************************************/
void GPI_voidDisable(void);




#endif /* GPI_INTERFACE_H_ */
