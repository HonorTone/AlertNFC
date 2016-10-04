/****************************************************************************
 *
 * @file	i2c_mst.h
 * @brief	This is I2C(Master) driver header file for S1C17M01/W22_W23.
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

#ifndef I2C_MST_H__
#define I2C_MST_H__


#include <init.h>


#define ADDRES_SHTW2 0X70
/* --- definition --- */

// I2C Status.
#define I2C_MST_STS_OK					( 0x0001 )		///< I2C status : OK.
#define I2C_MST_STS_NG					( 0x8000 )		///< I2C status : NG.
#define I2C_MST_STS_BYTEEND			( 0x8001 )		///< I2C status : End of data transfer.
#define I2C_MST_STS_GC					( 0x8002 )		///< I2C status : General call address reception.
#define I2C_MST_STS_NACK				( 0x8003 )		///< I2C status : NACK reception.
#define I2C_MST_STS_STOP				( 0x8004 )		///< I2C status : STOP condition.
#define I2C_MST_STS_START				( 0x8005 )		///< I2C status : START condition.
#define I2C_MST_STS_ERR				( 0x8006 )		///< I2C status : Error detection.
#define I2C_MST_STS_RBF				( 0x8007 )		///< I2C status : Receive buffer full.
#define I2C_MST_STS_TBE				( 0x8008 )		///< I2C status : Transmit buffer empty.
#define I2C_MST_STS_SND_TO				( 0x8009 )		///< I2C status : Transmit timeout.
#define I2C_MST_STS_RCV_TO				( 0x8010 )		///< I2C status : Receive timeout.


/* --- external declaration --- */
extern int initI2cMst(void);
extern void startI2cMst(void);
extern void stopI2cMst(void);
extern int sendI2cMstData( unsigned char address, unsigned char *data, int size ,char isStop);
extern int receiveI2cMstData( unsigned char address, unsigned char *data, int size );
extern int SHTW2ReadData(unsigned char *revData,char len);



#endif	// I2C_MST_H__
