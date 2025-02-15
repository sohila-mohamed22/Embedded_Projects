/*
 * seven_segment.c
 *
 * Created: 2/16/2024 6:03:19 PM
 *  Author: sohila mohamed
 */ 


#include "DIO.h"
void seven_seg_vinit(unsigned char port_name)
{
	DIO_vset_port_dir(port_name,0xFF);
}

void seven_seg_vwrite(unsigned char portname,unsigned char number)
{
unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};

DIO_vwrite_port(portname,arr[number]);
}