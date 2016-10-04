/****************************************************************************
 *
 * @file	clg.c
 * @brief	This is clg(osc) driver program file for S1C17M01/W22/W23.
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
 *			- 06/16/2014    1.20
 *				- Change source code.
 *
 ***************************************************************************/

#include "clg.h"


/****************************************************************************
 * startClgOSC1 function.
 *
 * @brief	Start OSC1.
 ***************************************************************************/
void startClgOSC1( void )
{
	/// It doesn't do at all when having already started.
	if ( CLGOSC_OSC1EN == 1 ) {
		return;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag(CLGINTF.OSC1STAIF and CLGINTF.OSC1STPIF).
	CLGINTF					= 0x0022;

	/// Enable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC1STAIE		= 1;

	CLGOSC_OSC1EN			= 0;	/// Stop OSC1.

	CLGOSC1				= 0x0001;	/// -###.-000.##00.--01  The following substitutions.
	//CLGOSC1_INV1N			= 0;	/// Set oscillation inverter gain(0 = Min).
	//CLGOSC1_CGI1			= 0;	/// Set internal gate capacitor(0 = Min).
	//CLGOSC1_OSC1WT		= 1;	/// Set oscillation stabilization waiting time(1 = 4096 clocks).

	asm("nop");
	asm("nop");
	asm("nop");

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	CLGOSC_OSC1EN			= 1;		/// Start oscillation.

	while ( CLGINTF_OSC1STAIF == 0 ) {
		asm("nop");		// wait ...
	}
}

/****************************************************************************
 * stopClgOSC1 function.
 *
 * @brief	Stop OSC1.
 ***************************************************************************/
void stopClgOSC1( void )
{
	CLGOSC_OSC1EN			= 0;		/// Stop OSC1.

	/// Disable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC1STAIE		= 0;

	/// Clear interrupt flag(CLGINTF.OSC1STAIF and CLGINTF.OSC1STPIF).
	CLGINTF					= 0x0022;
}

/****************************************************************************
 * enableClgStopDetectionOSC1 function.
 *
 * @brief	Enable oscillation stop detection function in OSC1.
 ***************************************************************************/
void enableClgStopDetectionOSC1( void )
{
	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	CLGOSC1				|= 0x6000;	/// -11#.-###.####.--**  **=01  The following substitutions.
	//CLGOSC1_OSDRB			= 1;	/// Enable OSC1 restart function.
	//CLGOSC1_OSDEN			= 1;	/// Enable oscillation stop detection function.

	/// Clear interrupt flag(CLGINTF.OSC1STPIF).
	CLGINTF					= 0x0020;

	/// Disable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC1STPIE		= 1;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );
}


/****************************************************************************
 * disableClgStopDetectionOSC1 function.
 *
 * @brief	Enable oscillation stop detection function in OSC1.
 ***************************************************************************/
void disableClgStopDetectionOSC1( void )
{
	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );
	CLGOSC1 			&= 0x9fff;	/// -00#.-###.####.--**  **=01  The following substitutions.
	//CLGOSC1_OSDRB			= 0;	/// Disable OSC1 restart function.
	//CLGOSC1_OSDEN			= 0;	/// Disable oscillation stop detection function.

	/// Disable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC1STPIE		= 0;

	/// Clear interrupt flag(CLGINTF.OSC1STPIF).
	CLGINTF					= 0x0020;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );
}


/****************************************************************************
 * isClgStopDetectionOSC1 function.
 *
 * @brief	oscillation stop detection function in OSC1.
 *
 * @retval	CLG_OSC1_STOP_DETECT		Stop detection.
 * @retval	CLG_OSC1_STOP_NO_DETECT		No stop detection.
 ***************************************************************************/
int isClgStopDetectionOSC1( void )
{
	int result = CLG_OSC1_STOP_NO_DETECT;

	if ( CLGINTF_OSC1STPIF == 1 ) {
		result = CLG_OSC1_STOP_DETECT;
	}

	return result;
}


