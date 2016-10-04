/** *************************************************************************
 *
 * @file	c17w13_reg.h
 * @brief	The definition of S1C17W13's register.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-2015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 27 Jul, 2015  1.00
 *				- First revision.
 *
 ************************************************************************* */
#ifndef	C17W13_REG_H__
#define	C17W13_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif

// Include Files
#include "./reg/misc_reg.h"
#include "./reg/pwg2_reg.h"
#include "./reg/clg_w13_reg.h"
#include "./reg/itc_reg.h"
#include "./reg/wdt2_reg.h"
#include "./reg/rtca_reg.h"
#include "./reg/svd_reg.h"
#include "./reg/t16_reg.h"
#include "./reg/t16b_reg.h"
#include "./reg/flashc_reg.h"
#include "./reg/pport_w13_reg.h"
#include "./reg/upmux_reg.h"
#include "./reg/uart2_reg.h"
#include "./reg/spia_reg.h"
#include "./reg/i2c_reg.h"
#include "./reg/snda_reg.h"
#include "./reg/lcd4a_reg.h"
#include "./reg/rfc_reg.h"
#include "./reg/remc2_reg.h"


// S1C17W13 mode.
#define	PWG2_ENABLE																						///< PWG2 Enable.
#define	CLG_OSC3_ENABLE																					///< OSC3 Enable.


// Status
#define 	STATUS_NG			( 0 )																	///< Status fail.
#define 	STATUS_OK			( 1 )																	///< Status success.
#define 	STATUS_DISABLE		( 0 )																	///< Status disable.
#define 	STATUS_ENABLE		( 1 )																	///< Status enable.
#define 	STATUS_NO_OCCURRED	( 0 )																	///< No cause of interrupt occurred.
#define 	STATUS_OCCURRED		( 1 )																	///< Cause of interrupt occurred.


// Interrupt Level Select
#define	INTERRUPT_LEVEL0		( 0x0 )																	///< Interrupt priorities 0
#define	INTERRUPT_LEVEL1		( 0x1 )																	///< Interrupt priorities 1
#define	INTERRUPT_LEVEL2		( 0x2 )																	///< Interrupt priorities 2
#define	INTERRUPT_LEVEL3		( 0x3 )																	///< Interrupt priorities 3
#define	INTERRUPT_LEVEL4		( 0x4 )																	///< Interrupt priorities 4
#define	INTERRUPT_LEVEL5		( 0x5 )																	///< Interrupt priorities 5
#define	INTERRUPT_LEVEL6		( 0x6 )																	///< Interrupt priorities 6
#define	INTERRUPT_LEVEL7		( 0x7 )																	///< Interrupt priorities 7



// Register Base Address
#define	MISC_REG_BASE_ADDR		( 0x4000 )																///< Misc Registers (MISC) Register Base Address.
#define	PWG2_REG_BASE_ADDR		( 0x4020 )																///< Power Generator (PWG2) Register Base Address.
#define	CLG_REG_BASE_ADDR		( 0x4040 )																///< Clock Generator (CLG) Register Base Address.
#define	ITC_REG_BASE_ADDR		( 0x4080 )																///< Interrupt Controller (ITC) Register Base Address.
#define	WDT2_REG_BASE_ADDR		( 0x40A0 )																///< Watchdog Timer (WDT2) Register Base Address.
#define	RTCA_REG_BASE_ADDR		( 0x40C0 )																///< Real-time Clock (RTCA) Register Base Address.
#define	SVD_REG_BASE_ADDR		( 0x4100 )																///< Supply Voltage Detector (SVD) Register Base Address.
#define	T16_0_REG_BASE_ADDR		( 0x4160 )																///< 16-bit Timer (T16) Ch.0 Register Base Address.
#define	FLASHC_REG_BASE_ADDR	( 0x41B0 )																///< Flash Controller (FLASHC) Register Base Address.
#define	PPORT_REG_BASE_ADDR		( 0x4200 )																///< I/O Ports (PPORT) Register Base Address.
#define	UPMUX_REG_BASE_ADDR		( 0x4300 )																///< Universal Port Multiplexer (UPMUX) Register Base Address.
#define	UART2_0_REG_BASE_ADDR	( 0x4380 )																///< UART (UART2) Ch.0 Register Base Address.
#define	T16_1_REG_BASE_ADDR		( 0x43A0 )																///< 16-bit Timer (T16) Ch.1 Register Base Address.
#define	SPIA_0_REG_BASE_ADDR	( 0x43B0 )																///< Synchronous Serial Interface (SPIA) Ch.0 Register Base Address.
#define	I2C_0_REG_BASE_ADDR		( 0x43C0 )																///< I2C (I2C) Ch.0 Register Base Address Register Base Address.
#define	T16B_0_REG_BASE_ADDR	( 0x5000 )																///< 16-bit PWM Timer (T16B) Ch.0 Register Base Address.
#define	T16B_1_REG_BASE_ADDR	( 0x5040 )																///< 16-bit PWM Timer (T16B) Ch.1 Register Base Address.
#define	UART2_1_REG_BASE_ADDR	( 0x5200 )																///< UART (UART2) Ch.1 Register Base Address.
#define	T16_2_REG_BASE_ADDR		( 0x5260 )																///< 16-bit Timer (T16) Ch.2 Register Base Address.
#define	SNDA_REG_BASE_ADDR		( 0x5300 )																///< Sound Generator (SNDA) Register Base Address.
#define	REMC2_REG_BASE_ADDR		( 0x5320 )																///< IR Remote Controller (REMC2) Register Base Address.
#define	LCD4A_REG_BASE_ADDR		( 0x5400 )																///< LCD Driver (LCD4A) Register Base Address.
#define	RFC_0_REG_BASE_ADDR		( 0x5440 )																///< R/F Converter (RFC) ch.0 Register Base Address.


/* ----- C17W13 Registers ----- */

/********************/
/* ----- MISC ----- */
/********************/

// MISC System Protect Register.
#define	MSCPROT				(*((volatile MSCPROT_REG *)(MISC_REG_BASE_ADDR + 0x00))).reg

// MISC IRAM Size Register.
#define	MSCIRAMSZ			(*((volatile MSCIRAMSZ_REG *)(MISC_REG_BASE_ADDR + 0x02))).reg
#define	MSCIRAMSZ_IRAMSZ	(*((volatile MSCIRAMSZ_REG *)(MISC_REG_BASE_ADDR + 0x02))).bit.IRAMSZ		///< These bits set the internal RAM size that can be used.

/// MISC Vector Table Address Low Register.
#define	MSCTTBRL			(*((volatile MSCTTBRL_REG *)(MISC_REG_BASE_ADDR + 0x04))).reg

/// MISC Vector Table Address High Register.
#define	MSCTTBRH			(*((volatile MSCTTBRH_REG *)(MISC_REG_BASE_ADDR + 0x06))).reg
#define	MSCTTBRH_TTBR		(*((volatile MSCTTBRH_REG *)(MISC_REG_BASE_ADDR + 0x06))).bit.TTBR			///< These bits set the vector table base address (eight high-order bits).


// MISC Vector Table Address Low Register.
// MISC Vector Table Address High Register.
#define MSCTTBR 			(*((volatile MSCTTBR_DWORD_REG *)(MISC_REG_BASE_ADDR + 0x04))).reg
#define MSCTTBR_TTBR		MSCTTBR 																	///< These bits set the vector table base address.

// MISC PSR Register.
#define	MSCPSR				(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).reg
#define	MSCPSR_PSRN			(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRN			///< The value (0 or 1) of the PSR N (negative) flag can be read out with this bit.
#define	MSCPSR_PSRZ			(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRZ			///< The value (0 or 1) of the PSR Z (zero) flag can be read out with this bit.
#define	MSCPSR_PSRV			(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRV			///< The value (0 or 1) of the PSR V (overflow) flag can be read out with this bit.
#define	MSCPSR_PSRC			(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRC			///< The value (0 or 1) of the PSR C (carry) flag can be read out with this bit.
#define	MSCPSR_PSRIE		(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRIE			///< The value (0 or 1) of the PSR IE (interrupt enable) bit can be read out with this bit.
#define	MSCPSR_PSRIL		(*((volatile MSCPSR_REG *)(MISC_REG_BASE_ADDR + 0x08))).bit.PSRIL			///< The value (0 to 7) of the PSR IL[2:0] (interrupt level) bits can be read out with these bits.


/*******************/
/* ----- PWG2 ----- */
/*******************/

// PWG2 Control Register.
#define	PWGCTL				(*((volatile PWGCTL_REG *)(PWG2_REG_BASE_ADDR + 0x00))).reg
#define	PWGCTL_PWGMOD		PWGCTL																		///< These bits control the internal regulator operating mode.

// PWG2 Timing Control Register.
#define	PWGTIM				(*((volatile PWGTIM_REG *)(PWG2_REG_BASE_ADDR + 0x02))).reg
#define	PWGTIM_DCCCLK		PWGTIM																		///< These bits set the charge pump operating clock (select an OSC1 clock division ratio).

// PWG2 Interrupt Flag Register.
#define	PWGINTF				(*((volatile PWGINTF_REG *)(PWG2_REG_BASE_ADDR + 0x04))).reg
#define	PWGINTF_MODCMPIF	PWGINTF																		///< This bit indicates the PWG2 mode transition completion interrupt cause occurrence status.

// PWG2 Interrupt Enable Register.
#define	PWGINTE				(*((volatile PWGINTE_REG *)(PWG2_REG_BASE_ADDR + 0x06))).reg
#define	PWGINTE_MODCMPIE	PWGINTE																		///< This bit enables the PWG2 mode transition completion interrupt.


/*******************/
/* ----- CLG ----- */
/*******************/

// CLG System Clock Control Register.
#define	CLGSCLK				(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).reg
#define	CLGSCLK_CLKSRC		(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the SYSCLK clock source.
#define	CLGSCLK_CLKDIV		(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits set the division ratio of the clock source to determine the SYSCLK frequency.
#define	CLGSCLK_WUPSRC		(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).bit.WUPSRC			///< These bits select the SYSCLK clock source for resetting the CLGSCLK.CLKSRC[1:0] bits at wake-up.
#define	CLGSCLK_WUPDIV		(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).bit.WUPDIV			///< These bits select the SYSCLK division ratio for resetting the CLGSCLK.CLKDIV[1:0] bits at wake-up.
#define	CLGSCLK_WUPMD		(*((volatile CLGSCLK_REG *)(CLG_REG_BASE_ADDR + 0x00))).bit.WUPMD			///< This bit enables the SYSCLK switching function at wake-up.

// CLG Oscillation Control Register.
#define	CLGOSC				(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).reg
#define	CLGOSC_IOSCEN		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.IOSCEN			///< This bit control the clock source(IOSC) operation.
#define	CLGOSC_OSC1EN		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.OSC1EN			///< This bit control the clock source(OSC1) operation.
#define	CLGOSC_OSC3EN		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.OSC3EN			///< This bit control the clock source(OSC3) operation.
#define	CLGOSC_EXOSCEN		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.EXOSCEN			///< This bit control the clock source(EXOSC) operation.
#define	CLGOSC_IOSCSLPC		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.IOSCSLPC			///< This bit control the clock source(IOSC) operations in SLEEP mode.
#define	CLGOSC_OSC1SLPC		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.OSC1SLPC			///< This bit control the clock source(OSC1) operations in SLEEP mode.
#define	CLGOSC_OSC3SLPC		(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.OSC3SLPC			///< This bit control the clock source(OSC3) operations in SLEEP mode.
#define	CLGOSC_EXOSCSLPC	(*((volatile CLGOSC_REG *)(CLG_REG_BASE_ADDR + 0x02))).bit.EXOSCSLPC		///< This bit control the clock source(EXOSC) operations in SLEEP mode.

// CLG IOSC Control Register.
#define	CLGIOSC				(*((volatile CLGIOSC_REG *)(CLG_REG_BASE_ADDR + 0x04))).reg
#define	CLGIOSC_IOSCSTM		(*((volatile CLGIOSC_REG *)(CLG_REG_BASE_ADDR + 0x04))).bit.IOSCSTM			///< This bit controls the IOSCCLK auto-trimming function.

// CLG OSC1 Control Register.
#define	CLGOSC1				(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).reg
#define	CLGOSC1_OSC1WT		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.OSC1WT			///< These bits set the oscillation stabilization waiting time for the OSC1 oscillator circuit.
#define	CLGOSC1_INV1N		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.INV1N			///< These bits set the oscillation inverter gain applied at normal operation of the OSC1 oscillator circuit.
#define	CLGOSC1_INV1B		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.INV1B			///< These bits set the oscillation inverter gain that will be applied at boost startup of the OSC1 oscillator circuit.
#define	CLGOSC1_CGI1		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.CGI1			///< These bits set the internal gate capacitance in the OSC1 oscillator circuit.
#define	CLGOSC1_OSC1SELCR	(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.OSC1SELCR		///< This bit selects an oscillator type of the OSC1 oscillator circuit.
#define	CLGOSC1_OSC1BUP		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.OSC1BUP			///< This bit enables the oscillation startup control circuit in the OSC1 oscillator circuit.
#define	CLGOSC1_OSDEN		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.OSDEN			///< This bit controls the oscillation stop detector in the OSC1 oscillator circuit.
#define	CLGOSC1_OSDRB		(*((volatile CLGOSC1_REG *)(CLG_REG_BASE_ADDR + 0x06))).bit.OSDRB			///< This bit enables the OSC1 oscillator circuit restart function by the oscillation stop detector when OSC1 oscillation stop is detected.

// CLG OSC3 Control Register.
#define	CLGOSC3				(*((volatile CLGOSC3_REG *)(CLG_REG_BASE_ADDR + 0x08))).reg
#define	CLGOSC3_OSC3WT		(*((volatile CLGOSC3_REG *)(CLG_REG_BASE_ADDR + 0x08))).bit.OSC3WT			///< These bits set the oscillation stabilization waiting time for the OSC3 oscillator circuit.
#define	CLGOSC3_OSC3INV		(*((volatile CLGOSC3_REG *)(CLG_REG_BASE_ADDR + 0x08))).bit.OSC3INV			///< These bits set the oscillation inverter gain of the OSC3 oscillator circuit.
#define	CLGOSC3_OSC3MD		(*((volatile CLGOSC3_REG *)(CLG_REG_BASE_ADDR + 0x08))).bit.OSC3MD			///< These bits select an oscillator type of the OSC3 oscillator circuit.
#define	CLGOSC3_OSC3FQ		(*((volatile CLGOSC3_REG *)(CLG_REG_BASE_ADDR + 0x08))).bit.OSC3FQ			///< These bits set the oscillation frequency when the internal oscillator is selected as the OSC3 oscillator.

// CLG Interrupt Flag Register.
#define	CLGINTF				(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).reg
#define	CLGINTF_IOSCSTAIF	(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).bit.IOSCSTAIF		///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(IOSC).
#define	CLGINTF_OSC1STAIF	(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).bit.OSC1STAIF		///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(OSC1).
#define	CLGINTF_OSC3STAIF	(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).bit.OSC3STAIF		///< This bit indicate the oscillation stabilization waiting completion interrupt cause occurrence status in each clock source(OSC3).
#define	CLGINTF_IOSCTEDIF	(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).bit.IOSCTEDIF		///< This bit indicate the IOSC oscillation auto-trimming completion interrupt cause occurrence statuses.
#define	CLGINTF_OSC1STPIF	(*((volatile CLGINTF_REG *)(CLG_REG_BASE_ADDR + 0x0C))).bit.OSC1STPIF		///< This bit indicate the OSC1 oscillation stop.

// CLG Interrupt Enable Register.
#define	CLGINTE				(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).reg
#define	CLGINTE_IOSCSTAIE	(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).bit.IOSCSTAIE		///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(IOSC).
#define	CLGINTE_OSC1STAIE	(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).bit.OSC1STAIE		///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(OSC1).
#define	CLGINTE_OSC3STAIE	(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).bit.OSC3STAIE		///< This bit enable the oscillation stabilization waiting completion interrupt of each clock source(OSC3).
#define	CLGINTE_IOSCTEDIE	(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).bit.IOSCTEDIE		///< This bit enable the IOSC oscillation auto-trimming completion interrupts.
#define	CLGINTE_OSC1STPIE	(*((volatile CLGINTE_REG *)(CLG_REG_BASE_ADDR + 0x0E))).bit.OSC1STPIE		///< This bit enable the OSC1 oscillation stop.

// CLG FOUT Control Register.
#define	CLGFOUT				(*((volatile CLGFOUT_REG *)(CLG_REG_BASE_ADDR + 0x10))).reg
#define	CLGFOUT_FOUTEN		(*((volatile CLGFOUT_REG *)(CLG_REG_BASE_ADDR + 0x10))).bit.FOUTEN			///< This bit controls the FOUT clock external output.
#define	CLGFOUT_FOUTSRC		(*((volatile CLGFOUT_REG *)(CLG_REG_BASE_ADDR + 0x10))).bit.FOUTSRC			///< These bits select the FOUT clock source.
#define	CLGFOUT_FOUTDIV		(*((volatile CLGFOUT_REG *)(CLG_REG_BASE_ADDR + 0x10))).bit.FOUTDIV			///< These bits set the FOUT clock division ratio.

