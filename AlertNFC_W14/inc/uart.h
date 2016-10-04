/****************************************************************************
 *
 * @file	uart.h
 * @brief	This is UART driver header file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *
 ***************************************************************************/

#ifndef UART_H__
#define UART_H__


#include <init.h>


/* --- external declaration --- */
extern void intUART0(void);
extern int initUart( void );
extern void startUart(void);
extern void stopUart(void);
extern int sendUartData( unsigned char *data, unsigned short size );
extern int receiveUartData( unsigned char *data, unsigned short size );


#endif	// UART_H__


