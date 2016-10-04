/****************************************************************************
 *
 * @file	init.h
 * @brief	This is Header file for init function .
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 19 Aug, 2015	1.00
 *				- First revision.
 *
 ***************************************************************************/

#ifndef INIT_H__
#define INIT_H__

#include "c17w13_reg.h"


/* --- definition --- */

#define CpuIntDisable()			asm("di")	///< Disable interrupt.
#define CpuIntEnable()				asm("ei")	///< Enable interrupt.

#define FALSE						( 0 )		///< False.
#define TRUE						( 1 )		///< True.
#define SUCCESS					( 0 )		///< Success.
#define ERROR						( -1 )		///< Error.

#define STATUS_NG					( 0 )		///< Status fail.
#define STATUS_OK					( 1 )		///< Status success.


// These protect the control registers related to the system against writings.
#define MSCPROT_PROTECT_ON			( 0x00 )	///< Set the write protect.
#define MSCPROT_PROTECT_OFF		( 0x96 )	///< Remove the write protect.

// These set the internal RAM size that can be used.
#define MSCIRAMSZ_512B				( 0x0 )		///< internal RAM size 512b.
#define MSCIRAMSZ_1KB				( 0x1 )		///< internal RAM size 1kb.
#define MSCIRAMSZ_2KB				( 0x2 )		///< internal RAM size 2kb.
#define MSCIRAMSZ_4KB				( 0x3 )		///< internal RAM size 4kb.


// This indicates whether the Flash memory can be accessed or not.
#define FLASHCWAIT_XBUSY_ON		( 0x0 )		///< Flash access prohibited.
#define FLASHCWAIT_XBUSY_OFF		( 0x1 )		///< Flash memory ready to access.

// These set the number of bus access cycles for reading from the Flash memory.
#define FLASHCWAIT_RDWAIT_1		( 0x0 )		///< Flash access prohibited.
#define FLASHCWAIT_RDWAIT_2		( 0x1 )		///< Flash access prohibited.
#define FLASHCWAIT_RDWAIT_3		( 0x2 )		///< Flash access prohibited.
#define FLASHCWAIT_RDWAIT_4		( 0x3 )		///< Flash access prohibited.


/* --- external declaration --- */

extern void protectMisc(unsigned char protectCode);
extern void setFlashcAccessCycle(unsigned char flashc);
extern void setMiscIRAMSize(unsigned char iramSize);
extern void setMiscVectorAddress(unsigned long baseAdrr);


#endif	// INIT_H__
