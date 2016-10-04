/****************************************************************************
 *
 * @file	lcd8b.h
 * @brief	This is LCD8B driver header file for S1C17W14/W16.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 09 APR, 2015	1.00
 *				- First revision.
 *
  ***************************************************************************/

#ifndef LCD8B_H__
#define LCD8B_H__

#include "init.h"
#include "main.h"

#define DISP_WHELL_LOGO 0X1A //ÂÖ×Ó
#define DISP_STOP_LOGO 0X9D //Í£Ö¹Í¼±ê
#define DISP_ARROW_UP 0X2A //ÏòÉÏµÄ¼ýÍ·
#define DISP_ALARM_CHAR 0X2C//¾¯±¨×Ö·û
#define DISP_ALARM_LOGO 0X9E//¾¯±¨Í¼±ê
#define DISP_HI_CHAR 0X2B//HI×Ö·û
#define DISP_LOW_CHAR 0X3B//LOW×Ö·û
#define DISP_AVG_CHAR 0X1B//AVG×Ö·û
#define DISP_HR_CHAR 0X8A//HR×Ö·û
#define DISP_MIN_CHAR 0X8D//MIN×Ö·û
#define DISP_C_LOGO 0X3A //C×Ö·û
#define DISP_D_LOGO 0X4A //D×Ö·û
#define DISP_R_LOGO 0X4A //R×Ö·û
#define DISP_T_LOGO 0X54 //T×Ö·û

#define UNIT_HUMIDITY 1 //Êª¶È
#define UNIT_TEMP_C   2 //ÉãÊÏÎÂ¶È
#define UNIT_TEMP_F   3 //»ªÊÏÎÂ¶È

#define LCD_1A_SEG 19
#define LCD_1B_SEG 19
#define LCD_1C_SEG 19
#define LCD_2A_SEG 18
#define LCD_2B_SEG 18
#define LCD_2C_SEG 18
#define LCD_3A_SEG 17
#define LCD_3B_SEG 17
#define LCD_3C_SEG 17
#define LCD_4A_SEG 16
#define LCD_4B_SEG 16
#define LCD_4C_SEG 16
#define LCD_4D_SEG 15
#define LCD_5E_SEG 14
#define LCD_5F_SEG 14
#define LCD_5A_SEG 14
#define LCD_5H_SEG 13
#define LCD_5D_SEG 12
#define LCD_5C_SEG 12
#define LCD_5G_SEG 12
#define LCD_5B_SEG 11
#define LCD_6F_SEG 11
#define LCD_6A_SEG 11
#define LCD_6E_SEG 10
#define LCD_6G_SEG 10
#define LCD_6B_SEG 10
#define LCD_8A_SEG 9
#define LCD_6D_SEG 9
#define LCD_6C_SEG 9
#define LCD_8B_SEG 8
#define LCD_7F_SEG 8
#define LCD_7A_SEG 8
#define LCD_7E_SEG 7
#define LCD_7G_SEG 7
#define LCD_7B_SEG 7
#define LCD_7D_SEG 6
#define LCD_7C_SEG 6
#define LCD_8C_SEG 6
#define LCD_8D_SEG 5
#define LCD_9C_SEG 5
#define LCD_9B_SEG 5
#define LCD_9E_SEG 4
#define LCD_9A_SEG 4
#define LCD_9D_SEG 4

#define LCD_1A_COM 0
#define LCD_1B_COM 1
#define LCD_1C_COM 2
#define LCD_2A_COM 0
#define LCD_2B_COM 1
#define LCD_2C_COM 2
#define LCD_3A_COM 0
#define LCD_3B_COM 1
#define LCD_3C_COM 2
#define LCD_4A_COM 0
#define LCD_4B_COM 1
#define LCD_4C_COM 2
#define LCD_4D_COM 0
#define LCD_5E_COM 0
#define LCD_5F_COM 1
#define LCD_5A_COM 2
#define LCD_5H_COM 0
#define LCD_5D_COM 0
#define LCD_5C_COM 1
#define LCD_5G_COM 2
#define LCD_5B_COM 0
#define LCD_6F_COM 1
#define LCD_6A_COM 2
#define LCD_6E_COM 0
#define LCD_6G_COM 1
#define LCD_6B_COM 2
#define LCD_8A_COM 0
#define LCD_6D_COM 1
#define LCD_6C_COM 2
#define LCD_8B_COM 0
#define LCD_7F_COM 1
#define LCD_7A_COM 2
#define LCD_7E_COM 0
#define LCD_7G_COM 1
#define LCD_7B_COM 2
#define LCD_7D_COM 0
#define LCD_7C_COM 1
#define LCD_8C_COM 2
#define LCD_8D_COM 0
#define LCD_9C_COM 1
#define LCD_9B_COM 2
#define LCD_9E_COM 0
#define LCD_9A_COM 1
#define LCD_9D_COM 2

