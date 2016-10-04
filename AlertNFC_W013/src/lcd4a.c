/****************************************************************************
 *
 * @file	lcd4a.c
 * @brief	This is LCD4A driver program file for S1C17W13 demonstration.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-5015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 19 Aug, 2015	1.00
 *				- First revision.
 *
 ***************************************************************************/

#include "lcd4a.h"

/* --- function declaration --- */

static void initLcd4aSegRam(void);
static void initLcd4aMode(void);
static void initLcd4aPort(void);

void ClrLcd4aIntFlg( void );


/* --- definition of constants --- */
static const unsigned char	DOT_DATA[] = {
	0x01, 0x02, 0x04, 0x08,
};

/* --- global variable --- */

/****************************************************************************
 * initLcd4a function.
 *
 * @brief	This function initializes LCD4A driver.
 ***************************************************************************/
void initLcd4a( void )
{
	initLcd4aSegRam();		/// Initialize RAM of LCD Panel.
	initLcd4aMode();		/// initialize LCD Driver.
	initLcd4aPort();		/// initialize port used with LCD4A.
}


/****************************************************************************
 * onLcd4aDisplay function.
 *
 * @brief	The display turn on.
 ***************************************************************************/
void onLcd4aDisplay( void )
{
	LCD4CTL_MODEN	= 1;	/// Enable LCD4A.
	LCD4DSP_DSPC	= 1;	/// The LCD4A display state set to "normal display".
}


/****************************************************************************
 * offLcd4aDisplay function.
 *
 * @brief	The display turn off.
 ***************************************************************************/
void offLcd4aDisplay( void )
{
	LCD4DSP_DSPC	= 0;	/// The LCD4A display state set to "display off".
	LCD4CTL_MODEN	= 0;	/// Disable LCD4A.
}


/****************************************************************************
 * setLcd4aDisplayState function.
 *
 * @brief	This function changes LCD4A driver's state.
 *
 * @param	state
 *	@li @c		LCD4A_STATE_ALL_OFF		Mode : All off.
 *	@li @c		LCD4A_STATE_ALL_ON		Mode : All on.
 *	@li @c		LCD4A_STATE_NORMAL		Mode : Normal display.
 *	@li @c		LCD4A_STATE_OFF			Mode : Display off.
 ***************************************************************************/
void setLcd4aDisplayState( unsigned char state )
{
	LCD4DSP_DSPC = state;	/// The LCD4A display state set.
}


/****************************************************************************
 * getLcd4aDisplayState function.
 *
 * @brief	This function gets LCD4A driver's state.
 *
 * @retval		LCD4A_STATE_ALL_OFF		Mode : All off.
 * @retval		LCD4A_STATE_ALL_ON		Mode : All on.
 * @retval		LCD4A_STATE_NORMAL		Mode : Normal display.
 * @retval		LCD4A_STATE_OFF			Mode : Display off.
 ***************************************************************************/
unsigned char getLcd4aDisplayState( void )
{
	return ( (unsigned char)LCD4DSP_DSPC );
}


/****************************************************************************
 * SetLCDDisplay1Seg function.
 *
 * @brief	This function display 1 dot of LCD.
 *
 * @param	*seg
 *	@li @c		LCD_SEG00-LCD_SEG25	SEG00-SEG25
 * @param	com
 *	@li @c		LCD_COM00	COM00
 *	@li @c		LCD_COM01	COM01
 *	@li @c		LCD_COM02	COM02
 *	@li @c		LCD_COM03	COM03
 * @param	data
 *	@li @c		LCD_DATA_TURNOFF	LCD Data Turn off
 *	@li @c		LCD_DATA_TURNON		LCD Data Turn on
 *
 * @retval	LCD_SET_NG		Failed.
 * @retval	LCD_SET_OK		Success.
 ***************************************************************************/
