/****************************************************************************
 *
 * @file	init.c
 * @brief	This is initialize program for S1C17W13 demonstration.
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

#include "init.h"


/****************************************************************************
 * protectMisc function.
 *
 * @brief	Misc register write protect mode setting.
 *
 * @param	protectCode
 *	@li @c		MSCPROT_OFF	remove the write protect.
 *	@li @c		other		write protect.
 ***************************************************************************/
void protectMisc(unsigned char protectCode)
{
	// Misc register write protect
	MSCPROT = protectCode;
}


/****************************************************************************
 * setFlashcAccessCycle  function.
 *
 * @brief	Flash access cycle setting.
 *
 * @param	flashc	Flashc read access cycle.
 ***************************************************************************/
void setFlashcAccessCycle(unsigned char flashc)
{

	protectMisc( MSCPROT_PROTECT_OFF );
	// Flashc read access cycle
	FLASHCWAIT_RDWAIT = flashc;
	protectMisc( MSCPROT_PROTECT_ON );

}


/****************************************************************************
 * setMiscIRAMSize function.
 *
 * @brief	the internal RAM size setting.
 *
 * @param	iramSize
 *	@li @c		MSCIRAMSZ_IRAMSZ_512B	internal RAM size 512b.
 *	@li @c		MSCIRAMSZ_IRAMSZ_1KB	internal RAM size 1kb.
 *	@li @c		MSCIRAMSZ_IRAMSZ_2KB	internal RAM size 2kb.
 *	@li @c		MSCIRAMSZ_IRAMSZ_4KB	internal RAM size 4kb.
 *	@li @c		MSCIRAMSZ_IRAMSZ_8KB	internal RAM size 8kb.
 ***************************************************************************/
void setMiscIRAMSize(unsigned char iramSize)
{
	protectMisc( MSCPROT_PROTECT_OFF );

	// Iram size select
	MSCIRAMSZ_IRAMSZ = iramSize;

	protectMisc( MSCPROT_PROTECT_ON );
}


/****************************************************************************
 * setMiscVectorAddress
 *
 * @brief	Vector table address setting.
 *
 * @param	baseAdrr	base address[23:0].
  ***************************************************************************/

void setMiscVectorAddress(unsigned long baseAdrr)
{
	protectMisc( MSCPROT_PROTECT_OFF );

	// Vector table base address low
	// Vector table base address high
	MSCTTBR = baseAdrr;

	protectMisc( MSCPROT_PROTECT_ON );
}
