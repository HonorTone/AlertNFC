/***************************************************************************
 *
 * @file	t16_reg.h
 * @brief	Definition of the 16-bit Timer(T16) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 22 Oct, 2013	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	T16_REG_H__
#define	T16_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// T16 Clock Control Register.
typedef union T16_NCLK_REG_TAG {
	unsigned short			reg;
	struct T16_NCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of T16 Ch.n.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 4;	///< These bits select the division ratio of the T16 Ch.n operating clock (counter clock).
		unsigned short		DBRUN		: 1;	///< This bit sets whether the T16 Ch.n operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} T16_NCLK_REG;

/// T16 Mode Register.
typedef union T16_NMOD_REG_TAG {
	unsigned short			reg;
	struct T16_NMOD_REG_BIT_TAG {
		unsigned short		TRMD		: 1;	///< This bit selects the T16 operation mode.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} T16_NMOD_REG;

/// T16 Control Register.
typedef union T16_NCTL_REG_TAG {
	unsigned short			reg;
	struct T16_NCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the T16 Ch.n operations.
		unsigned short		PRESET		: 1;	///< This bit presets the reload data stored in the T16_nTR register to the counter.
		unsigned short		reserved_1	: 6;	///< Reserved.
		unsigned short		PRUN		: 1;	///< This bit starts/stops the timer.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} T16_NCTL_REG;

/// T16 Reload Data Register.
typedef union T16_NTR_REG_TAG {
	unsigned short			reg;
} T16_NTR_REG;

/// T16 Counter Data Register.
typedef union T16_NTC_REG_TAG {
	unsigned short			reg;
} T16_NTC_REG;

/// T16 Interrupt Flag Register.
typedef union T16_NINTF_REG_TAG {
	unsigned short			reg;
	struct T16_NINTF_REG_BIT_TAG {
		unsigned short		UFIF		: 1;	///< This bit indicates the T16 Ch.n underflow interrupt cause occurrence status.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} T16_NINTF_REG;

/// T16 Interrupt Enable Register.
typedef union T16_NINTE_REG_TAG {
	unsigned short			reg;
	struct T16_NINTE_REG_BIT_TAG {
		unsigned short		UFIE		: 1;	///< This bit enables T16 Ch.n underflow interrupts.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} T16_NINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// T16_REG_H__