// CLG Oscillation Frequency Trimming Register.
#define	CLGTRIM				(*((volatile CLGTRIM_REG *)(CLG_REG_BASE_ADDR + 0x12))).reg
#define	CLGTRIM_IOSCAJ		(*((volatile CLGTRIM_REG *)(CLG_REG_BASE_ADDR + 0x12))).byte_reg[0]			///< These bits sets the frequency trimming value for the IOSC internal oscillator circuit.
#define	CLGTRIM_OSC3AJ		(*((volatile CLGTRIM_REG *)(CLG_REG_BASE_ADDR + 0x12))).byte_reg[1]			///< These bits sets the frequency trimming value for the OSC3 internal oscillator circuit.


/*******************/
/* ----- ITC ----- */
/*******************/

// ITC Interrupt Level Setup Register 0
#define	ITCLV0				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x00))).reg
#define	ITCLV0_ILV0			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x00))).byte_reg[0]			///< Supply voltage detector interrupt.
#define	ITCLV0_ILV1			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< Port interrupt.

// ITC Interrupt Level Setup Register 1
#define	ITCLV1				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x02))).reg
#define	ITCLV1_ILV2			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x02))).byte_reg[0]			///< Power generator interrupt.
#define	ITCLV1_ILV3			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x02))).byte_reg[1]			///< Clock generator interrupt.

// ITC Interrupt Level Setup Register 2
#define	ITCLV2				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x04))).reg
#define	ITCLV2_ILV4			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x04))).byte_reg[0]			///< Real-time clock interrupt.
#define	ITCLV2_ILV5			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x04))).byte_reg[1]			///< 16-bit timer Ch.0 interrupt.

// ITC Interrupt Level Setup Register 3
#define	ITCLV3				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x06))).reg
#define	ITCLV3_ILV6			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x06))).byte_reg[0]			///< UART2 Ch.0 interrupt.
#define	ITCLV3_ILV7			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x06))).byte_reg[1]			///< 16-bit timer Ch.1 interrupt.

// ITC Interrupt Level Setup Register 4
#define	ITCLV4				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x08))).reg
#define	ITCLV4_ILV8			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x08))).byte_reg[0]			///< Synchronous serial interface Ch.0 interrupt.
#define	ITCLV4_ILV9			(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x08))).byte_reg[1]			///< I2C interrupt.

// ITC Interrupt Level Setup Register 5
#define	ITCLV5				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0A))).reg
#define	ITCLV5_ILV10		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0A))).byte_reg[0]			///< 16-bit PWM timer Ch.0 interrupt.
#define	ITCLV5_ILV11		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0A))).byte_reg[1]			///< 16-bit PWM timer Ch.1 interrupt.

// ITC Interrupt Level Setup Register 6
#define	ITCLV6				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0C))).reg
#define	ITCLV6_ILV12		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0C))).byte_reg[0]			///< UART2 Ch.1 interrupt.
#define	ITCLV6_ILV13		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0C))).byte_reg[1]			///< 16-bit timer Ch.2 interrupt.

// ITC Interrupt Level Setup Register 7
#define	ITCLV7				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0E))).reg
#define	ITCLV7_ILV14		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0E))).byte_reg[0]			///< Sound generator interrupt.
#define	ITCLV7_ILV15		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x0E))).byte_reg[1]			///< LCD driver interrupt.

// ITC Interrupt Level Setup Register 8
#define	ITCLV8				(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x10))).reg
#define	ITCLV8_ILV16		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x10))).byte_reg[0]			///< R/F converter Ch.0 interrupt.
#define	ITCLV8_ILV17		(*((volatile ITCLVX_REG *)(ITC_REG_BASE_ADDR + 0x10))).byte_reg[1]			///< IR remote controller interrupt.



// Interrupt Level Registers.
#define	ILVSVD				( ITCLV0_ILV0 )																///< Supply voltage detector interrupt.
#define	ILVPPORT			( ITCLV0_ILV1 )																///< Port interrupt.
#define	ILVPWG2				( ITCLV1_ILV2 )																///< Power generator interrupt.
#define	ILVCLG				( ITCLV1_ILV3 )																///< Clock generator interrupt.
#define	ILVRTCA_0			( ITCLV2_ILV4 )																///< Real-time clock interrupt.
#define	ILVT16_0			( ITCLV2_ILV5 )																///< 16-bit timer Ch.0 interrupt.
#define	ILVUART2_0			( ITCLV3_ILV6 )																///< UART2 Ch.0 interrupt.
#define	ILVT16_1			( ITCLV3_ILV7 )																///< 16-bit timer Ch.1 interrupt.
#define	ILVSPIA_0			( ITCLV4_ILV8 )																///< Synchronous serial interface Ch.0 interrupt.
#define	ILVI2C_0			( ITCLV4_ILV9 )																///< I2C interrupt.
#define	ILVT16B_0			( ITCLV5_ILV10 )															///< 16-bit PWM timer Ch.0 interrupt.
#define	ILVT16B_1			( ITCLV5_ILV11 )															///< 16-bit PWM timer Ch.1 interrupt.
#define	ILVUART2_1			( ITCLV6_ILV12 )															///< UART2 Ch.1 interrupt.
#define	ILVT16_2			( ITCLV6_ILV13 )															///< 16-bit timer Ch.2 interrupt.
#define	ILVSNDA_0			( ITCLV7_ILV14 )															///< Sound generator interrupt.
#define	ILVLCD4A			( ITCLV7_ILV15 )															///< LCD driver interrupt.
#define	ILVRFC_0			( ITCLV8_ILV16 )															///< R/F converter Ch.0 interrupt.
#define	ILVREMC2_0			( ITCLV8_ILV17 )															///< IR remote controller interrupt


/*******************/
/* ----- WDT2 ---- */
/*******************/

// WDT2 Clock Control Register
#define	WDTCLK				(*((volatile WDTCLK_REG *)(WDT2_REG_BASE_ADDR + 0x00))).reg
#define	WDTCLK_CLKSRC		(*((volatile WDTCLK_REG *)(WDT2_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of WDT2.
#define	WDTCLK_CLKDIV		(*((volatile WDTCLK_REG *)(WDT2_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the WDT2 operating clock (counter clock).
#define	WDTCLK_DBRUN		(*((volatile WDTCLK_REG *)(WDT2_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< This bit sets whether the WDT operating clock is supplied in DEBUG mode or not.

// WDT2 Control Register
#define	WDTCTL				(*((volatile WDTCTL_REG *)(WDT2_REG_BASE_ADDR + 0x02))).reg
#define	WDTCTL_WDTRUN		(*((volatile WDTCTL_REG *)(WDT2_REG_BASE_ADDR + 0x02))).bit.WDTRUN			///< These bits control WDT2 to run and stop.
#define	WDTCTL_WDTCNTRST	(*((volatile WDTCTL_REG *)(WDT2_REG_BASE_ADDR + 0x02))).bit.WDTCNTRST		///< This bit resets WDT2.
#define WDTCTL_STATNMI		(*((volatile WDTCTL_REG *)(WDT2_REG_BASE_ADDR + 0x02))).bit.STATNMI			///< This bit indicates that a counter overflow and NMI have occurred.
#define WDTCTL_MOD			(*((volatile WDTCTL_REG *)(WDT2_REG_BASE_ADDR + 0x02))).bit.MOD				///< This bit sets the WDT2 operating mode.

// WDT2 Counter Compare Match Register.
#define WDTCMP				(*((volatile WDTCMP_REG *)(WDT2_REG_BASE_ADDR + 0x04))).reg
#define WDTCMP_CMP			WDTCMP																	///< These bits set the NMI/reset generation cycle.


/********************/
/* ----- RTCA ----- */
/********************/

// RTCA Control Register
#define	RTCCTL				(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).reg
#define	RTCCTL_RTCRUN		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCRUN			///< This bit starts/stops the real-time clock counter.
#define	RTCCTL_RTCRST		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCRST			///< This bit resets the 1 Hz counter, the RTCCTL.RTCADJ bit, and the RTCCTL.RTCHLD bit.
#define	RTCCTL_RTCADJ		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCADJ			///< This bit executes the 30-second correction time adjustment function.
#define	RTCCTL_RTC24H		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTC24H			///< This bit sets the hour counter to 24H mode or 12H mode.
#define	RTCCTL_RTCHLD		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCHLD			///< This bit halts the count-up operation of the real-time clock counter.
#define	RTCCTL_RTCBSY		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCBSY			///< This bit indicates whether the counter is performing count-up operation or not.
#define	RTCCTL_RTCTRM		(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCTRM			///< Write the correction value for adjusting the 1 Hz frequency to these bits to execute theoretical regulation.
#define	RTCCTL_RTCTRMBSY	(*((volatile RTCCTL_REG *)(RTCA_REG_BASE_ADDR + 0x00))).bit.RTCTRMBSY		///< This bit indicates whether the theoretical regulation is currently executed or not.

// RTCA Second Alarm Register
#define	RTCALM1				(*((volatile RTCALM1_REG *)(RTCA_REG_BASE_ADDR + 0x02))).reg
#define	RTCALM1_RTCSLA		(*((volatile RTCALM1_REG *)(RTCA_REG_BASE_ADDR + 0x02))).bit.RTCSLA			///< There bits set the 1-second digit of the alarm time.
#define	RTCALM1_RTCSHA		(*((volatile RTCALM1_REG *)(RTCA_REG_BASE_ADDR + 0x02))).bit.RTCSHA			///< There bits set the 10-second digit of the alarm time.

// RTCA Hour/Minute Alarm Register
#define	RTCALM2				(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).reg
#define	RTCALM2_RTCMILA		(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).bit.RTCMILA		///< There bits set the 1-minute digit of the alarm time.
#define	RTCALM2_RTCMIHA		(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).bit.RTCMIHA		///< There bits set the 10-minute digit of the alarm time
#define	RTCALM2_RTCHLA		(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).bit.RTCHLA			///< There bits set the 1-hour digit of the alarm time.
#define	RTCALM2_RTCHHA		(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).bit.RTCHHA			///< There bits set the 10-hour digit of the alarm time.
#define	RTCALM2_RTCAPA		(*((volatile RTCALM2_REG *)(RTCA_REG_BASE_ADDR + 0x04))).bit.RTCAPA			///< This bit set A.M. or P.M. of the alarm time in 12H mode (RTCCTL.RTC24H bit = 0).

// RTCA Stopwatch Control Register
#define	RTCSWCTL			(*((volatile RTCSWCTL_REG *)(RTCA_REG_BASE_ADDR + 0x06))).reg
#define	RTCSWCTL_SWRUN		(*((volatile RTCSWCTL_REG *)(RTCA_REG_BASE_ADDR + 0x06))).bit.SWRUN			///< This bit starts/stops the stopwatch counter.
#define	RTCSWCTL_SWRST		(*((volatile RTCSWCTL_REG *)(RTCA_REG_BASE_ADDR + 0x06))).bit.SWRST			///< This bit resets the stopwatch counter to 0x00.
#define	RTCSWCTL_BCD100		(*((volatile RTCSWCTL_REG *)(RTCA_REG_BASE_ADDR + 0x06))).bit.BCD100		///< The 1/100-second digits of the stopwatch counter can be read as a BCD code.
#define	RTCSWCTL_BCD10		(*((volatile RTCSWCTL_REG *)(RTCA_REG_BASE_ADDR + 0x06))).bit.BCD10			///< The 1/10-second digits of the stopwatch counter can be read as a BCD code.

// RTCA Second/1[Hz] Register
#define	RTCSEC				(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).reg
#define	RTCSEC_RTC128HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC128HZ		///< 1 Hz counter data can be read from these bits(128Hz).
#define	RTCSEC_RTC64HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC64HZ			///< 1 Hz counter data can be read from these bits(64Hz).
#define	RTCSEC_RTC32HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC32HZ			///< 1 Hz counter data can be read from these bits(32Hz).
#define	RTCSEC_RTC16HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC16HZ			///< 1 Hz counter data can be read from these bits(16Hz).
#define	RTCSEC_RTC8HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC8HZ			///< 1 Hz counter data can be read from these bits(8Hz).
#define	RTCSEC_RTC4HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC4HZ			///< 1 Hz counter data can be read from these bits(4Hz).
#define	RTCSEC_RTC2HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC2HZ			///< 1 Hz counter data can be read from these bits(2Hz).
#define	RTCSEC_RTC1HZ		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTC1HZ			///< 1 Hz counter data can be read from these bits(1Hz).
#define	RTCSEC_RTCSL		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTCSL			///< There bits are used to set and read the 1-second digit of the second counter.
#define	RTCSEC_RTCSH		(*((volatile RTCSEC_REG *)(RTCA_REG_BASE_ADDR + 0x08))).bit.RTCSH			///< There bits are used to set and read the 10-second digit of the second counter.

// RTCA Hour/Minute Register
#define	RTCHUR				(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).reg
#define	RTCHUR_RTCMIL		(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).bit.RTCMIL			///< There bits are used to set and read the 1-minute digit of the minute counter.
#define	RTCHUR_RTCMIH		(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).bit.RTCMIH			///< There bits are used to set and read the 10-minute digit of the minute counter.
#define	RTCHUR_RTCHL		(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).bit.RTCHL			///< There bits are used to set and read the 1-hour digit of the hour counter.
#define	RTCHUR_RTCHH		(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).bit.RTCHH			///< There bits are used to set and read the 10-hour digit of the hour counter.
#define	RTCHUR_RTCAP		(*((volatile RTCHUR_REG *)(RTCA_REG_BASE_ADDR + 0x0A))).bit.RTCAP			///< This bit is used to set and read A.M. or P.M. data in 12H mode (RTCCTL.RTC24H bit = 0).

// RTCA Month/Day Register
#define	RTCMON				(*((volatile RTCMON_REG *)(RTCA_REG_BASE_ADDR + 0x0C))).reg
#define	RTCMON_RTCDL		(*((volatile RTCMON_REG *)(RTCA_REG_BASE_ADDR + 0x0C))).bit.RTCDL			///< There bits are used to set and read the 1-day digit of the day counter.
#define	RTCMON_RTCDH		(*((volatile RTCMON_REG *)(RTCA_REG_BASE_ADDR + 0x0C))).bit.RTCDH			///< There bits are used to set and read the 10-day digit of the day counter.
#define	RTCMON_RTCMOL		(*((volatile RTCMON_REG *)(RTCA_REG_BASE_ADDR + 0x0C))).bit.RTCMOL			///< There bits are used to set and read the 1-month digit of the month counter.
#define	RTCMON_RTCMOH		(*((volatile RTCMON_REG *)(RTCA_REG_BASE_ADDR + 0x0C))).bit.RTCMOH			///< There bits are used to set and read the 10-month digit of the month counter.

// RTCA Year/Week Register
#define	RTCYAR				(*((volatile RTCYAR_REG *)(RTCA_REG_BASE_ADDR + 0x0E))).reg
#define	RTCYAR_RTCYL		(*((volatile RTCYAR_REG *)(RTCA_REG_BASE_ADDR + 0x0E))).bit.RTCYL			///< There bits are used to set and read the 1-year digit of the year counter.
#define	RTCYAR_RTCYH		(*((volatile RTCYAR_REG *)(RTCA_REG_BASE_ADDR + 0x0E))).bit.RTCYH			///< There bits are used to set and read the 10-year digit of the year counter.
#define	RTCYAR_RTCWK		(*((volatile RTCYAR_REG *)(RTCA_REG_BASE_ADDR + 0x0E))).byte_reg[1]			///< These bits are used to set and read day of the week.

// RTCA Interrupt Flag Register
#define	RTCINTF				(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).reg
#define	RTCINTF_1_32SECIF	(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1_32SECIF		///< This bit indicate 1/32-second interrupt cause occurrence status.
#define	RTCINTF_1_8SECIF	(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1_8SECIF		///< This bit indicate 1/8-second interrupt cause occurrence status.
#define	RTCINTF_1_4SECIF	(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1_4SECIF		///< This bit indicate 1/4-second interrupt cause occurrence status.
#define	RTCINTF_1_2SECIF	(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1_2SECIF		///< This bit indicate 1/2-second interrupt cause occurrence status.
#define	RTCINTF_1SECIF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1SECIF		///< This bit indicate 1-second interrupt cause occurrence status.
#define	RTCINTF_1MINIF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1MINIF		///< This bit indicate 1-minute interrupt cause occurrence status.
#define	RTCINTF_1HURIF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1HURIF		///< This bit indicate 1-day interrupt cause occurrence status.
#define	RTCINTF_1DAYIF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit._1DAYIF		///< This bit indicate 1-day interrupt cause occurrence status.
#define	RTCINTF_ALARMIF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit.ALARMIF		///< This bit indicate Alarm interrupt cause occurrence status.
#define	RTCINTF_SW100IF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit.SW100IF		///< This bit indicate Stopwatch 100 Hz interrupt cause occurrence status.
#define	RTCINTF_SW10IF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit.SW10IF			///< This bit indicate Stopwatch 10 Hz interrupt cause occurrence status.
#define	RTCINTF_SW1IF		(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit.SW1IF			///< This bit indicate Stopwatch 1 Hz interrupt cause occurrence status.
#define	RTCINTF_RTCTRMIF	(*((volatile RTCINTF_REG *)(RTCA_REG_BASE_ADDR + 0x10))).bit.RTCTRMIF		///< This bit indicate Theoretical regulation completion interrupt cause occurrence status.

