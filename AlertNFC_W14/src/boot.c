/*******************************************************************************
 *
 * @file	boot.c
 * @brief	This is vector and interrupt program with C.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2013-2014. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 10/04/2013    1.00
 *				- First revision.
 *			- 03/27/2014    1.10
 *				- Change source code.
 *			- 06/25/2014    1.20
 *				- Change source code.
 *
 ******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <libstdio.h>
#include <init.h>
#include <port.h>
#include <t16_ch0.h>
#include <uart.h>
#include <rtca.h>


/* --- definition --- */

/* -----------------------------------------------------------------------------
 * 	When simulated I/O is used, the following are made effective.
 * 	Please confirm "GNU17 GDB commands" and "GNU17 linker script setting"
 * 	that exists in the property of the project.
 * -------------------------------------------------------------------------- */
//#define SIM_IO_USED


/* --- function declaration --- */

void boot( void );

static void initPwg(void);
static void initItc(void);
static void clearBss(void);
static void loadLmaToVmaData(void);
#ifdef SIM_IO_USED
static void loadLmaToVmaSimIO(void);
#endif // SIM_IO_USED
static void end(void);

// Non Maskable Interrupt Handler
void intAddrErr(void)			__attribute__ ((interrupt_handler));
void intReserved(void)		__attribute__ ((interrupt_handler));

/* --- external declaration --- */

extern int main(void);

extern unsigned long __START_bss;
extern unsigned long __END_bss;
extern unsigned long __START_data;
extern unsigned long __START_data_lma;
extern unsigned long __END_data;
extern unsigned long __START_simio;
extern unsigned long __START_simio_lma;
extern unsigned long __END_simio;

/* special definitions for vector table  */
typedef void func(void);
#ifdef __POINTER16
#define VECTOR(vec)  ( vec ),0
#else
#define VECTOR(vec)  ( vec )
#endif

/** vector table */
func *const vector[] = {			// No	Base+	Name

	/* ----- Non-Maskable Interrupts ----- */
	VECTOR( boot ),					// 0	00		Reset
	VECTOR( intAddrErr ),			// 1	04		Address misaligned
	VECTOR( intReserved ),			// 2	08		NMI
	VECTOR( intReserved ),			// 3	0C		Co-processor emulation

	/* ----- Maskable Interrupts ----- */
	VECTOR( intReserved ),			// 4	10		SVD interrupt
	VECTOR( intPortInput ),			// 5	14		PORT interrupt
	VECTOR( intReserved ),			// 6	18		PWG2 interrupt
	VECTOR( intReserved ),			// 7	1C		CLG interrupt
	VECTOR( intRtca ),			    // 8	20		RTCA interrupt
	VECTOR( intT16Ch0 ),			// 9	24		T16 ch.0 interrupt
	VECTOR( intUART0 ),			    // 10	28		UART ch.0 interrupt
	VECTOR( intReserved ),			// 11	2C		T16 ch.1 interrupt
	VECTOR( intReserved ),			// 12	30		SPIA ch.0 interrupt
	VECTOR( intReserved ),			// 13	34		I2C ch.0 interrupt
	VECTOR( intReserved ),			// 14	38		T16B ch.0 interrupt
	VECTOR( intReserved ),			// 15	3C		T16B ch.1 interrupt
	VECTOR( intReserved ),			// 16	40		UART ch.1 interrupt
	VECTOR( intReserved ),			// 17	44		SNDA interrupt
	VECTOR( intReserved ),			// 18	48		REMC2 interrupt
	VECTOR( intReserved ),			// 19	4C		LCD8B interrupt
	VECTOR( intReserved ),			// 20	50		RFC ch.0 interrupt
	VECTOR( intReserved ),			// 21	54		W14:reserved	W16:RFC ch.1 interrupt
	VECTOR( intReserved ),			// 22	58		T16 ch.2 interrupt
	VECTOR( intReserved ),			// 23	5C		SPIA ch.1 interrupt
	VECTOR( intReserved ),			// 24	60		W14:reserved	W16:T16 ch.3 interrupt
	VECTOR( intReserved ),			// 25	64		W14:reserved	W16:ADC12A interrupt
	VECTOR( intReserved ),			// 26	68		W14:reserved	W16:T16 ch.3 interrupt
	VECTOR( intReserved ),			// 27	6C		W14:reserved	W16:SPIA ch.1 interrupt
	VECTOR( intReserved ),			// 28	70		reserved
	VECTOR( intReserved ),			// 29	74		reserved
	VECTOR( intReserved ),			// 30	78		reserved
	VECTOR( intReserved ),			// 31	7C		reserved


};


/****************************************************************************
 * boot function.
 *
 * @brief	First, it resets the Stack Pointer, clear the bss area,
 * 			and copy LMA to VMA.
 *			Next, it calls "main" function and calls "end" function.
 ***************************************************************************/
