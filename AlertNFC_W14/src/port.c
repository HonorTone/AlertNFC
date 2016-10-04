/*******************************************************************************
 *
 * @file	port.c
 * @brief	This is Port program for S1C17M01/W22_W23 demonstration.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *			- 06/16/2014    1.10
 *				- Change source code.
 *
 ******************************************************************************/

#include <port.h>


/* --- global variable --- */
unsigned char key_start=0;
unsigned char key_stop=0;

// Interrupt flag.
unsigned short portP0xIntInputFlag = 0;				///< Port P0x interrupt flag.
unsigned short portP3xIntInputFlag = 0;
unsigned short portChatteringFlag = STATUS_DISABLE;	///< Chattering filter flag.

/****************************************************************************
 * initPort function.
 *
 * @brief	First, Clear interrupt flag.
 *			Next, Set Chattering filter.
 ***************************************************************************/
void initPort( void )
{

	// Clear Chattering filter flag.
		portChatteringFlag	= STATUS_DISABLE;

		/// Clear interrupt flag.
		portP3xIntInputFlag 	= 0;
		P3INTF					= 0x00FF;

		/// Set Chattering filter.
		if ( CLGOSC_OSC1EN == 1 ) {
			/// Disable write-protect.
			protectMisc( MSCPROT_PROTECT_OFF );

			PCLK_CLKSRC			= 1;	/// - Set clock source for chattering filter(OSC1).
			PCLK_CLKDIV			= 0;	/// - Set division ratio for clock source(1/1).
			PCLK_DBRUN			= 1;	/// - Clock supplied in DEBUG mode.
			portChatteringFlag	= STATUS_ENABLE;	/// Enable Chattering filter.

			/// Enable write-protect.
			protectMisc( MSCPROT_PROTECT_ON );
		}
	    //unsigned int i=0;
	    /// P43 set to the output.
		initPortOutputP4x( PORT_NO_PX3 );
		/// P43 set the interrupt.
		disablePortIntP4x( PORT_NO_PX3 );
		/// P30 set to the input.
		initPortInputP3x( PORT_NO_PX0 );
		/// P30 clear interrupt flag.
		clearPortIntP3x( PORT_NO_PX0 );
		/// P30 set the interrupt(LOW by HIGH).
		enablePortIntP3x( PORT_NO_PX0, PORT_INT_EDGE_FALLING );

		/// P31 set to the input.
		initPortInputP3x( PORT_NO_PX1 );
		/// P31 clear interrupt flag.
		clearPortIntP3x( PORT_NO_PX1 );

		/// P30 set the interrupt(LOW by HIGH).
		enablePortIntP3x( PORT_NO_PX1, PORT_INT_EDGE_FALLING );
		P0RCTL|=0x303;//p30,p31上拉



		/*

	*/
}


/****************************************************************************
 * initPortInputP0x function.
 *
 * @brief	Initialize general-purpose input port.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 ***************************************************************************/