// RTCA Interrupt Enable Register
#define	RTCINTE				(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).reg
#define	RTCINTE_1_32SECIE	(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1_32SECIE		///< This bits enable 1/32-second interrupt.
#define	RTCINTE_1_8SECIE	(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1_8SECIE		///< This bits enable 1/8-second interrupt.
#define	RTCINTE_1_4SECIE	(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1_4SECIE		///< This bits enable 1/4-second interrupt.
#define	RTCINTE_1_2SECIE	(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1_2SECIE		///< This bits enable 1/2-second interrupt.
#define	RTCINTE_1SECIE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1SECIE		///< This bits enable 1-second interrupt.
#define	RTCINTE_1MINIE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1MINIE		///< This bits enable 1-minute interrupt.
#define	RTCINTE_1HURIE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1HURIE		///< This bits enable 1-hour interrupt.
#define	RTCINTE_1DAYIE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit._1DAYIE		///< This bits enable 1-day interrupt.
#define	RTCINTE_ALARMIE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit.ALARMIE		///< This bits enable Alarm interrupt.
#define	RTCINTE_SW100IE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit.SW100IE		///< This bit enable Stopwatch 100 Hz interrupt.
#define	RTCINTE_SW10IE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit.SW10IE			///< This bit enable Stopwatch 10 Hz interrupt.
#define	RTCINTE_SW1IE		(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit.SW1IE			///< This bit enable Stopwatch 1 Hz interrupt.
#define	RTCINTE_RTCTRMIE	(*((volatile RTCINTE_REG *)(RTCA_REG_BASE_ADDR + 0x12))).bit.RTCTRMIE		///< This bit enable Theoretical regulation completion interrupt.


/*******************/
/* ----- SVD ----- */
/*******************/

// SVD Clock Control Register
#define	SVDCLK				(*((volatile SVDCLK_REG *)(SVD_REG_BASE_ADDR + 0x00))).reg
#define	SVDCLK_CLKSRC		(*((volatile SVDCLK_REG *)(SVD_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of SVD.
#define	SVDCLK_CLKDIV		(*((volatile SVDCLK_REG *)(SVD_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the SVD operating clock.
#define	SVDCLK_DBRUN		(*((volatile SVDCLK_REG *)(SVD_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< This bit sets whether the SVD operating clock is supplied in DEBUG mode or not.

// SVD Control Register
#define	SVDCTL				(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).reg
#define	SVDCTL_MODEN		(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.MODEN			///< This bit enables/disables for the SVD circuit to operate.
#define	SVDCTL_SVDMD		(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.SVDMD			///< These bits select intermittent operation mode and its detection cycle.
#define	SVDCTL_SVDRE		(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.SVDRE			///< These bits enable/disable the reset issuance function when a low power supply voltage is detected.
#define	SVDCTL_SVDC			(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.SVDC				///< These bits select a comparison voltage for detecting low voltage from among 20 levels.
#define	SVDCTL_SVDSC		(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.SVDSC			///< These bits set the condition to generate an interrupt/reset in intermittent operation mode.
#define	SVDCTL_VDSEL		(*((volatile SVDCTL_REG *)(SVD_REG_BASE_ADDR + 0x02))).bit.VDSEL			///< his bit selects the power supply voltage to be detected by SVD.

// SVD Status and Interrupt Flag Register
#define	SVDINTF				(*((volatile SVDINTF_REG *)(SVD_REG_BASE_ADDR + 0x04))).reg
#define	SVDINTF_SVDIF		(*((volatile SVDINTF_REG *)(SVD_REG_BASE_ADDR + 0x04))).byte_reg[0]			///< This bit indicates the low power supply voltage detection interrupt cause occurrence status.
#define	SVDINTF_SVDDT		(*((volatile SVDINTF_REG *)(SVD_REG_BASE_ADDR + 0x04))).byte_reg[1]			///< The power supply voltage detection results can be read out from this bit.

// SVD Interrupt Enable Register
#define	SVDINTE				(*((volatile SVDINTE_REG *)(SVD_REG_BASE_ADDR + 0x06))).reg
#define	SVDINTE_SVDIE		SVDINTE																		///< This bit enables low power supply voltage detection interrupts.


/*******************/
/* ----- T16 ----- */
/*******************/

// T16 Ch.0 Clock Control Register
#define	T16_0CLK			(*((volatile T16_NCLK_REG *)(T16_0_REG_BASE_ADDR + 0x00))).reg
#define	T16_0CLK_CLKSRC		(*((volatile T16_NCLK_REG *)(T16_0_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of T16 Ch.0.
#define	T16_0CLK_CLKDIV		(*((volatile T16_NCLK_REG *)(T16_0_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the T16 Ch.0 operating clock (counter clock).
#define	T16_0CLK_DBRUN		(*((volatile T16_NCLK_REG *)(T16_0_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the T16 Ch.0 operating clock is supplied in DEBUG mode or not.

// T16 Ch.0 Mode Register
#define	T16_0MOD			(*((volatile T16_NMOD_REG *)(T16_0_REG_BASE_ADDR + 0x02))).reg
#define	T16_0MOD_TRMD		T16_0MOD																	///< This bit selects the T16(Ch.0) operation mode.

// T16 Ch.0 Control Register
#define	T16_0CTL			(*((volatile T16_NCTL_REG *)(T16_0_REG_BASE_ADDR + 0x04))).reg
#define	T16_0CTL_MODEN		(*((volatile T16_NCTL_REG *)(T16_0_REG_BASE_ADDR + 0x04))).bit.MODEN		///< This bit enables the T16 operations(Ch.0).
#define	T16_0CTL_PRESET		(*((volatile T16_NCTL_REG *)(T16_0_REG_BASE_ADDR + 0x04))).bit.PRESET		///< This bit presets the reload data stored in the T16_0TR register to the counter.
#define	T16_0CTL_PRUN		(*((volatile T16_NCTL_REG *)(T16_0_REG_BASE_ADDR + 0x04))).byte_reg[1]		///< This bit starts/stops the timer(Ch.0).

// T16 Ch.0 Reload Data Register
#define	T16_0TR				(*((volatile T16_NTR_REG *)(T16_0_REG_BASE_ADDR + 0x06))).reg

// T16 Ch.0 Counter Data Register
#define	T16_0TC				(*((volatile T16_NTC_REG *)(T16_0_REG_BASE_ADDR + 0x08))).reg

// T16 Ch.0 Interrupt Flag Register
#define	T16_0INTF			(*((volatile T16_NINTF_REG *)(T16_0_REG_BASE_ADDR + 0x0A))).reg
#define	T16_0INTF_UFIF		T16_0INTF																	///< This bit indicates the T16 Ch.0 underflow interrupt cause occurrence status.

// T16 Ch.0 Interrupt Enable Register
#define	T16_0INTE			(*((volatile T16_NINTE_REG *)(T16_0_REG_BASE_ADDR + 0x0C))).reg
#define	T16_0INTE_UFIE		T16_0INTE																	///< This bit enables T16 Ch.0 underflow interrupts.

// T16 Ch.1 Clock Control Register
#define	T16_1CLK			(*((volatile T16_NCLK_REG *)(T16_1_REG_BASE_ADDR + 0x00))).reg
#define	T16_1CLK_CLKSRC		(*((volatile T16_NCLK_REG *)(T16_1_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of T16 Ch.1.
#define	T16_1CLK_CLKDIV		(*((volatile T16_NCLK_REG *)(T16_1_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the T16 Ch.1 operating clock (counter clock).
#define	T16_1CLK_DBRUN		(*((volatile T16_NCLK_REG *)(T16_1_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the T16 Ch.1 operating clock is supplied in DEBUG mode or not.

// T16 Ch.1 Mode Register
#define	T16_1MOD			(*((volatile T16_NMOD_REG *)(T16_1_REG_BASE_ADDR + 0x02))).reg
#define	T16_1MOD_TRMD		T16_1MOD																	///< This bit selects the T16(Ch.1) operation mode.

// T16 Ch.1 Control Register
#define	T16_1CTL			(*((volatile T16_NCTL_REG *)(T16_1_REG_BASE_ADDR + 0x04))).reg
#define	T16_1CTL_MODEN		(*((volatile T16_NCTL_REG *)(T16_1_REG_BASE_ADDR + 0x04))).bit.MODEN		///< This bit enables the T16 operations(Ch.1).
#define	T16_1CTL_PRESET		(*((volatile T16_NCTL_REG *)(T16_1_REG_BASE_ADDR + 0x04))).bit.PRESET		///< This bit presets the reload data stored in the T16_1TR register to the counter.
#define	T16_1CTL_PRUN		(*((volatile T16_NCTL_REG *)(T16_1_REG_BASE_ADDR + 0x04))).byte_reg[1]		///< This bit starts/stops the timer(Ch.1).

// T16 Ch.1 Reload Data Register
#define	T16_1TR				(*((volatile T16_NTR_REG *)(T16_1_REG_BASE_ADDR + 0x06))).reg

// T16 Ch.1 Counter Data Register
#define	T16_1TC				(*((volatile T16_NTC_REG *)(T16_1_REG_BASE_ADDR + 0x08))).reg

// T16 Ch.1 Interrupt Flag Register
#define	T16_1INTF			(*((volatile T16_NINTF_REG *)(T16_1_REG_BASE_ADDR + 0x0A))).reg
#define	T16_1INTF_UFIF		T16_1INTF																	///< This bit indicates the T16 Ch.1 underflow interrupt cause occurrence status.

// T16 Ch.1 Interrupt Enable Register
#define	T16_1INTE			(*((volatile T16_NINTE_REG *)(T16_1_REG_BASE_ADDR + 0x0C))).reg
#define	T16_1INTE_UFIE		T16_1INTE																	///< This bit enables T16 Ch.1 underflow interrupts.

// T16 Ch.2 Clock Control Register
#define	T16_2CLK			(*((volatile T16_NCLK_REG *)(T16_2_REG_BASE_ADDR + 0x00))).reg
#define	T16_2CLK_CLKSRC		(*((volatile T16_NCLK_REG *)(T16_2_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of T16 Ch.2.
#define	T16_2CLK_CLKDIV		(*((volatile T16_NCLK_REG *)(T16_2_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the T16 Ch.2 operating clock (counter clock).
#define	T16_2CLK_DBRUN		(*((volatile T16_NCLK_REG *)(T16_2_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the T16 Ch.2 operating clock is supplied in DEBUG mode or not.

// T16 Ch.2 Mode Register
#define	T16_2MOD			(*((volatile T16_NMOD_REG *)(T16_2_REG_BASE_ADDR + 0x02))).reg
#define	T16_2MOD_TRMD		T16_2MOD																	///< This bit selects the T16(Ch.2) operation mode.

// T16 Ch.2 Control Register
#define	T16_2CTL			(*((volatile T16_NCTL_REG *)(T16_2_REG_BASE_ADDR + 0x04))).reg
#define	T16_2CTL_MODEN		(*((volatile T16_NCTL_REG *)(T16_2_REG_BASE_ADDR + 0x04))).bit.MODEN		///< This bit enables the T16 operations(Ch.2).
#define	T16_2CTL_PRESET		(*((volatile T16_NCTL_REG *)(T16_2_REG_BASE_ADDR + 0x04))).bit.PRESET		///< This bit presets the reload data stored in the T16_2TR register to the counter.
#define	T16_2CTL_PRUN		(*((volatile T16_NCTL_REG *)(T16_2_REG_BASE_ADDR + 0x04))).byte_reg[1]		///< This bit starts/stops the timer(Ch.2).

// T16 Ch.2 Reload Data Register
#define	T16_2TR				(*((volatile T16_NTR_REG *)(T16_2_REG_BASE_ADDR + 0x06))).reg

// T16 Ch.2 Counter Data Register
#define	T16_2TC				(*((volatile T16_NTC_REG *)(T16_2_REG_BASE_ADDR + 0x08))).reg

// T16 Ch.2 Interrupt Flag Register
#define	T16_2INTF			(*((volatile T16_NINTF_REG *)(T16_2_REG_BASE_ADDR + 0x0A))).reg
#define	T16_2INTF_UFIF		T16_2INTF																	///< This bit indicates the T16 Ch.2 underflow interrupt cause occurrence status.

// T16 Ch.2 Interrupt Enable Register
#define	T16_2INTE			(*((volatile T16_NINTE_REG *)(T16_2_REG_BASE_ADDR + 0x0C))).reg
#define	T16_2INTE_UFIE		T16_2INTE																	///< This bit enables T16 Ch.2 underflow interrupts.


/**********************/
/* ----- FLASHC ----- */
/**********************/

// FLASHC Flash Read Cycle Register
#define	FLASHCWAIT			(*((volatile FLASHCWAIT_REG *)(FLASHC_REG_BASE_ADDR + 0x00))).reg
#define	FLASHCWAIT_RDWAIT	FLASHCWAIT																	///< These bits set the number of bus access cycles for reading from the Flash memory.



/*********************/
/* ----- PPORT ----- */
/*********************/

// P0 Port Data Register
#define	P0DAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).reg
#define	P0DAT_P00IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px0IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P01IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px1IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P02IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px2IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P03IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px3IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P04IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px4IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P05IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px5IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P06IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px6IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P07IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px7IN			///< The GPIO port pin status can be read out from this bit.
#define	P0DAT_P00OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P01OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P02OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px2OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P03OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px3OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P04OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px4OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P05OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px5OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P06OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px6OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P0DAT_P07OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).bit.Px7OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define P0DAT_P0IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).byte_reg[0] 		///< The GPIO port pin status can be read out from this bit.
#define P0DAT_P0OUT 		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x00))).byte_reg[1] 		///< This bit are used to set data to be output from the GPIO port pin.


// P0 Port Enable Register
#define	P0IOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).reg
#define	P0IOEN_P00OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P01OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P02OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px2OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P03OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px3OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P04OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px4OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P05OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px5OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P06OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px6OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P07OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px7OEN			///< This bit enable/disable the GPIO port output.
#define	P0IOEN_P00IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px0IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P01IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px1IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P02IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px2IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P03IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px3IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P04IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px4IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P05IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px5IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P06IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px6IEN			///< This bit enable/disable the GPIO port input.
#define	P0IOEN_P07IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).bit.Px7IEN			///< This bit enable/disable the GPIO port input.

#define P0IOEN_P0OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).byte_reg[0]		///< This bit enable/disable the GPIO port output.
#define P0IOEN_P0IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x02))).byte_reg[1]		///< This bit enable/disable the GPIO port input.


// P0 Port Pull-up/down Control Register
#define	P0RCTL				(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).reg
#define	P0RCTL_P00REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px0REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P01REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px1REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P02REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px2REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P03REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px3REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P04REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px4REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P05REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px5REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P06REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px6REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P07REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px7REN			///< This bit enable/disable the port pull-up/down control.
#define	P0RCTL_P00PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px0PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P01PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px1PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P02PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px2PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P03PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px3PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P04PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px4PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P05PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px5PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P06PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px6PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P0RCTL_P07PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).bit.Px7PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.

#define P0RCTL_P0REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).byte_reg[0]		///< This bit enable/disable the port pull-up/down control.
#define P0RCTL_P0PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x04))).byte_reg[1]		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.



// P0 Port Interrupt Flag Register
#define	P0INTF				(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).reg
#define	P0INTF_P00IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px0IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P01IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px1IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P02IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px2IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P03IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px3IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P04IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px4IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P05IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px5IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P06IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px6IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P0INTF_P07IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x06))).bit.Px7IF			///< This bit indicate the port input interrupt cause occurrence status.

#define	P0INTF_P0IF			P0INTF																		///< This bit indicate the port input interrupt cause occurrence status.


// P0 Port Interrupt Control Register
#define	P0INTCTL			(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).reg
#define	P0INTCTL_P00IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px0IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P01IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px1IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P02IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px2IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P03IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px3IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P04IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px4IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P05IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px5IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P06IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px6IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P07IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px7IE		///< This bit enable port input interrupt.
#define	P0INTCTL_P00EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px0EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P01EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px1EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P02EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px2EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P03EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px3EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P04EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px4EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P05EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px5EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P06EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px6EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P0INTCTL_P07EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).bit.Px7EDGE		///< This bit select the input signal edge to generate a port input interrupt.

