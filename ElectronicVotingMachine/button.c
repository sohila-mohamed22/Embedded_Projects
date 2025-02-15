/*
 * button.c
 *
 * Created: 10/9/2023 6:35:36 PM
 *  Author: sohila mohamed
 */ 


#include <avr/io.h>
#include "DIO.h"

void button_vinit(unsigned char port_name , unsigned char port_number)
{
	DIO_vset_pin_dir(port_name , port_number , 0);
}
unsigned char button_u8read(unsigned char port_name , unsigned char port_number)
{
	return(DIO_u8read_pin(port_name,port_number));
}
