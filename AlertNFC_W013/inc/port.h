/****************************************************************************
 *
 * @file	port.h
 * @brief	This is port driver header file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04    1.00
 *				- First revision.
 *
 ***************************************************************************/

#ifndef PORT_H__
#define PORT_H__


#include <init.h>


/* --- definition --- */

// Port P0x Number.
#define PORT_NO_PX0					( 0 )			///< Port number P00.
#define PORT_NO_PX1					( 1 )			///< Port number P01.
#define PORT_NO_PX2					( 2 )			///< Port number P02.
#define PORT_NO_PX3					( 3 )			///< Port number P03.
#define PORT_NO_PX4					( 4 )			///< Port number P04.
#define PORT_NO_PX5					( 5 )			///< Port number P05.
#define PORT_NO_PX6					( 6 )			///< Port number P06.
#define PORT_NO_PX7					( 7 )			///< Port number P07.

// Port Data.
#define PORT_DATA_LOW					( 0 )			///< Port Data:LOW.
#define PORT_DATA_HIGH					( 1 )			///< Port Data:HIGH.

// Input signa edge.
#define PORT_INT_EDGE_RISING			( 0 )			///< Input signal:Rising edge.
#define PORT_INT_EDGE_FALLING			( 1 )			///< Input signal:Falling edge.


extern volatile unsigned char key_start;
extern volatile unsigned char key_stop;
extern volatile unsigned char nfc_operate;
/* --- external declaration --- */
extern void initPort( void );
extern void initPortInputP0x( unsigned char portNo );
extern void initPortOutputP0x( unsigned char portNo );
extern void enablePortIntP0x( unsigned char portNo, unsigned char edge );
extern void disablePortIntP0x( unsigned char portNo );
extern void intPortInput( void )	__attribute__ ((interrupt_handler));
extern int isPortIntP0x( unsigned char portNo );
extern void clearPortIntP0x( unsigned char portNo );
extern void initPortInputP0x( unsigned char portNo );
extern unsigned char getPortOutputP0x( unsigned char portNo );
extern void setPortOutputP0x( unsigned char portNo, unsigned char data );
extern unsigned char getPortInputP0x( unsigned char portNo );

extern void initPortOutputP4x( unsigned char portNo );
extern void disablePortIntP4x( unsigned char portNo );
extern void setPortOutputP4x( unsigned char portNo, unsigned char data );
extern void enablePortIntP3x( unsigned char portNo, unsigned char edge );
extern void disablePortIntP3x( unsigned char portNo );
extern void initPortInputP3x( unsigned char portNo );
extern void clearPortIntP3x( unsigned char portNo );
extern int isPortIntP3x( unsigned char portNo );
extern unsigned char getPortInputP3x( unsigned char portNo );
void setPortOutputP1x( unsigned char portNo, unsigned char data );
void disablePortIntP1x( unsigned char portNo );
void initPortOutputP1x( unsigned char portNo );
void enablePortIntP1x( unsigned char portNo, unsigned char edge );
void initPortInputP1x( unsigned char portNo );
void clearPortIntP1x( unsigned char portNo );
int isPortIntP1x( unsigned char portNo );
unsigned char getPortInputP1x( unsigned char portNo );



#endif	//PORT_H__
