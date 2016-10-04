/***************************************************************************
 *
 * @file	lcd4a_reg.h
 * @brief	Definition of the LCD Driver(LCD4A) Register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 23 Jul, 2015	1.00
 *				- First revision.
 *
 ************************************************************************* */
#ifndef	LCD4A_REG_H__
#define	LCD4A_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// LCD4A Clock Control Register.
typedef union LCD4CLK_REG_TAG{
	unsigned short			reg;
	struct LCD4CLK_REG_BIT_TAG{
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of the LCD4A.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 3;	///< These bits select the division ratio of the LCD4A operating clock.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the LCD4A operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4CLK_REG;

/// LCD4A Control Register.
typedef union LCD4CTL_REG_TAG{
	unsigned short			reg;
	struct LCD4CTL_REG_BIT_TAG{
		unsigned short		MODEN		: 1;	///< This bit enables the LCD4A operations.
		unsigned short		LCDDIS		: 1;	///< This bit enables the discharge operations.
		unsigned short		reserved_1	:14;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4CTL_REG;

/// LCD4A Timing Control Register 1.
typedef union LCD4TIM1_REG_TAG{
	unsigned short			reg;
	struct LCD4TIM1_REG_BIT_TAG{
		unsigned short		LDUTY		: 2;	///< These bits set the drive duty.
		unsigned short		reserved_1	: 6;	///< Reserved.
		unsigned short		FRMCNT		: 4;	///< These bits set the frame frequency.
		unsigned short		reserved_2	: 4;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4TIM1_REG;

/// LCD4A Timing Control Register 2.
typedef union LCD4TIM2_REG_TAG {
	unsigned short			reg;
	struct LCD4TIM2_REG_BIT_TAG {
		unsigned short		NLINE		: 2;	///< These bits enable the n-line inverse AC drive function and set the number of inverse lines.
		unsigned short		reserved_1	: 6;	///< Reserved.
		unsigned short		BSTC		: 2;	///< These bits select the booster clock frequency for the LCD voltage booster.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4TIM2_REG;

/// LCD4A Power Control Register.
typedef union LCD4PWR_REG_TAG {
	unsigned short			reg;
	struct LCD4PWR_REG_BIT_TAG {
		unsigned short		VCEN		: 1;	///< This bit turns the LCD voltage regulator on and off.
		unsigned short		VCSEL		: 1;	///< This bit sets the LCD voltage regulator output (reference voltage for boosting).
		unsigned short		HVLD		: 1;	///< This bit sets the LCD voltage regulator into heavy load protection mode.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		BSTEN		: 1;	///< This bit turns the LCD voltage booster on and off.
		unsigned short		reserved_2	: 3;	///< Reserved.
		unsigned short		LC			: 4;	///< These bits set the LCD panel contrast.
		unsigned short		reserved_3	: 3;	///< Reserved.
		unsigned short		EXVCSEL		: 1;	///< This bit selects the LCD drive power supply mode (external voltage application mode or internal generation mode).
	} bit;
	unsigned char 			byte_reg[2];
} LCD4PWR_REG;

/// LCD4A Display Control Register.
typedef union LCD4DSP_REG_TAG {
	unsigned short			reg;
	struct LCD4DSP_REG_BIT_TAG {
		unsigned short		DSPC		: 2;	///< These bits control the LCD display on/off and select a display mode.
		unsigned short		DSPAR		: 1;	///< This bit switches the display area in the display data RAM.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		DSPREV		: 1;	///< This bit controls black/white inversion on the LCD display.
		unsigned short		COMREV		: 1;	///< This bit selects the common pin assignment direction.
		unsigned short		SEGREV		: 1;	///< This bit selects the segment pin assignment direction.
		unsigned short		reserved_2	: 9;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4DSP_REG;

/// LCD4A COM Pin Control Register.
typedef union LCD4COMCX_REG_TAG {
	unsigned short			reg;
	struct LCD4COMCX_REG_BIT_TAG {
		unsigned short		COM0DEN		: 1;	///< These bits configure the partial drive of the COMx pins(0).
		unsigned short		COM1DEN		: 1;	///< These bits configure the partial drive of the COMx pins(1).
		unsigned short		COM2DEN		: 1;	///< These bits configure the partial drive of the COMx pins(2).
		unsigned short		COM3DEN		: 1;	///< These bits configure the partial drive of the COMx pins(3).
		unsigned short		reserved_1	: 12;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4COMCX_REG;

/// LCD4A Interrupt Flag Register.
typedef union LCD4INTF_REG_TAG {
	unsigned short			reg;
	struct LCD4INTF_REG_BIT_TAG {
		unsigned short		FRMIF		: 1;	///< This bit indicates the frame interrupt cause occurrence status.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4INTF_REG;

/// LCD4A Interrupt Enable Register.
typedef union LCD4INTE_REG_TAG {
	unsigned short			reg;
	struct LCD4INTE_REG_BIT_TAG {
		unsigned short		FRMIE		: 1;	///< This bit enables the frame interrupt.
		unsigned short		reserved_1	:15;	///< Reserved.
	} bit;
	unsigned char 			byte_reg[2];
} LCD4INTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// LCD4A_REG_H__

