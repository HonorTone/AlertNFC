/****************************************************************************
 *
 * @file	lcd4a.h
 * @brief	This is LCD4A driver header file for S1C17W13.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 19 Aug, 2015	1.00
 *				- First revision.
 *
  ***************************************************************************/

#ifndef LCD4A_H__
#define LCD4A_H__

#include "init.h"

/// End Status
#define LCD_SET_NG					( 0 )		///< Fail
#define LCD_SET_OK					( 1 )		///< Success

// Display STATE.
#define	LCD4A_STATE_ALL_OFF		( 0x3 )							///< Mode : All off.
#define	LCD4A_STATE_ALL_ON		( 0x2 )							///< Mode : All on.
#define	LCD4A_STATE_NORMAL		( 0x1 )							///< Mode : Normal display.
#define	LCD4A_STATE_OFF			( 0x0 )							///< Mode : Display off.

// Display Memory Address.
#define	LCD4A_SEGRAM_TOP_ADDR	( 0x7000 )						///< The display data RAM start address.
#define	LCD4A_SEGRAM_END_ADDR	( 0x7039 )						///< The display data RAM end address.

/// LCD Data Turn on/off a Light
#define LCD_DATA_TURNOFF			( 0 )		///< LCD Data Turn off
#define LCD_DATA_TURNON			( 1 )		///< LCD Data Turn on



/* --- external declaration --- */

extern void initLcd4a( void );
extern void onLcd4aDisplay( void );
extern void offLcd4aDisplay( void );
extern void setLcd4aDisplayState( unsigned char state );
extern unsigned char getLcd4aDisplayState( void );
extern int SetLcd4aDisplay1Seg( unsigned char* seg, unsigned char com, unsigned char data );
extern void StartLcd4aClock( void );
extern void StopLcd4aClock( void );
extern short InitLcd4aInt( unsigned char intLevel );
extern void EnableLcd4aInt( void );
extern void DisableLcd4aInt( void );
extern int isLcd4aInt(void);
extern void ClrLcd4aIntFlg( void );


/// LCD SEG / COM No.
enum {
	LCD_SEG00 = 0x00,							///< 00 : SEG00
	LCD_SEG01,									///< 01 : SEG01
	LCD_SEG02,									///< 02 : SEG02
	LCD_SEG03,									///< 03 : SEG03
	LCD_SEG04,									///< 04 : SEG04
	LCD_SEG05,									///< 05 : SEG05
	LCD_SEG06,									///< 06 : SEG06
	LCD_SEG07,									///< 07 : SEG07
	LCD_SEG08,									///< 08 : SEG08
	LCD_SEG09,									///< 09 : SEG09
	LCD_SEG10,									///< 10 : SEG10
	LCD_SEG11,									///< 11 : SEG11
	LCD_SEG12,									///< 12 : SEG12
	LCD_SEG13,									///< 13 : SEG13
	LCD_SEG14,									///< 14 : SEG14
	LCD_SEG15,									///< 15 : SEG15
	LCD_SEG16,									///< 16 : SEG16
	LCD_SEG17,									///< 17 : SEG17
	LCD_SEG18,									///< 18 : SEG18
	LCD_SEG19,									///< 19 : SEG19
	LCD_SEG20,									///< 20 : SEG20
	LCD_SEG21,									///< 21 : SEG21
	LCD_SEG22,									///< 22 : SEG22
	LCD_SEG23,									///< 23 : SEG23
	LCD_SEG24,									///< 24 : SEG24
	LCD_SEG25,									///< 25 : SEG25

	LCD_SEG_MAX
};


enum {
	LCD_COM00 = 0x00,							///< 00 : COM00
	LCD_COM01,									///< 01 : COM01
	LCD_COM02,									///< 02 : COM02
	LCD_COM03,									///< 03 : COM03

	LCD_COM_MAX
};

#endif // LCD4A_H__

