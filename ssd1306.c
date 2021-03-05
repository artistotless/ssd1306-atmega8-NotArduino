/*
 * ssd1306.c
 *
 * Created: 04.03.2021 21:28:16
 *  Author: User
 */ 
#include "avr/delay.h"

void lcdSendCommand(unsigned char cmd){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b00000000); // байт управления (0 - Комманды)
	I2C_SendByte(cmd);
	I2C_StopCondition();
}

void lcdTextDisplay(char *text){
	for(int i =0; i< strlen(text); i++){
		
		lcdSendData(255);
		
	}
}

void lcdSendData(unsigned char data){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b01000000); // байт управления (1 - Данные)
	I2C_SendByte(data);
	I2C_StopCondition();
}

void lcdClearDisplay(){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b01000000); // байт управления (1 - Данные)
	
	for(int i =0; i< 128*64/8;i++){
		lcdSendData(0x00);
	}

	I2C_StopCondition();
}

void lcdSelectSeg(short int start, short int end){
		lcdSendCommand(0x21);
		lcdSendCommand(start);
		lcdSendCommand(end);
}

void lcdSelectPage(short int start, short int end){
	lcdSendCommand(0x22);
	lcdSendCommand(start);
	lcdSendCommand(end);
}

void lcdBufferDisplay(unsigned char * buffer){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b01000000); // байт управления (1 - Данные)
	
	for(int i =0; i< 128*64/8;i++){
		
		lcdSendData(buffer[i]);
	}

	I2C_StopCondition();
}

void lcdInit(){
	lcdSendCommand(0x8D);
	lcdSendCommand(0x14);
	lcdSendCommand(0x20);
	lcdSendCommand(0x00);
	lcdSendCommand(0xA0 | 0x01);
	lcdSendCommand(0xC8);
	lcdSendCommand(0x81);
	lcdSendCommand(100);
	lcdSendCommand(0xD9);
	lcdSendCommand(0xF1);
	lcdSendCommand(0xAF);
	_delay_ms(12);
}