#define P0INTCTL_P0IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).byte_reg[0]		///< This bit enable port input interrupt.
#define P0INTCTL_P0EDGE 	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x08))).byte_reg[1]		///< This bit select the input signal edge to generate a port input interrupt.


// P0 Port Chattering Filter Enable Register
#define	P0CHATEN			(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).reg
#define	P0CHATEN_P00CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px0CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P01CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px1CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P02CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px2CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P03CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px3CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P04CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px4CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P05CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px5CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P06CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px6CHATEN	///< This bit enable/disable the chattering filter function.
#define	P0CHATEN_P07CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x0A))).bit.Px7CHATEN	///< This bit enable/disable the chattering filter function.

#define P0CHATEN_P0CHATEN	P0CHATEN																	///< This bit enable/disable the chattering filter function.


// P0 Port Mode Select Register
#define	P0MODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).reg
#define	P0MODSEL_P00SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P01SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P02SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px2SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P03SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px3SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P04SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px4SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P05SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px5SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P06SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px6SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P0MODSEL_P07SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0C))).bit.Px7SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.

#define	P0MODSEL_P0SEL		P0MODSEL																	///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.


// P0 Port Function Select Register
#define	P0FNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).reg
#define	P0FNCSEL_P00MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P01MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P02MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px2MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P03MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px3MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P04MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px4MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P05MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px5MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P06MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px6MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P0FNCSEL_P07MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x0E))).bit.Px7MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.


// P1 Port Data Register
#define	P1DAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).reg
#define	P1DAT_P10IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px0IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P11IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px1IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P12IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px2IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P13IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px3IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P14IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px4IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P15IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px5IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P16IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px6IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P17IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px7IN			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P10OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P11OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P12OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px2OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P13OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px3OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P14OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px4OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P15OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px5OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P16OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px6OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P1DAT_P17OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).bit.Px7OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define	P1DAT_P1IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).byte_reg[0]			///< The GPIO port pin status can be read out from this bit.
#define	P1DAT_P1OUT			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x10))).byte_reg[1]			///< This bit are used to set data to be output from the GPIO port pin.


// P1 Port Enable Register
#define	P1IOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).reg
#define	P1IOEN_P10OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P11OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P12OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px2OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P13OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px3OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P14OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px4OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P15OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px5OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P16OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px6OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P17OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px7OEN			///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P10IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px0IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P11IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px1IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P12IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px2IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P13IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px3IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P14IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px4IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P15IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px5IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P16IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px6IEN			///< This bit enable/disable the GPIO port input.
#define	P1IOEN_P17IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).bit.Px7IEN			///< This bit enable/disable the GPIO port input.

#define	P1IOEN_P1OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).byte_reg[0]		///< This bit enable/disable the GPIO port output.
#define	P1IOEN_P1IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x12))).byte_reg[1]		///< This bit enable/disable the GPIO port input.


// P1 Port Pull-up/down Control Register
#define	P1RCTL				(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).reg
#define	P1RCTL_P10REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px0REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P11REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px1REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P12REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px2REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P13REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px3REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P14REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px4REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P15REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px5REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P16REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px6REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P17REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px7REN			///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P10PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px0PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P11PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px1PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P12PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px2PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P13PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px3PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P14PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px4PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P15PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px5PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P16PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px6PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P1RCTL_P17PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).bit.Px7PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.

#define	P1RCTL_P1REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).byte_reg[0]		///< This bit enable/disable the port pull-up/down control.
#define	P1RCTL_P1PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x14))).byte_reg[1]		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.


// P1 Port Interrupt Flag Register
#define	P1INTF				(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).reg
#define	P1INTF_P10IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px0IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P11IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px1IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P12IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px2IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P13IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px3IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P14IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px4IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P15IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px5IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P16IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px6IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P1INTF_P17IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x16))).bit.Px7IF			///< This bit indicate the port input interrupt cause occurrence status.

#define	P1INTF_P1IF			P1INTF																		///< This bit indicate the port input interrupt cause occurrence status.


// P1 Port Interrupt Control Register
#define	P1INTCTL			(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).reg
#define	P1INTCTL_P10IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px0IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P11IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px1IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P12IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px2IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P13IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px3IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P14IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px4IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P15IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px5IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P16IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px6IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P17IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px7IE		///< This bit enable port input interrupt.
#define	P1INTCTL_P10EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px0EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P11EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px1EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P12EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px2EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P13EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px3EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P14EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px4EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P15EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px5EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P16EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px6EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P1INTCTL_P17EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).bit.Px7EDGE		///< This bit select the input signal edge to generate a port input interrupt.

#define	P1INTCTL_P1IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).byte_reg[0]		///< This bit enable port input interrupt.
#define	P1INTCTL_P1EDGE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x18))).byte_reg[1]		///< This bit select the input signal edge to generate a port input interrupt.


// P1 Port Chattering Filter Enable Register
#define	P1CHATEN			(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).reg
#define	P1CHATEN_P10CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px0CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P11CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px1CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P12CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px2CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P13CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px3CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P14CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px4CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P15CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px5CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P16CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px6CHATEN	///< This bit enable/disable the chattering filter function.
#define	P1CHATEN_P17CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x1A))).bit.Px7CHATEN	///< This bit enable/disable the chattering filter function.

#define	P1CHATEN_P1CHATEN	P1CHATEN																	///< This bit enable/disable the chattering filter function.


// P1 Port Mode Select Register
#define	P1MODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).reg
#define	P1MODSEL_P10SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P11SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P12SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px2SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P13SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px3SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P14SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px4SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P15SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px5SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P16SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px6SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P1MODSEL_P17SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1C))).bit.Px7SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.

#define	P1MODSEL_P1SEL		P1MODSEL																	///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.


// P1 Port Function Select Register
#define	P1FNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).reg
#define	P1FNCSEL_P10MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P11MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P12MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px2MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P13MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px3MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P14MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px4MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P15MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px5MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P16MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px6MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P1FNCSEL_P17MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x1E))).bit.Px7MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.


// P2 Port Data Register
#define	P2DAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).reg
#define	P2DAT_P20IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px0IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P21IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px1IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P22IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px2IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P23IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px3IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P24IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px4IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P25IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px5IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P26IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px6IN			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P20OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P21OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P22OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px2OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P23OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px3OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P24OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px4OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P25OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px5OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P2DAT_P26OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).bit.Px6OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define	P2DAT_P2IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).byte_reg[0]			///< The GPIO port pin status can be read out from this bit.
#define	P2DAT_P2OUT			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x20))).byte_reg[1]			///< This bit are used to set data to be output from the GPIO port pin.


// P2 Port Enable Register
#define	P2IOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).reg
#define	P2IOEN_P20OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P21OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P22OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px2OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P23OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px3OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P24OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px4OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P25OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px5OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P26OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px6OEN			///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P20IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px0IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P21IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px1IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P22IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px2IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P23IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px3IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P24IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px4IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P25IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px5IEN			///< This bit enable/disable the GPIO port input.
#define	P2IOEN_P26IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).bit.Px6IEN			///< This bit enable/disable the GPIO port input.

#define	P2IOEN_P2OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).byte_reg[0]		///< This bit enable/disable the GPIO port output.
#define	P2IOEN_P2IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x22))).byte_reg[1]		///< This bit enable/disable the GPIO port input.


// P2 Port Pull-up/down Control Register
#define	P2RCTL				(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).reg
#define	P2RCTL_P20REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px0REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P21REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px1REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P22REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px2REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P23REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px3REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P24REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px4REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P25REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px5REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P26REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px6REN			///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P20PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px0PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P21PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px1PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P22PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px2PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P23PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px3PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P24PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px4PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P25PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px5PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P2RCTL_P26PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).bit.Px6PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.

#define	P2RCTL_P2REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).byte_reg[0]		///< This bit enable/disable the port pull-up/down control.
#define	P2RCTL_P2PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x24))).byte_reg[1]		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.


// P2 Port Interrupt Flag Register
#define	P2INTF				(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).reg
#define	P2INTF_P20IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px0IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P21IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px1IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P22IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px2IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P23IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px3IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P24IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px4IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P25IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px5IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P2INTF_P26IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x26))).bit.Px6IF			///< This bit indicate the port input interrupt cause occurrence status.

#define	P2INTF_P2IF			P2INTF																		///< This bit indicate the port input interrupt cause occurrence status.


// P2 Port Interrupt Control Register
#define	P2INTCTL			(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).reg
#define	P2INTCTL_P20IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px0IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P21IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px1IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P22IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px2IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P23IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px3IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P24IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px4IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P25IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px5IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P26IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px6IE		///< This bit enable port input interrupt.
#define	P2INTCTL_P20EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px0EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P21EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px1EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P22EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px2EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P23EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px3EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P24EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px4EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P25EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px5EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P2INTCTL_P26EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).bit.Px6EDGE		///< This bit select the input signal edge to generate a port input interrupt.

#define	P2INTCTL_P2IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).byte_reg[0]		///< This bit enable port input interrupt.
#define	P2INTCTL_P2EDGE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x28))).byte_reg[1]		///< This bit select the input signal edge to generate a port input interrupt.


// P2 Port Chattering Filter Enable Register
#define	P2CHATEN			(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).reg
#define	P2CHATEN_P20CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px0CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P21CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px1CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P22CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px2CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P23CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px3CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P24CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px4CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P25CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px5CHATEN	///< This bit enable/disable the chattering filter function.
#define	P2CHATEN_P26CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x2A))).bit.Px6CHATEN	///< This bit enable/disable the chattering filter function.

#define	P2CHATEN_P2CHATEN	P2CHATEN																	///< This bit enable/disable the chattering filter function.


// P2 Port Mode Select Register
#define	P2MODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).reg
#define	P2MODSEL_P20SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P21SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P22SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px2SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P23SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px3SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P24SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px4SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P25SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px5SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P2MODSEL_P26SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2C))).bit.Px6SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.

#define	P2MODSEL_P2SEL		P2MODSEL																	///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.


// P2 Port Function Select Register
#define	P2FNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).reg
#define	P2FNCSEL_P20MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P21MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P22MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px2MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P23MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px3MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P24MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px4MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P25MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px5MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P2FNCSEL_P26MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x2E))).bit.Px6MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.


// P3 Port Data Register
#define	P3DAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x30))).reg
#define	P3DAT_P30OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x30))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P3DAT_P31OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x30))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define	P3DAT_P3OUT			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x30))).byte_reg[1]			///< This bit are used to set data to be output from the GPIO port pin.


// P3 Port Enable Register
#define	P3IOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x32))).reg
#define	P3IOEN_P30OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x32))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	P3IOEN_P31OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x32))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.

#define	P3IOEN_P3OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x32))).byte_reg[0]		///< This bit enable/disable the GPIO port output.


// P3 Port Mode Select Register
#define	P3MODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3C))).reg
#define	P3MODSEL_P30SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3C))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P3MODSEL_P31SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3C))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.

#define	P3MODSEL_P3SEL		P3MODSEL																	///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.


// P3 Port Function Select Register
#define	P3FNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3E))).reg
#define	P3FNCSEL_P30MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3E))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P3FNCSEL_P31MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x3E))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.


// P4 Port Data Register
#define	P4DAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).reg
#define	P4DAT_P40IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px0IN			///< The GPIO port pin status can be read out from this bit.
#define	P4DAT_P41IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px1IN			///< The GPIO port pin status can be read out from this bit.
#define	P4DAT_P42IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px2IN			///< The GPIO port pin status can be read out from this bit.
#define	P4DAT_P43IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px3IN			///< The GPIO port pin status can be read out from this bit.
#define	P4DAT_P40OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P4DAT_P41OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P4DAT_P42OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px2OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	P4DAT_P43OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).bit.Px3OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define	P4DAT_P4IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).byte_reg[0]			///< The GPIO port pin status can be read out from this bit.
#define	P4DAT_P4OUT			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0x40))).byte_reg[1]			///< This bit are used to set data to be output from the GPIO port pin.


// P4 Port Enable Register
#define	P4IOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).reg
#define	P4IOEN_P40OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	P4IOEN_P41OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.
#define	P4IOEN_P42OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px2OEN			///< This bit enable/disable the GPIO port output.
#define	P4IOEN_P43OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px3OEN			///< This bit enable/disable the GPIO port output.
#define	P4IOEN_P40IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px0IEN			///< This bit enable/disable the GPIO port input.
#define	P4IOEN_P41IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px1IEN			///< This bit enable/disable the GPIO port input.
#define	P4IOEN_P42IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px2IEN			///< This bit enable/disable the GPIO port input.
#define	P4IOEN_P43IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).bit.Px3IEN			///< This bit enable/disable the GPIO port input.

#define	P4IOEN_P4OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).byte_reg[0]		///< This bit enable/disable the GPIO port output.
#define	P4IOEN_P4IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0x42))).byte_reg[1]		///< This bit enable/disable the GPIO port input.


// P4 Port Pull-up/down Control Register
#define	P4RCTL				(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).reg
#define	P4RCTL_P40REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px0REN			///< This bit enable/disable the port pull-up/down control.
#define	P4RCTL_P41REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px1REN			///< This bit enable/disable the port pull-up/down control.
#define	P4RCTL_P42REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px2REN			///< This bit enable/disable the port pull-up/down control.
#define	P4RCTL_P43REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px3REN			///< This bit enable/disable the port pull-up/down control.
#define	P4RCTL_P40PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px0PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P4RCTL_P41PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px1PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P4RCTL_P42PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px2PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	P4RCTL_P43PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).bit.Px3PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.

#define	P4RCTL_P4REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).byte_reg[0]		///< This bit enable/disable the port pull-up/down control.
#define	P4RCTL_P4PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0x44))).byte_reg[1]		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.


// P4 Port Interrupt Flag Register
#define	P4INTF				(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x46))).reg
#define	P4INTF_P40IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x46))).bit.Px0IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P4INTF_P41IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x46))).bit.Px1IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P4INTF_P42IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x46))).bit.Px2IF			///< This bit indicate the port input interrupt cause occurrence status.
#define	P4INTF_P43IF		(*((volatile PXINTF_REG *)(PPORT_REG_BASE_ADDR + 0x46))).bit.Px3IF			///< This bit indicate the port input interrupt cause occurrence status.

#define	P4INTF_P4IF			P4INTF																		///< This bit indicate the port input interrupt cause occurrence status.


// P4 Port Interrupt Control Register
#define	P4INTCTL			(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).reg
#define	P4INTCTL_P40IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px0IE		///< This bit enable port input interrupt.
#define	P4INTCTL_P41IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px1IE		///< This bit enable port input interrupt.
#define	P4INTCTL_P42IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px2IE		///< This bit enable port input interrupt.
#define	P4INTCTL_P43IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px3IE		///< This bit enable port input interrupt.
#define	P4INTCTL_P40EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px0EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P4INTCTL_P41EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px1EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P4INTCTL_P42EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px2EDGE		///< This bit select the input signal edge to generate a port input interrupt.
#define	P4INTCTL_P43EDGE	(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).bit.Px3EDGE		///< This bit select the input signal edge to generate a port input interrupt.

#define	P4INTCTL_P4IE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).byte_reg[0]		///< This bit enable port input interrupt.
#define	P4INTCTL_P4EDGE		(*((volatile PXINTCTL_REG *)(PPORT_REG_BASE_ADDR + 0x48))).byte_reg[1]		///< This bit select the input signal edge to generate a port input interrupt.


// P4 Port Chattering Filter Enable Register
#define	P4CHATEN			(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x4A))).reg
#define	P4CHATEN_P40CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x4A))).bit.Px0CHATEN	///< This bit enable/disable the chattering filter function.
#define	P4CHATEN_P41CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x4A))).bit.Px1CHATEN	///< This bit enable/disable the chattering filter function.
#define	P4CHATEN_P42CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x4A))).bit.Px2CHATEN	///< This bit enable/disable the chattering filter function.
#define	P4CHATEN_P43CHATEN	(*((volatile PXCHATEN_REG *)(PPORT_REG_BASE_ADDR + 0x4A))).bit.Px3CHATEN	///< This bit enable/disable the chattering filter function.

#define	P4CHATEN_P4CHATEN	P4CHATEN																	///< This bit enable/disable the chattering filter function.


// P4 Port Mode Select Register
#define	P4MODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4C))).reg
#define	P4MODSEL_P40SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4C))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P4MODSEL_P41SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4C))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P4MODSEL_P42SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4C))).bit.Px2SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P4MODSEL_P43SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4C))).bit.Px3SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	P4MODSEL_P4SEL		P4MODSEL

// P4 Port Function Select Register
#define	P4FNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4E))).reg
#define	P4FNCSEL_P40MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4E))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P4FNCSEL_P41MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4E))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P4FNCSEL_P42MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4E))).bit.Px2MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	P4FNCSEL_P43MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0x4E))).bit.Px3MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.


