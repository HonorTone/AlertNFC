/****************************************************************************
 *
 * @file	uart.c
 * @brief	This is UART driver program file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2014. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *			- 03/27/2014    1.10
 *				- Change source code.
 *
 ***************************************************************************/

#include <uart.h>

void intUART0(void)		__attribute__ ((interrupt_handler));
unsigned char  intUARTBuf[32];
unsigned char 	intUARTBuf_pos;

/****************************************************************************
 * initUart function.
 *
 * @brief	initialize UART.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int initUart( void )
{
	/// When IOSC doesn't start, nothing is done.
	if ( CLGOSC_OSC3EN == 0 ) {
		return STATUS_NG;
	}

	/// Stop UART.
	stopUart();

	/// Initialize the UART input/output function to the ports.
	P3IOEN_P37IEN		= 0;			/// - P37 : Disable input.
	P3IOEN_P37OEN		= 0;			/// - P37 : Disable output.
	P3MODSEL_P37SEL		= 0;			/// - P37 : Disable peripheral I/O function.
	P3IOEN_P36IEN		= 0;			/// - P36 : Disable input.
	P3IOEN_P36OEN		= 0;			/// - P36 : Disable output.
	P3MODSEL_P36SEL		= 0;			/// - P36 : Disable peripheral I/O function.


	/// Assign the UART input/output function to the ports.
	P3FNCSEL_P37MUX		= 1;			/// - P37 : UPMUX.
	P3MODSEL_P37SEL		= 1;			/// - P37 : Enable peripheral I/O function.
	P3FNCSEL_P36MUX		= 1;			/// - P36 : UPMUX.
	P3MODSEL_P36SEL		= 1;			/// - P36 : Enable peripheral I/O function.

	/// Set Universal Port Multiplexer (UPMUX).
	P3UPMUX3_P37PERISEL	= 3;			/// - P41 : UART.
	P3UPMUX3_P37PPFNC	= 1;			/// - P41 : USIN.
	P3UPMUX3_P37PERICH	= 0;			/// - P41 : Ch.0.
	P3UPMUX3_P36PERISEL	= 3;			/// - P42 : UART.
	P3UPMUX3_P36PPFNC	= 2;			/// - P42 : USOUT.
	P3UPMUX3_P36PERICH	= 0;			/// - P42 : Ch.0.

	/// Configure operating clock.
	UA0CLK_CLKSRC		= 2;			/// - Select the clock source of the UART(OSC3).
	UA0CLK_CLKDIV		= 3;			/// - Select the division ratio(1/8).
	UA0CLK_DBRUN		= 1;			/// - Clock supplied in DEBUG mode.

	/// The clock source operations in SLEEP mode.
	CLGOSC_IOSCSLPC		= 0;			/// - Continue operation state before SLEEP.

	/// Configure the following UA0MOD register bits.
	UA0MOD_PUEN			= 1;			/// - Set USIN0 pin(0=Disable pull-up / 1=Enable pull-up).
	UA0MOD_OUTMD		= 0;			/// - Set USOUT0 pin(0=Push-pull output / 1=open-drain output).
	UA0MOD_IRMD			= 0;			/// - IrDA interface(0=Disable / 1=Enable).
	UA0MOD_CHLN			= 1;			/// - Data length(0=7-bit  / 1=8-bit).
	UA0MOD_PREN			= 0;			/// - Parity function(0=Disable / 1=Enable).
	UA0MOD_PRMD			= 0;			/// - Even parity selection(0=Unused / 1=Used).
	UA0MOD_STPB			= 0;			/// - Stop bit length(0=1-bit  / 1=2-bit).

	/// Set transfer rate( bps = CLK_UART / {(BRT + 1) x 16 + FMD} ).
	/// - S1C17M01     : 460800 bps = 7.37MHz / 16 = 460625(-0.038%).
	/// - S1C17W22_W23 :  43750 bps =  700KHz / 16 = 43750.
	///									32768/27 = 1213
	///                                 4MHz     =9600
	UA0BR_BRT			= 0x2;			/// - BRT : 0
	UA0BR_FMD			= 4;			///	- FMD : 0

	UA0INTE_RB1FIE = 1;
	/// Set interrupt level.
	ILVUART_0			= INTERRUPT_LEVEL1;	/// - Set interrupt level-0.

	intUARTBuf_pos = 0;
	return STATUS_OK;
}


/****************************************************************************
 * startUart function.
 *
 * @brief	Set UART enable.
 ***************************************************************************/
void startUart( void )
{
	/// Execute software reset.
	UA0CTL_SFTRST		= 1;
	while( UA0CTL_SFTRST == 1 ) {
		// Wait...
	}

	/// Enable UART Ch.0 operations.
	UA0CTL_MODEN		= 1;
}


/****************************************************************************
 * stopUart function.
 *
 * @brief	Set UART enable.
 ***************************************************************************/
void stopUart( void )
{
	/// Disable UART Ch.0 operations.
	UA0CTL_MODEN		= 0;

	/// Execute software reset.
	UA0CTL_SFTRST		= 1;
	while( UA0CTL_SFTRST == 1 ) {
		// Wait...
	}
}


/****************************************************************************
 * sendUartData function.
 *
 * @brief	UART transmit data write.
 *
 * @param	data	Pointer of transmit data.
 * @param	size	Transmit data size.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int sendUartData( unsigned char *data, unsigned short size )
{
	unsigned short i;

	// Send data.
	for ( i = 0 ; i < size ; i++ ) {

		/// Check Transmit buffer empty interrupt.
		while ( UA0INTF_TBEIF == 0 ) {
			// Wait...
		}

		/// Send data.
		UA0TXD_TXD = data[i];
	}

	return STATUS_OK;
}


/****************************************************************************
 * receiveUartData function.
 *
 * @brief	UART receive data read.
 *
 * @param	data	Pointer of receive data.
 * @param	size	Receive data size.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int receiveUartData( unsigned char *data, unsigned short size )
{
	unsigned short i;


	/// Receive data.
/*
	for ( i = 0 ; i < size ; i++ ) {

		/// Check receive buffer one byte full interrupt.
		while ( UA0INTF_RB1FIF == 0 ) {
			// Wait...
		}

		/// Read receive data.
		data[i]	= UA0RXD_RXD;

	}
*/
	while (intUARTBuf_pos < size) ;

	for ( i = 0 ; i < size ; i++ ) {
		data[i] = intUARTBuf[i];
	}
	intUARTBuf_pos = 0;

	return STATUS_OK;
}

/****************************************************************************
 * intUART0 function.
 *
 * @brief	UART receive data interrupt.
 *

 ***************************************************************************/
void intUART0(void)
{
	if (UA0INTF_RB1FIF)
	{
		intUARTBuf[intUARTBuf_pos++] = UA0RXD_RXD;
		if (intUARTBuf_pos >= 32)
			intUARTBuf_pos = 0;
	}
	if (UA0INTF_OEIF)
		UA0INTF_OEIF = 1;
	if (UA0INTF_PEIF)
		UA0INTF_PEIF = 1;
	if (UA0INTF_FEIF)
		UA0INTF_FEIF = 1;
}

