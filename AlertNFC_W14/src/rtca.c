/*******************************************************************************
 *
 * @file	rtca.c
 * @brief	This is RTCA program for S1C17M01/W22_W23 demonstration.
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
 ******************************************************************************/

#include <rtca.h>

/* --- global variable --- */

// Interrupt counter.
unsigned int rtcaIntCount1Sec		= 0;	///< Interrupt frequency every one second.
// Theoretical Regulation.
unsigned long rtcaTrTime			= 0;				///< The theoretical regulation execution cycle time(1/2seconds).
volatile unsigned long rtcaTrCount			= 0;	///< The theoretical regulation execution cycle time counter(1/2-second).
unsigned char rtcaTrBits			= 0;				///< The theoretical regulation execution bits.
volatile struct swCounter swCount;

#define STATUS_ASSERT( value )		{ if ( (value) == STATUS_NG ) { return STATUS_NG; } }
const unsigned char mon_table[12]={31,28,31,30,31,30,31,31,30,31,30,31};
unsigned int timeCount=0;

//与/// "01/01/00 Sunday 00:00:00" 相比较得到秒数
unsigned int rtc_getSeconds()
{
	unsigned int totalDay=0;
	unsigned int seconds;
	unsigned char tem,tem1,i;

	//tem = getRtcaWeek();					// get week.

	tem1 = getRtcaYear();					// get Year.
	for(i=1;i<=tem1;i++)//计算经历过的所有的年所占的天数
	{
		if(Is_Leap_Year(i-1))//完全跨过了闰年
		{
			totalDay+=366;//闰年的秒钟数
		}
		else totalDay+=365;	  //平年
	}
	tem = getRtcaMonth();// get month.
	for(i=1;i<tem;i++)//求得一年内所有所经历过的月数所占的天数
	{
		totalDay+=mon_table[i-1];
		if(i==3)//完全经过了二月
		{
		    if(Is_Leap_Year(tem1))//闰年二月份
		    {
		    	totalDay+1;
		    }
		}
	}
	tem	= getRtcaDay();// get day.
	totalDay+=(tem-1);//求得一个月内所经过的天数
	seconds=totalDay*86400;

	tem = getRtcaHour();					// get hour.
	seconds+=(tem*60*60);
	tem = getRtcaMinute();					// get minute.
	seconds+=(tem*60);
	tem = getRtcaSecond();					// get second.
	seconds+=tem;

	return seconds;
}
//判断是否是闰年函数
//月份   1  2  3  4  5  6  7  8  9  10 11 12
//闰年   31 29 31 30 31 30 31 31 30 31 30 31
//非闰年 31 28 31 30 31 30 31 31 30 31 30 31
//输入:年份
//输出:该年份是不是闰年.1,是.0,不是
unsigned char Is_Leap_Year(unsigned char year)
{
	if(year==0)return 0;//第0年作普通年
	if(year%4==0) //必须能被4整除
	{
		return 1;
	}
	else return 0;
}
unsigned char rtc_initSet()
{
	int status;
	/// Set RTCA date.
	/// Initialize RTCA.
	status = initRtca();							// initialize RTCA.
	if ( status == STATUS_NG )
	STATUS_ASSERT( status );

	status = setRtca24hMode( RTCCTL_RTC24H_24H );	// mode   = 24h mode.
	/*STATUS_ASSERT( status );
	status = setRtcaYear( 99 );						// Year   = 99.
	STATUS_ASSERT( status );
	status = setRtcaMonth( 12 );					// Month  = 12.
	STATUS_ASSERT( status );
	status = setRtcaDay( 31 );						// Day    = 31.
	STATUS_ASSERT( status );
	status = setRtcaWeek( RTCYAR_RTCWK_SAT );		// Week   = Saturday.
	STATUS_ASSERT( status );
	status = setRtcaHour( 23 );						// Hour   = 23.
	STATUS_ASSERT( status );
	status = setRtcaMinute( 57 );					// Minute = 59.
	STATUS_ASSERT( status );
	status = setRtcaSecond( 51 );					// Second = 51.
	STATUS_ASSERT( status );*/

	/// start RTCA.
	//startRtca();									// start RTCA.
	return 1;
}