// Pd Port Data Register
#define	PDDAT				(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).reg
#define	PDDAT_PD0IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px0IN			///< The GPIO port pin status can be read out from this bit.
#define	PDDAT_PD1IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px1IN			///< The GPIO port pin status can be read out from this bit.
#define	PDDAT_PD3IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px3IN			///< The GPIO port pin status can be read out from this bit.
#define	PDDAT_PD4IN			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px4IN			///< The GPIO port pin status can be read out from this bit.
#define	PDDAT_PD0OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px0OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	PDDAT_PD1OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px1OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	PDDAT_PD2OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px2OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	PDDAT_PD3OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px3OUT			///< This bit are used to set data to be output from the GPIO port pin.
#define	PDDAT_PD4OUT		(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).bit.Px4OUT			///< This bit are used to set data to be output from the GPIO port pin.

#define	PDDAT_PDOUT			(*((volatile PXDAT_REG *)(PPORT_REG_BASE_ADDR + 0xD0))).byte_reg[1]			///< This bit are used to set data to be output from the GPIO port pin.


// Pd Port Enable Register
#define	PDIOEN				(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).reg
#define	PDIOEN_PD0OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px0OEN			///< This bit enable/disable the GPIO port output.
#define	PDIOEN_PD1OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px1OEN			///< This bit enable/disable the GPIO port output.
#define	PDIOEN_PD3OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px3OEN			///< This bit enable/disable the GPIO port output.
#define	PDIOEN_PD4OEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px4OEN			///< This bit enable/disable the GPIO port output.
#define	PDIOEN_PD0IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px0IEN			///< This bit enable/disable the GPIO port input.
#define	PDIOEN_PD1IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px1IEN			///< This bit enable/disable the GPIO port input.
#define	PDIOEN_PD3IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px3IEN			///< This bit enable/disable the GPIO port input.
#define	PDIOEN_PD4IEN		(*((volatile PXIOEN_REG *)(PPORT_REG_BASE_ADDR + 0xD2))).bit.Px4IEN			///< This bit enable/disable the GPIO port input.


// Pd Port Pull-up/down Control Register
#define	PDRCTL				(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).reg
#define	PDRCTL_PD0REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px0REN			///< This bit enable/disable the port pull-up/down control.
#define	PDRCTL_PD1REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px1REN			///< This bit enable/disable the port pull-up/down control.
#define	PDRCTL_PD3REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px3REN			///< This bit enable/disable the port pull-up/down control.
#define	PDRCTL_PD4REN		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px4REN			///< This bit enable/disable the port pull-up/down control.
#define	PDRCTL_PD0PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px0PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	PDRCTL_PD1PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px1PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	PDRCTL_PD3PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px3PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.
#define	PDRCTL_PD4PDPU		(*((volatile PXRCTL_REG *)(PPORT_REG_BASE_ADDR + 0xD4))).bit.Px4PDPU		///< This bit select either the pull-up resistor or the pull-down resistor when using a resistor built into the port.


// Pd Port Mode Select Register
#define	PDMODSEL			(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).reg
#define	PDMODSEL_PD0SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).bit.Px0SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	PDMODSEL_PD1SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).bit.Px1SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	PDMODSEL_PD2SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).bit.Px2SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	PDMODSEL_PD3SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).bit.Px3SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.
#define	PDMODSEL_PD4SEL		(*((volatile PXMODSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDC))).bit.Px4SEL		///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.

#define	PDMODSEL_PDSEL		PDMODSEL																	///< This bit select whether each port is used for the GPIO function or a peripheral I/O function.


// Pd Port Function Select Register
#define	PDFNCSEL			(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).reg
#define	PDFNCSEL_PD0MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).bit.Px0MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	PDFNCSEL_PD1MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).bit.Px1MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	PDFNCSEL_PD2MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).bit.Px2MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	PDFNCSEL_PD3MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).bit.Px3MUX		///< This bit select the peripheral I/O function to be assigned to each port pin.
#define	PDFNCSEL_PD4MUX		(*((volatile PXFNCSEL_REG *)(PPORT_REG_BASE_ADDR + 0xDE))).byte_reg[1]		///< This bit select the peripheral I/O function to be assigned to each port pin.


// P Port Clock Control Register
#define	PCLK				(*((volatile PCLK_REG *)(PPORT_REG_BASE_ADDR + 0xE0))).reg
#define	PCLK_CLKSRC			(*((volatile PCLK_REG *)(PPORT_REG_BASE_ADDR + 0xE0))).bit.CLKSRC			///< These bits select the clock source of PPORT (chattering filter).
#define	PCLK_KRSTCFG		(*((volatile PCLK_REG *)(PPORT_REG_BASE_ADDR + 0xE0))).bit.KRSTCFG			///< These bits configure the key-entry reset function.
#define	PCLK_CLKDIV			(*((volatile PCLK_REG *)(PPORT_REG_BASE_ADDR + 0xE0))).bit.CLKDIV			///< These bits select the division ratio of the PPORT operating clock (chattering filter clock).
#define	PCLK_DBRUN			(*((volatile PCLK_REG *)(PPORT_REG_BASE_ADDR + 0xE0))).byte_reg[1]			///< This bit sets whether the PPORT operating clock is supplied in DEBUG mode or not.


// P Port Interrupt Flag Group Register
#define	PINTFGRP			(*((volatile PINTFGRP_REG *)(PPORT_REG_BASE_ADDR + 0xE2))).reg
#define	PINTFGRP_P0INT		(*((volatile PINTFGRP_REG *)(PPORT_REG_BASE_ADDR + 0xE2))).bit.P0INT		///< This bit indicate that P0 port group includes a port that has generated an interrupt.
#define	PINTFGRP_P1INT		(*((volatile PINTFGRP_REG *)(PPORT_REG_BASE_ADDR + 0xE2))).bit.P1INT		///< This bit indicate that P1 port group includes a port that has generated an interrupt.
#define	PINTFGRP_P2INT		(*((volatile PINTFGRP_REG *)(PPORT_REG_BASE_ADDR + 0xE2))).bit.P2INT		///< This bit indicate that P2 port group includes a port that has generated an interrupt.
#define	PINTFGRP_P4INT		(*((volatile PINTFGRP_REG *)(PPORT_REG_BASE_ADDR + 0xE2))).bit.P4INT		///< This bit indicate that P4 port group includes a port that has generated an interrupt.



/********************/
/* ----- UPMUX ---- */
/********************/
// P00-01 Universal Port Multiplexer Setting Register
#define	P0UPMUX0			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).reg
#define	P0UPMUX0_P00PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX0_P00PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX0_P00PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P0UPMUX0_P01PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX0_P01PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX0_P01PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x00))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P02-03 Universal Port Multiplexer Setting Register
#define	P0UPMUX1			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).reg
#define	P0UPMUX1_P02PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX1_P02PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX1_P02PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P0UPMUX1_P03PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX1_P03PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX1_P03PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x02))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P04-05 Universal Port Multiplexer Setting Register
#define	P0UPMUX2			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).reg
#define	P0UPMUX2_P04PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX2_P04PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX2_P04PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P0UPMUX2_P05PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX2_P05PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX2_P05PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x04))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P06-07 Universal Port Multiplexer Setting Register
#define	P0UPMUX3			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).reg
#define	P0UPMUX3_P06PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX3_P06PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX3_P06PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P0UPMUX3_P07PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P0UPMUX3_P07PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P0UPMUX3_P07PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x06))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P10-11 Universal Port Multiplexer Setting Register
#define	P1UPMUX0			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).reg
#define	P1UPMUX0_P10PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX0_P10PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX0_P10PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P1UPMUX0_P11PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX0_P11PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX0_P11PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x08))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P12-13 Universal Port Multiplexer Setting Register
#define	P1UPMUX1			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).reg
#define	P1UPMUX1_P12PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX1_P12PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX1_P12PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P1UPMUX1_P13PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX1_P13PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX1_P13PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0A))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P14-15 Universal Port Multiplexer Setting Register
#define	P1UPMUX2			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).reg
#define	P1UPMUX2_P14PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX2_P14PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX2_P14PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P1UPMUX2_P15PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX2_P15PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX2_P15PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0C))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P16-17 Universal Port Multiplexer Setting Register
#define	P1UPMUX3			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).reg
#define	P1UPMUX3_P16PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX3_P16PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX3_P16PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P1UPMUX3_P17PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P1UPMUX3_P17PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P1UPMUX3_P17PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x0E))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P20-21 Universal Port Multiplexer Setting Register
#define	P2UPMUX0			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).reg
#define	P2UPMUX0_P20PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX0_P20PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX0_P20PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P2UPMUX0_P21PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX0_P21PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX0_P21PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x10))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P22-23 Universal Port Multiplexer Setting Register
#define	P2UPMUX1			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).reg
#define	P2UPMUX1_P22PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX1_P22PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX1_P22PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P2UPMUX1_P23PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX1_P23PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX1_P23PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x12))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P24-25 Universal Port Multiplexer Setting Register
#define	P2UPMUX2			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).reg
#define	P2UPMUX2_P24PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX2_P24PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX2_P24PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.
#define	P2UPMUX2_P25PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxzPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX2_P25PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxzPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX2_P25PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x14))).bit.PxzPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.

// P26 Universal Port Multiplexer Setting Register
#define	P2UPMUX3			(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x16))).reg
#define	P2UPMUX3_P26PERISEL	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x16))).bit.PxyPERISEL	///< These bits specify a peripheral circuit.
#define	P2UPMUX3_P26PERICH	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x16))).bit.PxyPERICH	///< These bits specify a peripheral circuit channel number.
#define	P2UPMUX3_P26PPFNC	(*((volatile PXUPMUXN_REG *)(UPMUX_REG_BASE_ADDR + 0x16))).bit.PxyPPFNC		///< These bits specify the peripheral I/O function to be assigned to the port.



/********************/
/* ---- UART2 ----- */
/********************/

// UART2 Ch.0 Clock Control Register
#define UA0CLK					(*((volatile UANCLK_REG *)(UART2_0_REG_BASE_ADDR + 0x00))).reg
#define UA0CLK_CLKSRC			(*((volatile UANCLK_REG *)(UART2_0_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of the UART2.
#define UA0CLK_CLKDIV			(*((volatile UANCLK_REG *)(UART2_0_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the UART2 operating clock.
#define UA0CLK_DBRUN			(*((volatile UANCLK_REG *)(UART2_0_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< This bit sets whether the UART2 operating clock is supplied in DEBUG mode or not.

// UART2 Ch.0 Mode Register
#define UA0MOD					(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).reg
#define UA0MOD_STPB 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.STPB				///< This bit sets the stop bit length.
#define UA0MOD_PRMD 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.PRMD				///< This bit selects either odd parity or even parity when using the parity function.
#define UA0MOD_PREN 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.PREN				///< This bit sets the data length.
#define UA0MOD_CHLN 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.CHLN				///< This bit sets the data length.
#define UA0MOD_IRMD 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.IRMD				///< This bit enables the IrDA interface function.
#define UA0MOD_OUTMD			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.OUTMD 			///< This bit sets the USOUT0 pin output mode.
#define UA0MOD_PUEN 			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.PUEN				///< This bit enables pull-up of the USIN0 pin.
#define UA0MOD_INVTX			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.INVTX			///< This bit enables the USOUTn output inverting function.
#define UA0MOD_INVRX			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.INVRX			///< This bit enables the USINn input inverting function.
#define UA0MOD_BRDIV			(*((volatile UANMOD_REG *)(UART2_0_REG_BASE_ADDR + 0x02))).bit.BRDIV			///< This bit sets the UART2 operating clock division ratio for generating the transfer (sampling) clock using the baud rate generator.

// UART2 Ch.0 Baud-Rate Register
#define UA0BR					(*((volatile UANBR_REG *)(UART2_0_REG_BASE_ADDR + 0x04))).reg
#define UA0BR_BRT				(*((volatile UANBR_REG *)(UART2_0_REG_BASE_ADDR + 0x04))).byte_reg[0]			///< These bits set the UART2 transfer rate.
#define UA0BR_FMD				(*((volatile UANBR_REG *)(UART2_0_REG_BASE_ADDR + 0x04))).byte_reg[1]			///< These bits set the UART2 transfer rate.

// UART2 Ch.0 Control Register
#define UA0CTL					(*((volatile UANCTL_REG *)(UART2_0_REG_BASE_ADDR + 0x06))).reg
#define UA0CTL_MODEN			(*((volatile UANCTL_REG *)(UART2_0_REG_BASE_ADDR + 0x06))).bit.MODEN 			///< This bit enables the UART2 operations.
#define UA0CTL_SFTRST			(*((volatile UANCTL_REG *)(UART2_0_REG_BASE_ADDR + 0x06))).bit.SFTRST			///< This bit issues software reset to the UART2.

// UART2 Ch.0 Transmit Data Register
#define UA0TXD					(*((volatile UANTXD_REG *)(UART2_0_REG_BASE_ADDR + 0x08))).reg
#define UA0TXD_TXD				UA0TXD																			///< Data can be written to the transmit data buffer through these bits.

// UART2 Ch.0 Receive Data Register
#define UA0RXD					(*((volatile UANRXD_REG *)(UART2_0_REG_BASE_ADDR + 0x0A))).reg
#define UA0RXD_RXD				UA0RXD																			///< The receive data buffer can be read through these bits.

// UART2 Ch.0 Status and Interrupt Flag Register
#define UA0INTF 				(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).reg
#define UA0INTF_TBEIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.TBEIF			///< These bits indicate Transmit buffer empty interrupt cause occurrence status.
#define UA0INTF_RB1FIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.RB1FIF			///< These bits indicate Receive buffer one byte full interrupt cause occurrence status.
#define UA0INTF_RB2FIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.RB2FIF			///< These bits indicate Receive buffer two bytes full interrupt cause occurrence status.
#define UA0INTF_OEIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.OEIF 			///< These bits indicate Overrun error interrupt cause occurrence status.
#define UA0INTF_PEIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.PEIF 			///< These bits indicate Parity error interrupt cause occurrence status.
#define UA0INTF_FEIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.FEIF 			///< These bits indicate Framing error interrupt cause occurrence status.
#define UA0INTF_TENDIF			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.TENDIF			///< These bits indicate End-of-transmission interrupt cause occurrence status.
#define UA0INTF_TBSY			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.TBSY 			///< This bit indicates the sending status.
#define UA0INTF_RBSY			(*((volatile UANINTF_REG *)(UART2_0_REG_BASE_ADDR + 0x0C))).bit.RBSY 			///< This bit indicates the receiving status.

// UART2 Ch.0 Interrupt Enable Register
#define UA0INTE 				(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).reg
#define UA0INTE_TBEIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.TBEIE			///< These bits enable Transmit buffer empty interrupt.
#define UA0INTE_RB1FIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.RB1FIE			///< These bits enable Receive buffer one byte full interrupt.
#define UA0INTE_RB2FIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.RB2FIE			///< These bits enable Receive buffer two bytes full interrupt.
#define UA0INTE_OEIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.OEIE 			///< These bits enable Overrun error interrupt.
#define UA0INTE_PEIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.PEIE 			///< These bits enable Parity error interrupt.
#define UA0INTE_FEIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.FEIE 			///< These bits enable Framing error interrupt.
#define UA0INTE_TENDIE			(*((volatile UANINTE_REG *)(UART2_0_REG_BASE_ADDR + 0x0E))).bit.TENDIE			///< These bits enable End-of-transmission interrupt.


// UART2 Ch.1 Clock Control Register
#define UA1CLK					(*((volatile UANCLK_REG *)(UART2_1_REG_BASE_ADDR + 0x00))).reg
#define UA1CLK_CLKSRC			(*((volatile UANCLK_REG *)(UART2_1_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of the UART2.
#define UA1CLK_CLKDIV			(*((volatile UANCLK_REG *)(UART2_1_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the UART2 operating clock.
#define UA1CLK_DBRUN			(*((volatile UANCLK_REG *)(UART2_1_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< This bit sets whether the UART2 operating clock is supplied in DEBUG mode or not.

// UART2 Ch.1 Mode Register
#define UA1MOD					(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).reg
#define UA1MOD_STPB 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.STPB				///< This bit sets the stop bit length.
#define UA1MOD_PRMD 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.PRMD				///< This bit selects either odd parity or even parity when using the parity function.
#define UA1MOD_PREN 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.PREN				///< This bit sets the data length.
#define UA1MOD_CHLN 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.CHLN				///< This bit sets the data length.
#define UA1MOD_IRMD 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.IRMD				///< This bit enables the IrDA interface function.
#define UA1MOD_OUTMD			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.OUTMD 			///< This bit sets the USOUT0 pin output mode.
#define UA1MOD_PUEN 			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.PUEN				///< This bit enables pull-up of the USIN0 pin.
#define UA1MOD_INVTX			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.INVTX			///< This bit enables the USOUTn output inverting function.
#define UA1MOD_INVRX			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.INVRX			///< This bit enables the USINn input inverting function.
#define UA1MOD_BRDIV			(*((volatile UANMOD_REG *)(UART2_1_REG_BASE_ADDR + 0x02))).bit.BRDIV			///< This bit sets the UART2 operating clock division ratio for generating the transfer (sampling) clock using the baud rate generator.

