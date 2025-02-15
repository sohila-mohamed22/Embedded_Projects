/*
 * DIO.c
 *
 * Created: 10/19/2023 12:06:17 PM
 *  Author: sohila mohamed
 */ 


#include <avr/io.h>
#include "std_macros.h"

void DIO_vset_pin_dir(unsigned char port_name , unsigned char pin_number , unsigned char pin_direction)
{
	switch ( port_name )
	{
		case 'A':
		case 'a':
		if (pin_direction==1)
		{
			SET_BIT(DDRA,pin_number);
		}
		else
		{
			CLEAR_BIT(DDRA,pin_number);
		}
		break ;
		case 'B':
		case 'b':
		if (pin_direction==1)
		{
			SET_BIT(DDRB,pin_number);
		}
		else
		{
			CLEAR_BIT(DDRB,pin_number);
		}
		break ;
		case 'C':
		case 'c':
		if (pin_direction==1)
		{
			SET_BIT(DDRC,pin_number);
		}
		else
		{
			CLEAR_BIT(DDRC,pin_number);
		}
		break ;
		case 'D':
		case 'd':
		if (pin_direction==1)
		{
			SET_BIT(DDRD,pin_number);
		}
		else
		{
			CLEAR_BIT(DDRD,pin_number);
		}
		break ;
		default:
		break;
	}
	
}

void DIO_vwrite_pin(unsigned char port_name , unsigned char pin_number , unsigned char pin_value)
{
	switch ( port_name )
	{
		case 'A':
		case 'a':
		if (pin_value==1)
		{
			SET_BIT(PORTA,pin_number);
		}
		else
		{
			CLEAR_BIT(PORTA,pin_number);
		}
		break ;
		case 'B':
		case 'b':
		if (pin_value==1)
		{
			SET_BIT(PORTB,pin_number);
		}
		else
		{
			CLEAR_BIT(PORTB,pin_number);
		}
		break ;
		case 'C':
		case 'c':
		if (pin_value==1)
		{
			SET_BIT(PORTC,pin_number);
		}
		else
		{
			CLEAR_BIT(PORTC,pin_number);
		}
		break ;
		case 'D':
		case 'd':
		if (pin_value==1)
		{
			SET_BIT(PORTD,pin_number);
		}
		else
		{
			CLEAR_BIT(PORTD,pin_number);
		}
		break ;
		default:
		break;
	}
	
}

void DIO_vtoggle_pin(unsigned char port_name , unsigned char pin_number)
{
	switch ( port_name )
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin_number);
		break ;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin_number);
		break ;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin_number);
		break ;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin_number);
		break ;
		default:
		break;
	}
	
}
unsigned char DIO_u8read_pin (unsigned char port_name ,unsigned char pin_number)
{
	unsigned char val = 0 ;
	switch ( port_name )
	{
		case 'A':
		case 'a':
		val = READ_BIT(PINA,pin_number);
		break;
		case 'B':
		case 'b':
		val = READ_BIT(PINB,pin_number);
		break;
		case 'C':
		case 'c':
		val = READ_BIT(PINC,pin_number);
		break;
		case 'D':
		case 'd':
		val = READ_BIT(PIND,pin_number);
		break;
		default:
		break;
	}
	return val ;
}
void DIO_vset_port_dir(unsigned char port_name ,unsigned char direction)
{
	switch ( port_name )
	{
		case 'A':
		case 'a':
		DDRA = direction ;
		break ;
		case 'B':
		case 'b':
		DDRB = direction ;
		break ;
		case 'C':
		case 'c':
		DDRC = direction ;
		break ;
		case 'D':
		case 'd':
		DDRD = direction ;
		break ;
		default:
		break;
	}
}
void DIO_vwrite_port(unsigned char port_name ,unsigned char port_value)
{
	switch ( port_name )
	{
		case 'A':
		case 'a':
		PORTA = port_value ;
		break ;
		case 'B':
		case 'b':
		PORTB = port_value ;
		break ;
		case 'C':
		case 'c':
		PORTC = port_value ;
		break ;
		case 'D':
		case 'd':
		PORTD = port_value;
		break ;
		default:
		break;
	}
}
unsigned char DIO_read_port(unsigned char port_name)
{
	unsigned char val =0 ;
	switch ( port_name )
	{
		case 'A':
		case 'a':
		val  = PINA ;
		break;
		case 'B':
		case 'b':
		val  = PINB ;
		break;
		case 'C':
		case 'c':
		val  = PINC ;
		break;
		case 'D':
		case 'd':
		val  = PIND ;
		break;
		default:
		break;
	}
	return val ;
}
void DIO_toggle_port (unsigned char port_name)
{
	switch ( port_name )
	{
		case'A':
		case'a':
		PORTA = ~PORTA ;
		break;
		case'B':
		case'b':
		PORTA = ~PORTB ;
		break;
		case'C':
		case'c':
		PORTA = ~PORTC ;
		break;
		case'D':
		case'd':
		PORTA = ~PORTD ;
		break;
		default :
		break ;
	}
}
void DIO_vconnect_pullup(unsigned char port_name , unsigned char port_number , unsigned char connect)
{
	DIO_vwrite_pin(port_name,port_number,connect);
}
void DIO_vwrite_low_nibble(unsigned char port_name , unsigned char value)
{
	value &= 0x0F ;
	switch (port_name)
	{
		case'A':
		case'a':
		PORTA &=0xF0;
		PORTA |= value ;
		break; 
		case'B':
		case'b':
		PORTB &=0xF0;
		PORTB |= value ;
		break;
		case'C':
		case'c':
		PORTC &=0xF0;
		PORTC |= value ;
		break;
		case'D':
		case'd':
		PORTD &=0xF0;
		PORTD |= value ;
		break;		
	}
}
void DIO_vwrite_high_nibble(unsigned char port_name , unsigned char value)
{
	value <<= 4 ;
	switch (port_name)
	{
		case'A':
		case'a':
		PORTA &=0x0F;
		PORTA |= value ;
		break;
		case'B':
		case'b':
		PORTB &=0xF0;
		PORTB |= value ;
		break;
		case'C':
		case'c':
		PORTC &=0xF0;
		PORTC |= value ;
		break;
		case'D':
		case'd':
		PORTD &=0xF0;
		PORTD |= value ;
		break;
	}
}