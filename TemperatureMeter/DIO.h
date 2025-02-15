/*
 * DIO.h
 *
 * Created: 10/19/2023 12:09:05 PM
 *  Author: sohila mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_vset_pin_dir(unsigned char port_name , unsigned char pin_number , unsigned char pin_direction);
void DIO_vwrite_pin(unsigned char port_name , unsigned char pin_number , unsigned char pin_value);
void DIO_vtoggle_pin(unsigned char port_name , unsigned char pin_number);
unsigned char DIO_u8read_pin (unsigned char port_name ,unsigned char pin_number);
void DIO_vset_port_dir(unsigned char port_name ,unsigned char direction);
void DIO_vwrite_port(unsigned char port_name ,unsigned char port_value);
unsigned char DIO_read_port(unsigned char port_name);
void DIO_toggle_port (unsigned char port_name);
void DIO_vconnect_pullup(unsigned char port_name , unsigned char port_number , unsigned char connect);
void DIO_vwrite_low_nibble(unsigned char port_name , unsigned char value);
void DIO_vwrite_high_nibble(unsigned char port_name , unsigned char value);
#endif /* DIO_H_ */