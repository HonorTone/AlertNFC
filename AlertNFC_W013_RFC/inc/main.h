/*
 * main.h
 *
 *  Created on: 2016-7-25
 *      Author: Administrator
 */

#ifndef MAIN_H_
#define MAIN_H_

#define NULL    0

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned char u8;
typedef unsigned int u16;
void delay_ms(int time);
void delay_us(int time);
void cleanDateBuf(uchar *data,uchar len);



extern uchar dispAddData[20];
extern uchar dispDelData[20];

#endif /* MAIN_H_ */
