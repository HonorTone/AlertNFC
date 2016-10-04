/***************************************************************************
 *
 * @file	svd_reg.h
 * @brief	Definition of the Supply Voltage Detector(SVD) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 02 Feb, 2015	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	SVD_REG_H__
#define	SVD_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// SVD Clock Control Register.
typedef union SVDCLK_REG_TAG {
	unsigned short			reg;
	struct SVDCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of SVD.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 3;	///< These bits select the division ratio of the SVD operating clock.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the SVD operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SVDCLK_REG;

/// SVD Control Register.
typedef union SVDCTL_REG_TAG {
	unsigned short			reg;
	struct SVDCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables/disables for the SVD circuit to operate.
		unsigned short		SVDMD		: 2;	///< These bits select intermittent operation mode and its detection cycle.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		SVDRE		: 4;	///< These bits enable/disable the reset issuance function when a low power supply voltage is detected.
		unsigned short		SVDC		: 5;	///< These bits select a comparison voltage for detecting low voltage from among 20 levels.
		unsigned short		SVDSC		: 2;	///< These bits set the condition to generate an interrupt/reset in intermittent operation mode.
		unsigned short		VDSEL		: 1;	///< This bit selects the power supply voltage to be detected by SVD.
	} bit;
	unsigned char byte_reg[2];
} SVDCTL_REG;

/// SVD Status and Interrupt Flag Register.
typedef union SVDINTF_REG_TAG {
	unsigned short			reg;
	struct SVDINTF_REG_BIT_TAG {
		unsigned short		SVDIF		: 1;	///< This bit indicates the low power supply voltage detection interrupt cause occurrence status.
		unsigned short		reserved_1	: 7;	///< Reserved.
		unsigned short		SVDDT		: 1;	///< The power supply voltage detection results can be read out from this bit.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SVDINTF_REG;

/// SVD Interrupt Enable Register.
typedef union SVDINTE_REG_TAG {
	unsigned short		reg;
	struct SVDINTE_REG_BIT_TAG {
		unsigned short		SVDIE		: 1;	///< This bit enables low power supply voltage detection interrupts.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SVDINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// SVD_REG_H__


