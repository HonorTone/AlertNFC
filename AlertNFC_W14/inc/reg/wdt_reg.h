/***************************************************************************
 *
 * @file	wdt_reg.h
 * @brief	Definition of the Watchdog Timer(WDT) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 06 Mar, 2015	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	WDT_REG_H__
#define	WDT_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// WDT Clock Control Register.
typedef union WDTCLK_REG_TAG {
	unsigned short			reg;
	struct WDTCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of WDT.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits select the division ratio of the WDT operating clock (counter clock).
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the WDT operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} WDTCLK_REG;

/// WDT Control Register.
typedef union WDTCTL_REG_TAG {
	unsigned short			reg;
	struct WDTCTL_REG_BIT_TAG {
		unsigned short		WDTRUN		: 4;	///< These bits control WDT to run and stop.
		unsigned short		WDTCNTRST	: 1;	///< This bit resets WDT.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		STATNMI		: 1;	///< This bit indicates that a counter overflow and NMI have occurred.
		unsigned short		NMIXRST		: 1;	///< This bit sets the WDT operating mode.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} WDTCTL_REG;


#ifdef __cplusplus
}
#endif

#endif	// WDT_REG_H__


