/*
 * ADC.c
 *
 * Created: 3/3/2024 2:17:02 PM
 *  Author: sohila mohamed
 */ 

#include <avr/io.h>
#include "std_macros.h"
void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,MUX4);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}
unsigned short ADC_u16Read(void)
{
	unsigned short read_val ;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);
	read_val = (ADCL);
	read_val |= (ADCH<<8);
	return read_val ;
}