/***************************************************************************
 *
 * @file	itc_reg.h
 * @brief	Definition of the Interrupt Controller(ITC) Register
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

#ifndef	ITC_REG_H__
#define	ITC_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// ITC Interrupt Level Setup Register.
typedef union ITCLVX_REG_TAG {
	unsigned short			reg;
	struct ITCLVX_REG_BIT_TAG {
		unsigned short		ILV_L		: 3;	///< These bits set the interrupt level of each interrupt.
		unsigned short		reserved_1	: 5;	///< Reserved.
		unsigned short		ILV_H		: 3;	///< These bits set the interrupt level of each interrupt.
		unsigned short		reserved_2	: 5;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} ITCLVX_REG;


#ifdef __cplusplus
}
#endif

#endif	// ITC_REG_H__


