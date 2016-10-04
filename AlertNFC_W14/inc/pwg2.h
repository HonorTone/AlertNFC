/****************************************************************************
 *
 * @file	pwg2.h
 * @brief	This is PWG2 driver header file for S1C17W22/W23.
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

#ifndef PWG2_H__
#define PWG2_H__


#include <init.h>


/* --- definition --- */

// PWG2 mode.
#define PWG2_MODE_AUTO					( 0 )			///< Auto Mode.
#define PWG2_MODE_NORMAL				( 2 )			///< Normal Mode.
#define PWG2_MODE_ECONOMY				( 3 )			///< Economy Mode.
#define PWG2_MODE_SUPER_ECONOMY		( 5 )			///< Super economy Mode.
#define PWG2_MODE_RESERVED				( 8 )			///< Reserved.


/* --- external declaration --- */
extern int setPwg2ModeNormal( void );
extern int setPwg2ModeEconomy( void );
extern int setPwg2ModeSuperEconomy( void );
extern int setPwg2ModeAuto( void );
extern int getPwg2Mode( void );

#endif	// PWG2_H__
