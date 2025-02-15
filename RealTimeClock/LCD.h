/*
 * LCD.h
 *
 * Created: 2/21/2024 3:19:48 PM
 *  Author: sohila mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCD_Configration.h"
#include "DIO.h"
#define CLEAR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define CURSOR_ON_DISPLAY_ON 0X0C
#define ROW_ONE_ADDRESS 0x80
#define ROW_TWO_ADDRESS 0xC0
#define DATA_PORT 'A'
#if defined eight_bit_mode
#define EN 0
#define RS 2
#define RW 1
#define EIGHT_BITS 0x38
#elif defined four_bit_mode
#define EN 0
#define RS 2
#define RW 1
#define FOUR_BITS 0x28
#endif
void LCD_vInit(void);
void send_falling_edge (void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void Send_vString(char* data);
void LCD_vClear_Screen (void);
void LCD_Movecursor(char row , char column);
#endif /* LCD_H_ */