/// End Status
#define LCD_SET_NG					( 0 )		///< Fail
#define LCD_SET_OK					( 1 )		///< Success

// Display STATE.
#define	LCD8B_STATE_ALL_OFF		( 0x3 )							///< Mode : All off.
#define	LCD8B_STATE_ALL_ON		( 0x2 )							///< Mode : All on.
#define	LCD8B_STATE_NORMAL		( 0x1 )							///< Mode : Normal display.
#define	LCD8B_STATE_OFF			( 0x0 )							///< Mode : Display off.

// Display Memory Address.
#define	LCD8B_SEGRAM_TOP_ADDR	( 0x7000 )						///< The display data RAM start address.
#ifdef MCUSEL_C17W14
#define	LCD8B_SEGRAM_END_ADDR	( 0x7075 )						///< The display data RAM end address.
#endif
#ifdef MCUSEL_C17W16
#define	LCD8B_SEGRAM_END_ADDR	( 0x707b )						///< The display data RAM end address.
#endif


/// LCD Data Turn on/off a Light
#define LCD_DATA_TURNOFF			( 0 )		///< LCD Data Turn off
#define LCD_DATA_TURNON			( 1 )		///< LCD Data Turn on



/* --- external declaration --- */

extern void initLcd8b( void );
extern void onLcd8bDisplay( void );
extern void offLcd8bDisplay( void );
extern void setLcd8bDisplayState( unsigned char state );
extern unsigned char getLcd8bDisplayState( void );
extern int SetLcd8bDisplay1Seg( unsigned char seg, unsigned char com, unsigned char data );
void LcdDisplayChar(unsigned char *addDataPos,unsigned char addNum,unsigned char *delDataPos,unsigned char delNum);
void dispDigital(float val,uchar dispType);
void OnOffSingleDisp(uchar type,uchar comm);
void FlashScreen(int gapTime);
extern void StartLcd8bClock( void );
extern void StopLcd8bClock( void );
extern short InitLcd8bInt( unsigned char intLevel );
extern void EnableLcd8bInt( void );
extern void DisableLcd8bInt( void );
extern int isLcd8bInt(void);
extern void ClrLcd8bIntFlg( void );
extern void onLcd8bReg(void);
extern void offLcd8bReg(void);



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
	LCD_SEG26,									///< 26 : SEG26
	LCD_SEG27,									///< 27 : SEG27
	LCD_SEG28,									///< 28 : SEG28
	LCD_SEG29,									///< 29 : SEG29
	LCD_SEG30,									///< 30 : SEG30
	LCD_SEG31,									///< 31 : SEG31
	LCD_SEG32,									///< 32 : SEG32
	LCD_SEG33,									///< 33 : SEG33
	LCD_SEG34,									///< 34 : SEG34
	LCD_SEG35,									///< 35 : SEG35
	LCD_SEG36,									///< 36 : SEG36
	LCD_SEG37,									///< 37 : SEG37
	LCD_SEG38,									///< 38 : SEG38
	LCD_SEG39,									///< 39 : SEG39
	LCD_SEG40,									///< 40 : SEG40
	LCD_SEG41,									///< 41 : SEG41
	LCD_SEG42,									///< 42 : SEG42
	LCD_SEG43,									///< 43 : SEG43
	LCD_SEG44,									///< 44 : SEG44
	LCD_SEG45,									///< 45 : SEG45
	LCD_SEG46,									///< 46 : SEG46
	LCD_SEG47,									///< 47 : SEG47
	LCD_SEG48,									///< 48 : SEG48
	LCD_SEG49,									///< 49 : SEG49
	LCD_SEG50,									///< 50 : SEG50
	LCD_SEG51,									///< 51 : SEG51
	LCD_SEG52,									///< 52 : SEG52
	LCD_SEG53,									///< 53 : SEG53
#ifdef MCUSEL_C17W16
	LCD_SEG54,									///< 54 : SEG54
	LCD_SEG55,									///< 55 : SEG55
	LCD_SEG56,									///< 56 : SEG56
	LCD_SEG57,									///< 57 : SEG57
	LCD_SEG58,									///< 58 : SEG58
	LCD_SEG59,									///< 59 : SEG59
#endif
	LCD_SEG_MAX
};


enum {
	LCD_COM00 = 0x00,							///< 00 : COM00
	LCD_COM01,									///< 01 : COM01
	LCD_COM02,									///< 02 : COM02
	LCD_COM03,									///< 03 : COM03
	LCD_COM04,									///< 04 : COM04
	LCD_COM05,									///< 05 : COM05
	LCD_COM06,									///< 06 : COM06
	LCD_COM07,									///< 07 : COM07

	LCD_COM_MAX
};

#endif // LCD8B_H__

