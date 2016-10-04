/***************************************************************************
 *
 * @file	remc2_reg.h
 * @brief	Definition of the Ir Remote Controller(REMC2) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-15. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 22 Oct, 2013	1.00
 *				- First revision.
 *
 **************************************************************************/

#ifndef	REMC2_REG_H__
#define	REMC2_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// REMC2 Clock Control Register.
typedef union REMCLK_REG_TAG {
	unsigned short			reg;
	struct REMCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of REMC2.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 4;	///< These bits select the division ratio of the REMC2 operating clock.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the REMC2 operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} REMCLK_REG;

/// REMC2 Data Bit Counter Control Register.
typedef union REMDBCTL_REG_TAG {
	unsigned short			reg;
	struct REMDBCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the REMC2 operations.
		unsigned short		REMCRST		: 1;	///< This bit issues software reset to the REMC2.
		unsigned short		TRMD		: 1;	///< This bit selects the operation mode of the 16-bit counter for data signal generation.
		unsigned short		BUFEN		: 1;	///< This bit enables or disables the compare buffers.
		unsigned short		REMOINV		: 1;	///< This bit inverts the REMO output signal.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		PRUN		: 1;	///< This bit starts/stops counting by the internal counters.
		unsigned short		PRESET		: 1;	///< This bit resets the internal counters.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} REMDBCTL_REG;

/// REMC2 Data Bit Counter.
typedef union REMDBCNT_REG_TAG {
	unsigned short			reg;
} REMDBCNT_REG;

/// REMC2 Data Bit Active Pulse Length Register.
typedef union REMAPLEN_REG_TAG {
	unsigned short			reg;
} REMAPLEN_REG;

/// REMC2 Data Bit Length Register.
typedef union REMDBLEN_REG_TAG {
	unsigned short			reg;
} REMDBLEN_REG;

/// REMC2 Status and Interrupt Flag Register.
typedef union REMINTF_REG_TAG {
	unsigned short			reg;
	struct REMINTF_REG_BIT_TAG {
		unsigned short		APIF		: 1;	///< This bit indicate the REMC2 AP interrupt cause occurrence status.
		unsigned short		DBIF		: 1;	///< This bit indicate the REMC2 DB interrupt cause occurrence status.
		unsigned short		reserved_1	: 6;	///< Reserved.
		unsigned short		APLENBSY	: 1;	///< This bit indicates whether a compare match occurs by the REMAPLEN buffer or not.
		unsigned short		DBLENBSY	: 1;	///< This bit indicates whether a compare match occurs by the REMDBLEN buffer or not.
		unsigned short		DBCNTRUN	: 1;	///< This bit indicates whether the 16-bit counter for data signal generation is running or not.
		unsigned short		reserved_2	: 5;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} REMINTF_REG;

/// REMC2 Interrupt Enable Register.
typedef union REMINTE_REG_TAG {
	unsigned short			reg;
	struct REMINTE_REG_BIT_TAG {
		unsigned short		APIE		: 1;	///< This bit enable REMC2 AP interrupts.
		unsigned short		DBIE		: 1;	///< This bit enable REMC2 DB interrupts.
		unsigned short		reserved_1	: 14;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} REMINTE_REG;

/// REMC2 Carrier Waveform Register.
typedef union REMCARR_REG_TAG {
	unsigned short			reg;
	struct REMCARR_REG_BIT_TAG {
		unsigned short		CRPER		: 8;	///< These bits set the carrier signal cycle.
		unsigned short		CRDTY		: 8;	///< These bits set the high level period of the carrier signal.
	} bit;
	unsigned char byte_reg[2];
} REMCARR_REG;

/// REMC2 Carrier Modulation Control Register.
typedef union REMCCTL_REG_TAG {
	unsigned short			reg;
	struct REMCCTL_REG_BIT_TAG {
		unsigned short		CARREN		: 1;	///< This bit enables carrier modulation.
		unsigned short		reserved_1	: 15;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} REMCCTL_REG;


#ifdef __cplusplus
}
#endif

#endif	// REMC2_REG_H__


