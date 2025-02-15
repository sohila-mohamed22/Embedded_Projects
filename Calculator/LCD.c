/*
 * LCD.c
 *
 * Created: 2/21/2024 3:18:52 PM
 *  Author: sohila mohamed
 */ 
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_vInit(void)
{
	_delay_ms(200);
	#if defined eight_bit_mode
	DIO_vset_port_dir(DATA_PORT,1);
	DIO_vset_pin_dir('B',EN,1);
	DIO_vset_pin_dir('B',RS,1);
	DIO_vset_pin_dir('B',RW,1);
	DIO_vwrite_pin('B',RW,0);
	LCD_vSend_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_vset_pin_dir(DATA_PORT,4,1);
	DIO_vset_pin_dir(DATA_PORT,5,1);
	DIO_vset_pin_dir(DATA_PORT,6,1);
	DIO_vset_pin_dir(DATA_PORT,7,1);
	DIO_vset_pin_dir('B',EN,1);
	DIO_vset_pin_dir('B',RS,1);
	DIO_vset_pin_dir('B',RW,1);
	DIO_vwrite_pin('B',RW,0);
	LCD_vSend_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}
void send_falling_edge (void)
{
	DIO_vwrite_pin('B',EN,1);
	_delay_ms(2);
	DIO_vwrite_pin('B',EN,0);
	_delay_ms(2);
}
void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bit_mode
	DIO_vwrite_port(DATA_PORT,cmd);
	DIO_vwrite_pin('B',RS,0);
	send_falling_edge();
	#elif defined four_bit_mode
	DIO_vwrite_high_nibble(DATA_PORT,(cmd>>4));
	DIO_vwrite_pin('B',RS,0);
	send_falling_edge();
	DIO_vwrite_high_nibble(cmd);
	send_falling_edge();
	#endif
	_delay_ms(1);
}
void LCD_vSend_char(char data)
{
	#if defined eight_bit_mode
	DIO_vwrite_port(DATA_PORT,data);
	DIO_vwrite_pin('B',RS,1);
	send_falling_edge();
	
	#elif defined four_bit_mode
	DIO_vwrite_high_nibble(DATA_PORT,data>>4);
	DIO_vwrite_pin('B',RS,1);
	send_falling_edge();
	DIO_vwrite_high_nibble(DATA_PORT,data);
	send_falling_edge();
	 #endif
	 _delay_ms(1);
}
void Send_vString(char* data)
{
	while((*data) != '\0')
	{
	  LCD_vSend_char(*data);
	  data++ ;	
	}
}
void LCD_vClear_Screen (void)
{
	LCD_vSend_cmd(CLEAR_SCREEN);
	_delay_ms(10);
}
void LCD_Movecursor(char row , char column)
{
	char data ;
	if((row<1)||(row>2)||(column<1)||(column>16))
	{
		data = ROW_ONE_ADDRESS ;
	}
	else if (row==1)
	{
		data = ROW_ONE_ADDRESS + column - 1 ;
	}
	else 
	{
		data = ROW_TWO_ADDRESS + column - 1 ;
	}	
	LCD_vSend_cmd(data);
	_delay_ms(1);
}