/****************************************************************************
 * initRtca function.
 *
 * @brief	First, stop RTCA.
 *			Next, the register set.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int initRtca( void )
{
	/// When OSC1 doesn't start, nothing is done.
	if ( CLGOSC_OSC1EN == 0 ) {
		return STATUS_NG;
	}

	/// Stop RTCA.
	stopRtca();

	/// Hour counter set to 24H mode.
	RTCCTL_RTC24H	= RTCCTL_RTC24H_24H;		// Set mode.

	/// "01/01/00 Sunday 00:00:00" setting.
	RTCYAR_RTCYH	= 0;						// Set year(tenths digit).
	RTCYAR_RTCYL	= 0;						// Set year(unit digit).
	RTCMON_RTCMOH	= 0;						// Set month(tenths digit).
	RTCMON_RTCMOL	= 1;						// Set month(unit digit).
	RTCMON_RTCDH	= 0;						// Set day(tenths digit).
	RTCMON_RTCDL	= 1;						// Set day(unit digit).
	RTCYAR_RTCWK	= RTCYAR_RTCWK_SUN;			// Set weak;
	RTCHUR_RTCHH	= 0;						// Set hour(tenths digit).
	RTCHUR_RTCHL	= 0;						// Set hour(unit digit).
	RTCHUR_RTCMIH	= 0;						// Set minute(tenths digit).
	RTCHUR_RTCMIL	= 0;						// Set minute(unit digit).
	RTCSEC_RTCSH	= 0;						// Set second(tenths digit).
	RTCSEC_RTCSL	= 0;						// Set second(unit digit).

	/// The variable initialize.
	rtcaIntCount1Sec = 0;
	rtcaTrTime		= 0;
	rtcaTrCount		= 0;
	rtcaTrBits		= 0;

	/// Initialize the interrupt.
	ILVRTCA_0 = INTERRUPT_LEVEL3;

	return STATUS_OK;
}


/****************************************************************************
 * startRtca function.
 *
 * @brief	Start RTCA.
 ***************************************************************************/
void startRtca( void )
{
	RTCCTL_RTCRUN = 1;
}


/****************************************************************************
 * stopRtca function.
 *
 * @brief	Stop RTCA.
 ***************************************************************************/
void stopRtca( void )
{
	RTCCTL_RTCRUN = 0;
}


/****************************************************************************
 * intRtca function.
 *
 * @brief	Interrupt processing of RTCA.
 * 			For "1-second interrupt"   :The number of counters increase.
 * 			For "1/2-second interrupt" :Execute theoretical regulation.
 * 			For "Stopwatch 1Hz interrupt": Count 1Hz interrupts(0-65535).
 * 			For "Stopwatch 10Hz interrupt": Update 10Hz-digit stopwatch count(0-9).
 * 			For "Stopwatch 100Hz interrupt": Update 100Hz-digit stopwatch count(0-9).
 ***************************************************************************/
void intRtca( void )
{
	unsigned short int rtcaIntf;

	// Evaluate RTC Interrupt Flag Register at a time.
	rtcaIntf = RTCINTF;

	// Clear interrupt flags which cause of interrupt occurred.
	RTCINTF = rtcaIntf;

	timeCount++;
	// 1-second interrupt.
	if ( (rtcaIntf & 0x0010) == 0x0010){
		// Count up the interrupt counter(1-second).
			rtcaIntCount1Sec++;
	}

	// 1/2-second interrupt
	if ( (rtcaIntf & 0x0008) == 0x0008){
		// Execute theoretical regulation.
		rtcaTrCount++;
		if ( rtcaTrCount == rtcaTrTime ) {
			RTCCTL_RTCTRM = rtcaTrBits;
			rtcaTrCount = 0;
		}
	}

	// Stopwatch 1Hz interrupt
	if ((rtcaIntf & 0x4000) == 0x4000){
		swCount.swInt1HzCount++;
	}

	// Stopwatch 10Hz interrupt
	if ((rtcaIntf & 0x2000) == 0x2000){
		swCount.swChar10HzDigit++;
		if(swCount.swChar10HzDigit == 10){
			swCount.swChar10HzDigit = 0;
		}
	}

	// Stopwatch 100Hz interrupt
	if ((rtcaIntf & 0x1000) == 0x1000){
		swCount.swChar100HzDigit++;
		if(swCount.swChar100HzDigit == 10){
			swCount.swChar100HzDigit = 0;
		}
	}
}


