/****************************************************************************
 *
 * @file	i2c_mst.c
 * @brief	This is I2C(Master) driver program file for S1C17M01/W22_W23.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2014. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 * 			- 10/04/2013    1.00
 *				- First revision.
 *			- 03/27/2014    1.10
 *				- Change source code.
 *
 ***************************************************************************/

#include <i2c_mst.h>
#include "I2C.h"
#include "main.h"
#include <port.h>


/* --- definition --- */

#define I2C_MST_WAIT_SEND			( 0xffff )			///< Transmission time-out time.
#define I2C_MST_WAIT_RECEIVE		( 0xffff )			///< Reception time-out time.


/* --- function declaration --- */

static void setI2cMstStartCondition( void );
static void setI2cMstStopCondition( void );
static int sendI2cMst( unsigned char data );
static int receiveI2cMst( unsigned char *data, int nextLast );


/****************************************************************************
 * initI2cMst function.
 *
 * @brief	I2C initialize.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int initI2cMst( void )
{
	/// When OSC1 doesn't start, nothing is done.
	if ( CLGOSC_IOSCEN == 0 ) {
		return STATUS_NG;
	}

	/// Stop I2C.
	stopI2cMst();


	/// Configure the PxIOEN register of the I/O port.
	P0IOEN_P02IEN		= 0;			/// - Set the P0IOEN.P0IEN2 bit to 0(Disable input).
	P0IOEN_P02OEN		= 0;			/// - Set the P0IOEN.P0OEN2 bit to 0(Disable output).
	P0IOEN_P03IEN		= 0;			/// - Set the P0IOEN.P0IEN3 bit to 0(Disable input).
	P0IOEN_P03OEN		= 0;			/// - Set the P0IOEN.P0OEN3 bit to 0(Disable output).

	/// Initialize the I2C input/output function to the ports.
	P0MODSEL_P02SEL		= 0;			/// - P02 : Disable peripheral I/O function.
	P0MODSEL_P03SEL		= 0;			/// - P03 : Disable peripheral I/O function.

	/// Set Universal Port Multiplexer (UPMUX).
	P0UPMUX1_P02PERISEL	= 1;			/// - P02 : I2C.
	P0UPMUX1_P02PPFNC	= 1;			/// - P02 : SCL.
	P0UPMUX1_P02PERICH	= 0;			/// - P02 : Ch.0.
	P0UPMUX1_P03PERISEL	= 1;			/// - P03 : I2C.
	P0UPMUX1_P03PPFNC	= 2;			/// - P03 : SDA.
	P0UPMUX1_P03PERICH	= 0;			/// - P03 : Ch.0.



	/// Assign the I2C input/output function to the ports.
	P0FNCSEL_P02MUX		= 1;			/// - P02 : UPMUX.
	P0FNCSEL_P03MUX		= 1;			/// - P03 : UPMUX.
	P0MODSEL_P02SEL		= 1;			/// - P02 : Enable peripheral I/O function.
	P0MODSEL_P03SEL		= 1;			/// - P03 : Enable peripheral I/O function.


	/// The clock source operations in SLEEP mode.
	//CLGOSC_OSC3SLPC		= 0;			/// - Continue operation state before SLEEP.
	CLGOSC_OSC1SLPC		= 1;			/// - Stop clock source in SLEEP mode

	/// Set the following I2C0CTL register.
	I2C0CTL_MST			= 1;			/// - Set master mode(Master).

	/// Configure operating clock.
	//I2C0CLK_CLKSRC		= 1;			/// - Select the OSC1 clock source of the I2C.
	//I2C0CLK_CLKDIV		= 3;			/// - Select the division ratio(1/8).
	//I2C0CLK_DBRUN		= 1;			/// - Clock supplied in DEBUG mode.
	I2C0CLK_CLKSRC		= 0;			/// - Select the IOSC clock source of the I2C.
	I2C0CLK_CLKDIV		= 0;			/// - Select the division ratio(1/1).
	I2C0CLK_DBRUN		= 1;			/// - Clock supplied in DEBUG mode.

	//I2C0CLK_CLKSRC		= 0;			/// - Select the clock source of the I2C.
	//I2C0CLK_CLKDIV		= 0;			/// - Select the division ratio(1/1).
	//I2C0CLK_DBRUN		= 1;			/// - Clock supplied in DEBUG mode.

	/// Set transfer rate( bps = CLK_I2C / (BRT + 3) x 2 ).
	/// - S1C17M01     : 7.37MHz / 20 = 368500 bps.
	/// - S1C17W22_W23 :  700KHz / 20 =  35000 bps.
	//I2C0BR_BRT			= 7;			/// - BRT : 7
	//I2C0BR_BRT			= 1;			/// - BRT : 0   4.096K
	I2C0BR_BRT			= 2;			/// - BRT : 0   70K

	/// Disable UART interrupts.
	I2C0INTE_TBEIE		= 0;			/// - Transmit buffer empty interrupt.
	I2C0INTE_RBFIE		= 0;			/// - Receive buffer full interrupt.
	I2C0INTE_ERRIE		= 0;			/// - Error detection interrupt.
	I2C0INTE_STARTIE	= 0;			/// - START condition interrupt.
	I2C0INTE_STOPIE		= 0;			/// - STOP condition interrupt.
	I2C0INTE_NACKIE		= 0;			/// - NACK reception interrupt.
	I2C0INTE_GCIE		= 0;			/// - General call address reception interrupt.
	I2C0INTE_BYTEENDIE	= 0;			/// - End of transfer interrupt.

	/// Set interrupt level.
	ILVI2C_0			= INTERRUPT_LEVEL0;	/// - Set interrupt level-0.

	return STATUS_OK;
}


int SHTW2ReadData(unsigned char *revData,char len)
{
	EE_ReadOneByte1(revData,len);
	/*
	int status;
	//startI2cMst();
	unsigned char comm[2]={0X5C,0X24};
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	status = sendI2cMstData( ADDRES_SHTW2, comm, 2,0 );
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
		return status;
	}
	delay_ms(20);
	/// Receive data.
	status = receiveI2cMstData( ADDRES_SHTW2, revData, len );

	/// Check on receive result.
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
		return status;
	}
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
	//stopI2cMst();
	return status;
	*/
}

