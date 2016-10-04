/***************************************************************************
 *
 * @file	spia_reg.h
 * @brief	Definition of the Synchronous Serial Interface(SPIA) Register.
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

#ifndef	SPIA_REG_H__
#define	SPIA_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// SPIA Mode Register.
typedef union SPINMOD_REG_TAG {
	unsigned short			reg;
	struct SPINMOD_REG_BIT_TAG {
		unsigned short		MST			: 1;	///< This bit sets the SPIA operating mode (master mode or slave mode).
		unsigned short		CPOL		: 1;	///< This bit set the SPI clock phase and polarity.
		unsigned short		CPHA		: 1;	///< This bit set the SPI clock phase and polarity.
		unsigned short		LSBFST		: 1;	///< This bit configures the data format (input/output permutation).
		unsigned short		NOCLKDIV	: 1;	///< This bit selects SPICLKn in master mode. This setting is ineffective in slave mode.
		unsigned short		PUEN		: 1;	///< This bit enables pull-up/down of the input pins.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CHLN		: 4;	///< These bits set the bit length of transfer data.
		unsigned short		reserved_2	: 4;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SPINMOD_REG;

/// SPIA Control Register.
typedef union SPINCTL_REG_TAG {
	unsigned short			reg;
	struct SPINCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the SPIA operations.
		unsigned short		SFTRST		: 1;	///< This bit issues software reset to SPIA.
		unsigned short		reserved_1	:14;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SPINCTL_REG;

/// SPIA Transmit Data Register.
typedef union SPINTXD_REG_TAG {
	unsigned short			reg; 				///< Data can be written to the transmit data buffer through these bits.
} SPINTXD_REG;

/// SPIA Receive Data Register.
typedef union SPINRXD_REG_TAG {
	unsigned short			reg; 				///< The receive data buffer can be read through these bits.
} SPINRXD_REG;

/// SPIA Interrupt Flag Register.
typedef union SPININTF_REG_TAG {
	unsigned short			reg;
	struct SPININTF_REG_BIT_TAG {
		unsigned short		TBEIF		: 1;	///< This bit indicate Transmit buffer empty interrupt cause occurrence status.
		unsigned short		RBFIF		: 1;	///< This bit indicate Receive buffer full interrupt cause occurrence status.
		unsigned short		TENDIF		: 1;	///< This bit indicate End-of-transmission interrupt cause occurrence status.
		unsigned short		OEIF		: 1;	///< This bit indicate Overrun error interrupt cause occurrence status.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		BSY			: 1;	///< This bit indicates the SPIA operating status.
		unsigned short		reserved_2	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SPININTF_REG;

/// SPIA Interrupt Enable Register.
typedef union SPININTE_REG_TAG {
	unsigned short			reg;
	struct SPININTE_REG_BIT_TAG {
		unsigned short		TBEIE		: 1;	///< This bit enable Transmit buffer empty interrupt.
		unsigned short		RBFIE		: 1;	///< This bit enable Receive buffer full interrupt.
		unsigned short		TENDIE		: 1;	///< This bit enable End-of-transmission interrupt.
		unsigned short		OEIE		: 1;	///< This bit enable Overrun error interrupt.
		unsigned short		reserved_1	:12;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} SPININTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// SPIA_REG_H__


