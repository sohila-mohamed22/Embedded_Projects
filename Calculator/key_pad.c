/*
 * key_pad.c
 *
 * Created: 2/23/2024 8:20:20 PM
 *  Author: sohila mohamed
 */ 


#include "key_pad.h"
void keypad_vinit(void)
{
	DIO_vset_pin_dir(KEY_PAD_PORT,0,1);
	DIO_vset_pin_dir(KEY_PAD_PORT,1,1);
	DIO_vset_pin_dir(KEY_PAD_PORT,2,1);
	DIO_vset_pin_dir(KEY_PAD_PORT,3,1);
	DIO_vset_pin_dir(KEY_PAD_PORT,4,0);
	DIO_vset_pin_dir(KEY_PAD_PORT,5,0);
	DIO_vset_pin_dir(KEY_PAD_PORT,6,0);
	DIO_vset_pin_dir(KEY_PAD_PORT,7,0);
	DIO_vconnect_pullup(KEY_PAD_PORT,4,1);
	DIO_vconnect_pullup(KEY_PAD_PORT,5,1);
	DIO_vconnect_pullup(KEY_PAD_PORT,6,1);
	DIO_vconnect_pullup(KEY_PAD_PORT,7,1);
}
char keypad_u8check_press(void)
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char row , column , x ;
	char return_value = NOT_PRESSED;
	for(row=0 ; row<=3 ; row++)
	{
		DIO_vwrite_pin(KEY_PAD_PORT,0,1);
		DIO_vwrite_pin(KEY_PAD_PORT,1,1);
		DIO_vwrite_pin(KEY_PAD_PORT,2,1);
		DIO_vwrite_pin(KEY_PAD_PORT,3,1);
		DIO_vwrite_pin(KEY_PAD_PORT,row,0);
		for(column=0 ; column<=3 ; column++)
		{
			x = DIO_u8read_pin(KEY_PAD_PORT,column+4);
			if(x==0)
			{
				return_value = arr[row][column];
				break;
			}
		}
		if(x==0)
		{
			break;
		}
	}
	return return_value ;
}