/*
 * button.h
 *
 * Created: 10/9/2023 6:41:00 PM
 *  Author: sohila mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
void button_vinit(unsigned char port_name , unsigned char port_number);
unsigned char button_u8read(unsigned char port_name , unsigned char port_number);
#endif /* BUTTON_H_ */