/****************************************************************************
 * startI2cMst function.
 *
 * @brief	Start I2C.
 ***************************************************************************/
void startI2cMst(void)
{
	/// Execute software reset.
	I2C0CTL_SFTRST		= 1;
	while( I2C0CTL_SFTRST == 1 ) {
		// Wait...
	}

	/// Enable I2C Ch.0 operations.
	I2C0CTL_MODEN		= 1;
}


/****************************************************************************
 * stopI2cMst function.
 *
 * @brief	Stop I2C.
 ***************************************************************************/
void stopI2cMst(void)
{
	/// Disable I2C Ch.0 operations.
	I2C0CTL_MODEN		= 0;

	/// Execute software reset.
	I2C0CTL_SFTRST		= 1;
	while( I2C0CTL_SFTRST == 1 ) {
		// Wait...
	}
}


/****************************************************************************
 * sendI2cMstData function.
 *
 * @brief	I2C transmit data(Master).
 *
 * @param	address	Slave address(6 to 0 bits).
 * @param	data	Transmit data.
 * @param	size	Transmit data size.
 *
 * @retval	I2C_MST_STS_OK				I2C status : OK.
 * @retval	I2C_MST_STS_NG				I2C status : NG.
 * @retval	I2C_MST_STS_BYTEEND			I2C status : End of data transfer.
 * @retval	I2C_MST_STS_GC				I2C status : General call address reception.
 * @retval	I2C_MST_STS_NACK			I2C status : NACK reception.
 * @retval	I2C_MST_STS_STOP			I2C status : STOP condition.
 * @retval	I2C_MST_STS_START			I2C status : START condition.
 * @retval	I2C_MST_STS_ERR				I2C status : Error detection.
 * @retval	I2C_MST_STS_RBF				I2C status : Receive buffer full.
 * @retval	I2C_MST_STS_TBE				I2C status : Transmit buffer empty.
 * @retval	I2C_MST_STS_SND_TO			I2C status : Transmit timeout.
 * @retval	I2C_MST_STS_RCV_TO			I2C status : Receive timeout.
 ***************************************************************************/
