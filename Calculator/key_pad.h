/*
 * key_pad.h
 *
 * Created: 2/24/2024 12:22:53 AM
 *  Author: sohila mohamed
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_
#include "DIO.h"
#define KEY_PAD_PORT 'D'
#define NOT_PRESSED 0xff 
void keypad_vinit(void);
char keypad_u8check_press(void);
#endif /* KEY_PAD_H_ */