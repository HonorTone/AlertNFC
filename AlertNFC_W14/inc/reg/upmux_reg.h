/***************************************************************************
 *
 * @file	upmux_reg.h
 * @brief	Definition of the Universal Port Multiplexer (UPMUX) Register.
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

#ifndef	UPMUX_REG_H__
#define	UPMUX_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// Pxy-xz Universal Port Multiplexer Setting Register.
typedef union PXUPMUXN_REG_TAG {
	unsigned short			reg;
	struct PXUPMUXN_REG_BIT_TAG {
		unsigned short		PxyPERISEL	: 3;	///< These bits specify the peripheral I/O function to be assigned to the port.
		unsigned short		PxyPERICH	: 2;	///< These bits specify a peripheral circuit channel number.
		unsigned short		PxyPPFNC	: 3;	///< These bits specify a peripheral circuit.
		unsigned short		PxzPERISEL	: 3;	///< These bits specify the peripheral I/O function to be assigned to the port.
		unsigned short		PxzPERICH	: 2;	///< These bits specify a peripheral circuit channel number.
		unsigned short		PxzPPFNC	: 3;	///< These bits specify a peripheral circuit.
	} bit;
	unsigned char byte_reg[2];
} PXUPMUXN_REG;


#ifdef __cplusplus
}
#endif

#endif	// UPMUX_REG_H__


