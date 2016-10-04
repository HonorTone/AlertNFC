/****************************************************************************
 *
 * @file	adc12a_reg.h
 * @brief	Definition of the A/D converter(ADC12A) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *			- 03/27/2014    1.10
 *				- Modify register definition.
 *			- 04/28/2014    1.20
 *				- Modify register definition.
 *			- 02/10/2015    1.21
 *				- Modify register definition.
 *
 ***************************************************************************/
#ifndef	ADC12A_REG_H__
#define	ADC12A_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// ADC12A Control Register.
typedef union ADC12_NCTL_REG_TAG {
	unsigned short			reg;
	struct ADC12_NCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the ADC12A operations.
		unsigned short		ADST		: 1;	///< This bit starts A/D conversion or enables to accept triggers.
		unsigned short		reserved_1	: 8;	///< Reserved.
		unsigned short		BSYSTAT		: 1;	///< This bit indicates whether the ADC12A is executing A/D conversion or not.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		ADSTAT		: 3;	///< These bits indicate the analog input pin number m being A/D converted.
		unsigned short		reserved_3	: 1;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} ADC12_NCTL_REG;

/// ADC12A Triger/Channel Select Register.
typedef union ADC12_NTRG_REG_TAG {
	unsigned short			reg;
	struct ADC12_NTRG_REG_BIT_TAG {
		unsigned short		SMPCLK		: 3;	///< These bits set the analog input signal sampling time.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		CNVTRG		: 2;	///< These bits select a trigger source to start A/D conversion.
		unsigned short		CNVMD		: 1;	///< This bit sets the A/D conversion mode.
		unsigned short		STMD		: 1;	///< This bit selects the data alignment when the conversion results are loaded into the A/D conversion result registers.
		unsigned short		STAAIN		: 3;	///< These bits set the analog input pin to be A/D converted first.
		unsigned short		ENDAIN		: 3;	///< These bits set the analog input pin to be A/D converted last.
		unsigned short		reserved_2	: 2;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} ADC12_NTRG_REG;

/// ADC12A Configulation Register.
typedef union ADC12_NCFG_REG_TAG {
	unsigned short			reg;
	struct ADC12_NCFG_REG_BIT_TAG {
		unsigned short		VRANGE		: 2;	///< These bits set the A/D converter operating voltage range.
		unsigned short		reserved_1	: 14;	///< Reserved.
	} bit;
	unsigned char			byte_reg[2];
} ADC12_NCFG_REG;

/// ADC12A Interrupt Flag Regisger.
typedef union ADC12_NINTF_REG_TAG {
	unsigned short			reg;
	struct ADC12_NINTF_REG_BIT_TAG {
		unsigned short		AD0CIF		: 1;	///< This bit indicate Analog input signal 0 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD1CIF		: 1;	///< This bit indicate Analog input signal 1 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD2CIF		: 1;	///< This bit indicate Analog input signal 2 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD3CIF		: 1;	///< This bit indicate Analog input signal 3 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD4CIF		: 1;	///< This bit indicate Analog input signal 4 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD5CIF		: 1;	///< This bit indicate Analog input signal 5 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD6CIF		: 1;	///< This bit indicate Analog input signal 6 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD7CIF		: 1;	///< This bit indicate Analog input signal 7 A/D conversion completion interrupt cause occurrence status.
		unsigned short		AD0OVIF		: 1;	///< This bit indicate Analog input signal 0 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD1OVIF		: 1;	///< This bit indicate Analog input signal 1 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD2OVIF		: 1;	///< This bit indicate Analog input signal 2 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD3OVIF		: 1;	///< This bit indicate Analog input signal 3 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD4OVIF		: 1;	///< This bit indicate Analog input signal 4 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD5OVIF		: 1;	///< This bit indicate Analog input signal 5 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD6OVIF		: 1;	///< This bit indicate Analog input signal 6 A/D conversion result overwrite error interrupt cause occurrence status.
		unsigned short		AD7OVIF		: 1;	///< This bit indicate Analog input signal 7 A/D conversion result overwrite error interrupt cause occurrence status.
	} bit;                                                   
	unsigned char			byte_reg[2];
} ADC12_NINTF_REG;

/// ADC12A Interrupt Enable Regisger.
typedef union ADC12_NINTE_REG_TAG {
	unsigned short			reg;
	struct ADC12_NINTE_REG_BIT_TAG {
		unsigned short		AD0CIE		: 1;	///< This bit enable Analog input signal 0 A/D conversion completion interrupt.
		unsigned short		AD1CIE		: 1;	///< This bit enable Analog input signal 1 A/D conversion completion interrupt.
		unsigned short		AD2CIE		: 1;	///< This bit enable Analog input signal 2 A/D conversion completion interrupt.
		unsigned short		AD3CIE		: 1;	///< This bit enable Analog input signal 3 A/D conversion completion interrupt.
		unsigned short		AD4CIE		: 1;	///< This bit enable Analog input signal 4 A/D conversion completion interrupt.
		unsigned short		AD5CIE		: 1;	///< This bit enable Analog input signal 5 A/D conversion completion interrupt.
		unsigned short		AD6CIE		: 1;	///< This bit enable Analog input signal 6 A/D conversion completion interrupt.
		unsigned short		AD7CIE		: 1;	///< This bit enable Analog input signal 7 A/D conversion completion interrupt.
		unsigned short		AD0OVIE		: 1;	///< This bit enable Analog input signal 0 A/D conversion result overwrite error interrupt.
		unsigned short		AD1OVIE		: 1;	///< This bit enable Analog input signal 1 A/D conversion result overwrite error interrupt.
		unsigned short		AD2OVIE		: 1;	///< This bit enable Analog input signal 2 A/D conversion result overwrite error interrupt.
		unsigned short		AD3OVIE		: 1;	///< This bit enable Analog input signal 3 A/D conversion result overwrite error interrupt.
		unsigned short		AD4OVIE		: 1;	///< This bit enable Analog input signal 4 A/D conversion result overwrite error interrupt.
		unsigned short		AD5OVIE		: 1;	///< This bit enable Analog input signal 5 A/D conversion result overwrite error interrupt.
		unsigned short		AD6OVIE		: 1;	///< This bit enable Analog input signal 6 A/D conversion result overwrite error interrupt.
		unsigned short		AD7OVIE		: 1;	///< This bit enable Analog input signal 7 A/D conversion result overwrite error interrupt.
	} bit;                                                   
	unsigned char			byte_reg[2];
} ADC12_NINTE_REG;

/// ADC12A Result Register m.
typedef union ADC12_NADMD_REG_TAG {
	unsigned short			reg;				///< These bits are the A/D conversion results of the analog input signal m.
} ADC12_NADMD_REG;




#ifdef __cplusplus
}
#endif

#endif	// ADC12A_REG_H__

