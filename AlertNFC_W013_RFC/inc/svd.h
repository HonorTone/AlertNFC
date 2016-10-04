/****************************************************************************
 *
 * @file	svd.h
 * @brief	This is SVD header file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.0
 *				- First revision.
 *
 ***************************************************************************/

#ifndef SVD_H__
#define SVD_H__


#include <init.h>


/* --- definition --- */

// Supply Voltage Detector (SVD) Low power interrupt flag.
#define SVD_PW_SUPPLY_V_HIGH		( 0 )			///< Power supply voltage(VDD or EXSVD) >=  comparison voltage.
#define SVD_PW_SUPPLY_V_LOW			( 1 )			///< Power supply voltage(VDD or EXSVD) <  comparison voltage.

// Comparison voltage for detecting low voltage
#define SVDCTL_SVDC_1200MV			( 0x01 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1250MV			( 0x02 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1300MV			( 0x03 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1350MV			( 0x04 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1400MV			( 0x05 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1450MV			( 0x06 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1500MV			( 0x07 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1550MV			( 0x08 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1600MV			( 0x09 )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1650MV			( 0x0A )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1700MV			( 0x0B )		///< Comparison voltage(Only S1C17W22_W23).
#define SVDCTL_SVDC_1800MV			( 0x0C )		///< Comparison voltage.
#define SVDCTL_SVDC_1900MV			( 0x0D )		///< Comparison voltage.
#define SVDCTL_SVDC_2000MV			( 0x0E )		///< Comparison voltage.
#define SVDCTL_SVDC_2100MV			( 0x0F )		///< Comparison voltage.
#define SVDCTL_SVDC_2200MV			( 0x10 )		///< Comparison voltage.
#define SVDCTL_SVDC_2300MV			( 0x11 )		///< Comparison voltage.
#define SVDCTL_SVDC_2400MV			( 0x12 )		///< Comparison voltage.
#define SVDCTL_SVDC_2500MV			( 0x13 )		///< Comparison voltage.
#define SVDCTL_SVDC_2600MV			( 0x14 )		///< Comparison voltage.
#define SVDCTL_SVDC_2700MV			( 0x15 )		///< Comparison voltage.
#define SVDCTL_SVDC_2800MV			( 0x16 )		///< Comparison voltage.
#define SVDCTL_SVDC_2900MV			( 0x17 )		///< Comparison voltage.
#define SVDCTL_SVDC_3000MV			( 0x18 )		///< Comparison voltage.
#define SVDCTL_SVDC_3100MV			( 0x19 )		///< Comparison voltage.
#define SVDCTL_SVDC_3200MV			( 0x1A )		///< Comparison voltage.
#define SVDCTL_SVDC_3300MV			( 0x1B )		///< Comparison voltage.
#define SVDCTL_SVDC_3400MV			( 0x1C )		///< Comparison voltage.
#define SVDCTL_SVDC_3500MV			( 0x1D )		///< Comparison voltage.
#define SVDCTL_SVDC_3600MV			( 0x1E )		///< Comparison voltage.
#define SVDCTL_SVDC_3700MV			( 0x1F )		///< Comparison voltage(Only S1C17M01).


/* --- external declaration --- */
extern int initSvd( void );
extern void startSvd( void );
extern void stopSvd( void );
extern int setSvdComparisonVoltage( unsigned char volt );
extern void intSvd( void )	__attribute__ ((interrupt_handler));
extern int isSvdIntLowVoltage( void );
extern void clearSvdIntLowVoltage( void );
extern int getSvdVoltageDetection( void );


#endif	// SVD_H__
