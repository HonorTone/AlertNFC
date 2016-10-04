/** *************************************************************************
 *
 * @file	pwg2_reg.h
 * @brief	Definition of the Power Generator(PWG2) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 20 Nov, 2013	1.00
 *				- First revision.
 *
 ************************************************************************* */
#ifndef	PWG2_REG_H__
#define	PWG2_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// PWG2 Control Register.
typedef union PWGCTL_REG_TAG {
	unsigned short			reg;
	struct PWGCTL_REG_BIT_TAG {
		unsigned short		PWGMOD		: 3;	///< These bits control the internal regulator operating mode.
		unsigned short		reserved_1	:13;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} PWGCTL_REG;

/// PWG2 Timing Control Register.
typedef union PWGTIM_REG_TAG {
	unsigned short			reg;
	struct PWGTIM_REG_BIT_TAG {
		unsigned short		DCCCLK		: 2;	///< These bits set the charge pump operating clock (select an OSC1 clock division ratio).
		unsigned short		reserved_1	:14;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} PWGTIM_REG;

/// PWG2 Interrupt Flag Register.
typedef union PWGINTF_REG_TAG {
	unsigned short			reg;
	struct PWGINTF_REG_BIT_TAG {
		unsigned short		MODCMPIF	: 1;	///< This bit indicates the PWG2 mode transition completion interrupt cause occurrence status.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} PWGINTF_REG;

/// PWG2 Interrupt Enable Register.
typedef union PWGINTE_REG_TAG {
	unsigned short			reg;
	struct PWGINTE_REG_BIT_TAG {
		unsigned short		MODCMPIE	: 1;	///< This bit enables the PWG2 mode transition completion interrupt.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} PWGINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// PWG2_REG_H__