void boot(void)
{
	int status;

	/// Set stack pointer.
	asm("xld.a %sp, __START_stack ");

	/// Initialize module.
	initPwg();						/// - Initialize PWG.
	initItc();						/// - Initialize ITC.

	/// Initialize section.
	clearBss();						/// - Clear the bss area.
	loadLmaToVmaData();				/// - Copy LMA data to VMA data(".data" section).
#ifdef SIM_IO_USED
	loadLmaToVmaSimIO();			/// - Copy LMA data to VMA data(".simio" section).
#endif // SIM_IO_USED

	/// Initialize library.
    _init_sys();					/// - Initialize for sys.c.
    _init_lib();					/// - Initialize for lib.c.

	setFlashcAccessCycle( FLASHCWAIT_RDWAIT_1 );

	asm ( "ei" );					/// Interrupt enable.

	status = main(); 				/// Call main.

	if ( status == STATUS_NG ) {
		/***** TEST ERROR *****/
		asm ( "brk" );
		asm ( "nop" );
	} else {
		/***** TEST OK *****/
	}

	end(); 							/// Call end.
}


/* ----- static ----- */

/****************************************************************************
 * initPwg function.
 *
 * @brief	Initialize PWG module.
 ***************************************************************************/
static void initPwg(void)
{

	/// disable write-protec.
	protectMisc( MSCPROT_PROTECT_OFF );

#ifdef	PWG2_ENABLE
	/// PWG2 Mode : Automatic mode.
	PWGCTL_PWGMOD		= 0;
#else
	/// PWG Mode : Automatic mode.
	PWGVD1CTL_REGMODE	= 0;
#endif

	/// enable write-protect.
	protectMisc( MSCPROT_PROTECT_ON );

	return;
}


/****************************************************************************
 * initItc function.
 *
 * @brief	 is initialized ITC module.
 ***************************************************************************/
static void initItc(void)
{
	/// Initialize interrupt level.
	ITCLV0_ILV0		= 0;
	ITCLV0_ILV1		= 0;
	ITCLV1_ILV2		= 0;
	ITCLV1_ILV3		= 0;
	ITCLV2_ILV4		= 0;
	ITCLV2_ILV5		= 0;
	ITCLV3_ILV6		= 0;
	ITCLV3_ILV7		= 0;
	ITCLV4_ILV8		= 0;
	ITCLV4_ILV9		= 0;
	ITCLV5_ILV10	= 0;
	ITCLV5_ILV11	= 0;
	ITCLV6_ILV12	= 0;
	ITCLV6_ILV13	= 0;
	ITCLV7_ILV14	= 0;
	ITCLV7_ILV15	= 0;
	ITCLV8_ILV16	= 0;
#ifdef MCUSEL_C17W16
	ITCLV8_ILV17	= 0;
#endif
	ITCLV9_ILV18	= 0;
	ITCLV9_ILV19	= 0;
#ifdef MCUSEL_C17W16
	ITCLV10_ILV20	= 0;
	ITCLV10_ILV21	= 0;
	ITCLV11_ILV22	= 0;
	ITCLV11_ILV23	= 0;
#endif

	return;
}


/****************************************************************************
 * clearBss function.
 *
 * @brief	Clear ".bss" Section.
 ***************************************************************************/
static void clearBss(void)
{
	unsigned char	*addr;
	unsigned long	size;
	unsigned long	i;

	addr	= (unsigned char *)&__START_bss;
	size	= (unsigned long)&__END_bss - (unsigned long)&__START_bss;

	/// Clear ".bss" section.
	for(i = 0 ; i < size ; i++){
		*addr++ = 0x00;
	}

	return;
}

/****************************************************************************
 * loadLmaToVma function.
 *
 * @brief	This function copys LMA data to VMA data(".data" section).
 ***************************************************************************/
static void loadLmaToVmaData(void)
{
	unsigned char		*src;
	unsigned char		*dst;
	unsigned long		size;
	unsigned long		i;

	/// Load ".data" section.
	src		= (unsigned char *)&__START_data_lma;
	dst		= (unsigned char *)&__START_data;
	size	= (unsigned long)&__END_data - (unsigned long)&__START_data;

	for(i = 0 ; i < size ; i++){
		*dst++ = *src++;
	}

}

#ifdef SIM_IO_USED
/****************************************************************************
 * loadLmaToVmaSimIO function.
 *
 * @brief	This function copys LMA data to VMA data(".simio" section).
 * 			When simulated I/O is used, it calls it.
 ***************************************************************************/
static void loadLmaToVmaSimIO(void)
{
	unsigned char		*src;
	unsigned char		*dst;
	unsigned long		size;
	unsigned long		i;

	/// Load ".simio" section.
	src		= (unsigned char *)&__START_simio_lma;
	dst		= (unsigned char *)&__START_simio;
	size	= (unsigned long)&__END_simio - (unsigned long)&__START_simio;

	for(i = 0 ; i < size ; i++){
		*dst++ = *src++;
	}

}
#endif // SIM_IO_USED

/****************************************************************************
 * end function.
 *
 * @brief	This function has only infinite loop.
 ***************************************************************************/
static void end(void)
{
	/// Infinite loop.
	while ( 1 ){
		asm("halt");
	}
}

/* ----- Non Maskable Interrupt Handler ----- */

/****************************************************************************
 * intAddrErr function.
 *
 * @brief	Interrupt handler for "Address misaligned".
 ***************************************************************************/
void intAddrErr(void)
{
	/// Undecid processing.
	asm("halt");
}


/****************************************************************************
 * intReserved function.
 *
 * @brief	Interrupt handler for "Reserved".
 ***************************************************************************/
void intReserved(void)
{
	/// Infinite loop.
	while ( 1 ){
		;
	}
}
