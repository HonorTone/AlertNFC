/***************************************************************************
 *
 * @file	rtca_reg.h
 * @brief	Definition of the Real-time Clock(RTCA) Register.
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

#ifndef	RTCA_REG_H__
#define	RTCA_REG_H__

#ifdef	__cplusplus
extern "C" {
#endif


/// RTC Control Register.
typedef union RTCCTL_REG_TAG {
	unsigned short			reg;
	struct RTCCTL_REG_BIT_TAG {
		unsigned short		RTCRUN		: 1;	///< This bit starts/stops the real-time clock counter.
		unsigned short		RTCRST		: 1;	///< This bit resets the 1 Hz counter, the RTCCTL.RTCADJ bit, and the RTCCTL.RTCHLD bit.
		unsigned short		RTCADJ		: 1;	///< This bit executes the 30-second correction time adjustment function.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		RTC24H		: 1;	///< This bit sets the hour counter to 24H mode or 12H mode.
		unsigned short		RTCHLD		: 1;	///< This bit halts the count-up operation of the real-time clock counter.
		unsigned short		RTCBSY		: 1;	///< This bit indicates whether the counter is performing count-up operation or not.
		unsigned short		reserved_2	: 1;	///< Reserved.
		unsigned short		RTCTRM		: 7;	///< Write the correction value for adjusting the 1 Hz frequency to these bits to execute theoretical regulation.
		unsigned short		RTCTRMBSY	: 1;	///< This bit indicates whether the theoretical regulation is currently executed or not.
	} bit;
	unsigned char byte_reg[2];
} RTCCTL_REG;

/// RTC Second Alarm Register.
typedef union RTCALM1_REG_TAG {
	unsigned short			reg;
	struct RTCALM1_REG_BIT_TAG {
		unsigned short		reserved_1	: 8;	///< Reserved.
		unsigned short		RTCSLA		: 4;	///< There bits set the 1-second digit of the alarm time.
		unsigned short		RTCSHA		: 3;	///< There bits set the 10-second digit of the alarm time.
		unsigned short		reserved_2	: 1;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCALM1_REG;

/// RTC Hour/Minute Alarm Register.
typedef union RTCALM2_REG_TAG {
	unsigned short			reg;
	struct RTCALM2_REG_BIT_TAG {
		unsigned short		RTCMILA		: 4;	///< There bits set the 1-minute digit of the alarm time.
		unsigned short		RTCMIHA		: 3;	///< There bits set the 10-minute digit of the alarm time.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		RTCHLA		: 4;	///< There bits set the 1-hour digit of the alarm time.
		unsigned short		RTCHHA		: 2;	///< There bits set the 10-hour digit of the alarm time.
		unsigned short		RTCAPA		: 1;	///< This bit set A.M. or P.M. of the alarm time in 12H mode (RTCCTL.RTC24H bit = 0).
		unsigned short		reserved_2	: 1;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCALM2_REG;

/// RTC Stopwatch Control Register.
typedef union RTCSWCTL_REG_TAG {
	unsigned short			reg;
	struct RTCSWCTL_REG_BIT_TAG {
		unsigned short		SWRUN		: 1;	///< This bit starts/stops the stop watch counter.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		SWRST		: 1;	///< This bit resets the stop watch counter to 0x00.
		unsigned short		reserved_2	: 3;	///< Reserved.
		unsigned short		BCD100		: 4;	///< The 1/100-second digits of the stop watch counter can be read as a BCD code.
		unsigned short		BCD10		: 4;	///< The 1/10-second digits of the stop watch counter can be read as a BCD code.
	} bit;
	unsigned char byte_reg[2];
} RTCSWCTL_REG;

/// RTC Second/1[Hz] Register.
typedef union RTCSEC_REG_TAG {
	unsigned short			reg;
	struct RTCSEC_REG_BIT_TAG {
		unsigned short		RTC128HZ	: 1;	///< 1 Hz counter data can be read from these bits(128Hz).
		unsigned short		RTC64HZ		: 1;	///< 1 Hz counter data can be read from these bits(64Hz).
		unsigned short		RTC32HZ		: 1;	///< 1 Hz counter data can be read from these bits(32Hz).
		unsigned short		RTC16HZ		: 1;	///< 1 Hz counter data can be read from these bits(16Hz).
		unsigned short		RTC8HZ		: 1;	///< 1 Hz counter data can be read from these bits(8Hz).
		unsigned short		RTC4HZ		: 1;	///< 1 Hz counter data can be read from these bits(4Hz).
		unsigned short		RTC2HZ		: 1;	///< 1 Hz counter data can be read from these bits(2Hz).
		unsigned short		RTC1HZ		: 1;	///< 1 Hz counter data can be read from these bits(1Hz).
		unsigned short		RTCSL		: 4;	///< There bits are used to set and read the 1-second digit of the second counter.
		unsigned short		RTCSH		: 3;	///< There bits are used to set and read the 10-second digit of the second counter.
		unsigned short		reserved_1	: 1;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCSEC_REG;

/// RTC Hour/Minute Register.
typedef union RTCHUR_REG_TAG {
	unsigned short			reg;
	struct RTCHUR_REG_BIT_TAG {
		unsigned short		RTCMIL		: 4;	///< There bits are used to set and read the 1-minute digit of the minute counter.
		unsigned short		RTCMIH		: 3;	///< There bits are used to set and read the 10-minute digit of the minute counter.
		unsigned short		reserved_1	: 1;	///< Reserved.
		unsigned short		RTCHL		: 4;	///< There bits are used to set and read the 1-hour digit of the hour counter.
		unsigned short		RTCHH		: 2;	///< There bits are used to set and read the 10-hour digit of the hour counter.
		unsigned short		RTCAP		: 1;	///< This bit is used to set and read A.M. or P.M. data in 12H mode (RTCCTL.RTC24H bit = 0).
		unsigned short		reserved_2	: 1;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCHUR_REG;

/// RTC Month/Day Register.
typedef union RTCMON_REG_TAG {
	unsigned short			reg;
	struct RTCMON_REG_BIT_TAG {
		unsigned short		RTCDL		: 4;	///< There bits are used to set and read the 1-day digit of the day counter.
		unsigned short		RTCDH		: 2;	///< There bits are used to set and read the 10-day digit of the day counter.
		unsigned short		reserved_1	: 2;	///< Reserved.
		unsigned short		RTCMOL		: 4;	///< There bits are used to set and read the 1-month digit of the month counter.
		unsigned short		RTCMOH		: 1;	///< There bits are used to set and read the 10-month digit of the month counter.
		unsigned short		reserved_2	: 3;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCMON_REG;

/// RTC Year/Week Register.
typedef union RTCYAR_REG_TAG {
	unsigned short			reg;
	struct RTCYAR_REG_BIT_TAG {
		unsigned short		RTCYL		: 4;	///< There bits are used to set and read the 1-year digit of the year counter.
		unsigned short		RTCYH		: 4;	///< There bits are used to set and read the 10-year digit of the year counter.
		unsigned short		RTCWK		: 3;	///< These bits are used to set and read day of the week.
		unsigned short		reserved_1	: 5;	///< Reserved.
	} bit;
	unsigned char byte_reg[2];
} RTCYAR_REG;

/// RTC Interrupt Flag Register.
typedef union RTCINTF_REG_TAG {
	unsigned short			reg;
	struct RTCINTF_REG_BIT_TAG {
		unsigned short		_1_32SECIF	: 1;	///< This bit indicate 1/32-second interrupt cause occurrence status.
		unsigned short		_1_8SECIF	: 1;	///< This bit indicate 1/8-second interrupt cause occurrence status.
		unsigned short		_1_4SECIF	: 1;	///< This bit indicate 1/4-second interrupt cause occurrence status.
		unsigned short		_1_2SECIF	: 1;	///< This bit indicate 1/2-second interrupt cause occurrence status.
		unsigned short		_1SECIF		: 1;	///< This bit indicate 1-second interrupt cause occurrence status.
		unsigned short		_1MINIF		: 1;	///< This bit indicate 1-minute interrupt cause occurrence status.
		unsigned short		_1HURIF		: 1;	///< This bit indicate 1-day interrupt cause occurrence status.
		unsigned short		_1DAYIF		: 1;	///< This bit indicate 1-day interrupt cause occurrence status.
		unsigned short		ALARMIF		: 1;	///< This bit indicate Alarm interrupt cause occurrence status.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		SW100IF		: 1;	///< This bit indicate Stop watch 100 Hz interrupt cause occurrence status.
		unsigned short		SW10IF		: 1;	///< This bit indicate Stop watch 10 Hz interrupt cause occurrence status.
		unsigned short		SW1IF		: 1;	///< This bit indicate Stop watch 1 Hz interrupt cause occurrence status.
		unsigned short		RTCTRMIF	: 1;	///< This bit indicate Theoretical regulation completion interrupt cause occurrence status.
	} bit;
	unsigned char byte_reg[2];
} RTCINTF_REG;

/// RTC Interrupt Enable Register.
typedef union RTCINTE_REG_TAG {
	unsigned short			reg;
	struct RTCINTE_REG_BIT_TAG {
		unsigned short		_1_32SECIE	: 1;	///< This bits enable 1/32-second interrupt.
		unsigned short		_1_8SECIE	: 1;	///< This bits enable 1/8-second interrupt.
		unsigned short		_1_4SECIE	: 1;	///< This bits enable 1/4-second interrupt.
		unsigned short		_1_2SECIE	: 1;	///< This bits enable 1/2-second interrupt.
		unsigned short		_1SECIE		: 1;	///< This bits enable 1-second interrupt.
		unsigned short		_1MINIE		: 1;	///< This bits enable 1-minute interrupt.
		unsigned short		_1HURIE		: 1;	///< This bits enable 1-hour interrupt.
		unsigned short		_1DAYIE		: 1;	///< This bits enable 1-day interrupt.
		unsigned short		ALARMIE		: 1;	///< This bits enable Alarm interrupt.
		unsigned short		reserved_1	: 3;	///< Reserved.
		unsigned short		SW100IE		: 1;	///< This bit enable Stop watch 100 Hz interrupt.
		unsigned short		SW10IE		: 1;	///< This bit enable Stop watch 10 Hz interrupt.
		unsigned short		SW1IE		: 1;	///< This bit enable Stop watch 1 Hz interrupt.
		unsigned short		RTCTRMIE	: 1;	///< This bit enable Theoretical regulation completion interrupt.
	} bit;
	unsigned char byte_reg[2];
} RTCINTE_REG;


#ifdef __cplusplus
}
#endif

#endif	// RTCA_REG_H__