// UART2 Ch.1 Baud-Rate Register
#define UA1BR					(*((volatile UANBR_REG *)(UART2_1_REG_BASE_ADDR + 0x04))).reg
#define UA1BR_BRT				(*((volatile UANBR_REG *)(UART2_1_REG_BASE_ADDR + 0x04))).byte_reg[0]			///< These bits set the UART2 transfer rate.
#define UA1BR_FMD				(*((volatile UANBR_REG *)(UART2_1_REG_BASE_ADDR + 0x04))).byte_reg[1]			///< These bits set the UART2 transfer rate.

// UART2 Ch.1 Control Register
#define UA1CTL					(*((volatile UANCTL_REG *)(UART2_1_REG_BASE_ADDR + 0x06))).reg
#define UA1CTL_MODEN			(*((volatile UANCTL_REG *)(UART2_1_REG_BASE_ADDR + 0x06))).bit.MODEN 			///< This bit enables the UART2 operations.
#define UA1CTL_SFTRST			(*((volatile UANCTL_REG *)(UART2_1_REG_BASE_ADDR + 0x06))).bit.SFTRST			///< This bit issues software reset to the UART2.

// UART2 Ch.1 Transmit Data Register
#define UA1TXD					(*((volatile UANTXD_REG *)(UART2_1_REG_BASE_ADDR + 0x08))).reg
#define UA1TXD_TXD				UA1TXD																			///< Data can be written to the transmit data buffer through these bits.

// UART2 Ch.1 Receive Data Register
#define UA1RXD					(*((volatile UANRXD_REG *)(UART2_1_REG_BASE_ADDR + 0x0A))).reg
#define UA1RXD_RXD				UA1RXD																			///< The receive data buffer can be read through these bits.

// UART2 Ch.1 Status and Interrupt Flag Register
#define UA1INTF 				(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).reg
#define UA1INTF_TBEIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.TBEIF			///< These bits indicate Transmit buffer empty interrupt cause occurrence status.
#define UA1INTF_RB1FIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.RB1FIF			///< These bits indicate Receive buffer one byte full interrupt cause occurrence status.
#define UA1INTF_RB2FIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.RB2FIF			///< These bits indicate Receive buffer two bytes full interrupt cause occurrence status.
#define UA1INTF_OEIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.OEIF 			///< These bits indicate Overrun error interrupt cause occurrence status.
#define UA1INTF_PEIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.PEIF 			///< These bits indicate Parity error interrupt cause occurrence status.
#define UA1INTF_FEIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.FEIF 			///< These bits indicate Framing error interrupt cause occurrence status.
#define UA1INTF_TENDIF			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.TENDIF			///< These bits indicate End-of-transmission interrupt cause occurrence status.
#define UA1INTF_TBSY			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.TBSY 			///< This bit indicates the sending status.
#define UA1INTF_RBSY			(*((volatile UANINTF_REG *)(UART2_1_REG_BASE_ADDR + 0x0C))).bit.RBSY 			///< This bit indicates the receiving status.

// UART2 Ch.1 Interrupt Enable Register
#define UA1INTE 				(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).reg
#define UA1INTE_TBEIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.TBEIE			///< These bits enable Transmit buffer empty interrupt.
#define UA1INTE_RB1FIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.RB1FIE			///< These bits enable Receive buffer one byte full interrupt.
#define UA1INTE_RB2FIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.RB2FIE			///< These bits enable Receive buffer two bytes full interrupt.
#define UA1INTE_OEIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.OEIE 			///< These bits enable Overrun error interrupt.
#define UA1INTE_PEIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.PEIE 			///< These bits enable Parity error interrupt.
#define UA1INTE_FEIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.FEIE 			///< These bits enable Framing error interrupt.
#define UA1INTE_TENDIE			(*((volatile UANINTE_REG *)(UART2_1_REG_BASE_ADDR + 0x0E))).bit.TENDIE			///< These bits enable End-of-transmission interrupt.


/*******************/
/* ----- SPIA ---- */
/*******************/

// SPIA Ch.0 Mode Register
#define	SPI0MOD				(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).reg
#define	SPI0MOD_MST			(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.MST			///< This bit sets the SPIA operating mode (master mode or slave mode).
#define	SPI0MOD_CPOL		(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.CPOL			///< This bit set the SPI clock phase and polarity.
#define	SPI0MOD_CPHA		(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.CPHA			///< This bit set the SPI clock phase and polarity.
#define	SPI0MOD_LSBFST		(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.LSBFST		///< This bit configures the data format (input/output permutation).
#define	SPI0MOD_NOCLKDIV	(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.NOCLKDIV		///< This bit selects SPICLKn in master mode. This setting is ineffective in slave mode.
#define	SPI0MOD_PUEN		(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).bit.PUEN			///< This bit enables pull-up/down of the input pins.
#define	SPI0MOD_CHLN		(*((volatile SPINMOD_REG *)(SPIA_0_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< These bits set the bit length of transfer data.

// SPIA Ch.0 Control Register
#define	SPI0CTL				(*((volatile SPINCTL_REG *)(SPIA_0_REG_BASE_ADDR + 0x02))).reg
#define	SPI0CTL_MODEN		(*((volatile SPINCTL_REG *)(SPIA_0_REG_BASE_ADDR + 0x02))).bit.MODEN		///< This bit enables the SPIA operations.
#define	SPI0CTL_SFTRST		(*((volatile SPINCTL_REG *)(SPIA_0_REG_BASE_ADDR + 0x02))).bit.SFTRST		///< This bit issues software reset to SPIA.

// SPIA Ch.0 Transmit Data Register
#define	SPI0TXD				(*((volatile SPINTXD_REG *)(SPIA_0_REG_BASE_ADDR + 0x04))).reg
#define	SPI0TXD_TXD			SPI0TXD																		///< Data can be written to the transmit data buffer through these bits.

// SPIA Ch.0 Receive Data Register
#define	SPI0RXD				(*((volatile SPINRXD_REG *)(SPIA_0_REG_BASE_ADDR + 0x06))).reg
#define	SPI0RXD_RXD			SPI0RXD																		///< The receive data buffer can be read through these bits.

// SPIA Ch.0 Interrupt Flag Register
#define	SPI0INTF			(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).reg
#define	SPI0INTF_TBEIF		(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).bit.TBEIF		///< This bit indicate Transmit buffer empty interrupt cause occurrence status.
#define	SPI0INTF_RBFIF		(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).bit.RBFIF		///< This bit indicate Receive buffer full interrupt cause occurrence status.
#define	SPI0INTF_TENDIF		(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).bit.TENDIF		///< This bit indicate End-of-transmission interrupt cause occurrence status.
#define	SPI0INTF_OEIF		(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).bit.OEIF		///< This bit indicate Overrun error interrupt cause occurrence status.
#define	SPI0INTF_BSY		(*((volatile SPININTF_REG *)(SPIA_0_REG_BASE_ADDR + 0x08))).bit.BSY			///< This bit indicates the SPIA operating status.

// SPIA Ch.0 Interrupt Enable Register
#define	SPI0INTE			(*((volatile SPININTE_REG *)(SPIA_0_REG_BASE_ADDR + 0x0A))).reg
#define	SPI0INTE_TBEIE		(*((volatile SPININTE_REG *)(SPIA_0_REG_BASE_ADDR + 0x0A))).bit.TBEIE		///< This bit enable Transmit buffer empty interrupt.
#define	SPI0INTE_RBFIE		(*((volatile SPININTE_REG *)(SPIA_0_REG_BASE_ADDR + 0x0A))).bit.RBFIE		///< This bit enable Receive buffer full interrupt.
#define	SPI0INTE_TENDIE		(*((volatile SPININTE_REG *)(SPIA_0_REG_BASE_ADDR + 0x0A))).bit.TENDIE		///< This bit enable End-of-transmission interrupt.
#define	SPI0INTE_OEIE		(*((volatile SPININTE_REG *)(SPIA_0_REG_BASE_ADDR + 0x0A))).bit.OEIE		///< This bit enable Overrun error interrupt.




/*******************/
/* ----- I2C ----- */
/*******************/

// I2C Ch.0 Clock Control Register
#define	I2C0CLK				(*((volatile I2CNCLK_REG *)(I2C_0_REG_BASE_ADDR + 0x00))).reg
#define	I2C0CLK_CLKSRC		(*((volatile I2CNCLK_REG *)(I2C_0_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of the I2C.
#define	I2C0CLK_CLKDIV		(*((volatile I2CNCLK_REG *)(I2C_0_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the I2C operating clock.
#define	I2C0CLK_DBRUN		(*((volatile I2CNCLK_REG *)(I2C_0_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the I2C operating clock is supplied in DEBUG mode or not.

// I2C Ch.0 Mode Register
#define	I2C0MOD				(*((volatile I2CNMOD_REG *)(I2C_0_REG_BASE_ADDR + 0x02))).reg
#define	I2C0MOD_GCEN		(*((volatile I2CNMOD_REG *)(I2C_0_REG_BASE_ADDR + 0x02))).bit.GCEN			///< This bit sets whether to respond to master general calls in slave mode or not.
#define	I2C0MOD_OADR10		(*((volatile I2CNMOD_REG *)(I2C_0_REG_BASE_ADDR + 0x02))).bit.OADR10		///< This bit sets the number of own address bits for slave mode.

// I2C Ch.0 Baud-Rate Register
#define	I2C0BR				(*((volatile I2CNBR_REG *)(I2C_0_REG_BASE_ADDR + 0x04))).reg
#define	I2C0BR_BRT			I2C0BR																		///< These bits set the I2C Ch.n transfer rate for master mode.

// I2C Ch.0 Own Address Register
#define	I2C0OADR			(*((volatile I2CNOADR_REG *)(I2C_0_REG_BASE_ADDR + 0x08))).reg
#define	I2C0OADR_OADR		I2C0OADR																	///< These bits set the own address for slave mode.

// I2C Ch.0 Control Register
#define	I2C0CTL				(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).reg
#define	I2C0CTL_MODEN		(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.MODEN			///< This bit enables the I2C operations.
#define	I2C0CTL_SFTRST		(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.SFTRST		///< This bit issues software reset to the I2C.
#define	I2C0CTL_TXSTART		(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.TXSTART		///< This bit issues a START condition in master mode.
#define	I2C0CTL_TXSTOP		(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.TXSTOP		///< This bit issues a STOP condition in master mode.
#define	I2C0CTL_TXNACK		(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.TXNACK		///< This bit issues a request for sending a NACK at the next responding.
#define	I2C0CTL_MST			(*((volatile I2CNCTL_REG *)(I2C_0_REG_BASE_ADDR + 0x0A))).bit.MST			///< This bit selects the I2C Ch.n operating mode.

// I2C Ch.0 Transmit Data Register
#define	I2C0TXD				(*((volatile I2CNTXD_REG *)(I2C_0_REG_BASE_ADDR + 0x0C))).reg
#define	I2C0TXD_TXD			I2C0TXD																		///< Data can be written to the transmit data buffer through these bits.

// I2C Ch.0 Receive Data Register
#define	I2C0RXD				(*((volatile I2CNRXD_REG *)(I2C_0_REG_BASE_ADDR + 0x0E))).reg
#define	I2C0RXD_RXD			I2C0RXD																		///< The receive data buffer can be read through these bits.

// I2C Ch.0 Status and Interrupt Flag Register
#define	I2C0INTF			(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).reg
#define	I2C0INTF_TBEIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.TBEIF		///< This bit indicate Transmit buffer empty interrupt cause occurrence status.
#define	I2C0INTF_RBFIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.RBFIF		///< This bit indicate Receive buffer full interrupt cause occurrence status.
#define	I2C0INTF_ERRIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.ERRIF		///< This bit indicate Error detection interrupt cause occurrence status.
#define	I2C0INTF_STARTIF	(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.STARTIF		///< This bit indicate START condition interrupt cause occurrence status.
#define	I2C0INTF_STOPIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.STOPIF		///< This bit indicate STOP condition interrupt cause occurrence status.
#define	I2C0INTF_NACKIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.NACKIF		///< This bit indicate NACK reception interrupt cause occurrence status.
#define	I2C0INTF_GCIF		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.GCIF			///< This bit indicate General call address reception interrupt cause occurrence status.
#define	I2C0INTF_BYTEENDIF	(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.BYTEENDIF	///< This bit indicate End of transfer interrupt cause occurrence status.
#define	I2C0INTF_TR			(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.TR			///< This bit indicates whether the I2C is set in transmission mode or not.
#define	I2C0INTF_BSY		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.BSY			///< This bit indicates that the I2C bus is placed into busy status.
#define	I2C0INTF_SCLLOW		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.SCLLOW		///< This bit indicates that SCL is set to low level.
#define	I2C0INTF_SDALOW		(*((volatile I2CNINTF_REG *)(I2C_0_REG_BASE_ADDR + 0x10))).bit.SDALOW		///< This bit indicates that SDA is set to low level.

// I2C Ch.0 Interrupt Enable Register
#define	I2C0INTE			(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).reg
#define	I2C0INTE_TBEIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.TBEIE		///< This bit enable Transmit buffer empty interrupt.
#define	I2C0INTE_RBFIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.RBFIE		///< This bit enable Receive buffer full interrupt.
#define	I2C0INTE_ERRIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.ERRIE		///< This bit enable Error detection interrupt.
#define	I2C0INTE_STARTIE	(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.STARTIE		///< This bit enable START condition interrupt.
#define	I2C0INTE_STOPIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.STOPIE		///< This bit enable STOP condition interrupt.
#define	I2C0INTE_NACKIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.NACKIE		///< This bit enable NACK reception interrupt.
#define	I2C0INTE_GCIE		(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.GCIE			///< This bit enable General call address reception interrupt.
#define	I2C0INTE_BYTEENDIE	(*((volatile I2CNINTE_REG *)(I2C_0_REG_BASE_ADDR + 0x12))).bit.BYTEENDIE	///< This bit enable End of transfer interrupt.



/*********************/
/* ----- T16B ------ */
/*********************/

// T16B Ch.0 Clock Control Register
#define	T16B0CLK			(*((volatile T16BNCLK_REG *)(T16B_0_REG_BASE_ADDR + 0x00))).reg
#define	T16B0CLK_CLKSRC		(*((volatile T16BNCLK_REG *)(T16B_0_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of T16B Ch.0.
#define	T16B0CLK_CLKDIV		(*((volatile T16BNCLK_REG *)(T16B_0_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the T16B Ch.0 operating clock (counter clock).
#define	T16B0CLK_DBRUN		(*((volatile T16BNCLK_REG *)(T16B_0_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the T16B Ch.0 operating clock is supplied in DEBUG mode or not.

// T16B Ch.0 Counter Control Register.
#define	T16B0CTL			(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).reg
#define	T16B0CTL_MODEN		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).bit.MODEN		///< This bit enables the T16B Ch.0 operations.
#define	T16B0CTL_PRESET		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).bit.PRESET		///< This bit resets the counter.
#define	T16B0CTL_RUN		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).bit.RUN			///< This bit starts/stops counting.
#define	T16B0CTL_ONEST		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).bit.ONEST		///< This bit selects the counter repeat/one-shot mode.
#define	T16B0CTL_CNTMD		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).bit.CNTMD		///< These bits select the counter up/down mode.
#define	T16B0CTL_MAXBSY		(*((volatile T16BNCTL_REG *)(T16B_0_REG_BASE_ADDR + 0x02))).byte_reg[1]		///< This bit indicates whether data can be written to the T16BnMC register or not.

// T16B Ch.0 Max Counter Data Register
#define	T16B0MC				(*((volatile T16BNMC_REG *)(T16B_0_REG_BASE_ADDR + 0x04))).reg

// T16B Ch.0 Timer Counter Data Register.
#define	T16B0TC				(*((volatile T16BNTC_REG *)(T16B_0_REG_BASE_ADDR + 0x06))).reg

// T16B Ch.0 Counter Status Register
#define	T16B0CS				(*((volatile T16BNCS_REG *)(T16B_0_REG_BASE_ADDR + 0x08))).reg
#define	T16B0CS_BSY			(*((volatile T16BNCS_REG *)(T16B_0_REG_BASE_ADDR + 0x08))).bit.BSY			///< This bit indicates the counter operating status.
#define	T16B0CS_UP_DOWN		(*((volatile T16BNCS_REG *)(T16B_0_REG_BASE_ADDR + 0x08))).bit.UP_DOWN		///< This bit indicates the currently set count direction.
#define	T16B0CS_CAPI0		(*((volatile T16BNCS_REG *)(T16B_0_REG_BASE_ADDR + 0x08))).bit.CAPI0		///< These bits indicate the signal level currently input to the CAPx0 pin.
#define	T16B0CS_CAPI1		(*((volatile T16BNCS_REG *)(T16B_0_REG_BASE_ADDR + 0x08))).bit.CAPI1		///< These bits indicate the signal level currently input to the CAPx1 pin.