int SetLcd4aDisplay1Seg( unsigned char* seg, unsigned char com, unsigned char data )
{

	unsigned char *lcdram;
	unsigned char tem;
	/// Parameter Check
	if( data > 1)
	{
	    return LCD_SET_NG;
	}

	lcdram = LCD4A_SEGRAM_TOP_ADDR + seg;
	if(data == 1)
	{
		*lcdram|=DOT_DATA[com];//一个SEG对应一个显示字节 bit0~bit8对应COM0~COM8。想让哪个COM上的点亮就让哪个BIT为1
	}
	else
	{
		tem= *lcdram;
		*lcdram = tem&(~DOT_DATA[com]);//只改变相应的COM位
	}

	return LCD_SET_OK;
	/*
	unsigned char *lcdram;

	/// Parameter Check
	if( data > 1){
		return LCD_SET_NG;
	}

	if(data == 1){

		unsigned char num;

		for( lcdram = (unsigned char*)LCD4A_SEGRAM_TOP_ADDR ; lcdram <= (LCD4A_SEGRAM_TOP_ADDR + seg) ; lcdram++){
			for(num = 0; num <= com; num++){
				*lcdram |= data * DOT_DATA[num];
			}

		}
	} else {
		for( lcdram = (unsigned char*)LCD4A_SEGRAM_TOP_ADDR ; lcdram <= (LCD4A_SEGRAM_TOP_ADDR + seg) ; lcdram++){
			*lcdram = data;
		}
	}

	return LCD_SET_OK;
	*/
}


/****************************************************************************
 * StartLCDClock function.
 *
 * @brief	This function sets LCD4A clock enable.
 ***************************************************************************/
void StartLcd4aClock( void )
{
	/// LCD4A Clock Enable
	LCD4CTL |= 0x01;
}

/****************************************************************************
 * StopLCDClock function.
 *
 * @brief	This function sets LCD4A clock disable.
 ***************************************************************************/
void StopLcd4aClock( void )
{
	/// LCD4A Clock Disable
	LCD4CTL &= 0xfe;
}

/****************************************************************************
 * InitLcd4aInt function.
 *
 * @brief	This function initializes LCD interrupt.
 *
 * @param	intLevel
 *	@li @c		0		Interrupt Level 0
 *	@li @c		1		Interrupt Level 1
 *	@li @c		2		Interrupt Level 2
 *	@li @c		3		Interrupt Level 3
 *	@li @c		4		Interrupt Level 4
 *	@li @c		5		Interrupt Level 5
 *	@li @c		6		Interrupt Level 6
 *	@li @c		7		Interrupt Level 7
 *
 *  @retval		0		Failed.
 *  @retval		1		Success.
 ***************************************************************************/
short InitLcd4aInt( unsigned char intLevel )
{
	/// Parameter Check
	if( intLevel > 7 ){
			return 0;
	}

	/// LCD4A Interrupt Level Set
	ILVLCD4A = intLevel;

	return 1;
}

/****************************************************************************
 * EnableLcd4aInt function.
 *
 * @brief	LCD4A interrupt enable.
 ***************************************************************************/
void EnableLcd4aInt( void )
{
	/// Clear LCD4A interrupt
	ClrLcd4aIntFlg();

	/// LCD4A interrupt enable
	LCD4INTE |= 0x01;
}

/****************************************************************************
 * DisableLcd4aInt function.
 *
 * @brief	LCD4A interrupt disable.
 ***************************************************************************/
void DisableLcd4aInt( void )
{
	/// LCD4A interrupt disable
	LCD4INTE &= 0xfe;

	/// Clear LCD4A interrupt
	ClrLcd4aIntFlg();
}

/****************************************************************************
 * isLcd4aInt function.
 *
 * @brief	This function check interrupt flag.
 *
 * @retval	0	Not occurred
 * @retval	1		Occurred.
 ***************************************************************************/
int isLcd4aInt(void)
{
	/// Interrupt Check
	if( LCD4INTF != 1 ){
		return 0;
	}

	/// Interrupt Flag Reset
	LCD4INTF = 0x01;

	return 1;
}

/****************************************************************************
 * ClrLcd4aIntFlg function.
 *
 * @brief	Clear LCD interrupt flag
 ***************************************************************************/
void ClrLcd4aIntFlg( void )
{
	/// Clear LCD interrupt
	LCD4INTF = 0x01;
}


/* ----- static ----- */

