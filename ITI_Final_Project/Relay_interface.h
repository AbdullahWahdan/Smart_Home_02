/*
 * Relay_interface.h
 *
 * Created: 9/12/2023 9:52:36 PM
 * Author : Hima
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

/**********************************************************************
* Function Name: Relay_Vid_Init
* Purpose:		 Initialize Relay
* Parameters:	 void
* Return value:	 void
**********************************************************************/
void Relay_Vid_Init();

/**********************************************************************
* Function Name: Relay_Vid_ON
* Purpose:		 Activate Relay
* Parameters:	 void
* Return value:	 void
**********************************************************************/
void Relay_Vid_ON();

/**********************************************************************
* Function Name: Relay_Vid_OFF
* Purpose:		 Deactivate Relay
* Parameters:	 void
* Return value:	 void
**********************************************************************/
void Relay_Vid_OFF();

#endif /* RELAY_INTERFACE_H_ */