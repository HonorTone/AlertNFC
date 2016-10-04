/***************************************************************************
 *
 * @file	uart_reg.h
 * @brief	Definition of the UART Register.
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

#ifndef	UART_REG_H__
#define	UART_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// UART Clock Control Register.
typedef union UANCLK_REG_TAG {
	unsigned short			reg;
	struct UANCLK_REG_BIT_TAG {
		unsigned short		CLKSRC		: 2;	///< These bits select the clock source of the UART.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		CLKDIV		: 2;	///< These bits select the division ratio of the UART operating clock.
		unsigned short		reserved_2	: 2;	///< Reserved.
		unsigned short		DBRUN		: 1;	///< This bit sets whether the UART operating clock is supplied in DEBUG mode or not.
		unsigned short		reserved_3	: 7;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANCLK_REG;

/// UART Mode Register.
typedef union UANMOD_REG_TAG {
	unsigned short			reg;
	struct UANMOD_REG_BIT_TAG {
		unsigned short		STPB		: 1;	///< This bit sets the stop bit length.
		unsigned short		PRMD		: 1;	///< This bit selects either odd parity or even parity when using the parity function.
		unsigned short		PREN		: 1;	///< This bit sets the data length.
		unsigned short		CHLN		: 1;	///< This bit sets the data length.
		unsigned short		IRMD		: 1;	///< This bit enables the IrDA interface function.
		unsigned short		OUTMD		: 1;	///< This bit sets the USOUTn pin output mode.
		unsigned short		PUEN		: 1;	///< This bit enables pull-up of the USINn pin.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		INVIRTX		: 1;	///< This bit enables the USOUTn output inverting function when the IrDA interface function is enabled.
		unsigned short		INVIRRX		: 1;	///< This bit enables the USINn input inverting function when the IrDA interface function is enabled.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANMOD_REG;

/// UART Baud-Rate Register.
typedef union UANBR_REG_TAG {
	unsigned short			reg;
	struct UANBR_REG_BIT_TAG {
		unsigned short		BRT			: 8;	///< These bits set the UART transfer rate.
		unsigned short		FMD			: 4;	///< These bits set the UART transfer rate.
		unsigned short		reserved_1	: 4;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANBR_REG;

/// UART Control Register.
typedef union UANCTL_REG_TAG {
	unsigned short			reg;
	struct UANCTL_REG_BIT_TAG {
		unsigned short		MODEN		: 1;	///< This bit enables the UART operations.
		unsigned short		SFTRST		: 1;	///< This bit issues software reset to the UART.
		unsigned short		reserved_1	:14;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANCTL_REG;

/// UART Transmit Data Register.
typedef union UANTXD_REG_TAG {
	unsigned short			reg;
	struct UANTXD_REG_BIT_TAG {
		unsigned short		TXD			: 8;	///< Data can be written to the transmit data buffer through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANTXD_REG;

/// UART Receive Data Register.
typedef union UANRXD_REG_TAG {
	unsigned short			reg;
	struct UANRXD_REG_BIT_TAG {
		unsigned short		RXD			: 8;	///< The receive data buffer can be read through these bits.
		unsigned short		reserved_1	: 8;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANRXD_REG;

/// UART Status and Interrupt Flag Register.
typedef union UANINTF_REG_TAG {
	unsigned short			reg;
	struct UANINTF_REG_BIT_TAG {
		unsigned short		TBEIF		: 1;	///< These bits indicate Transmit buffer empty interrupt cause occurrence status.
		unsigned short		RB1FIF		: 1;	///< These bits indicate Receive buffer one byte full interrupt cause occurrence status.
		unsigned short		RB2FIF		: 1;	///< These bits indicate Receive buffer two bytes full interrupt cause occurrence status.
		unsigned short		OEIF		: 1;	///< These bits indicate Overrun error interrupt cause occurrence status.
		unsigned short		PEIF		: 1;	///< These bits indicate Parity error interrupt cause occurrence status.
		unsigned short		FEIF		: 1;	///< These bits indicate Framing error interrupt cause occurrence status.
		unsigned short		TENDIF		: 1;	///< These bits indicate End-of-transmission interrupt cause occurrence status.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		TBSY		: 1;	///< This bit indicates the sending status.
		unsigned short		RBSY		: 1;	///< This bit indicates the receiving status.
		unsigned short		reserved_2	: 6;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANINTF_REG;

/// UART Interrupt Enable Register.
typedef union UANINTE_REG_TAG {
	unsigned short			reg;
	struct UANINTE_REG_BIT_TAG {
		unsigned short		TBEIE		: 1;	///< These bits enable Transmit buffer empty interrupt.
		unsigned short		RB1FIE		: 1;	///< These bits enable Receive buffer one byte full interrupt.
		unsigned short		RB2FIE		: 1;	///< These bits enable Receive buffer two bytes full interrupt.
		unsigned short		OEIE		: 1;	///< These bits enable Overrun error interrupt.
		unsigned short		PEIE		: 1;	///< These bits enable Parity error interrupt.
		unsigned short		FEIE		: 1;	///< These bits enable Framing error interrupt.
		unsigned short		TENDIE		: 1;	///< These bits enable End-of-transmission interrupt.
		unsigned short		reserved_1	: 9;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} UANINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// UART_REG_H__


