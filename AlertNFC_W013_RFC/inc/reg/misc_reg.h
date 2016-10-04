/***************************************************************************
 *
 * @file	misc_reg.h
 * @brief	Definition of the Misc Registers(MISC) Register.
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

#ifndef	MISC_REG_H__
#define	MISC_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// MISC System Protect Register.
typedef union MSCPROT_REG_TAG {
	unsigned short			reg;
} MSCPROT_REG;

/// MISC IRAM Size Register.
typedef union MSCIRAMSZ_REG_TAG {
	unsigned short			reg;
	struct MSCIRAMSZ_REG_BIT_TAG {
		unsigned short		IRAMSZ		: 3;	///< These bits set the internal RAM size that can be used.
		unsigned short		reserved_1	:13;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} MSCIRAMSZ_REG;

/// MISC Vector Table Address Low Register.
typedef union MSCTTBRL_REG_TAG{
	unsigned short			reg;
} MSCTTBRL_REG;

/// MISC Vector Table Address High Register.
typedef union MSCTTBRH_REG_TAG{
	unsigned short			reg;
	struct MSCTTBRH_REG_BIT_TAG {
		unsigned short		TTBR		: 8;	///< These bits set the vector table base address (eight high-order bits).
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
} MSCTTBRH_REG;

/// MISC Vector Table Address Low Register.
/// MISC Vector Table Address High Register.
typedef union MSCTTBR_REG_DWORD_TAG {
	unsigned long			reg;
	struct MSCTTBR_REG_DWORD_BIT_TAG {
		unsigned long		TTBR		: 24;	///< These bits set the vector table base address.
		unsigned long		reserved_1	: 8;	///< Reserved.
	} bit;
} MSCTTBR_DWORD_REG;

/// MISC PSR Register.
typedef union MSCPSR_REG_TAG {
	unsigned short			reg;
	struct MSCPSR_REG_BIT_TAG {
		unsigned short		PSRN		: 1;	///< The value (0 or 1) of the PSR N (negative) flag can be read out with this bit.
		unsigned short		PSRZ		: 1;	///< The value (0 or 1) of the PSR Z (zero) flag can be read out with this bit.
		unsigned short		PSRV		: 1;	///< The value (0 or 1) of the PSR V (overflow) flag can be read out with this bit.
		unsigned short		PSRC		: 1;	///< The value (0 or 1) of the PSR C (carry) flag can be read out with this bit.
		unsigned short		PSRIE		: 1;	///< The value (0 or 1) of the PSR IE (interrupt enable) bit can be read out with this bit.
		unsigned short		PSRIL		: 3;	///< The value (0 to 7) of the PSR IL[2:0] (interrupt level) bits can be read out with these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} MSCPSR_REG;


#ifdef __cplusplus
}
#endif

#endif	// MISC_REG_H__


