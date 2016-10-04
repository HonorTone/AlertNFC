/****************************************************************************
 *
 * @file	t16_ch0.c
 * @brief	This is 16-bit Ch.0 Timers driver header file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *
 ***************************************************************************/

#include <t16_ch0.h>


/* --- global variable --- */

// Interrupt counter.
unsigned int t16Ch0IntCount		= 0;	///< Interruption counter.



/****************************************************************************
 * initT16Ch0 function.
 *
 * @brief	T16 Ch.0 timer initialize.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int initT16Ch0( void )
{
	/// Check IOSC.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// Stop T16 Ch.0 Timer.
 	stopT16Ch0();

	T16_0CTL_MODEN		= 0;				/// - Stop supplying operating clock

	/// Configure the T16 Ch.0 operating clock.
	T16_0CLK_CLKSRC 	= 1;				/// - Clock source selection(setting OSC3)
	T16_0CLK_CLKDIV 	= 5;				/// - Clock division ratio selection(setting 1/32)
	T16_0CLK_DBRUN		= 1;				/// - No clock supplied in DEBUG mode

	/// Enable count operation clock.
	T16_0CTL_MODEN		= 1;				/// - Start supplying operating clock.

	/// Select operation mode.
	T16_0MOD_TRMD		= 0;				/// - Set Repeat mode.

	/// initialize interrupt.
	T16_0INTF			= 0x0001;			/// - Clear interrupt flag(T16_0INTF_UFIF = 1).
	T16_0INTE_UFIE		= 0;				/// - Disable interrupt.
	ILVT16_0			= INTERRUPT_LEVEL3;	/// - Set interrupt level-3.

	/// Preset reload data to counter.
	presetT16Ch0Count(0xFFFF);

	/// Clear Interruption counter.
	t16Ch0IntCount		= 0;

	return STATUS_OK;
}


/****************************************************************************
 * startT16Ch0  function.
 *
 * @brief	T16 Ch.0 timer start.
 ***************************************************************************/
void startT16Ch0(void)
{
	/// Clear interrupt flag.
	//T16_0INTF_UFIF		= 1;
	T16_0INTF			= 0x0001;
	/// Enable T16 Ch.0 underflow interrupts.
	T16_0INTE_UFIE		= 1;
	/// T16_0CTL.PRUN set 1(timer start).
	T16_0CTL_PRUN		= 1;
}


/****************************************************************************
 * stopT16Ch0 function.
 *
 * @brief	T16 Ch.0 timer stop.
 ***************************************************************************/
void stopT16Ch0(void)
{
	/// T16_0CTL.PRUN set 1(timer stop).
	T16_0CTL_PRUN		= 0;
	/// Disble T16 Ch.0 underflow interrupts.
	T16_0INTE_UFIE		= 0;
	/// Clear interrupt flag.
	//T16_0INTF_UFIF		= 1;
	T16_0INTF			= 0x0001;
}


/****************************************************************************
 * presetT16Ch0Count function.
 *
 * @brief	 Set T16 Ch.0 timer count value.
 *
 * @param	count		Counter Data.
 ***************************************************************************/
void presetT16Ch0Count( unsigned short count )
{
	/// Set the initial value to be preset to the counter.
	T16_0TR = count;

	/// Presets the reload data stored in the T16_0TR register to the counter.
	T16_0CTL_PRESET = 1;

	/// It is confirmed whether the preset finished.
	while ( T16_0CTL_PRESET != 0 ) {
		// wait...
	}
}


/****************************************************************************
 * getT16Ch0Count function.
 *
 * @brief	 Get T16 Ch.0 timer counter value.
 *
 * @return 	data	Return count value.
 ***************************************************************************/
unsigned short getT16Ch0Count( void )
{
	return ( T16_0TC );
}


/****************************************************************************
 * intT16 function.
 *
 * @brief	First, It checks in underflow interruption.
 * 			Next, underflow interruption flag is cleared.
 *			then, Increment the interrupt counter.
 ***************************************************************************/
void intT16Ch0(void)
{
	/// Check interrupt cause occurrence status.
	if ( T16_0INTF_UFIF == 1 ) {
		/// Clear T16 Ch.0 Interrupt flag.
		//T16_0INTF_UFIF = 1;
		T16_0INTF			= 0x0001;

		/// Increment the interrupt counter.
		t16Ch0IntCount++;
		//if(timeCount>0)timeCount--;
	}
}


/****************************************************************************
 * setT16Ch0IntCount function.
 *
 * @brief	The frequency to which interrupt occurs set.
 *
 * @param	count			Set value.
 ***************************************************************************/
void setT16Ch0IntCount( unsigned int count )
{
	t16Ch0IntCount = count;
}


/****************************************************************************
 * getT16Ch0IntCount function.
 *
 * @brief	The frequency to which interrupt occurs get.
 *
 * @return	count			The counter value return.
 ***************************************************************************/
unsigned int getT16Ch0IntCount( void )
{
	return t16Ch0IntCount;
}
