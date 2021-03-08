/*
* ssd1306.c
*
* Created: 04.03.2021 21:28:16
*  Author: User
*/
#include "avr/delay.h"

void commandBytes(){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b00000000); // байт управления (0 - Комманды)
}
void dataBytes(){
	I2C_StartCondition();
	I2C_SendByte(0b01111000); // байт адреса ( 0 - Запись)
	I2C_SendByte(0b01000000); // байт управления (0 - Данные)
}
void lcdSendCommand(unsigned char cmd){
	commandBytes();
	I2C_SendByte(cmd);
	I2C_StopCondition();
}

// Вывод текста
void lcdTextDisplay(char * text){
	
	dataBytes();
	int indexByte = 0;
	
	unsigned char * ascii_symbols1 = getAsciiSymbols();
	unsigned char * ascii_bytes1 = getAsciiBytes();
	
	int j = 1;
	
	
	for(int i=0; i<strlen(text); i++){
		for(int j=0;j<95;j++){
			if(text[i] == ascii_symbols1[j]){
				indexByte=j*5;
				for(int k=indexByte;k<indexByte+5;k++){
					I2C_SendByte(ascii_bytes1[k]);
				}
			}
		}
	}
	
	I2C_StopCondition();

}

 


// Отправка байтов на дисплей
void lcdSendData(unsigned char data){
	dataBytes();
	I2C_SendByte(data);
	I2C_StopCondition();
}

// Очистка дисплея
void lcdClearDisplay(){
	dataBytes();
	for(int i =0; i< 128*64/8;i++){
		lcdSendData(0x00);
	}

	I2C_StopCondition();
}

// Выбор столбца
void lcdSelectSeg(short int start, short int end){
	lcdSendCommand(0x21);
	lcdSendCommand(start);
	lcdSendCommand(end);
}

// Выбор строки
void lcdSelectPage(short int start, short int end){
	lcdSendCommand(0x22);
	lcdSendCommand(start);
	lcdSendCommand(end);
}


void lcdBufferDisplay(unsigned char * buffer){
	dataBytes();
	for(int i =0; i< 128*64/8;i++){
		
		lcdSendData(buffer[i]);
	}

	I2C_StopCondition();
}

//Инициализация дисплея
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
	_delay_ms(5);
}