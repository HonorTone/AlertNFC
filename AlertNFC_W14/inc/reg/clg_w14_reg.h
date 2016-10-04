/***************************************************************************
 *
 * @file	clg_w14_reg.h
 * @brief	Definition of the Clock Generator(CLG) Register for S1C17W14.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 09 Feb, 2015	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	CLG_REG_H__
#define	CLG_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// CLG System Clock Control Register.
typedef union CLGSCLK_REG_TAG {
	unsigned short			reg;
	struct CLGSCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the SYSCLK clock source.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits set the division ratio of the clock source to determine the SYSCLK frequency.
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		WUPSRC		: 2;	///< These bits select the SYSCLK clock source for resetting the CLGSCLK.CLKSRC[1:0] bits at wake-up.
		unsigned short		reserved_3	: 2;	///< Reserved.
		unsigned short		WUPDIV		: 2;	///< These bits select the SYSCLK division ratio for resetting the CLGSCLK.CLKDIV[1:0] bits at wake-up.
		unsigned short		reserved_4	: 1;	///< Reserved.
		unsigned short		WUPMD		: 1;	///< This bit enables the SYSCLK switching function at wake-up.
	} bit;
	unsigned char			byte_reg[2];
} CLGSCLK_REG;

/// CLG Oscillation Control Register.
typedef union CLGOSC_REG_TAG {
	unsigned short			reg;
	struct CLGOSC_REG_BIT_TAG {
		unsigned short		IOSCEN		: 1;	///< This bit control the clock source(IOSC) operation.
		unsigned short		OSC1EN		: 1;	///< This bit control the clock source(OSC1) operation.
		unsigned short		OSC3EN		: 1;	///< This bit control the clock source(OSC3) operation.
		unsigned short		EXOSCEN		: 1;	///< This bit control the clock source(EXOSC) operation.
		unsigned short		reserved_1	: 4;	///< Reserved.
		unsigned short		IOSCSLPC	: 1;	///< This bit control the clock source(IOSC) operations in SLEEP mode.
		unsigned short		OSC1SLPC	: 1;	///< This bit control the clock source(OSC1) operations in SLEEP mode.
		unsigned short		OSC3SLPC	: 1;	///< This bit control the clock source(OSC3) operations in SLEEP mode.
		unsigned short		EXOSCSLPC	: 1;	///< This bit control the clock source(EXOSC) operations in SLEEP mode.
		unsigned short		reserved_2	: 4;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGOSC_REG;

/// CLG IOSC Control Register.
typedef union CLGIOSC_REG_TAG {
	unsigned short			reg;
	struct CLGIOSC_REG_BIT_TAG {
		unsigned short		reserved_1	: 4;	///< Reserved.
		unsigned short		IOSCSTM		: 1;	///< This bit controls the IOSCCLK auto-trimming function.
		unsigned short		reserved_2	:11;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGIOSC_REG;

/// CLG OSC1 Control Register.
typedef union CLGOSC1_REG_TAG {
	unsigned short			reg;
	struct CLGOSC1_REG_BIT_TAG {
		unsigned short		OSC1WT		: 2;	///< These bits set the oscillation stabilization waiting time for the OSC1 oscillator circuit.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		INV1N		: 2;	///< These bits set the oscillation inverter gain applied at normal operation of the OSC1 oscillator circuit.
		unsigned short		INV1B		: 2;	///< These bits set the oscillation inverter gain that will be applied at boost startup of the OSC1 oscillator circuit.
		unsigned short		CGI1		: 3;	///< These bits set the internal gate capacitance in the OSC1 oscillator circuit.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		OSC1BUP		: 1;	///< This bit enables the oscillation startup control circuit in the OSC1 oscillator circuit.
		unsigned short		OSDEN		: 1;	///< This bit controls the oscillation stop detector in the OSC1 oscillator circuit.
		unsigned short		OSDRB		: 1;	///< This bit enables the OSC1 oscillator circuit restart function by the oscillation stop detector when OSC1 oscillation stop is detected.
		unsigned short		reserved_3	: 1;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGOSC1_REG;

/// CLG OSC3 Control Register.
typedef union CLGOSC3_REG_TAG {
	unsigned short			reg;
	struct CLGOSC3_REG_BIT_TAG {
		unsigned short		OSC3WT		: 3;	///< These bits set the oscillation stabilization waiting time for the OSC3 oscillator circuit.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		OSC3INV		: 2;	///< These bits set the oscillation inverter gain of the OSC3 oscillator circuit.
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		OSC3MD		: 2;	///< These bits set the oscillation select type of the OSC3 oscillator circuit.
		unsigned short		OSC3FQ		: 3;	///< These bits set the oscillation frequency of the OSC3 oscillator circuit.
		unsigned short		reserved_3	: 3;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGOSC3_REG;

/// CLG Interrupt Flag Register.
typedef union CLGINTF_REG_TAG {
	unsigned short			reg;
	struct CLGINTF_REG_BIT_TAG {
		unsigned short		IOSCSTAIF	: 1;	///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(IOSC).
		unsigned short		OSC1STAIF	: 1;	///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(OSC1).
		unsigned short		OSC3STAIF	: 1;	///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(OSC3).
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		IOSCTEDIF	: 1;	///< This bit indicate the IOSC oscillation auto-trimming completion interrupt cause occurrence statuses.
		unsigned short		OSC1STPIF	: 1;	///< This bit indicate the OSC1 oscillation stop.
		unsigned short		reserved_2	: 10;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGINTF_REG;

/// CLG Interrupt Enable Register.
typedef union CLGINTE_REG_TAG {
	unsigned short			reg;
	struct CLGINTE_REG_BIT_TAG {
		unsigned short		IOSCSTAIE	: 1;	///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(IOSC).
		unsigned short		OSC1STAIE	: 1;	///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(OSC1).
		unsigned short		OSC3STAIE	: 1;	///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(OSC3).
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		IOSCTEDIE	: 1;	///< This bit enable the IOSC oscillation auto-trimming completion interrupts.
		unsigned short		OSC1STPIE	: 1;	///< This bit enable the OSC1 oscillation stop.
		unsigned short		reserved_2	: 10;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGINTE_REG;

/// CLG FOUT Control Register.
typedef union CLGFOUT_REG_TAG {
	unsigned short			reg;
	struct CLGFOUT_REG_BIT_TAG {
		unsigned short		FOUTEN		: 1;	///< This bit controls the FOUT clock external output.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		FOUTSRC		: 2;	///< These bits select the FOUT clock source.
		unsigned short		FOUTDIV		: 3;	///< These bits set the FOUT clock division ratio.
		unsigned short		reserved_2	: 9;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} CLGFOUT_REG;


#ifdef __cplusplus
}
#endif

#endif	// CLG_REG_H__


