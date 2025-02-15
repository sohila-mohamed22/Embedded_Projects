/*
 * timer.c
 *
 * Created: 4/13/2024 9:42:15 PM
 *  Author: sohila mohamed
 */ 


#include "std_macros.h"
#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void timer0_CTC_init_interrupt()
{
	SET_BIT(TCCR0,WGM01);
	OCR0 = 80 ;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	sei() ;
	SET_BIT(TIMSK,OCIE0);
}
void timer0_wave_fastPWM()
{
	DIO_vset_pin_dir('B',3,1);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	OCR0 = 64 ;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
void timer0_wave_phasecorrectPWM()
{
	DIO_vset_pin_dir('B',3,1);
	SET_BIT(TCCR0,WGM00);
	OCR0 = 64 ;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
void timer2_overflow_init_interrupt()
{
	SET_BIT(ASSR,AS2);
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	sei() ;
	SET_BIT(TIMSK,TOIE2);
}