int sendI2cMstData( unsigned char address, unsigned char *data, int size,char isStop )
{
	int i;
	unsigned char connect;
	int result;

	/// Set Start condition.
	setI2cMstStartCondition();

	/// Send slave address(+Write).
	/// slave address(7 to 1 bits) + Read(1)/Write(0)).
	connect = ( ( address << 1 ) & 0xFE );
	//connect = address & 0xFE ;
	result = sendI2cMst( connect );
	if ( result != I2C_MST_STS_OK ) {
		// Set STOP condition.
		setI2cMstStopCondition();
		return result;
	}

	/// Send data.
	for ( i = 0; i < size; i++ ) {
		result = sendI2cMst( data[i] );
		/// Check result.
		if ( result != I2C_MST_STS_OK ) {
			/// The result is not checked at the last data.
			if ( i + 1 == size && result == I2C_MST_STS_NACK ) {
				result = I2C_MST_STS_OK;
			}
			// End processing when failing.
			break;
		}
	}
    //if(isStop)
	/// Set STOP condition.
	setI2cMstStopCondition();

	return result;
}


/****************************************************************************
 * receiveI2cMstData function.
 *
 * @brief	I2C receive data(Master).
 *
 * @param	address	Slave address(6 to 0 bits).
 * @param	data	Receive data.
 * @param	size	Receive data size.
 *
 * @retval	I2C_MST_STS_OK				I2C status : OK.
 * @retval	I2C_MST_STS_NG				I2C status : NG.
 * @retval	I2C_MST_STS_BYTEEND			I2C status : End of data transfer.
 * @retval	I2C_MST_STS_GC				I2C status : General call address reception.
 * @retval	I2C_MST_STS_NACK			I2C status : NACK reception.
 * @retval	I2C_MST_STS_STOP			I2C status : STOP condition.
 * @retval	I2C_MST_STS_START			I2C status : START condition.
 * @retval	I2C_MST_STS_ERR				I2C status : Error detection.
 * @retval	I2C_MST_STS_RBF				I2C status : Receive buffer full.
 * @retval	I2C_MST_STS_TBE				I2C status : Transmit buffer empty.
 * @retval	I2C_MST_STS_SND_TO			I2C status : Transmit timeout.
 * @retval	I2C_MST_STS_RCV_TO			I2C status : Receive timeout.
 ***************************************************************************/
int receiveI2cMstData( unsigned char address, unsigned char *data, int size )
{
	int i;
	int nextLast = STATUS_DISABLE;
	unsigned char connect;
	int result = I2C_MST_STS_NG;

	/// Set Start condition.
	setI2cMstStartCondition();

	/// Send slave address(+Read).
	/// slave address(7 to 1 bits) + Read(1)/Write(0)).
	connect = ( ( address << 1 ) | 0x01 );
	//connect = address | 0x01 ;
	if(size<2)//如果要接收的长度小于2，必须加这段代码,否则收不到长度小于1的数据
	{
	   I2C0CTL_TXNACK = 1;
	   nextLast = STATUS_ENABLE;
	}
	result = sendI2cMst( connect );
	if ( result != I2C_MST_STS_OK && result != I2C_MST_STS_RBF ) {
		// Set STOP condition.
		setI2cMstStopCondition();
		return result;
	}

	/// Receive data.
	for ( i = 0; i < size; i++ ) {
		/// When the next-to-last data is received, send a NACK.
		if ( i + 2 == size ) {//判断是否是最后一个字节
			nextLast = STATUS_ENABLE;
		} else {
			nextLast = STATUS_DISABLE;
		}

		// Receive data.
		result = receiveI2cMst( &(data[i]), nextLast );
		if ( result != I2C_MST_STS_OK ) {
			break;
		}
	}

	/// Set STOP condition.
	setI2cMstStopCondition();

	return result;
}


/* ----- static ----- */

/****************************************************************************
 * setI2cMstStartCondition function.
 *
 * @brief	Issue a START condition.
 ***************************************************************************/
static void setI2cMstStartCondition( void )
{
	// Clear START condition interrupt.
	//I2C0INTF_STARTIF = 1;
	I2C0INTF = 0x0008;

	// Issue a START condition.
	I2C0CTL_TXSTART = 1;

	// Wait START condition.
	while ( I2C0CTL_TXSTART == 1 ) {
		/// Wait...
	}

	// Clear START condition interrupt.
	//I2C0INTF_STARTIF = 1;
	I2C0INTF = 0x0008;
}

