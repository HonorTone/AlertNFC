/***************************************************************************
 *
 * @file	wdt2_reg.h
 * @brief	Definition of the Watchdog Timer(WDT2) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 12 Mar, 2015	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	WDT2_REG_H__
#define	WDT2_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// WDT2 Clock Control Register.
typedef union WDTCLK_REG_TAG {
	unsigned short			reg;
	struct WDTCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of WDT2.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits select the division ratio of the WDT2 operating clock (counter clock).
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the WDT2 operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} WDTCLK_REG;

/// WDT2 Control Register.
typedef union WDTCTL_REG_TAG {
	unsigned short			reg;
	struct WDTCTL_REG_BIT_TAG {
		unsigned short		WDTRUN		: 4;	///< These bits control WDT2 to run and stop.
		unsigned short		WDTCNTRST	: 1;	///< This bit resets the 10-bit counter and the WDTCTL.STATNMI bit.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		STATNMI		: 1;	///< This bit indicates that a counter overflow and NMI have occurred.
		unsigned short		MOD			: 2;	///< These bits set the WDT2 operating mode.
		unsigned short		reserved_2	: 5;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} WDTCTL_REG;

/// WDT2 Counter Compare Match Register.
typedef union WDTCMP_REG_TAG {
	unsigned short			reg;
	struct WDTCMP_REG_BIT_TAG {
		unsigned short		CMP			: 10;	///< These bits set the NMI/reset generation cycle.
		unsigned short		reserved_1	:  6;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} WDTCMP_REG;


#ifdef __cplusplus
}
#endif

#endif	// WDT2_REG_H__


