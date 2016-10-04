/****************************************************************************
 *
 * @file	rtca.h
 * @brief	This is RTCA driver header file for S1C17M01/W22_W23.
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

#ifndef RTCA_H__
#define RTCA_H__


#include <init.h>


/* --- definition --- */

// Hour counter mode.
#define RTCCTL_RTC24H_12H				( 0 )			///< Hour counter - 12H mode.
#define RTCCTL_RTC24H_24H				( 1 )			///< Hour counter - 24H mode.

// A.M. or P.M. data in 12H mode.
#define RTCHUR_RTCAP_AM				( 0 )			///< Mode - A.M.
#define RTCHUR_RTCAP_PM				( 1 )			///< Mode - P.M.

// Day of the week.
#define RTCYAR_RTCWK_SUN				( 0 )			///< Day of the week - Sunday.
#define RTCYAR_RTCWK_MON				( 1 )			///< Day of the week - Monday.
#define RTCYAR_RTCWK_TUE				( 2 )			///< Day of the week - Tuesday.
#define RTCYAR_RTCWK_WED				( 3 )			///< Day of the week - Wednesday.
#define RTCYAR_RTCWK_THU				( 4 )			///< Day of the week - Thursday.
#define RTCYAR_RTCWK_FRI				( 5 )			///< Day of the week - Friday.
#define RTCYAR_RTCWK_SAT				( 6 )			///< Day of the week - Saturday.

/* --- Struct   ---*/
struct swCounter{
	unsigned int swInt1HzCount;						///< Counts of 1Hz interrupts(0-65535).
	unsigned char swChar10HzDigit;						///< 10Hz-digit stopwatch count(0-9).
	unsigned char swChar100HzDigit;					///< 100Hz-digit stopwatch count(0-9).
};


/* --- external declaration --- */
// initialize.
extern unsigned int timeCount;
extern unsigned int rtcaIntCount1Sec;
extern unsigned char rtc_initSet();
unsigned int rtc_getSeconds();
unsigned char Is_Leap_Year(unsigned char);
extern int initRtca( void );
extern unsigned char initSw( void );
// Start/Stop
extern void startRtca( void );
extern void stopRtca( void );
extern void startSw( void );
extern void stopSw( void );
// Interrupt setting.
extern void intRtca(void)	__attribute__ ((interrupt_handler));
// 1 sec timer.
extern void enableRtca1SecTimer( void );
extern void disableRtca1SecTimer( void );
extern void setRtca1SecTimerCount( unsigned int count );
extern unsigned int getRtca1SecTimerCount( void );
// Theoretical Regulation setting.
extern void enableRtcaTheoreticalRegulation( void );
extern void disableRtcaTheoreticalRegulation( void );
// 24h/12h mode setting.
extern int setRtca24hMode( unsigned char mode );
extern unsigned char getRtca24hMode( void );
// Date setting.
extern int setRtcaYear( unsigned char year );
extern unsigned char getRtcaYear( void );
extern int setRtcaMonth( unsigned char month );
extern unsigned char getRtcaMonth( void );
extern int setRtcaDay( unsigned char day );
extern unsigned char getRtcaDay( void );
extern int setRtcaWeek( unsigned char week );
extern unsigned char getRtcaWeek( void );
// Time setting.
extern int setRtcaHour( unsigned char hour );
extern unsigned char getRtcaHour( void );
extern int setRtcaMinute( unsigned char minute );
extern unsigned char getRtcaMinute( void );
extern int setRtcaSecond( unsigned char second );
extern unsigned char getRtcaSecond( void );
// AM/PM setting.
extern int setRtcaIndicator( unsigned char indicator );
extern unsigned char getRtcaIndicator( void );
// Stopwatch
extern void enableSw( void );
extern void disableSw( void );
extern unsigned short int readSwCount(void );
extern unsigned int getSw1HzCount( void );


#endif	//RTCA_H__