/****************************************************************************
 * initLcd4aSegRam function.
 *
 * @brief	This function initializes RAM of LCD4A Panel.
 ***************************************************************************/

static void initLcd4aSegRam(void)
{
	unsigned char	*segram = (unsigned char *)LCD4A_SEGRAM_TOP_ADDR;
	unsigned short	i;
	unsigned char size;

	size = LCD4A_SEGRAM_END_ADDR - LCD4A_SEGRAM_TOP_ADDR;

	for(i = 0 ; i < size ; i++){
		*segram++ = 0x00;
	}
}



/****************************************************************************
 * initLcd4aMode function.
 *
 * @brief	This function initializes LCD4A Driver.
 ***************************************************************************/
static void initLcd4aMode( void )
{
	LCD4CTL_MODEN		= 0;		/// LCD disable.
	LCD4CTL_LCDDIS		= 1;		/// Enable the discharge operations

	LCD4INTF			= 0x0001;	/// Clear frame interrupt flag.
	LCD4INTE			= 0x0000;	/// Disable frame interrupt.


	LCD4CLK_CLKSRC		= 1;		/// clock source = OSC1.
	LCD4CLK_CLKDIV		= 0;		/// division ratio = 1/1.
	LCD4CLK_DBRUN		= 1;		/// Clock supplied in DEBUG mode.

	LCD4TIM1_LDUTY		= 3;		/// drive duty = 1/4.
	LCD4TIM1_FRMCNT		= 7;		/// frame frequency = 64Hz.
	LCD4TIM2_NLINE		= 0;		/// n-line inverse AC drive function = Normal drive.
	LCD4TIM2_BSTC		= 0;		/// booster clock frequency = fCLK_LCD4A/4 Hz.

	LCD4PWR_EXVCSEL		= 0;		/// LCD drive power supply mode = Internal generation mode.
	LCD4PWR_VCEN		= 1;		/// voltage regulator = on.
	LCD4PWR_VCSEL		= 1;		/// voltage regulator output = VC2.
	LCD4PWR_HVLD		= 0;		/// voltage regulator into heavy load protection mode = Normal mode.
	LCD4PWR_BSTEN		= 1;		/// voltage booster = on.
	LCD4PWR_LC			= 12;		/// LCD panel contrast = 0x0:light - 0xF:dark.


	LCD4DSP_DSPC		= 0;		/// LCD display = display off.
	LCD4DSP_DSPAR		= 0;		/// display area in the display data RAM = Display area 0.
	//LCD4DSP_DSPAR		= 1;		/// display area in the display data RAM = Display area 1.
	LCD4DSP_DSPREV		= 1;		/// black/white inversion = Normal display.
	LCD4DSP_COMREV		= 1;		/// common pin assignment direction = Normal assignment.
	LCD4DSP_SEGREV		= 1;		/// segment pin assignment direction = Normal assignment.
	LCD4COMC0_COM0DEN	= 1;		/// partial drive of COM0 pin = Normal output;
	LCD4COMC0_COM1DEN	= 1;		/// partial drive of COM1 pin = Normal output;
	LCD4COMC0_COM2DEN	= 1;		/// partial drive of COM2 pin = Normal output;
	LCD4COMC0_COM3DEN	= 1;		/// partial drive of COM3 pin = Normal output;

}


/****************************************************************************
 * initLcd4aPort function.
 *
 * @brief	The port with LCD4A initialize.
 ***************************************************************************/
static void initLcd4aPort( void )
{

	P1FNCSEL		|= 0xFFC0;		/// P13 to P17 = Function 3(LCD4A / SEG15 to SEG19).
	P1MODSEL		|= 0x00F8;		/// P13 to P17 = Use peripheral I/O function(SEG15 to SEG19).

	P2FNCSEL		|= 0x3FFF;		/// P20 to P26 = Function 3(LCD4A / SEG8 to SEG14).
	P2MODSEL		|= 0x007F;		/// P20 to P26 = Use peripheral I/O function(SEG8 to SEG14).

	P4FNCSEL		|= 0x00C0;		/// P43 = Function 3(LCD4A / SEG22).
	P4MODSEL		|= 0x0008;		/// P43 = Use peripheral I/O function(SEG22).

}