// T16B Ch.0 Interrupt Flag Register.
#define	T16B0INTF			(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).reg
#define	T16B0INTF_CNTZEROIF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CNTZEROIF	///< Counter zero interrupt
#define	T16B0INTF_CNTMAXIF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CNTMAXIF	///< Counter MAX interrupt
#define	T16B0INTF_CMPCAP0IF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CMPCAP0IF	///< Compare/capture 0 interrupt
#define	T16B0INTF_CAPOW0IF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CAPOW0IF	///< Capture 0 overwrite interrupt
#define	T16B0INTF_CMPCAP1IF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CMPCAP1IF	///< Compare/capture 1 interrupt
#define	T16B0INTF_CAPOW1IF	(*((volatile T16BNINTF_REG *)(T16B_0_REG_BASE_ADDR + 0x0A))).bit.CAPOW1IF	///< Capture 1 overwrite interrupt

// T16B Ch.0 Interrupt Enable Register.
#define	T16B0INTE			(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).reg
#define	T16B0INTE_CNTZEROIE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CNTZEROIE	///< Counter zero interrupt
#define	T16B0INTE_CNTMAXIE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CNTMAXIE	///< Counter MAX interrupt
#define	T16B0INTE_CMPCAP0IE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CMPCAP0IE	///< Compare/capture 0 interrupt
#define	T16B0INTE_CAPOW0IE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CAPOW0IE	///< Capture 0 overwrite interrupt
#define	T16B0INTE_CMPCAP1IE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CMPCAP1IE	///< Compare/capture 1 interrupt
#define	T16B0INTE_CAPOW1IE	(*((volatile T16BNINTE_REG *)(T16B_0_REG_BASE_ADDR + 0x0C))).bit.CAPOW1IE	///< Capture 1 overwrite interrupt

// T16B Ch.0 Comparator/Capture 0 Control Register.
#define	T16B0CCCTL0			(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).reg
#define	T16B0CCCTL0_CCMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.CCMD		///< This bit selects the operating mode of the comparator/capture circuit m.
#define	T16B0CCCTL0_TOUTINV	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.TOUTINV	///< This bit selects the TOUT00 signal polarity.
#define	T16B0CCCTL0_TOUTMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.TOUTMD	///< These bits configure how the TOUT00 signal waveform is changed.
#define	T16B0CCCTL0_TOUTO	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.TOUTO	///< This bit sets the TOUT00 signal output level
#define	T16B0CCCTL0_TOUTMT	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.TOUTMT	///< This bit selects whether the comparator equal signal.
#define	T16B0CCCTL0_CAPTRG	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.CAPTRG	///< These bits select the trigger edge(s) of the trigger signal.
#define	T16B0CCCTL0_CAPIS	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.CAPIS	///< These bits select the trigger signal for capturing.
#define	T16B0CCCTL0_CBUFMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.CBUFMD	///< These bits select the timing to load the comparison value written.
#define	T16B0CCCTL0_SCS		(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x10))).bit.SCS		///< This bit selects either synchronous capture mode or asynchronous capture mode.

// T16B Ch.0 Compare/Capture 0 Data Register.
#define	T16B0CCR0			(*((volatile T16BNCCRM_REG *)(T16B_0_REG_BASE_ADDR + 0x12))).reg

// T16B Ch.0 Comparator/Capture 1 Control Register.
#define	T16B0CCCTL1			(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).reg
#define	T16B0CCCTL1_CCMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.CCMD		///< This bit selects the operating mode of the comparator/capture circuit m.
#define	T16B0CCCTL1_TOUTINV	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.TOUTINV	///< This bit selects the TOUT01 signal polarity.
#define	T16B0CCCTL1_TOUTMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.TOUTMD	///< These bits configure how the TOUT01 signal waveform is changed.
#define	T16B0CCCTL1_TOUTO	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.TOUTO	///< This bit sets the TOUT01 signal output level
#define	T16B0CCCTL1_TOUTMT	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.TOUTMT	///< This bit selects whether the comparator equal signal.
#define	T16B0CCCTL1_CAPTRG	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.CAPTRG	///< These bits select the trigger edge(s) of the trigger signal.
#define	T16B0CCCTL1_CAPIS	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.CAPIS	///< These bits select the trigger signal for capturing.
#define	T16B0CCCTL1_CBUFMD	(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.CBUFMD	///< These bits select the timing to load the comparison value written.
#define	T16B0CCCTL1_SCS		(*((volatile T16BNCCCTLM_REG *)(T16B_0_REG_BASE_ADDR + 0x18))).bit.SCS		///< This bit selects either synchronous capture mode or asynchronous capture mode.

// T16B Ch.0 Compare/Capture 1 Data Register.
#define	T16B0CCR1			(*((volatile T16BNCCRM_REG *)(T16B_0_REG_BASE_ADDR + 0x1A))).reg


// T16B Ch.1 Clock Control Register
#define	T16B1CLK			(*((volatile T16BNCLK_REG *)(T16B_1_REG_BASE_ADDR + 0x00))).reg
#define	T16B1CLK_CLKSRC		(*((volatile T16BNCLK_REG *)(T16B_1_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of T16B Ch.1.
#define	T16B1CLK_CLKDIV		(*((volatile T16BNCLK_REG *)(T16B_1_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the T16B Ch.1 operating clock (counter clock).
#define	T16B1CLK_DBRUN		(*((volatile T16BNCLK_REG *)(T16B_1_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the T16B Ch.1 operating clock is supplied in DEBUG mode or not.

// T16B Ch.1 Counter Control Register.
#define	T16B1CTL			(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).reg
#define	T16B1CTL_MODEN		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).bit.MODEN		///< This bit enables the T16B Ch.1 operations.
#define	T16B1CTL_PRESET		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).bit.PRESET		///< This bit resets the counter.
#define	T16B1CTL_RUN		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).bit.RUN			///< This bit starts/stops counting.
#define	T16B1CTL_ONEST		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).bit.ONEST		///< This bit selects the counter repeat/one-shot mode.
#define	T16B1CTL_CNTMD		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).bit.CNTMD		///< These bits select the counter up/down mode.
#define	T16B1CTL_MAXBSY		(*((volatile T16BNCTL_REG *)(T16B_1_REG_BASE_ADDR + 0x02))).byte_reg[1]		///< This bit indicates whether data can be written to the T16BnMC register or not.

// T16B Ch.1 Max Counter Data Register
#define	T16B1MC				(*((volatile T16BNMC_REG *)(T16B_1_REG_BASE_ADDR + 0x04))).reg

// T16B Ch.1 Timer Counter Data Register.
#define	T16B1TC				(*((volatile T16BNTC_REG *)(T16B_1_REG_BASE_ADDR + 0x06))).reg

// T16B Ch.1 Counter Status Register
#define	T16B1CS				(*((volatile T16BNCS_REG *)(T16B_1_REG_BASE_ADDR + 0x08))).reg
#define	T16B1CS_BSY			(*((volatile T16BNCS_REG *)(T16B_1_REG_BASE_ADDR + 0x08))).bit.BSY			///< This bit indicates the counter operating status.
#define	T16B1CS_UP_DOWN		(*((volatile T16BNCS_REG *)(T16B_1_REG_BASE_ADDR + 0x08))).bit.UP_DOWN		///< This bit indicates the currently set count direction.
#define	T16B1CS_CAPI0		(*((volatile T16BNCS_REG *)(T16B_1_REG_BASE_ADDR + 0x08))).bit.CAPI0		///< These bits indicate the signal level currently input to the CAPx0 pin.
#define	T16B1CS_CAPI1		(*((volatile T16BNCS_REG *)(T16B_1_REG_BASE_ADDR + 0x08))).bit.CAPI1		///< These bits indicate the signal level currently input to the CAPx1 pin.

// T16B Ch.1 Interrupt Flag Register.
#define	T16B1INTF			(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).reg
#define	T16B1INTF_CNTZEROIF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CNTZEROIF	///< Counter zero interrupt
#define	T16B1INTF_CNTMAXIF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CNTMAXIF	///< Counter MAX interrupt
#define	T16B1INTF_CMPCAP0IF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CMPCAP0IF	///< Compare/capture 0 interrupt
#define	T16B1INTF_CAPOW0IF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CAPOW0IF	///< Capture 0 overwrite interrupt
#define	T16B1INTF_CMPCAP1IF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CMPCAP1IF	///< Compare/capture 1 interrupt
#define	T16B1INTF_CAPOW1IF	(*((volatile T16BNINTF_REG *)(T16B_1_REG_BASE_ADDR + 0x0A))).bit.CAPOW1IF	///< Capture 1 overwrite interrupt

// T16B Ch.1 Interrupt Enable Register.
#define	T16B1INTE			(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).reg
#define	T16B1INTE_CNTZEROIE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CNTZEROIE	///< Counter zero interrupt
#define	T16B1INTE_CNTMAXIE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CNTMAXIE	///< Counter MAX interrupt
#define	T16B1INTE_CMPCAP0IE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CMPCAP0IE	///< Compare/capture 0 interrupt
#define	T16B1INTE_CAPOW0IE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CAPOW0IE	///< Capture 0 overwrite interrupt
#define	T16B1INTE_CMPCAP1IE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CMPCAP1IE	///< Compare/capture 1 interrupt
#define	T16B1INTE_CAPOW1IE	(*((volatile T16BNINTE_REG *)(T16B_1_REG_BASE_ADDR + 0x0C))).bit.CAPOW1IE	///< Capture 1 overwrite interrupt

// T16B Ch.1 Comparator/Capture 0 Control Register.
#define	T16B1CCCTL0			(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).reg
#define	T16B1CCCTL0_CCMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.CCMD		///< This bit selects the operating mode of the comparator/capture circuit m.
#define	T16B1CCCTL0_TOUTINV	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.TOUTINV	///< This bit selects the TOUT10 signal polarity.
#define	T16B1CCCTL0_TOUTMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.TOUTMD	///< These bits configure how the TOUT10 signal waveform is changed.
#define	T16B1CCCTL0_TOUTO	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.TOUTO	///< This bit sets the TOUT10 signal output level
#define	T16B1CCCTL0_TOUTMT	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.TOUTMT	///< This bit selects whether the comparator equal signal.
#define	T16B1CCCTL0_CAPTRG	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.CAPTRG	///< These bits select the trigger edge(s) of the trigger signal.
#define	T16B1CCCTL0_CAPIS	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.CAPIS	///< These bits select the trigger signal for capturing.
#define	T16B1CCCTL0_CBUFMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.CBUFMD	///< These bits select the timing to load the comparison value written.
#define	T16B1CCCTL0_SCS		(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x10))).bit.SCS		///< This bit selects either synchronous capture mode or asynchronous capture mode.

// T16B Ch.1 Compare/Capture 0 Data Register.
#define	T16B1CCR0			(*((volatile T16BNCCRM_REG *)(T16B_1_REG_BASE_ADDR + 0x12))).reg

// T16B Ch.1 Comparator/Capture 1 Control Register.
#define	T16B1CCCTL1			(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).reg
#define	T16B1CCCTL1_CCMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.CCMD		///< This bit selects the operating mode of the comparator/capture circuit m.
#define	T16B1CCCTL1_TOUTINV	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.TOUTINV	///< This bit selects the TOUT11 signal polarity.
#define	T16B1CCCTL1_TOUTMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.TOUTMD	///< These bits configure how the TOUT11 signal waveform is changed.
#define	T16B1CCCTL1_TOUTO	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.TOUTO	///< This bit sets the TOUT11 signal output level
#define	T16B1CCCTL1_TOUTMT	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.TOUTMT	///< This bit selects whether the comparator equal signal.
#define	T16B1CCCTL1_CAPTRG	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.CAPTRG	///< These bits select the trigger edge(s) of the trigger signal.
#define	T16B1CCCTL1_CAPIS	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.CAPIS	///< These bits select the trigger signal for capturing.
#define	T16B1CCCTL1_CBUFMD	(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.CBUFMD	///< These bits select the timing to load the comparison value written.
#define	T16B1CCCTL1_SCS		(*((volatile T16BNCCCTLM_REG *)(T16B_1_REG_BASE_ADDR + 0x18))).bit.SCS		///< This bit selects either synchronous capture mode or asynchronous capture mode.

// T16B Ch.1 Compare/Capture 1 Data Register.
#define	T16B1CCR1			(*((volatile T16BNCCRM_REG *)(T16B_1_REG_BASE_ADDR + 0x1A))).reg


/*********************/
/* ----- SNDA ------ */
/*********************/

// SNDA Clock Control Register
#define	SNDCLK				(*((volatile SNDCLK_REG *)(SNDA_REG_BASE_ADDR + 0x00))).reg
#define	SNDCLK_CLKSRC		(*((volatile SNDCLK_REG *)(SNDA_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of SNDA.
#define	SNDCLK_CLKDIV		(*((volatile SNDCLK_REG *)(SNDA_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the SNDA operating clock.
#define	SNDCLK_DBRUN		(*((volatile SNDCLK_REG *)(SNDA_REG_BASE_ADDR + 0x00))).byte_reg[1]			///< This bit sets whether the SNDA operating clock is supplied in DEBUG mode or not.

// SNDA Select Register
#define	SNDSEL				(*((volatile SNDSEL_REG *)(SNDA_REG_BASE_ADDR + 0x02))).reg
#define	SNDSEL_MOSEL		(*((volatile SNDSEL_REG *)(SNDA_REG_BASE_ADDR + 0x02))).bit.MOSEL			///< These bits select a sound output mode.
#define	SNDSEL_SINV			(*((volatile SNDSEL_REG *)(SNDA_REG_BASE_ADDR + 0x02))).bit.SINV			///< This bit selects an output pin drive mode.
#define	SNDSEL_STIM			(*((volatile SNDSEL_REG *)(SNDA_REG_BASE_ADDR + 0x02))).byte_reg[1]			///< These bits select a tempo or a one-shot buzzer output duration.

// SNDA Control Register
#define	SNDCTL				(*((volatile SNDCTL_REG *)(SNDA_REG_BASE_ADDR + 0x04))).reg
#define	SNDCTL_MODEN		(*((volatile SNDCTL_REG *)(SNDA_REG_BASE_ADDR + 0x04))).byte_reg[0]			///< This bit enables the SNDA operations.
#define	SNDCTL_SSTP			(*((volatile SNDCTL_REG *)(SNDA_REG_BASE_ADDR + 0x04))).byte_reg[1]			///< This bit stops sound output.

// SNDA Data Register
#define	SNDDAT				(*((volatile SNDDAT_REG *)(SNDA_REG_BASE_ADDR + 0x06))).reg
#define	SNDDAT_SFRQ			(*((volatile SNDDAT_REG *)(SNDA_REG_BASE_ADDR + 0x06))).byte_reg[0]			///< These bits select a scale or a buzzer signal frequency.
#define	SNDDAT_SLEN			(*((volatile SNDDAT_REG *)(SNDA_REG_BASE_ADDR + 0x06))).bit.SLEN			///< These bits select a duration or a buzzer signal duty ratio.
#define	SNDDAT_MDRS			(*((volatile SNDDAT_REG *)(SNDA_REG_BASE_ADDR + 0x06))).bit.MDRS			///< This bit selects the output type in melody mode from a note or a rest.
#define	SNDDAT_MDTI			(*((volatile SNDDAT_REG *)(SNDA_REG_BASE_ADDR + 0x06))).bit.MDTI			///< This bit specifies a tie in melody mode.

// SNDA Interrupt Flag Register
#define	SNDINTF				(*((volatile SNDINTF_REG *)(SNDA_REG_BASE_ADDR + 0x08))).reg
#define	SNDINTF_EDIF		(*((volatile SNDINTF_REG *)(SNDA_REG_BASE_ADDR + 0x08))).bit.EDIF			///< Sound buffer empty interrupt status.
#define	SNDINTF_EMIF		(*((volatile SNDINTF_REG *)(SNDA_REG_BASE_ADDR + 0x08))).bit.EMIF			///< Sound output completion interrupt status.
#define	SNDINTF_SBSY		(*((volatile SNDINTF_REG *)(SNDA_REG_BASE_ADDR + 0x08))).byte_reg[1]		///< This bit indicates the sound output status.

// SNDA Interrupt Enable Register
#define	SNDINTE				(*((volatile SNDINTE_REG *)(SNDA_REG_BASE_ADDR + 0x0A))).reg
#define	SNDINTE_EDIE		(*((volatile SNDINTE_REG *)(SNDA_REG_BASE_ADDR + 0x0A))).bit.EDIE			///< Sound output completion interrupt.
#define	SNDINTE_EMIE		(*((volatile SNDINTE_REG *)(SNDA_REG_BASE_ADDR + 0x0A))).bit.EMIE			///< Sound buffer empty interrupt.



