/***************************************************************************
 *
 * @file	i2c_reg.h
 * @brief	Definition of the I2C Register.
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

#ifndef	I2C_REG_H__
#define	I2C_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// I2C Clock Control Register.
typedef union I2CNCLK_REG_TAG {
	unsigned short			reg;
	struct I2CNCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of the I2C.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits select the division ratio of the I2C operating clock.
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the I2C operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNCLK_REG;

/// I2C Mode Register.
typedef union I2CNMOD_REG_TAG {
	unsigned short			reg;
	struct I2CNMOD_REG_BIT_TAG {
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		GCEN		: 1;	///< This bit sets whether to respond to master general calls in slave mode or not.
		unsigned short		OADR10		: 1;	///< This bit sets the number of own address bits for slave mode.
		unsigned short		reserved_2	:13;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNMOD_REG;

/// I2C Baud-Rate Register.
typedef union I2CNBR_REG_TAG {
	unsigned short			reg;
	struct I2CNBR_REG_BIT_TAG {
		unsigned short		BRT			: 7;	///< These bits set the I2C Ch.n transfer rate for master mode.
		unsigned short		reserved_1	: 9;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNBR_REG;

/// I2C Own Address Register.
typedef union I2CNOADR_REG_TAG {
	unsigned short			reg;
	struct I2CNOADR_REG_BIT_TAG {
		unsigned short		OADR		:10;	///< These bits set the own address for slave mode.
		unsigned short		reserved_1	: 6;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNOADR_REG;

/// I2C Control Register.
typedef union I2CNCTL_REG_TAG {
	unsigned short			reg;
	struct I2CNCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the I2C operations.
		unsigned short		SFTRST		: 1;	///< This bit issues software reset to the I2C.
		unsigned short		TXSTART		: 1;	///< This bit issues a START condition in master mode.
		unsigned short		TXSTOP		: 1;	///< This bit issues a STOP condition in master mode.
		unsigned short		TXNACK		: 1;	///< This bit issues a request for sending a NACK at the next responding.
		unsigned short		MST			: 1;	///< This bit selects the I2C Ch.n operating mode.
		unsigned short		reserved_1	:10;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNCTL_REG;

/// I2C Transmit Data Register.
typedef union I2CNTXD_REG_TAG {
	unsigned short			reg;
	struct I2CNTXD_REG_BIT_TAG {
		unsigned short		TXD			: 8;	///< Data can be written to the transmit data buffer through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNTXD_REG;

/// I2C Receive Data Register.
typedef union I2CNRXD_REG_TAG {
	unsigned short			reg;
	struct I2CNRXD_REG_BIT_TAG {
		unsigned short		RXD			: 8;	///< The receive data buffer can be read through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNRXD_REG;

/// I2C Status and Interrupt Flag Register.
typedef union I2CNINTF_REG_TAG {
	unsigned short			reg;
	struct I2CNINTF_REG_BIT_TAG {
		unsigned short		TBEIF		: 1;	///< This bit indicate Transmit buffer empty interrupt cause occurrence status.
		unsigned short		RBFIF		: 1;	///< This bit indicate Receive buffer full interrupt cause occurrence status.
		unsigned short		ERRIF		: 1;	///< This bit indicate Error detection interrupt cause occurrence status.
		unsigned short		STARTIF		: 1;	///< This bit indicate START condition interrupt cause occurrence status.
		unsigned short		STOPIF		: 1;	///< This bit indicate STOP condition interrupt cause occurrence status.
		unsigned short		NACKIF		: 1;	///< This bit indicate NACK reception interrupt cause occurrence status.
		unsigned short		GCIF		: 1;	///< This bit indicate General call address reception interrupt cause occurrence status.
		unsigned short		BYTEENDIF	: 1;	///< This bit indicate End of transfer interrupt cause occurrence status.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		TR			: 1;	///< This bit indicates whether the I2C is set in transmission mode or not.
		unsigned short		BSY			: 1;	///< This bit indicates that the I2C bus is placed into busy status.
		unsigned short		SCLLOW		: 1;	///< This bit indicates that SCL is set to low level.
		unsigned short		SDALOW		: 1;	///< This bit indicates that SDA is set to low level.
		unsigned short		reserved_2	: 3;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNINTF_REG;

/// I2C Interrupt Enable Register.
typedef union I2CNINTE_REG_TAG {
	unsigned short			reg;
	struct I2CNINTE_REG_BIT_TAG {
		unsigned short		TBEIE		: 1;	///< This bit enable Transmit buffer empty interrupt.
		unsigned short		RBFIE		: 1;	///< This bit enable Receive buffer full interrupt.
		unsigned short		ERRIE		: 1;	///< This bit enable Error detection interrupt.
		unsigned short		STARTIE		: 1;	///< This bit enable START condition interrupt.
		unsigned short		STOPIE		: 1;	///< This bit enable STOP condition interrupt.
		unsigned short		NACKIE		: 1;	///< This bit enable NACK reception interrupt.
		unsigned short		GCIE		: 1;	///< This bit enable General call address reception interrupt.
		unsigned short		BYTEENDIE	: 1;	///< This bit enable End of transfer interrupt.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} I2CNINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// I2C_REG_H__


