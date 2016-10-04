/****************************************************************************
 *
 * @file	rfc.h
 * @brief	This is RFC header file for S1C17M01/W22_W23.
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

#ifndef RFC_H__
#define RFC_H__


#include <init.h>


/* --- definition --- */

// Converting Operation Status.
#define RFC_STS_CONV_SEN_A			( 0x0001 )			///< Status : Sensor A oscillation completion interrupt.
#define RFC_STS_CONV_ERR_OVTC		( 0x8001 )			///< Status : Time base counter overflow error.
#define RFC_STS_CONV_ERR_OVMC		( 0x8002 )			///< Status : Measurement counter overflow error.


/* --- external declaration --- */
extern int initRfc( void );
extern void startRfc( void );
extern void stopRfc( void );
extern void setRfcMeasurementCounter( unsigned long count );
extern unsigned long getRfcMeasurementCounter( void );
extern void setRfcTimeBaseCounter( unsigned long count );
extern unsigned long getRfcTimeBaseCounter( void );
extern int runRfcConvertingOperation( unsigned long startCount, unsigned long* sensorCount );
extern float getTemp( unsigned long data );


#endif	// RFC_H__
