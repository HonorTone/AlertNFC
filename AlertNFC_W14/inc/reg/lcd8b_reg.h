/***************************************************************************
 *
 * @file	lcd8b_reg.h
 * @brief	Definition of the LCD Driver(LCD8B) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 06 Mar, 2015	1.00
 *				- First revision.
 *
 ************************************************************************* */
#ifndef	LCD8B_REG_H__
#define	LCD8B_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// LCD8B Clock Control Register.
typedef union LCD8CLK_REG_TAG{
	unsigned short			reg;
	struct LCD8CLK_REG_BIT_TAG{
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of the LCD8B.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 3;	///< These bits select the division ratio of the LCD8B operating clock.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the LCD8B operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8CLK_REG;

/// LCD8B Control Register.
typedef union LCD8CTL_REG_TAG{
	unsigned short			reg;
	struct LCD8CTL_REG_BIT_TAG{
		unsigned short		MODEN		: 1;	///< This bit enables the LCD8B operations.
		unsigned short		LCDDIS		: 1;	///< This bit enables the discharge operations.
		unsigned short		reserved_1	:14;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8CTL_REG;

/// LCD8B Timing Control Register 1.
typedef union LCD8TIM1_REG_TAG{
	unsigned short			reg;
	struct LCD8TIM1_REG_BIT_TAG{
		unsigned short		LDUTY		: 3;	///< These bits set the drive duty.
		unsigned short		reserved_1	: 5;	///< Reserved.
		unsigned short		FRMCNT		: 4;	///< These bits set the frame frequency.
		unsigned short		reserved_2	: 4;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8TIM1_REG;

/// LCD8B Timing Control Register 2.
typedef union LCD8TIM2_REG_TAG {
	unsigned short			reg;
	struct LCD8TIM2_REG_BIT_TAG {
		unsigned short		NLINE		: 3;	///< These bits enable the n-line inverse AC drive function and set the number of inverse lines.
		unsigned short		reserved_1	: 5;	///< Reserved.
		unsigned short		BSTC		: 2;	///< These bits select the booster clock frequency for the LCD voltage booster.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8TIM2_REG;

/// LCD8B Power Control Register.
typedef union LCD8PWR_REG_TAG {
	unsigned short			reg;
	struct LCD8PWR_REG_BIT_TAG {
		unsigned short		VCEN		: 1;	///< This bit turns the LCD voltage regulator on and off.
		unsigned short		VCSEL		: 1;	///< This bit sets the LCD voltage regulator output (reference voltage for boosting).
		unsigned short		HVLD		: 1;	///< This bit sets the LCD voltage regulator into heavy load protection mode.
		unsigned short		BISEL		: 1;	///< This bit selects the LCD drive bias.
		unsigned short		BSTEN		: 1;	///< This bit turns the LCD voltage booster on and off.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		LC			: 5;	///< These bits set the LCD panel contrast.
		unsigned short		reserved_2	: 3;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8PWR_REG;

/// LCD8B Display Control Register.
typedef union LCD8DSP_REG_TAG {
	unsigned short			reg;
	struct LCD8DSP_REG_BIT_TAG {
		unsigned short		DSPC		: 2;	///< These bits control the LCD display on/off and select a display mode.
		unsigned short		DSPAR		: 1;	///< This bit switches the display area in the display data RAM.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		DSPREV		: 1;	///< This bit controls black/white inversion on the LCD display.
		unsigned short		COMREV		: 1;	///< This bit selects the common pin assignment direction.
		unsigned short		SEGREV		: 1;	///< This bit selects the segment pin assignment direction.
		unsigned short		reserved_2	: 9;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8DSP_REG;

/// LCD8B COM Pin Control Register.
typedef union LCD8COMCX_REG_TAG {
	unsigned short			reg;
	struct LCD8COMCX_REG_BIT_TAG {
		unsigned short		COM0DEN		: 1;	///< These bits configure the partial drive of the COMx pins(0).
		unsigned short		COM1DEN		: 1;	///< These bits configure the partial drive of the COMx pins(1).
		unsigned short		COM2DEN		: 1;	///< These bits configure the partial drive of the COMx pins(2).
		unsigned short		COM3DEN		: 1;	///< These bits configure the partial drive of the COMx pins(3).
		unsigned short		COM4DEN		: 1;	///< These bits configure the partial drive of the COMx pins(4).
		unsigned short		COM5DEN		: 1;	///< These bits configure the partial drive of the COMx pins(5).
		unsigned short		COM6DEN		: 1;	///< These bits configure the partial drive of the COMx pins(6).
		unsigned short		COM7DEN		: 1;	///< These bits configure the partial drive of the COMx pins(7).
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8COMCX_REG;

/// LCD8B Interrupt Flag Register.
typedef union LCD8INTF_REG_TAG {
	unsigned short			reg;
	struct LCD8INTF_REG_BIT_TAG {
		unsigned short		FRMIF		: 1;	///< This bit indicates the frame interrupt cause occurrence status.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8INTF_REG;

/// LCD8B Interrupt Enable Register.
typedef union LCD8INTE_REG_TAG {
	unsigned short			reg;
	struct LCD8INTE_REG_BIT_TAG {
		unsigned short		FRMIE		: 1;	///< This bit enables the frame interrupt.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD8INTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// LCD8B_REG_H__