/****************************************************************************
 * enableRtca1SecTimer function.
 *
 * @brief	Start 1 sec timer.
 *			The interrupt of RTCA set enable(1-second interrupt).
 ***************************************************************************/
void enableRtca1SecTimer( void )
{
	/// Reset 1 sec timer count.
	rtcaIntCount1Sec	= 0;

	/// Clear interrupt flag.
	//RTCINTF_1SECIF	= 1;
	RTCINTF				= 0x0010;

	/// The interrupt of RTCA set enable(1-second interrupt).
	RTCINTE_1SECIE		= 1;
}


/****************************************************************************
 * disableRtca1SecTimer function.
 *
 * @brief	Stop 1 sec timer.
 ***************************************************************************/
void disableRtca1SecTimer( void )
{
	/// The interrupt of RTCA set disable(1-second interrupt).
	RTCINTE_1SECIE		= 0;

	/// Clear interrupt flag.
	//RTCINTF_1SECIF		= 1;
	RTCINTF				= 0x0010;
}


/****************************************************************************
 * setRtca1SecTimerCount function.
 *
 * @brief	The frequency to which "1-second interrupt" occurs set.
 *
 * @param	count			Set value.
 ***************************************************************************/
void setRtca1SecTimerCount( unsigned int count )
{
	rtcaIntCount1Sec = count;
}


/****************************************************************************
 * getRtca1SecTimerCount function.
 *
 * @brief	The frequency to which "1-second interrupt" occurs get.
 *
 * @return	count			The counter value return.
 ***************************************************************************/
unsigned int getRtca1SecTimerCount( void )
{
	return rtcaIntCount1Sec;
}


/****************************************************************************
 * enableRtcaTheoreticalRegulation function.
 *
 * @brief	Start theoretical regulation.
 *			The interrupt of RTCA set enable(1-second interrupt).
 ***************************************************************************/
void enableRtcaTheoreticalRegulation( void )
{
	/// Correction rate : -58.2 ppm(Bits = 0x43).
	rtcaTrBits			= 0x43;
	/// Execution cycle time(1/2-second) : 4096 seconds.
	rtcaTrTime			= 4096 * 2;
	// The theoretical regulation execution cycle time counter(1/2-second).
	rtcaTrCount			= 0;

	/// Clear interrupt flag.
	//RTCINTF_1_2SECIF	= 1;
	RTCINTF				= 0x0008;

	/// The interrupt of RTCA set enable(1-second interrupt).
	RTCINTE_1_2SECIE	= 1;
}


/****************************************************************************
 * disableRtcaTheoreticalRegulation function.
 *
 * @brief	Stop theoretical regulation.
 ***************************************************************************/
void disableRtcaTheoreticalRegulation( void )
{
	/// The interrupt of RTCA set enable(1-second interrupt).
	RTCINTE_1_2SECIE	= 0;

	/// Clear interrupt flag.
	//RTCINTF_1_2SECIF	= 1;
	RTCINTF				= 0x0008;

}


