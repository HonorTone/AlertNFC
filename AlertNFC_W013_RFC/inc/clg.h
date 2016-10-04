/****************************************************************************
 *
 * @file	clg.h
 * @brief	This is clg(osc) driver header file for S1C17M01/W22/W23.
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
 *				- Add external declaration.
  *			- 06/16/2014    1.20
 *				- Change source code.
 *
 ***************************************************************************/

#ifndef CLG_H__
#define CLG_H__

#include <init.h>


/* --- definition --- */

#define CLG_OSC1_STOP_DETECT		( 1 )		///< Oscillation stop detection(OSC1).
#define CLG_OSC1_STOP_NO_DETECT	( 0 )		///< Not oscillation stop detection(OSC1).

#define CLG_OSC3_SEL_500KHZ		( 0 )
#define CLG_OSC3_SEL_1MHZ			( 1 )
#define CLG_OSC3_SEL_2MHZ			( 2 )
#define CLG_OSC3_SEL_4MHZ			( 3 )
#define CLG_OSC3_SEL_384KHZ		(4)
#define CLG_OSC3_SEL_250KHZ		(5)

/* --- external declaration --- */

extern void startClgOSC1( void );
extern void stopClgOSC1( void );
extern void enableClgStopDetectionOSC1( void );
extern void disableClgStopDetectionOSC1( void );
int isClgStopDetectionOSC1( void );
#ifdef CLG_OSC3_ENABLE
extern void startClgOSC3( void );
extern void startClgOSC3f( unsigned short freq );
extern void stopClgOSC3( void );
#endif	// CLG_OSC3_ENABLE
extern void startClgIOSC( void );
extern void stopClgIOSC( void );
extern int runClgAutoTrimmingIOSC( void );
extern int switchClgSystemClockOSC1( void );
extern int switchClgSystemClockIOSC( void );
#ifdef CLG_OSC3_ENABLE
extern int switchClgSystemClockOSC3( void );
#endif	// CLG_OSC3_ENABLE

extern void setIoscOperInSlp(unsigned short ioscslpc);
extern void setOsc1OperInSlp(unsigned short osc1slpc);
#ifdef CLG_OSC3_ENABLE
extern void setOsc3OperInSlp(unsigned short osc3slpc);
#endif


#endif	// CLG_H__
