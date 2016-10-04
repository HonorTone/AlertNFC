/*******************************************************************************
 *
 * @file	svd.c
 * @brief	This is Supply voltage detector program for S1C17M01/W22_W23 demonstration.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.0
 *				- First revision.
  *			- 06/16/2014    1.10
 *				- Change source code.
 *
 ******************************************************************************/

#include <svd.h>


/* --- global variable --- */

// Interrupt flag.
unsigned int svdIntLowVoltage = STATUS_NO_OCCURRED;	///< Low voltage interrupt.


/****************************************************************************
 * initSvd function.
 *
 * @brief	First, Stop SVD.
 *			Next, Initialize SVD.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int initSvd( void )
{
	/// When OSC1 doesn't start, nothing is done.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// Stop SVD.
	stopSvd();

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Set clock source for SVD.
	SVDCLK_CLKSRC		= 1;	/// - Set clock source(OSC1).
	SVDCLK_CLKDIV		= 0;	/// - Set division ratio for clock source(1/1).
	SVDCLK_DBRUN		= 1;	/// - Clock supplied in DEBUG mode.


	/// Select detection voltage(0:VDD / 1:EXSVD).
	SVDCTL_VDSEL		= 0;

	/// Select reset(0xA)/interrupt(others) mode.
	SVDCTL_SVDRE		= 0x00;

	/// Set intermittent operation mode.
	/// Intermittent operation mode(0x1-0x3) / Continuous operation mode(0x0).
	SVDCTL_SVDMD		= 0;	/// - Continuous operation mode.


	// Comparison voltage for detecting low voltage(2.0V).
	SVDCTL_SVDC			= SVDCTL_SVDC_2000MV;

	// The condition to generate an interrupt/reset.
	// number of successive low voltage.
	SVDCTL_SVDSC		= 0;	/// - Low power supply voltage is successively detected once.

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	/// Initialize the interrupt.
	ILVSVD				= INTERRUPT_LEVEL3;

	return STATUS_OK;
}


/****************************************************************************
 * startSvd function.
 *
 * @brief	Start SVD.
 ***************************************************************************/
void startSvd( void )
{
	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Clear interrupt flag.
	//SVDINTF_SVDIF		= 1;
	SVDINTF				= 0x0001;

	/// Enable interrupt.
	SVDINTE_SVDIE		= 1;

	/// Start SVD.
	SVDCTL_MODEN		= 1;

	/// Clear Low voltage interrupt flag.
	svdIntLowVoltage = STATUS_NO_OCCURRED;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );
}


/****************************************************************************
 * stopSvd function.
 *
 * @brief	Stop SVD.
 ***************************************************************************/
void stopSvd( void )
{
	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	/// Stop SVD.
	SVDCTL_MODEN		= 0;

	/// Disable interrupt.
	SVDINTE_SVDIE		= 0;

	/// Clear interrupt flag.
	//SVDINTF_SVDIF		= 1;
	SVDINTF				= 0x0001;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );
}


/****************************************************************************
 * setSvdComparisonVoltage function.
 *
 * @brief	Set Comparison voltage for detecting low voltage.
 *
 * @param	volt		Comparison voltage for detecting low voltage.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setSvdComparisonVoltage( unsigned char volt )
{
	if ( SVDCTL_MODEN == 1 ) {
		return STATUS_NG;
	}

	/// Disable write-protect.
	protectMisc( MSCPROT_PROTECT_OFF );

	// Comparison voltage for detecting low voltage(2.0V).
	SVDCTL_SVDC = volt;

	/// Enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return STATUS_OK;
}


/****************************************************************************
 * intSvd function.
 *
 * @brief	SVD interrupt.
 ***************************************************************************/
void intSvd( void )
{
	if ( SVDINTF_SVDIF == 1 ) {
		/// Clear interrupt flag.
		//SVDINTF_SVDIF		= 1;
		SVDINTF				= 0x0001;
		/// Set Low voltage interrupt flag.
		svdIntLowVoltage = STATUS_OCCURRED;
	}
}


/****************************************************************************
 * isSvdInt function.
 *
 * @brief	Check SVD low voltage interrupt.
 *
 * @retval	STATUS_NO_OCCURRED		No cause of interrupt occurred
 * @retval	STATUS_OCCURRED			Cause of interrupt occurred.
 ***************************************************************************/
int isSvdIntLowVoltage( void )
{
	int result = STATUS_NO_OCCURRED;

	/// Check Low voltage interrupt flag.
	if ( svdIntLowVoltage == STATUS_OCCURRED ) {
		result = STATUS_OCCURRED;
	}

	return result;
}


/****************************************************************************
 * clearSvdIntLowVoltage function.
 *
 * @brief	Clear SVD low voltage interrupt.
 ***************************************************************************/
void clearSvdIntLowVoltage( void )
{
	/// Clear interrupt flag.
	//SVDINTF_SVDIF		= 1;
	SVDINTF				= 0x0001;

	/// Clear Low voltage interrupt flag.
	svdIntLowVoltage = STATUS_NO_OCCURRED;
}


/****************************************************************************
 * getSvdVoltageDetection function.
 *
 * @brief	Get power supply voltage detection results.
 *
 * @retval	SVD_PW_SUPPLY_V_HIGH	Power supply voltage(VDD or EXSVD) >=  comparison voltage.
 * @retval	SVD_PW_SUPPLY_V_LOW		Power supply voltage(VDD or EXSVD) <  comparison voltage.
 ***************************************************************************/
int getSvdVoltageDetection( void )
{
	// Power supply voltage(VDD or EXSVD) >=  comparison voltage.
	int result = SVD_PW_SUPPLY_V_HIGH;

	// Check Power supply voltage(VDD or EXSVD) to comparison voltage.
	if ( SVDINTF_SVDDT == 1 ) {
		result = SVD_PW_SUPPLY_V_LOW;
	}

	return result;
}