/****************************************************************************
 * setRtcaMode function.
 *
 * @brief	The mode set in the register.
 *
 * @param	mode	12h or 24h mode.
 *	@li @c		RTCCTL_RTC24H_12H		12H mode.
 *	@li @c		RTCCTL_RTC24H_24H		24H mode.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtca24hMode( unsigned char mode )
{
	unsigned char indicator = RTCHUR_RTCAP_AM;
	unsigned char hour;
	int result = STATUS_OK;

	if ( RTCCTL_RTC24H_24H != mode && RTCCTL_RTC24H_12H != mode ) {
		return STATUS_NG;
	}

	/// It doesn't do at all for the same mode.
	if ( RTCCTL_RTC24H == mode ) {
		return STATUS_OK;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// The hour take out.
	hour = getRtcaHour();

	/// The set value calculate.
	// 24H mode -> 12H mode.
	if ( getRtca24hMode() == RTCCTL_RTC24H_24H ) {
		if ( hour == 0 ) {					// 0o'clock(12AM).
			hour = 12;
			indicator = RTCHUR_RTCAP_AM;
		} else if ( hour == 12 ) {			// 12o'clock(12PM).
			indicator = RTCHUR_RTCAP_PM;
		} else if ( hour >= 13 ) {			// 13 to 23o'clock(01PM to 11PM).
			hour = hour - 12;
			indicator = RTCHUR_RTCAP_PM;
		} else {							// 1 to 11o'clock(01AM to 11AM).
			indicator = RTCHUR_RTCAP_AM;
		}
	// 12H mode -> 24H mode.
	} else {
		// 12AM(0o'clock).
		if ( getRtcaIndicator() == RTCHUR_RTCAP_AM && hour == 12) {
			hour = 0;
		// 01PM to 11PM(13 to 23o'clock).
		} else 	if ( getRtcaIndicator() == RTCHUR_RTCAP_PM && hour < 12 ) {
			hour = hour + 12;
		} else {
			// Non.
		}
	}

	// Set mode.
	RTCCTL_RTC24H = mode;

	/// Set hour.
	if ( STATUS_NG == setRtcaHour( hour ) ) {
		result = STATUS_NG;
	}

	/// Set indicator(A.M/P.M).
	if ( STATUS_NG == setRtcaIndicator( indicator ) ) {
		result = STATUS_NG;
	}

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * getRtcaMode function.
 *
 * @brief	The value of the mode get from the register.
 *
 * @retval	RTCCTL_RTC24H_12H	12H mode.
 * @retval	RTCCTL_RTC24H_24H	24H mode.
 ***************************************************************************/
