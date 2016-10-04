/***************************************************************************
 *
 * @file	flashc_reg.h
 * @brief	Definition of the Flash Controller(FLASHC) Register.
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

#ifndef	FLASHC_REG_H__
#define	FLASHC_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// FLASHC Flash Read Cycle Register.
typedef union FLASHCWAIT_REG_TAG {
	unsigned short			reg;
	struct FLASHCWAIT_REG_BIT_TAG {
		unsigned short		RDWAIT		: 2;	///< These bits set the number of bus access cycles for reading from the Flash memory.
		unsigned short		reserved_1	: 5;	///< Reserved.
		unsigned short		XBUSY		: 1;	///< This bit indicates whether the Flash memory can be accessed or not.
		unsigned short		reserved_2	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} FLASHCWAIT_REG;


#ifdef __cplusplus
}
#endif

#endif	// FLASHC_REG_H__


