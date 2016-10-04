/*******************************************************************************
 *
 * @file	pwg2.c
 * @brief	This is Power Generator program for S1C17W22/W23 demonstration.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 09/17/2013    1.00
 *				- First revision.
 *			- 06/16/2014    1.10
 *				- Change source code.
 *
 ******************************************************************************/

#include <pwg2.h>


/****************************************************************************
 * setPwg2ModeNormal function.
 *
 * @brief	Set Normal mode.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setPwg2ModeNormal( void )
{
	/// When OSC1 doesn't start, return STATUS_NG.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// When changing from Super economy, return STATUS_NG.
	if ( PWGCTL_PWGMOD == 5 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Set Normal mode.
	PWGCTL_PWGMOD		= 2;	/// - Mode(0:Auto/2:Normal/3:Economy/5:Super economy).

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


/****************************************************************************
 * setPwg2ModeEconomy function.
 *
 * @brief	Set Economy mode.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setPwg2ModeEconomy( void )
{
	unsigned char mode = PWGCTL_PWGMOD;

	/// When OSC1 doesn't start, return STATUS_NG.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// When OSC3 or IOSC start, return STATUS_NG.
	if ( CLGOSC_OSC3EN == 1 || CLGOSC_IOSCEN == 1 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag.
	//PWGINTF_MODCMPIF	= 1;
	PWGINTF				= 0x0001;

	/// Set Economy mode.
	PWGCTL_PWGMOD		= 3;	/// - Mode(0:Auto/2:Normal/3:Economy/5:Super economy).

	/// When changing from Super economy to Economy.
	if ( mode == 5 ) {
		while ( PWGINTF_MODCMPIF == 0 ) {
			// Wait...
		}
	}

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


/****************************************************************************
 * setPwg2ModeSuperEconomy function.
 *
 * @brief	Set Super economy mode.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setPwg2ModeSuperEconomy( void )
{
	/// When OSC1 doesn't start, return STATUS_NG.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// When OSC3 or IOSC or EXOSC start, return STATUS_NG.
	if ( CLGOSC_OSC3EN == 1 || CLGOSC_IOSCEN == 1 || CLGOSC_EXOSCEN == 1 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// OSC1 only will operate SLEEP mode.
	CLGOSC_IOSCSLPC = 1;
	CLGOSC_EXOSCSLPC = 1;

	/// Clear interrupt flag.
	//PWGINTF_MODCMPIF	= 1;
	PWGINTF				= 0x0001;

	/// Set the charge pump operating clock(select an OSC1 clock division ratio).
	PWGTIM_DCCCLK		= 1;	/// - Division ratio(0:1/32 1:1/64 2:1/128 3:1/256).

	/// Set Economy mode.
	PWGCTL_PWGMOD		= 5;	/// - Mode(0:Auto/2:Normal/3:Economy/5:Super economy).

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


/****************************************************************************
 * setPwg2ModeAuto function.
 *
 * @brief	Set Auto mode.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setPwg2ModeAuto( void )
{
	unsigned char mode = PWGCTL_PWGMOD;

	/// When OSC1 doesn't start, return STATUS_NG.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// When OSC3 or IOSC start, return STATUS_NG.
	if ( CLGOSC_OSC3EN == 1 || CLGOSC_IOSCEN == 1 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag.
	//PWGINTF_MODCMPIF	= 1;
	PWGINTF				= 0x0001;

	/// Set Economy mode.
	PWGCTL_PWGMOD		= 0;	/// - Mode(0:Auto/2:Normal/3:Economy/5:Super economy).

	/// When changing from Super economy to Economy.
	if ( mode == 5 ) {
		while ( PWGINTF_MODCMPIF == 0 ) {
			// Wait...
		}
	}

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


/****************************************************************************
 * getPwg2Mode function.
 *
 * @brief	Get PWG2 mode.
 *
 * @retval	PWG2_MODE_AUTO				Auto Mode.
 * @retval	PWG2_MODE_NORMAL			Normal Mode.
 * @retval	PWG2_MODE_ECONOMY			Economy Mode.
 * @retval	PWG2_MODE_SUPER_ECONOMY		Super economy Mode.
 * @retval	PWG2_MODE_RESERVED			Reserved.
 ***************************************************************************/
int getPwg2Mode( void )
{
	unsigned char result = PWG2_MODE_RESERVED;

	switch ( PWGCTL_PWGMOD ) {
	case 0:		// Auto mode.
		result = PWG2_MODE_AUTO;
		break;
	case 2:		// Normal mode.
		result = PWG2_MODE_NORMAL;
		break;
	case 3:		// Economy mode.
		result = PWG2_MODE_ECONOMY;
		break;
	case 5:		// Super economy  mode.
		result = PWG2_MODE_SUPER_ECONOMY;
		break;
	default:	// Reserved.
		result = PWG2_MODE_RESERVED;
		break;
	}

	return result;
}