unsigned char getRtca24hMode( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCCTL_RTC24H;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaYear function.
 *
 * @brief	The year set in the register.
 *
 * @param	year				Set value.
 *	@li @c		0 to 99			year.
 *	@li @c		others			Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaYear( unsigned char year )
{
	if ( year > 99 ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCYAR_RTCYH = year / 10 % 10;		/// Set year(tenths digit).
	RTCYAR_RTCYL = year /  1 % 10;		/// Set year(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaYear function.
 *
 * @brief	The value of the year get from the register.
 *
 * @return	0 to 99			Return the get value.
 ***************************************************************************/
unsigned char getRtcaYear( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCYAR_RTCYH * 10 + RTCYAR_RTCYL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaMonth function.
 *
 * @brief	The month set in the register.
 *
 * @param	month			Set value.
 *	@li @c		1 to 12		month.
 *	@li @c		others		Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaMonth( unsigned char month )
{
	if ( month < 1 || month > 12 ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCMON_RTCMOH = month / 10 % 10;		/// Set month(tenths digit).
	RTCMON_RTCMOL = month /  1 % 10;		/// Set month(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaMonth function.
 *
 * @brief	The value of the month get from the register.
 *
 * @return	1 to 12			Return the get value.
 ***************************************************************************/
unsigned char getRtcaMonth( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCMON_RTCMOH * 10 + RTCMON_RTCMOL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaDay function.
 *
 * @brief	The day set in the register.
 *
 * @param	day				Set value.
 *	@li @c		1 to 31		day.
 *	@li @c		others		Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaDay( unsigned char day )
{
	if ( day < 1 || day > 31 ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCMON_RTCDH = day / 10 % 10;		/// Set day(tenths digit).
	RTCMON_RTCDL = day /  1 % 10;		/// Set day(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaDay function.
 *
 * @brief	The value of the day get from the register.
 *
 * @return	1 to 31			Return the set value.
 ***************************************************************************/
unsigned char getRtcaDay( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCMON_RTCDH * 10 + RTCMON_RTCDL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaWeek function.
 *
 * @brief	The week set in the register.
 *
 * @param	week			Set value.
 *	@li @c		RTCYAR_RTCWK_SUN	Sunday.
 *	@li @c		RTCYAR_RTCWK_MON	Monday.
 *	@li @c		RTCYAR_RTCWK_TUE	Tuesday.
 *	@li @c		RTCYAR_RTCWK_WED	Wednesday.
 *	@li @c		RTCYAR_RTCWK_THU	Thursday.
 *	@li @c		RTCYAR_RTCWK_FRI	Friday.
 *	@li @c		RTCYAR_RTCWK_SAT	Saturday.
 *	@li @c		others				Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaWeek( unsigned char week )
{
	if ( week > RTCYAR_RTCWK_SAT ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCYAR_RTCWK = week;				/// Set weak;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaWeek function.
 *
 * @brief	The value of the week get from the register.
 *
 * @retval	RTCYAR_RTCWK_SUN		Sunday.
 * @retval	RTCYAR_RTCWK_MON		Monday.
 * @retval	RTCYAR_RTCWK_TUE		Tuesday.
 * @retval	RTCYAR_RTCWK_WED		Wednesday.
 * @retval	RTCYAR_RTCWK_THU		Thursday.
 * @retval	RTCYAR_RTCWK_FRI		Friday.
 * @retval	RTCYAR_RTCWK_SAT		Saturday.
 ***************************************************************************/
unsigned char getRtcaWeek( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCYAR_RTCWK;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaHour function.
 *
 * @brief	The hour set in the register.
 *
 * @param	hour			Set value.
 *	@li @c		0 to 23		hour(24H mode).
 *	@li @c		1 to 12		hour(12H mode).
 *	@li @c		others		Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaHour( unsigned char hour )
{
	if ( getRtca24hMode() == RTCCTL_RTC24H_24H && hour > 23 ) {
		return STATUS_NG;
	}

	if ( getRtca24hMode() == RTCCTL_RTC24H_12H && ( hour < 1 || hour > 12 ) ) {
		return STATUS_NG;
	}


	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCHUR_RTCHH	= hour / 10 % 10;		/// Set hour(tenths digit).
	RTCHUR_RTCHL	= hour / 1  % 10;		/// Set hour(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaHour function.
 *
 * @brief	The value of the hour get from the register.
 *
 * @retval	0 to 23			Return the get value(24H mode).
 * @retval	1 to 12			Return the get value(12H mode).
 ***************************************************************************/
unsigned char getRtcaHour( void )
{
	unsigned char result = 0;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCHUR_RTCHH * 10 + RTCHUR_RTCHL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaMinute function.
 *
 * @brief	The minute set in the register.
 *
 * @param	minute				Set value.
 *	@li @c		0 to 59			minute.
 *	@li @c		others			Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaMinute( unsigned char minute )
{
	if ( minute > 59 ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCHUR_RTCMIH = minute / 10 % 10;	/// Set minute(tenths digit).
	RTCHUR_RTCMIL = minute /  1 % 10;	/// Set minute(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaMinute function.
 *
 * @brief	The value of the minute get from the register.
 *
 * @return	0 to 59			Return the get value.
 ***************************************************************************/
unsigned char getRtcaMinute( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCHUR_RTCMIH * 10 + RTCHUR_RTCMIL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaSecond function.
 *
 * @brief	The second set in the register.
 *
 * @param	second				Set value.
 *	@li @c		0 to 59			second.
 *	@li @c		others			Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaSecond( unsigned char second )
{
	if ( second > 59 ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCSEC_RTCSH = second / 10 % 10;	/// Set second(tenths digit).
	RTCSEC_RTCSL = second /  1 % 10;	/// Set second(unit digit).

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaSecond function.
 *
 * @brief	The value of the second get from the register.
 *
 * @return	0 to 59			Return the get value.
 ***************************************************************************/
unsigned char getRtcaSecond( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCSEC_RTCSH * 10 + RTCSEC_RTCSL;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * setRtcaIndicator function.
 *
 * @brief	The AM/PM set in the register(12H mode).
 *
 * @param	week			Set value.
 *	@li @c		RTCHUR_RTCAP_AM		A.M.
 *	@li @c		RTCHUR_RTCAP_PM		P.M.
 *	@li @c		others				Nothing is done.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
int setRtcaIndicator( unsigned char indicator )
{
	if ( indicator > RTCHUR_RTCAP_PM ) {
		return STATUS_NG;
	}

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Set value.
	RTCHUR_RTCAP = indicator;				/// Set AM/PM;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return STATUS_OK;
}


/****************************************************************************
 * getRtcaIndicator function.
 *
 * @brief	The value of the week get from the register.
 *
 * @retval	RTCHUR_RTCAP_AM			A.M.
 * @retval	RTCHUR_RTCAP_PM			P.M.
 ***************************************************************************/
unsigned char getRtcaIndicator( void )
{
	unsigned char result;

	/// Check busy.
	while ( RTCCTL_RTCBSY == 1 ) {
		// Wait...
	}

	/// Hold RTCA count-up.
	RTCCTL_RTCHLD = 1;

	/// Get value.
	result = RTCHUR_RTCAP;

	/// Resume RTCA count-up.
	RTCCTL_RTCHLD = 0;

	return result;
}


/****************************************************************************
 * initSw 	function.
 *
 * @brief	Firstly, stop stopwatch.
 *			Secondarily, initialize registers.
 *
 * @retval	STATUS_OK	Success.
 * @retval	STATUS_NG	Failed.
 ***************************************************************************/
unsigned char initSw( void )
{
	/// When OSC1 doesn't start, nothing is done.
		if ( CLGOSC_OSC1EN == 0 ) {
			return STATUS_NG;
		}

		/// Stop stopwatch.
		disableSw();
		stopSw();

		/// Reset stopwatch counter.
		RTCSWCTL_SWRST = 1;

		/// Initialize global variables.
		swCount.swInt1HzCount = 0;
		swCount.swChar10HzDigit = 0;
		swCount.swChar100HzDigit = 0;

		/// Set interrupt level.
		ILVRTCA_0 = INTERRUPT_LEVEL3;

		return STATUS_OK;
}


/****************************************************************************
 * startSw function.
 *
 * @brief	Start stopwatch.
 ***************************************************************************/
void startSw( void )
{
	RTCSWCTL_SWRUN = 1;
}


/****************************************************************************
 * stopSw function.
 *
 * @brief	Stop stopwatch.
 ***************************************************************************/
void stopSw( void )
{
	RTCSWCTL_SWRUN = 0;
}


/****************************************************************************
 * enableSw function.
 *
 * @brief	Enable stopwatch interrupts.
 ***************************************************************************/
void enableSw( void )
{
	/// Clear global variables.
	swCount.swInt1HzCount 		= 0;
	swCount.swChar10HzDigit 	= 0;
	swCount.swChar100HzDigit 	= 0;

	/// Clear interrupt flag.
	// RTCINTF_SW1IF 	= 1;
	// RTCINTF_SW10IF 	= 1;
	// RTCINTF_SW100IF 	= 1;
	RTCINTF = 0x7000;

	/// Enable stopwatch interrupts.
	// RTCINTE_SW1IE 	= 1;
	// RTCINTE_SW10IE 	= 1;
	// RTCINTE_SW100IE 	= 1;
	RTCINTE = RTCINTE | 0x7000;
}


/****************************************************************************
 * disableSw function.
 *
 * @brief	Disable stopwatch interrupts.
 ***************************************************************************/
void disableSw( void )
{
	/// Disable stopwatch interrupts.
	// RTCINTE_SW1IE 	= 0;
	// RTCINTE_SW10IE 	= 0;
	// RTCINTE_SW100IE 	= 0;
	RTCINTE = RTCINTE & 0x8fff;

	/// Clear interrupt flags.
	// RTCINTF_SW1IF 	= 1;
	// RTCINTF_SW10IF 	= 1;
	// RTCINTF_SW100IF 	= 1;
	RTCINTF = 0x7000;
}


/****************************************************************************
 * readSwCount function.
 *
 * @brief	10Hz digit and 100Hz digit of stopwatch counts are read.
 ***************************************************************************/
unsigned short int readSwCount(void )
{
	unsigned short int regRtcSwCtl[3];

	/// Read RTCSWCTL register consecutively.
	regRtcSwCtl[0] = RTCSWCTL;
	regRtcSwCtl[1] = RTCSWCTL;
	regRtcSwCtl[2] = RTCSWCTL;

	/// Compare read results and return their matched results.
	if(regRtcSwCtl[0] == regRtcSwCtl[1]){
		return regRtcSwCtl[0];
	}
	else if(regRtcSwCtl[1] == regRtcSwCtl[2]){
		return regRtcSwCtl[1];
	}
	else{
		asm( "brk" );
		asm( "nop" );
		return STATUS_NG;
	}
}


/****************************************************************************
 * getSw1HzCount function.
 *
 * @brief	Get stopwatch 1Hz count updated by stopwatch interrupts.
 *
 * @return	stopwatch 1Hz Count
 ***************************************************************************/
unsigned int getSw1HzCount( void )
{
	return swCount.swInt1HzCount;
}
