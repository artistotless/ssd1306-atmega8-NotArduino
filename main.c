/*
* i2cLCD.c
*
* Created: 13.05.2018 12:41:46
* Author : digun
*/

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "twi.h"
#include "LCD_I2C.h"




static unsigned char buffer[128*64/8] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0x70, 0x70, 0x70,
	0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x70,
	0x70, 0x70, 0xE0, 0xE0, 0xC0, 0xC0, 0x80, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0x3E, 0x1F,
	0x07, 0x03, 0x01, 0xC1, 0xE0, 0xE0, 0xC0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xC0, 0xE0, 0xE0, 0xE0, 0xC1, 0x03, 0x07, 0x0F,
	0x3E, 0xFC, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xC1, 0xC3, 0x83, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x81, 0xC1, 0x81, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x01, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0F, 0x1F, 0x7F, 0xF8, 0xE0,
	0xC0, 0x80, 0x00, 0x01, 0x07, 0x0F, 0x1F, 0x1C,
	0x3C, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x3E,
	0x1F, 0x0F, 0x07, 0x03, 0x00, 0x80, 0xC0, 0xE0,
	0xF8, 0x7F, 0x1F, 0x0F, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x03, 0x07, 0x07, 0x0E, 0x1E, 0x1C, 0x1C, 0x3C,
	0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C,
	0x1C, 0x1C, 0x1E, 0x0E, 0x07, 0x07, 0x03, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};



void delay(short int cnt){
	for (int i =0;i<cnt;i++){
		_delay_ms(1);
	}
}



int main(void)
{
	
	DDRD |= (1<<1);
	
	I2C_Init();
	lcdInit();

	//��������� ������������� - 100 ( ����. 255)
	lcdSendCommand(0x81);
	lcdSendCommand(100);

	lcdClearDisplay();


	//����� ������ ��������� - ��������������
	lcdSendCommand(0x20);
	lcdSendCommand(0x0);

	// ����� �������
	//lcdSelectSeg(0,39);
	lcdSelectSeg(10,110);

	//����� ��������
	//lcdSelectPage(3,7);
	lcdSelectPage(3,3);

	lcdSendCommand(0xA1);
	lcdSendCommand(0xC8);

	//�������� ���-��������

	unsigned char color = 0xFF;
	int smooth = 2;

	//lcdBufferDisplay();


	for(int i = 0;i<14; i++ ){
	lcdSendData(color);
	delay(smooth);
	lcdSendData(color);
	delay(smooth);
	lcdSendData(0);
	lcdSendData(0);
	delay(smooth);
	lcdSendData(color);
	delay(smooth);
	lcdSendData(color);
	
	if(i == 13){
		
	i=0;
	if(color == 0xFF){
PORTD &= (0<<1);
	color = 0x00;
	smooth = 2;
	}else{
		PORTD |= (1<<1);
	color = 0xFF;
	smooth = 2;
	}
	lcdSelectSeg(10,110);
	}
	}


	while(1)
	{

	}
}