#ifdef CLG_OSC3_ENABLE
/****************************************************************************
 * startClgOSC3 function.
 *
 * @brief	Start OSC3.
 *
 * @param	freq	Oscillation frequency.  (CLG_OSC3_SEL...)
 ***************************************************************************/
void startClgOSC3f( unsigned short freq )
{
	/// It doesn't do at all when having already started.
	if ( CLGOSC_OSC3EN == 1 ) {
		return;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag(CLGINTF.OSC3STAIF).
	CLGINTF					= 0x0004;

	/// Enable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC3STAIE		= 1;

	CLGOSC_OSC3EN			= 0;	/// Stop OSC3.

	CLGOSC3	= 0x0004 | ( freq << 10 );	/// ----.**00.--##.-100  **=freq  The following substitutions.
	//CLGOSC3_OSC3MD			= 0;	/// Select an oscillator type of the OSC3(0 = Internal oscillator).
	//CLGOSC3_OSC3WT			= 4;	/// Set the oscillation stabilization waiting time(4 = 1,024 clocks).
	//CLGOSC3_OSC3FQ			= 3;	/// Set the oscillation frequency when the internal oscillator.

	asm("nop");
	asm("nop");
	asm("nop");

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	CLGOSC_OSC3EN			= 1;		/// Start oscillation.

	while ( CLGINTF_OSC3STAIF == 0 ) {
		asm("nop");		// wait ...
	}
}
/****************************************************************************
 * startClgOSC3 function.
 *
 * @brief	Start OSC3.
 ***************************************************************************/
void startClgOSC3( void )
{
	/// It doesn't do at all when having already started.
	if ( CLGOSC_OSC3EN == 1 ) {
		return;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag(CLGINTF.OSC3STAIF).
	CLGINTF					= 0x0004;

	/// Enable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC3STAIE		= 1;

	CLGOSC_OSC3EN			= 0;	/// Stop OSC3.

	CLGOSC3_OSC3MD			= 0;	/// Select an oscillator type of the OSC3(0 = Internal oscillator).
	CLGOSC3_OSC3WT			= 4;	/// Set the oscillation stabilization waiting time(4 = 1,024 clocks).
	CLGOSC3_OSC3FQ			= 3;	/// Set the oscillation frequency when the internal oscillator(3 = 4 MHz).

	asm("nop");
	asm("nop");
	asm("nop");

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	CLGOSC_OSC3EN			= 1;		/// Start oscillation.

	while ( CLGINTF_OSC3STAIF == 0 ) {
		asm("nop");		// wait ...
	}
}

/****************************************************************************
 * stopClgOSC3 function.
 *
 * @brief	Stop OSC3.
 ***************************************************************************/
void stopClgOSC3( void )
{
	CLGOSC_OSC3EN			= 0;	/// Stop OSC3.

	/// Disable interrupt.(Please make the following effective when you use interrupt.)
	//CLGINTE_OSC3STAIE		= 0;

	/// Clear interrupt flag(CLGINTF.OSC3STAIF).
	CLGINTF					= 0x0004;
}

#endif	// CLG_OSC3_ENABLE


/****************************************************************************
 * startClgIOSC function.
 *
 * @brief	Start IOSC.
 ***************************************************************************/
void startClgIOSC( void )
{
	/// It doesn't do at all when having already started.
	if ( CLGOSC_IOSCEN == 1 ) {
		return;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag(CLGINTF.IOSCSTAIF).
	CLGINTF					= 0x0001;

	/// Enable interrupt.(Please make the following effective when you use interrupt.)
	///CLGINTE_IOSCSTAIE		= 1;

	CLGOSC_IOSCEN			= 0;	/// Stop IOSC.

	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	CLGOSC_IOSCEN			= 1;	/// Start oscillation.

	while ( CLGINTF_IOSCSTAIF == 0 ) {
		asm("nop");		// wait ...
	}
}

/****************************************************************************
 * stopClgIOSC function.
 *
 * @brief	Stop IOSC.
 ***************************************************************************/
void stopClgIOSC( void )
{
	CLGOSC_IOSCEN			= 0;	/// Stop IOSC.

	/// Disable interrupt.(Please make the following effective when you use interrupt.)
	///CLGINTE_IOSCSTAIE		= 0;

	/// Clear interrupt flag(CLGINTF.IOSCSTAIF and CLGINTF.IOSCTEDIF).
	CLGINTF					= 0x0011;
}

/****************************************************************************
 * runClgAutoTrimmingIOSC function.
 *
 * @brief	The auto-trimming function adjusts the IOSCCLK clock frequency by
 * 			trimming the clock with reference to the high precision OSC1CLK
 * 			clock generated by the OSC1 oscillator circuit.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int runClgAutoTrimmingIOSC( void )
{
	int status;

	// start OSC1.
	startClgOSC1();
	/// The system clock set to OSC1.
	status = switchClgSystemClockOSC1();
	if ( status == STATUS_NG ) {
		return STATUS_NG;
	}

	// stop and start IOSC.
	stopClgIOSC();
	startClgIOSC();

	// Check OSC1 and IOSC operation has completed.
	if ( ( CLGINTF & 0x0003 ) != 0x0003 ) {	// ----.----.--##.-#??  The following substitutions.
	//if ( CLGINTF_OSC1STAIF == 0 || CLGINTF_IOSCSTAIF == 0 ) {
		return STATUS_NG;
	}

	/// Clear interrupt flag(CLGINTF.IOSCTEDIF).
	CLGINTF					= 0x0010;

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Enable IOSC oscillation auto-trimming.
	CLGIOSC_IOSCSTM			= 1;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	/// Wait IOSC oscillation auto-trimming.
	while ( CLGINTF_IOSCTEDIF == 0 ) {
		asm("nop");		// wait ...
	}

	/// The system clock set to IOSC.
	status = switchClgSystemClockIOSC();

	return status;
}

/****************************************************************************
 * switchClgSystemClockOSC1 function.
 *
 * @brief	The system clock set in OSC1.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int switchClgSystemClockOSC1( void )
{
	/// When OSC1 doesn't start, nothing is done.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	CLGSCLK = (CLGSCLK & 0xffcc) | 0x0001;		/// Set system clock source(OSC1).
												/// Set division ratio of the clock source(1/1).


	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}




/****************************************************************************
 * switchClgSystemClockIOSC function.
 *
 * @brief	The system clock set in IOSC.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int switchClgSystemClockIOSC( void )
{
	/// When IOSC doesn't start, nothing is done.
	if ( CLGOSC_IOSCEN == 0 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Select the system clock source.
	CLGSCLK &= 0xffcc ;				/// Set system clock source(IOSC).
									/// Set division ratio of the clock source(1/1).


	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


#ifdef CLG_OSC3_ENABLE
/****************************************************************************
 * switchClgSystemClockOSC3 function.
 *
 * @brief	The system clock set in OSC3.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int switchClgSystemClockOSC3( void )
{
	/// When OSC3 doesn't start, nothing is done.
	if ( CLGOSC_OSC3EN == 0 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Select the system clock source.
	CLGSCLK = (CLGSCLK & 0xffcc) | 0x0002;		/// Set system clock source(OSC3).
												/// Set division ratio of the clock source(1/1).


	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


#endif	// CLG_OSC3_ENABLE

/****************************************************************************
 * setOsc1OperInSlp function.
 *
 * @brief	Set To OSC1SLPC.
 *
 ***************************************************************************/
void setOsc1OperInSlp(unsigned short osc1slpc)
{
	CLGOSC_OSC1SLPC = osc1slpc;
}


/****************************************************************************
 * setIoscOperInSlp function.
 *
 * @brief	Set To IOSCSLPC.
 *
 ***************************************************************************/
void setIoscOperInSlp(unsigned short ioscslpc)
{
	CLGOSC_IOSCSLPC = ioscslpc;
}


#ifdef CLG_OSC3_ENABLE
/****************************************************************************
 * setOsc3OperInSlp function.
 *
 * @brief	Set To OSC3SLPC.
 *
 ***************************************************************************/
void setOsc3OperInSlp(unsigned short osc3slpc)
{
	CLGOSC_OSC3SLPC = osc3slpc;
}
#endif	// CLG_OSC3_ENABLE

