/*
 * LCD_I2C.h
 *
 * Created: 13.05.2018 18:51:37
 *  Author: digun
 */ 


#ifndef LCD_I2C_H_
#define LCD_I2C_H_
#include <stdio.h>
#include "twi.h"

#define BLACK                                         0
#define WHITE                                         1

#define SSD1306_LCDWIDTH                              128
#define SSD1306_LCDHEIGHT                             64

#define SSD1306_ADDRESS         0x3C
#define WRITE         0
#define CONTROL_BYTE_COMMAND    0 << DC_BIT
#define CONTROL_BYTE_DATA       1 << DC_BIT
#define DC_BIT                  6


/*Fundamental Command Table*/
#define SSD1306_SETCONTRAST                           0x81
#define RESET_CONTRAST                              0x7F
#define SSD1306_DISPLAYALLON_RESUME                   0xA4
#define SSD1306_DISPLAYALLON                          0xA5
#define SSD1306_NORMALDISPLAY                         0xA6
#define SSD1306_INVERTDISPLAY                         0xA7
#define SSD1306_DISPLAYOFF                            0xAE
#define SSD1306_DISPLAYON                             0xAF

/*Scrolling Command Table*/
#define SSD1306_RIGHT_HORIZONTAL_SCROLL               0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL                0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL  0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL   0x2A
#define SSD1306_DEACTIVATE_SCROLL                     0x2E
#define SSD1306_ACTIVATE_SCROLL                       0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA              0xA3
#define RESET_TOP_ROW                                  0
#define RESET_ROWS_NUMBER                             64

/*Addressing Setting Command Table*/
#define SSD1306_SETLOWCOLUMN                          0x00
#define RESET_LOWER_NIBBLE                          0x00
#define SSD1306_SETHIGHCOLUMN                         0x10
#define RESET_HIGHER_NIBBLE                         0x00
#define SSD1306_MEMORYMODE                            0x20
#define HORIZONTAL_ADDRESSING                       0x00
#define VERTICAL_ADDRESSING                         0x01
#define PAGE_ADDRESSING                             0x02
#define SSD1306_COLUMNADDR                            0x21
#define RESET_COLUMNADDR                            0x00
#define SSD1306_PAGEADDR                              0x22
#define RESET_PAGEADDR                              0x00
#define SSD1306_PAGESTARTADDR                         0xB0
#define PAGE0                                       0x00
#define PAGE1                                       0x01
#define PAGE2                                       0x02
#define PAGE3                                       0x03
#define PAGE4                                       0x04
#define PAGE5                                       0x05
#define PAGE6                                       0x06
#define PAGE7                                       0x07

/*Hardware Configuration Command Table*/
#define SSD1306_SETSTARTLINE                          0x40
#define RESET_STARTLINE                             0x00
#define SSD1306_SEGREMAP                              0xA0
#define SEGREMAP_OFF                                0x00
#define SEGREMAP_ON                                 0x01
#define SSD1306_SETMULTIPLEX                          0xA8
#define RESET_MUX_RATIO                             0x3F
#define SSD1306_COMSCANINC                            0xC0
#define SSD1306_COMSCANDEC                            0xC8
#define SSD1306_SETDISPLAYOFFSET                      0xD3
#define RESET_OFFSET                                0x00
#define SSD1306_SETCOMPINS                            0xDA
#define RESET_SETCOMPINS                            0x12

/*Timing & Driving Scheme Setting Command Table*/
#define SSD1306_SETDISPLAYCLOCKDIV                    0xD5
#define RESET_CLOCKDIV                              0x80
#define SSD1306_SETPRECHARGE                          0xD9
#define RESET_PRECHARGE                             0x22
#define SSD1306_SETVCOMDETECT                         0xDB
#define RESET_SETVCOMDETECT                         0x20

/*Charge Pump Setting Command Table*/
#define SSD1306_CHARGEPUMP                            0x8D
#define CHARGEPUMP_DISABLE                          0x10
#define CHARGEPUMP_ENABLE                           0x14


#endif /* LCD_I2C_H_ */