/****************************************************************************
 * setI2cMstStopCondition function.
 *
 * @brief	Issue a STOP condition.
 ***************************************************************************/
static void setI2cMstStopCondition( void )
{
	// Clear STOP condition interrupt.
	//I2C0INTF_STOPIF = 1;
	I2C0INTF = 0x0010;

	// Issue a STOP condition.
	I2C0CTL_TXSTOP = 1;

	// Wait STOP condition.
	while ( I2C0CTL_TXSTOP == 1 ) {
		/// Wait...
	}

	// Clear STOP condition interrupt.
	//I2C0INTF_STOPIF = 1;
	I2C0INTF = 0x0010;
}


/****************************************************************************
 * sendI2cMst function.
 *
 * @brief	I2C transmit data write.
 *
 * @param	data	Transmit data(8-bits mode = 0x00-0xff / 7-bits mode = 0x00-0x7f).
 *
 * @retval	I2C_MST_STS_OK			I2C status : OK.
 * @retval	I2C_MST_STS_NG			I2C status : NG(unknown).
 * @retval	I2C_MST_STS_NACK		I2C status : NACK reception.
 * @retval	I2C_MST_STS_STOP		I2C status : STOP condition.
 * @retval	I2C_MST_STS_SND_TO		I2C status : Transmit timeout.
 ***************************************************************************/
static int sendI2cMst( unsigned char data )
{
	int i;
	int result;

	/// Wait transmit buffer empty.
	for ( i = 0; i < I2C_MST_WAIT_SEND; i++ ) {
		if ( I2C0INTF_TBEIF == 1 ) {
			break;
		}
	}
	/// Check transmit buffer empty.
	if ( I2C0INTF_TBEIF == 0 ) {
		return I2C_MST_STS_SND_TO;
	}

	/// Send Data.
	I2C0TXD_TXD = data;

	/// Wait interrupt.
	result = I2C_MST_STS_SND_TO;
	for ( i = 0; i < I2C_MST_WAIT_SEND; i++ ) {
		// Check transmit buffer empty.
		if ( I2C0INTF_TBEIF == 1 ) {
			result = I2C_MST_STS_OK;
			break;
		}

		// Check NACK reception interrupt.
		if ( I2C0INTF_NACKIF == 1 ) {
			// Clear NACK reception interrupt.
			//I2C0INTF_NACKIF = 1;
			I2C0INTF = 0x0020;
			result = I2C_MST_STS_NACK;
			break;
		}

		// Check Receive buffer full interrupt.
		if ( I2C0INTF_RBFIF == 1 ) {
			result = I2C_MST_STS_RBF;
			break;
		}
	}

	return result;
}


/****************************************************************************
 * receiveI2cMst function.
 *
 * @brief	I2C receive data read.
 *
 * @param	data		Pointer of place where receive data is stored.
 * @param	nextLast	The next-to-last data flag(STATUS_ENABLE/STATUS_DISABLE).
 *
 * @retval	I2C_MST_STS_OK			I2C status : OK.
 * @retval	I2C_MST_STS_NG			I2C status : NG(unknown).
 * @retval	I2C_MST_STS_NACK		I2C status : NACK reception.
 * @retval	I2C_MST_STS_STOP		I2C status : STOP condition.
 * @retval	I2C_MST_STS_RCV_TO		I2C status : Receive timeout.
 ***************************************************************************/
static int receiveI2cMst( unsigned char *data, int nextLast )
{
	int i;
	int result = I2C_MST_STS_NG;

	// Wait interrupt.
	result = I2C_MST_STS_RCV_TO;
	for ( i = 0; i < I2C_MST_WAIT_RECEIVE; i++ ) {
		// Check receive buffer full interrupt.
		if ( I2C0INTF_RBFIF == 1 ) {
			/// When the next-to-last data is received, send a NACK.
			if ( nextLast == STATUS_ENABLE ) {
				I2C0CTL_TXNACK = 1;
			}
			/// receive Data.
			*data = I2C0RXD_RXD;
			result = I2C_MST_STS_OK;
			break;
		}

		// Check NACK reception interrupt.
		if ( I2C0INTF_NACKIF == 1 ) {
			// Clear NACK reception interrupt.
			//I2C0INTF_NACKIF = 1;
			I2C0INTF = 0x0020;
			result = I2C_MST_STS_NACK;
			break;
		}
	}

	return result;
}