void initPortInputP0x( unsigned char portNo )
{

	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Enable Chattering filter.
	if ( portChatteringFlag == STATUS_ENABLE) {
		P0CHATEN = ( P0CHATEN | ( 0x0001 << portNo ) );
	} else {
		P0CHATEN = ( P0CHATEN & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
	}

	/// Disable pull-up or pull-down resistor.
	P0RCTL = ( P0RCTL & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	P0RCTL = ( P0RCTL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	// Enable GPIO function.
	P0MODSEL = ( P0MODSEL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Set input port(Disable output port).
	P0IOEN = ( P0IOEN | ( 0x0100 << portNo ) );
	P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Initialize the interrupt.
	ILVPPORT = INTERRUPT_LEVEL3;
}
void initPortInputP3x( unsigned char portNo )
{
	//unsigned int i=0;
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Enable Chattering filter.
	if ( portChatteringFlag == STATUS_ENABLE) {
		P3CHATEN = ( P3CHATEN | ( 0x0001 << portNo ) );
	} else {
		P3CHATEN = ( P3CHATEN & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
	}

	/// Disable pull-up or pull-down resistor.
	//P3RCTL = ( P3RCTL & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	//P3RCTL = ( P3RCTL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
	P3RCTL = ( P3RCTL | ( 0x0001 << portNo ) );//设置成上拉
	P3RCTL = ( P3RCTL | ( 0x0100 << portNo ) );

	// Enable GPIO function.
	P3MODSEL = ( P3MODSEL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Set input port(Disable output port).
	P3IOEN = ( P3IOEN | ( 0x0100 << portNo ) );
	P3IOEN = ( P3IOEN & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Initialize the interrupt.
	ILVPPORT = INTERRUPT_LEVEL3;
}

/****************************************************************************
 * initPortOutputP0x function.
 *
 * @brief	Initialize general-purpose output port.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 ***************************************************************************/
void initPortOutputP0x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	// Enable GPIO function.
	P0MODSEL = ( P0MODSEL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Set output port(Disable input port).
	P0IOEN = ( P0IOEN | ( 0x0001 << portNo ) );
	P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
}
void initPortOutputP4x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	// Enable GPIO function.
	P4MODSEL = ( P4MODSEL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );

	/// Set output port(Disable input port).
	P4IOEN = ( P4IOEN | ( 0x0001 << portNo ) );
	P4IOEN = ( P4IOEN & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
}

/****************************************************************************
 * enablePortIntP0x function.
 *
 * @brief	Set port interrupt.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 * @param	edge			Interrupt edge.
 *	@li @c		PORT_INT_EDGE_RISING			Rising edge.
 *	@li @c		PORT_INT_EDGE_FALLING			Falling edge.
 ***************************************************************************/
void enablePortIntP0x( unsigned char portNo, unsigned char edge )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Clear interrupt flag.
	portP0xIntInputFlag = ( portP0xIntInputFlag & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
	P0INTF = ( P0INTF | ( 0x0001 << portNo ) );

	/// Set interrupt edge.
	if ( edge == PORT_INT_EDGE_FALLING ) {
		// Rising edge.
		P0INTCTL = ( P0INTCTL | ( 0x0100 << portNo ) );
	} else {
		// Falling edge.
		P0INTCTL = ( P0INTCTL & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	}

	// Enable interrupt.
	P0INTCTL = ( P0INTCTL | ( 0x0001 << portNo ) );
}
void enablePortIntP3x( unsigned char portNo, unsigned char edge )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Clear interrupt flag.
	portP3xIntInputFlag = ( portP3xIntInputFlag & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
	P3INTF = ( P3INTF | ( 0x0001 << portNo ) );

	/// Set interrupt edge.
	if ( edge == PORT_INT_EDGE_FALLING ) {
		// Rising edge.
		P3INTCTL = ( P3INTCTL | ( 0x0100 << portNo ) );
	} else {
		// Falling edge.
		P3INTCTL = ( P3INTCTL & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	}

	// Enable interrupt.
	P3INTCTL = ( P3INTCTL | ( 0x0001 << portNo ) );
}

/****************************************************************************
 * disablePortIntP0x function.
 *
 * @brief	Set port interrupt.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 ***************************************************************************/
void disablePortIntP0x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	// Disable interrupt.
	P0INTCTL = ( P0INTCTL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
}
void disablePortIntP4x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	// Disable interrupt.
	P4INTCTL = ( P4INTCTL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
}
void disablePortIntP3x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	// Disable interrupt.
	P3INTCTL = ( P3INTCTL & ( 0xFFFF ^ ( 0x0001 << portNo ) ) );
}

/****************************************************************************
 * intPortInput function.
 *
 * @brief	port input interrupt.
 ***************************************************************************/
void intPortInput( void )
{
	// Check interrupt flag(P0INTF).
	//asm("nop");
	if(isPortIntP3x(PORT_NO_PX0))
	{
		key_start=1;
		/// Clear interrupt flag.
		P3INTF = ( P3INTF | ( 0x0001 << PORT_NO_PX0 ) );
	}
	if(isPortIntP3x(PORT_NO_PX1))
	{
		key_stop=1;
		/// Clear interrupt flag.
		P3INTF = ( P3INTF | ( 0x0001 << PORT_NO_PX1 ) );
	}
}


/****************************************************************************
 * isPortIntP0x function.
 *
 * @brief	Check port interrupt flag.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 *
 * @retval	STATUS_NO_OCCURRED		No cause of interrupt occurred
 * @retval	STATUS_OCCURRED			Cause of interrupt occurred.
 ***************************************************************************/
int isPortIntP0x( unsigned char portNo )
{
	volatile unsigned short flag = P0INTF;
	int result = STATUS_NO_OCCURRED;

	if ( portNo > PORT_NO_PX7 ) {
		return result;
	}

	if ( 0 != ( flag & ( 0x0001 << portNo ) ) ) {
		result = STATUS_OCCURRED;
	}

	return result;
}
int isPortIntP3x( unsigned char portNo )
{
	volatile unsigned short flag = P3INTF;
	int result = STATUS_NO_OCCURRED;

	if ( portNo > PORT_NO_PX7 ) {
		return result;
	}

	if ( 0 != ( flag & ( 0x0001 << portNo ) ) ) {
		result = STATUS_OCCURRED;
	}

	return result;
}

/****************************************************************************
 * clearPortIntP0x function.
 *
 * @brief	Clear port interrupt flag.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 ***************************************************************************/
void clearPortIntP0x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Clear interrupt flag.
	P0INTF = ( P0INTF | ( 0x0001 << portNo ) );
}
void clearPortIntP3x( unsigned char portNo )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	/// Clear interrupt flag.
	P3INTF = ( P3INTF | ( 0x0001 << portNo ) );
}

/****************************************************************************
 * getPortOutputP0x function.
 *
 * @brief	Set output port data.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 *
 *	@retval		PORT_DATA_LOW					Low.
 *	@retval		PORT_DATA_HIGH					High.
 ***************************************************************************/
unsigned char getPortOutputP0x( unsigned char portNo )
{
	volatile unsigned short data = P0DAT;
	unsigned char result = PORT_DATA_LOW;

	if ( portNo > PORT_NO_PX7 ) {
		return result;
	}

	// Get output data.
	data = ( data & ( 0x0100 << portNo ) );

	if ( data != 0 ) {
		result = PORT_DATA_HIGH;
	}

	return result;
}


/****************************************************************************
 * setPortOutputP0x function.
 *
 * @brief	Set output port data.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 * @param	data			Port Data.
 *	@li @c		PORT_DATA_LOW					Low.
 *	@li @c		PORT_DATA_HIGH					High.
 ***************************************************************************/
void setPortOutputP0x( unsigned char portNo, unsigned char data )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	if ( data == PORT_DATA_HIGH ) {
		P0DAT = ( P0DAT | ( 0x0100 << portNo ) );
	} else {
		P0DAT = ( P0DAT & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	}
}
void setPortOutputP4x( unsigned char portNo, unsigned char data )
{
	if ( portNo > PORT_NO_PX7 ) {
		return;
	}

	if ( data == PORT_DATA_HIGH ) {
		P4DAT = ( P4DAT | ( 0x0100 << portNo ) );
	} else {
		P4DAT = ( P4DAT & ( 0xFFFF ^ ( 0x0100 << portNo ) ) );
	}
}

/****************************************************************************
 * getPortInputP0x function.
 *
 * @brief	Set output port data.
 *
 * @param	portNo			Port Number.
 *	@li @c		PORT_NO_PX0 to PORT_NO_PX7		Port Number.
 *	@li @c		others							Nothing is done.
 *
 *	@retval		PORT_DATA_LOW					Low.
 *	@retval		PORT_DATA_HIGH					High.
 ***************************************************************************/
unsigned char getPortInputP0x( unsigned char portNo )
{
	volatile unsigned short data = P0DAT;
	unsigned char result = PORT_DATA_LOW;

	if ( portNo > PORT_NO_PX7 ) {
		return result;
	}

	// Get output data.
	data = ( data & ( 0x0001 << portNo ) );

	if ( data != 0 ) {
		result = PORT_DATA_HIGH;
	}

	return result;
}
unsigned char getPortInputP3x( unsigned char portNo )
{
	volatile unsigned short data = P3DAT;
	unsigned char result = PORT_DATA_LOW;

	if ( portNo > PORT_NO_PX7 ) {
		return result;
	}

	// Get output data.
	data = ( data & ( 0x0001 << portNo ) );

	if ( data != 0 ) {
		result = PORT_DATA_HIGH;
	}

	return result;
}
