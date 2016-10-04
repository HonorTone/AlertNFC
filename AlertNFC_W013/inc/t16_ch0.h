/****************************************************************************
 *
 * @file	t16_ch0.h
 * @brief	This is 16-bit Ch.0 Timers driver header file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *
 ***************************************************************************/
#ifndef T16_CH0_H__
#define T16_CH0_H__


#include <init.h>


/* --- external declaration --- */

extern int initT16Ch0(void);

extern void startT16Ch0(void);
extern void stopT16Ch0(void);
extern void presetT16Ch0Count( unsigned short count );
extern unsigned short getT16Ch0Count( void );
extern void intT16Ch0(void)	__attribute__ ((interrupt_handler));
extern void setT16Ch0IntCount( unsigned int count );
extern unsigned int getT16Ch0IntCount( void );

#endif	// T16_CH0_H__
