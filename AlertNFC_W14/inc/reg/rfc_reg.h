/***************************************************************************
 *
 * @file	rfc_reg.h
 * @brief	Definition of the R/F Converter(RFC) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 09 Mar, 2015	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	RFC_REG_H__
#define	RFC_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// RFC Clock Control Register.
typedef union RFCNCLK_REG_TAG {
	unsigned short			reg;
	struct RFCNCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of the RFC.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits select the division ratio of the RFC operating clock.
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the RFC operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} RFCNCLK_REG;

/// RFC Control Register.
typedef union RFCNCTL_REG_TAG {
	unsigned short			reg;
	struct RFCNCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the RFC operations.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		SMODE		: 2;	///< These bits configure the oscillation mode.
		unsigned short		EVTEN		: 1;	///< This bit enables external clock input mode (event counter mode).
		unsigned short		CONEN		: 1;	///< This bit disables the automatic CR oscillation stop function to enable continuous oscillation function.
		unsigned short		RFCLKMD		: 1;	///< This bit sets the RFCLKOn pin to output the divided-by-two oscillation clock.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} RFCNCTL_REG;

/// RFC Oscillation Trigger Register.
typedef union RFCNTRG_REG_TAG {
	unsigned short			reg;
	struct RFCNTRG_REG_BIT_TAG {
		unsigned short		SREF		: 1;	///< This bit controls CR oscillation for the reference resistor.
		unsigned short		SSENA		: 1;	///< This bit controls CR oscillation for sensor A.
		unsigned short		SSENB		: 1;	///< This bit controls CR oscillation for sensor B.
		unsigned short		reserved_1	:13;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} RFCNTRG_REG;

/// RFC Measurement Counter Low Register.
typedef union RFCNMCL_REG_TAG {
	unsigned short			reg;
} RFCNMCL_REG;


/// RFC Measurement Counter High Register.
typedef union RFCNMCH_REG_TAG {
	unsigned short			reg;
	struct RFCNMCH_REG_BIT_TAG {
		unsigned short		MC			: 8;	///< Measurement counter data can be read and written through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
} RFCNMCH_REG;

/// RFC Measurement Counter Low Register.
/// RFC Measurement Counter High Register.
typedef union RFCNMC_REG_DWORD_TAG {
	unsigned long reg;
	struct RFCNMC_REG_DWORD_BIT_TAG {
		unsigned long MC				:24;	///< Measurement counter data can be read and written through these bits.
		unsigned long reserved_1		:8;		///< Reserved.
	} bit;
} RFCNMC_DWORD_REG;

/// RFC Time Base Counter Low Register.
typedef union RFCNTCL_REG_TAG {
	unsigned short			reg;
} RFCNTCL_REG;

/// RFC Time Base Counter High Register.
typedef union RFCNTCH_REG_TAG {
	unsigned short			reg;
	struct RFCNTCH_REG_BIT_TAG {
		unsigned short		TC			: 8;	///< Time base counter data can be read and written through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
} RFCNTCH_REG;

/// RFC Time Base Counter Low Register.
/// RFC Time Base Counter High Register.
typedef union RFCNTC_REG_DWORD_TAG {
	unsigned long reg;
	struct RFCNTC_REG_DWORD_BIT_TAG {
		unsigned long 		TC			:24;	///< Time base counter data can be read and written through these bits.
		unsigned long 		reserved_1	:8;		///< Reserved.
	} bit;
} RFCNTC_DWORD_REG;

/// RFC Interrupt Flag Register.
typedef union RFCNINTF_REG_TAG {
	unsigned short			reg;
	struct RFCNINTF_REG_BIT_TAG {
		unsigned short		EREFIF		: 1;	///< This bit indicate Reference oscillation completion interrupt cause occurrence status.
		unsigned short		ESENAIF		: 1;	///< This bit indicate Sensor B oscillation completion interrupt cause occurrence status.
		unsigned short		ESENBIF		: 1;	///< This bit indicate Sensor B oscillation completion interrupt cause occurrence status.
		unsigned short		OVMCIF		: 1;	///< This bit indicate Measurement counter overflow error interrupt cause occurrence status.
		unsigned short		OVTCIF		: 1;	///< This bit indicate Time base counter overflow error interrupt cause occurrence status.
		unsigned short		reserved_1	:11;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} RFCNINTF_REG;

/// RFC Interrupt Enable Register.
typedef union RFCNINTE_REG_TAG {
	unsigned short			reg;
	struct RFCNINTE_REG_BIT_TAG {
		unsigned short		EREFIE		: 1;	///< This bit enable Reference oscillation completion interrupt.
		unsigned short		ESENAIE		: 1;	///< This bit enable Sensor A oscillation completion interrupt.
		unsigned short		ESENBIE		: 1;	///< This bit enable Sensor B oscillation completion interrupt.
		unsigned short		OVMCIE		: 1;	///< This bit enable Measurement counter overflow error interrupt.
		unsigned short		OVTCIE		: 1;	///< This bit enable Time base counter overflow error interrupt.
		unsigned short		reserved_1	:11;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} RFCNINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// RFC_REG_H__


