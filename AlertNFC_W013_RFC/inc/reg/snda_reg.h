/** *************************************************************************
 *
 * @file	snda_reg.h
 * @brief	Definition of the Sound Generator(SNDA) Register.
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
#ifndef	SNDA_REG_H__
#define	SNDA_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// SNDA Clock Control Register.
typedef union SNDCLK_REG_TAG {
	unsigned short			reg;
	struct SNDCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of SNDA.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 3;	///< These bits select the division ratio of the SNDA operating clock.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the SNDA operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} SNDCLK_REG;


/// SNDA Select Register.
typedef union SNDSEL_REG_TAG {
	unsigned short			reg;
	struct SNDSEL_REG_BIT_TAG {
		unsigned short		MOSEL		: 2;	///< These bits select a sound output mode.
		unsigned short		SINV		: 1;	///< This bit selects an output pin drive mode.
		unsigned short		reserved_1	: 5;	///< Reserved.
		unsigned short		STIM		: 4;	///< These bits select a tempo or a one-shot buzzer output duration.
		unsigned short		reserved_2	: 4;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} SNDSEL_REG;


/// SNDA Control Register.
typedef union SNDCTL_REG_TAG {
	unsigned short			reg;
	struct SNDCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the SNDA operations.
		unsigned short		reserved_1	: 7;	///< Reserved.
		unsigned short		SSTP		: 1;	///< This bit stops sound output.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} SNDCTL_REG;


/// SNDA Data Register.
typedef union SNDDAT_REG_TAG {
	unsigned short			reg;
	struct SNDDAT_REG_BIT_TAG {
		unsigned short		SFRQ		: 8;	///< These bits select a scale or a buzzer signal frequency.
		unsigned short		SLEN		: 6;	///< These bits select a duration or a buzzer signal duty ratio.
		unsigned short		MDRS		: 1;	///< This bit selects the output type in melody mode from a note or a rest.
		unsigned short		MDTI		: 1;	///< This bit specifies a tie in melody mode.
	} bit;
	unsigned char 			byte_reg[2];
} SNDDAT_REG;


/// SNDA Interrupt Flag Register.
typedef union SNDINTF_REG_TAG {
	unsigned short			reg;
	struct SNDINTF_REG_BIT_TAG {
		unsigned short		EDIF		: 1;	///< Sound buffer empty interrupt status.
		unsigned short		EMIF		: 1;	///< Sound output completion interrupt status.
		unsigned short		reserved_1	: 6;	///< Reserved.
		unsigned short		SBSY		: 1;	///< This bit indicates the sound output status.
		unsigned short		reserved_2	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} SNDINTF_REG;


/// SNDA Interrupt Enable Register.
typedef union SNDINTE_REG_TAG {
	unsigned short			reg;
	struct SNDINTE_REG_BIT_TAG {
		unsigned short		EDIE		: 1;	///< Sound output completion interrupt.
		unsigned short		EMIE		: 1;	///< Sound buffer empty interrupt.
		unsigned short		reserved_1	: 14;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} SNDINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// SNDA_REG_H__