/*********************/
/* ----- REMC2 ----  */
/*********************/

// REMC2 Clock Control Register
#define	REMCLK				(*((volatile REMCLK_REG *)(REMC2_REG_BASE_ADDR + 0x00))).reg
#define	REMCLK_CLKSRC		(*((volatile REMCLK_REG *)(REMC2_REG_BASE_ADDR + 0x00))).bit.CLKSRC			///< These bits select the clock source of REMC2.
#define	REMCLK_CLKDIV		(*((volatile REMCLK_REG *)(REMC2_REG_BASE_ADDR + 0x00))).bit.CLKDIV			///< These bits select the division ratio of the REMC2 operating clock.
#define	REMCLK_DBRUN		(*((volatile REMCLK_REG *)(REMC2_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the REMC2 operating clock is supplied in DEBUG mode or not.

// REMC2 Data Bit Counter Control Register.
#define	REMDBCTL			(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).reg
#define	REMDBCTL_MODEN		(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.MODEN		///< This bit enables the REMC2 operations.
#define	REMDBCTL_REMCRST	(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.REMCRST		///< This bit issues software reset to the REMC2.
#define	REMDBCTL_TRMD		(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.TRMD			///< This bit selects the operation mode of the 16-bit counter for data signal generation.
#define	REMDBCTL_BUFEN		(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.BUFEN		///< This bit enables or disables the compare buffers.
#define	REMDBCTL_REMOINV	(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.REMOINV		///< This bit inverts the REMO output signal.
#define	REMDBCTL_PRUN		(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.PRUN			///< This bit starts/stops counting by the internal counters.
#define	REMDBCTL_PRESET		(*((volatile REMDBCTL_REG *)(REMC2_REG_BASE_ADDR + 0x02))).bit.PRESET		///< This bit resets the internal counters.

// REMC2 Data Bit Counter Register.
#define	REMDBCNT			(*((volatile REMDBCNT_REG *)(REMC2_REG_BASE_ADDR + 0x04))).reg

// REMC2 Data Bit Active Pulse Length Register.
#define	REMAPLEN			(*((volatile REMAPLEN_REG *)(REMC2_REG_BASE_ADDR + 0x06))).reg

// REMC2 Data Bit Length Register.
#define	REMDBLEN			(*((volatile REMDBLEN_REG *)(REMC2_REG_BASE_ADDR + 0x08))).reg

// REMC2 Status and Interrupt Flag Register.
#define	REMINTF				(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).reg
#define	REMINTF_APIF		(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).bit.APIF			///< This bit indicate the REMC2 Compare AP interrupt cause occurrence status.
#define	REMINTF_DBIF		(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).bit.DBIF			///< This bit indicate the REMC2 Compare DB interrupt cause occurrence status.
#define	REMINTF_APLENBSY	(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).bit.APLENBSY		///< This bit indicates whether a compare match occurs by the REMAPLEN buffer or not.
#define	REMINTF_DBLENBSY	(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).bit.DBLENBSY		///< This bit indicates whether a compare match occurs by the REMDBLEN buffer or not.
#define	REMINTF_DBCNTRUN	(*((volatile REMINTF_REG *)(REMC2_REG_BASE_ADDR + 0x0A))).bit.DBCNTRUN		///< This bit indicates whether the 16-bit counter for data signal generation is running or not.

// REMC2 Interrupt Enable Register.
#define	REMINTE				(*((volatile REMINTE_REG *)(REMC2_REG_BASE_ADDR + 0x0c))).reg
#define	REMINTE_APIE		(*((volatile REMINTE_REG *)(REMC2_REG_BASE_ADDR + 0x0c))).bit.APIE			///< This bit enable REMC2 Compare AP interrupt.
#define	REMINTE_DBIE		(*((volatile REMINTE_REG *)(REMC2_REG_BASE_ADDR + 0x0c))).bit.DBIE			///< This bit enable REMC2 Compare DB interrupt.

// REMC2 Carrier Waveform Register.
#define	REMCARR				(*((volatile REMCARR_REG *)(REMC2_REG_BASE_ADDR + 0x10))).reg
#define	REMCARR_CRPER		(*((volatile REMCARR_REG *)(REMC2_REG_BASE_ADDR + 0x10))).byte_reg[0]			///< These bits set the carrier signal cycle.
#define	REMCARR_CRDTY		(*((volatile REMCARR_REG *)(REMC2_REG_BASE_ADDR + 0x10))).byte_reg[1]			///< These bits set the high level period of the carrier signal.

// REMC2 Carrier Modulation Control Register.
#define	REMCCTL				(*((volatile REMCCTL_REG *)(REMC2_REG_BASE_ADDR + 0x12))).reg
#define	REMCCTL_CARREN		REMCCTL																		///< This bit enables carrier modulation.



/*********************/
/* ----- LCD4A ----- */
/*********************/
// LCD4A Clock Control Register
#define	LCD4CLK				(*((volatile LCD4CLK_REG *)(LCD4A_REG_BASE_ADDR + 0x00))).reg
#define	LCD4CLK_CLKSRC		(*((volatile LCD4CLK_REG *)(LCD4A_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of the LCD4A.
#define	LCD4CLK_CLKDIV		(*((volatile LCD4CLK_REG *)(LCD4A_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the LCD4A operating clock.
#define	LCD4CLK_DBRUN		(*((volatile LCD4CLK_REG *)(LCD4A_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the LCD4A operating clock is supplied in DEBUG mode or not.

// LCD4A Control Register
#define	LCD4CTL				(*((volatile LCD4CTL_REG *)(LCD4A_REG_BASE_ADDR + 0x02))).reg
#define	LCD4CTL_MODEN		(*((volatile LCD4CTL_REG *)(LCD4A_REG_BASE_ADDR + 0x02))).bit.MODEN			///< This bit enables the LCD4A operations.
#define	LCD4CTL_LCDDIS		(*((volatile LCD4CTL_REG *)(LCD4A_REG_BASE_ADDR + 0x02))).bit.LCDDIS		///< This bit enables the discharge operations.

// LCD4A Timing Control Register 1
#define	LCD4TIM1			(*((volatile LCD4TIM1_REG *)(LCD4A_REG_BASE_ADDR + 0x04))).reg
#define	LCD4TIM1_LDUTY		(*((volatile LCD4TIM1_REG *)(LCD4A_REG_BASE_ADDR + 0x04))).byte_reg[0]		///< These bits set the drive duty.
#define	LCD4TIM1_FRMCNT		(*((volatile LCD4TIM1_REG *)(LCD4A_REG_BASE_ADDR + 0x04))).byte_reg[1]		///< These bits set the frame frequency.

// LCD4A Timing Control Register 2
#define	LCD4TIM2			(*((volatile LCD4TIM2_REG *)(LCD4A_REG_BASE_ADDR + 0x06))).reg
#define	LCD4TIM2_NLINE		(*((volatile LCD4TIM2_REG *)(LCD4A_REG_BASE_ADDR + 0x06))).byte_reg[0]		///< These bits enable the n-line inverse AC drive function and set the number of inverse lines.
#define	LCD4TIM2_BSTC		(*((volatile LCD4TIM2_REG *)(LCD4A_REG_BASE_ADDR + 0x06))).byte_reg[1]		///< These bits select the booster clock frequency for the LCD voltage booster.

// LCD4A Power Control Register
#define	LCD4PWR				(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).reg
#define	LCD4PWR_VCEN		(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.VCEN			///< This bit turns the LCD voltage regulator on and off.
#define	LCD4PWR_VCSEL		(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.VCSEL			///< This bit sets the LCD voltage regulator output (reference voltage for boosting).
#define	LCD4PWR_HVLD		(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.HVLD			///< This bit sets the LCD voltage regulator into heavy load protection mode.
#define	LCD4PWR_BSTEN		(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.BSTEN			///< This bit turns the LCD voltage booster on and off.
#define	LCD4PWR_LC			(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.LC			///< These bits set the LCD panel contrast.
#define	LCD4PWR_EXVCSEL		(*((volatile LCD4PWR_REG *)(LCD4A_REG_BASE_ADDR + 0x08))).bit.EXVCSEL		///< This bit selects the LCD drive power supply mode (external voltage application mode or internal generation mode).

// LCD4A Display Control Register
#define	LCD4DSP				(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).reg
#define	LCD4DSP_DSPC		(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).bit.DSPC			///< These bits control the LCD display on/off and select a display mode.
#define	LCD4DSP_DSPAR		(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).bit.DSPAR			///< This bit switches the display area in the display data RAM.
#define	LCD4DSP_DSPREV		(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).bit.DSPREV		///< This bit controls black/white inversion on the LCD display.
#define	LCD4DSP_COMREV		(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).bit.COMREV		///< This bit selects the common pin assignment direction.
#define	LCD4DSP_SEGREV		(*((volatile LCD4DSP_REG *)(LCD4A_REG_BASE_ADDR + 0x0A))).bit.SEGREV		///< This bit selects the segment pin assignment direction.

// LCD4A COM Pin Control Register 0
#define	LCD4COMC0			(*((volatile LCD4COMCX_REG *)(LCD4A_REG_BASE_ADDR + 0x0C))).reg
#define	LCD4COMC0_COM0DEN	(*((volatile LCD4COMCX_REG *)(LCD4A_REG_BASE_ADDR + 0x0C))).bit.COM0DEN		///< These bits configure the partial drive of the COM0 pin.
#define	LCD4COMC0_COM1DEN	(*((volatile LCD4COMCX_REG *)(LCD4A_REG_BASE_ADDR + 0x0C))).bit.COM1DEN		///< These bits configure the partial drive of the COM1 pin.
#define	LCD4COMC0_COM2DEN	(*((volatile LCD4COMCX_REG *)(LCD4A_REG_BASE_ADDR + 0x0C))).bit.COM2DEN		///< These bits configure the partial drive of the COM2 pin.
#define	LCD4COMC0_COM3DEN	(*((volatile LCD4COMCX_REG *)(LCD4A_REG_BASE_ADDR + 0x0C))).bit.COM3DEN		///< These bits configure the partial drive of the COM3 pin.

// LCD4A Interrupt Flag Register
#define	LCD4INTF			(*((volatile LCD4INTF_REG *)(LCD4A_REG_BASE_ADDR + 0x10))).reg
#define	LCD4INTF_FRMIF		LCD4INTF																	///< This bit indicates the frame interrupt cause occurrence status.

// LCD4A Interrupt Enable Register
#define	LCD4INTE			(*((volatile LCD4INTE_REG *)(LCD4A_REG_BASE_ADDR + 0x12))).reg
#define	LCD4INTE_FRMIE		LCD4INTE																	///< This bit enables the frame interrupt.



/*******************/
/* ----- RFC ----- */
/*******************/

// RFC Ch.0 Clock Control Register
#define	RFC0CLK				(*((volatile RFCNCLK_REG *)(RFC_0_REG_BASE_ADDR + 0x00))).reg
#define	RFC0CLK_CLKSRC		(*((volatile RFCNCLK_REG *)(RFC_0_REG_BASE_ADDR + 0x00))).bit.CLKSRC		///< These bits select the clock source of the RFC.
#define	RFC0CLK_CLKDIV		(*((volatile RFCNCLK_REG *)(RFC_0_REG_BASE_ADDR + 0x00))).bit.CLKDIV		///< These bits select the division ratio of the RFC operating clock.
#define	RFC0CLK_DBRUN		(*((volatile RFCNCLK_REG *)(RFC_0_REG_BASE_ADDR + 0x00))).byte_reg[1]		///< This bit sets whether the RFC operating clock is supplied in DEBUG mode or not.

// RFC Ch.0 Control Register
#define	RFC0CTL				(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).reg
#define	RFC0CTL_MODEN		(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).bit.MODEN			///< This bit enables the RFC operations.
#define	RFC0CTL_SMODE		(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).bit.SMODE			///< These bits configure the oscillation mode.
#define	RFC0CTL_EVTEN		(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).bit.EVTEN			///< This bit enables external clock input mode (event counter mode).
#define	RFC0CTL_CONEN		(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).bit.CONEN			///< This bit disables the automatic CR oscillation stop function to enable continuous oscillation function.
#define	RFC0CTL_RFCLKMD		(*((volatile RFCNCTL_REG *)(RFC_0_REG_BASE_ADDR + 0x02))).byte_reg[1]		///< This bit sets the RFCLKOn pin to output the divided-by-two oscillation clock.

// RFC Ch.0 Oscillation Trigger Register
#define	RFC0TRG				(*((volatile RFCNTRG_REG *)(RFC_0_REG_BASE_ADDR + 0x04))).reg
#define	RFC0TRG_SREF		(*((volatile RFCNTRG_REG *)(RFC_0_REG_BASE_ADDR + 0x04))).bit.SREF			///< This bit controls CR oscillation for the reference resistor.
#define	RFC0TRG_SSENA		(*((volatile RFCNTRG_REG *)(RFC_0_REG_BASE_ADDR + 0x04))).bit.SSENA			///< This bit controls CR oscillation for sensor A.
#define	RFC0TRG_SSENB		(*((volatile RFCNTRG_REG *)(RFC_0_REG_BASE_ADDR + 0x04))).bit.SSENB			///< This bit controls CR oscillation for sensor B.

// RFC Ch.0 Measurement Counter Low Register
#define	RFC0MCL				(*((volatile RFCNMCL_REG *)(RFC_0_REG_BASE_ADDR + 0x06))).reg

// RFC Ch.0 Measurement Counter High Register
#define	RFC0MCH				(*((volatile RFCNMCH_REG *)(RFC_0_REG_BASE_ADDR + 0x08))).reg
#define	RFC0MCH_MC			(*((volatile RFCNMCH_REG *)(RFC_0_REG_BASE_ADDR + 0x08))).bit.MC			///< Measurement counter data can be read and written through these bits.

// RFC Ch.0 Measurement Counter Register
#define RFC0MC				(*((volatile RFCNMC_DWORD_REG *)(RFC_0_REG_BASE_ADDR + 0x06))).reg			///< Measurement counter data can be read and written through these bits.

// RFC Ch.0 Time Base Counter Low Register
#define	RFC0TCL				(*((volatile RFCNTCL_REG *)(RFC_0_REG_BASE_ADDR + 0x0A))).reg

// RFC Ch.0 Time Base Counter High Register
#define	RFC0TCH				(*((volatile RFCNTCH_REG *)(RFC_0_REG_BASE_ADDR + 0x0C))).reg
#define	RFC0TCH_TC			(*((volatile RFCNTCH_REG *)(RFC_0_REG_BASE_ADDR + 0x0C))).bit.TC			///< Time base counter data can be read and written through these bits.

// RFC Ch.0 Time Base Counter Register
#define RFC0TC				(*((volatile RFCNTC_DWORD_REG *)(RFC_0_REG_BASE_ADDR + 0x0A))).reg			///< Time base counter data can be read and written through these bits.

// RFC Ch.0 Interrupt Flag Register
#define	RFC0INTF			(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).reg
#define	RFC0INTF_EREFIF		(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).bit.EREFIF		///< This bit indicate Reference oscillation completion interrupt cause occurrence status.
#define	RFC0INTF_ESENAIF	(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).bit.ESENAIF		///< This bit indicate Sensor B oscillation completion interrupt cause occurrence status.
#define	RFC0INTF_ESENBIF	(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).bit.ESENBIF		///< This bit indicate Sensor B oscillation completion interrupt cause occurrence status.
#define	RFC0INTF_OVMCIF		(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).bit.OVMCIF		///< This bit indicate Measurement counter overflow error interrupt cause occurrence status.
#define	RFC0INTF_OVTCIF		(*((volatile RFCNINTF_REG *)(RFC_0_REG_BASE_ADDR + 0x0E))).bit.OVTCIF		///< This bit indicate Time base counter overflow error interrupt cause occurrence status.

// RFC Ch.0 Interrupt Enable Register
#define	RFC0INTE			(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).reg
#define	RFC0INTE_EREFIE		(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).bit.EREFIE		///< This bit enable Reference oscillation completion interrupt.
#define	RFC0INTE_ESENAIE	(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).bit.ESENAIE		///< This bit enable Sensor A oscillation completion interrupt.
#define	RFC0INTE_ESENBIE	(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).bit.ESENBIE		///< This bit enable Sensor B oscillation completion interrupt.
#define	RFC0INTE_OVMCIE		(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).bit.OVMCIE		///< This bit enable Measurement counter overflow error interrupt.
#define	RFC0INTE_OVTCIE		(*((volatile RFCNINTE_REG *)(RFC_0_REG_BASE_ADDR + 0x10))).bit.OVTCIE		///< This bit enable Time base counter overflow error interrupt.



#ifdef __cplusplus
}
#endif

#endif	// C17W13_REG_H__
