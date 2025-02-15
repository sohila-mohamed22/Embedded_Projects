/*
 * real_time_clock.c
 *
 * Created: 4/14/2024 8:46:33 PM
 *  Author: sohila mohamed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "key_pad.h"
#include "timer.h"
#include "seven_segment.h"

volatile unsigned char seconds_counter = 0 ;
volatile unsigned char minutes_counter =0 ;
volatile unsigned char hours_counter = 0 ;
volatile unsigned char counter = 0 ;
unsigned char num=NOT_PRESSED ;
unsigned char hour[] ={NOT_PRESSED,NOT_PRESSED} ;
unsigned char minute[] ={NOT_PRESSED,NOT_PRESSED} ;
unsigned char second[] ={NOT_PRESSED,NOT_PRESSED} ;
int main(void)
{
	LCD_vInit();
	keypad_vinit();
	timer2_overflow_init_interrupt();
	seven_seg_vinit('B');
	DIO_vset_pin_dir('C',0,1);
	DIO_vset_pin_dir('C',1,1);
	DIO_vset_pin_dir('C',2,1);
	DIO_vset_pin_dir('C',3,1);
	DIO_vset_pin_dir('C',4,1);
	DIO_vset_pin_dir('C',5,1);
	Send_vString("press 1 to");
	LCD_Movecursor(2,1);
	Send_vString("set clock");
    while(1)
    {
	  num = keypad_u8check_press();
	  if(seconds_counter==60)
	  {
		  seconds_counter = 0 ;
		  minutes_counter++ ;
		  if(minutes_counter==60)
		  {
			  minutes_counter = 0 ;
			  hours_counter++;
		  }			  
	  }
	  DIO_vwrite_pin('C',0,0);
	  DIO_vwrite_pin('C',1,1);
	  DIO_vwrite_pin('C',2,1);
	  DIO_vwrite_pin('C',3,1);
	  DIO_vwrite_pin('C',4,1);
	  DIO_vwrite_pin('C',5,1);
	  seven_seg_vwrite('B',seconds_counter%10);
	  _delay_ms(6);
	  DIO_vwrite_pin('C',0,1);
	  DIO_vwrite_pin('C',1,0);
	  DIO_vwrite_pin('C',2,1);
	  DIO_vwrite_pin('C',3,1);
	  DIO_vwrite_pin('C',4,1);
	  DIO_vwrite_pin('C',5,1);
	  seven_seg_vwrite('B',seconds_counter/10);
	  _delay_ms(6);
	  DIO_vwrite_pin('C',0,1);
	  DIO_vwrite_pin('C',1,1);
	  DIO_vwrite_pin('C',2,0);
	  DIO_vwrite_pin('C',3,1);
	  DIO_vwrite_pin('C',4,1);
	  DIO_vwrite_pin('C',5,1);
	  seven_seg_vwrite('B',minutes_counter%10);
	  _delay_ms(6);
	  DIO_vwrite_pin('C',0,1);
	  DIO_vwrite_pin('C',1,1);
	  DIO_vwrite_pin('C',2,1);
	  DIO_vwrite_pin('C',3,0);
	  DIO_vwrite_pin('C',4,1);
	  DIO_vwrite_pin('C',5,1);
	  seven_seg_vwrite('B',minutes_counter/10);
	  _delay_ms(6);
	  DIO_vwrite_pin('C',0,1);
	  DIO_vwrite_pin('C',1,1);
	  DIO_vwrite_pin('C',2,1);
	  DIO_vwrite_pin('C',3,1);
	  DIO_vwrite_pin('C',4,0);
	  DIO_vwrite_pin('C',5,1);
	  seven_seg_vwrite('B',hours_counter%10);
	  _delay_ms(6);
	  DIO_vwrite_pin('C',0,1);
	  DIO_vwrite_pin('C',1,1);
	  DIO_vwrite_pin('C',2,1);
	  DIO_vwrite_pin('C',3,1);
	  DIO_vwrite_pin('C',4,1);
	  DIO_vwrite_pin('C',5,0);
	  seven_seg_vwrite('B',hours_counter/10);
	  _delay_ms(6);
	  if(num!=NOT_PRESSED)
	  {
		  _delay_ms(200);
		  if(num!='1')
		  {
			  LCD_vClear_Screen();
			  Send_vString("wrong number");
			  _delay_ms(500);
			  LCD_vClear_Screen();
			  Send_vString("press 1 to");
			  LCD_Movecursor(2,1);
			  Send_vString("set clock");
		  }	
		  else
		  { 
			  LCD_vClear_Screen();
			  Send_vString("hour = ");
			  do 
			  {
				 hour[counter] = keypad_u8check_press(); 
			  } while(hour[counter]==NOT_PRESSED);
			  if(hour[counter]=='A' || hour[counter]=='=' || hour[counter]=='+' || hour[counter]=='-' || hour[counter]=='/' || hour[counter]=='*')
			  {
				  LCD_Movecursor(1,8);
				  LCD_vSend_char(hour[counter]);
				  _delay_ms(300);
				  LCD_vClear_Screen();
				  Send_vString("wrong number");
				  _delay_ms(500);
				  LCD_vClear_Screen();
				  Send_vString("press 1 to");
				  LCD_Movecursor(2,1);
				  Send_vString("set clock");
			  }
			  else
			  {
				  _delay_ms(200);
				  LCD_Movecursor(1,8);
				  LCD_vSend_char(hour[counter]);
				  counter++ ;
				  do
				  {
					  hour[counter] = keypad_u8check_press();
				   }while(hour[counter]==NOT_PRESSED);
			       if(hour[counter]=='A' || hour[counter]=='=' || hour[counter]=='+' || hour[counter]=='-' || hour[counter]=='/' || hour[counter]=='*')
			       	{
						LCD_vSend_char(hour[counter]);
						counter = 0 ;
				       	_delay_ms(300);
				       	LCD_vClear_Screen();
				       	Send_vString("wrong number");
				       	_delay_ms(500);
				       	LCD_vClear_Screen();
				       	Send_vString("press 1 to");
				        LCD_Movecursor(2,1);
				       	Send_vString("set clock");
			      	}
				   else
					{
						LCD_vSend_char(hour[counter]); 
						counter = 0 ;
						_delay_ms(500);
						LCD_vClear_Screen();  
						Send_vString("minute = ");
						do
						{
						     minute[counter] = keypad_u8check_press();
						}while(minute[counter]==NOT_PRESSED);
						if(minute[counter]=='A' || minute[counter]=='=' || minute[counter]=='+' || minute[counter]=='-' || minute[counter]=='/' || minute[counter]=='*')
						 {
							 LCD_Movecursor(1,8);
							 LCD_vSend_char(minute[counter]);
							 _delay_ms(300);
							 LCD_vClear_Screen();
							 Send_vString("wrong number");
							 _delay_ms(500);
							 LCD_vClear_Screen();
							 Send_vString("press 1 to");
							 LCD_Movecursor(2,1);
							 Send_vString("set clock");
						 }
						 else
						 {
							 _delay_ms(200);
							 LCD_Movecursor(1,8);
							 LCD_vSend_char(minute[counter]);
							 counter++ ;
							 do
							 {
								 minute[counter] = keypad_u8check_press();
							 }while(minute[counter]==NOT_PRESSED);
							 if(minute[counter]=='A' || minute[counter]=='=' || minute[counter]=='+' || minute[counter]=='-' || minute[counter]=='/' || minute[counter]=='*')
							 {
								 LCD_vSend_char(minute[counter]);
								 counter = 0 ;
								 _delay_ms(300);
								 LCD_vClear_Screen();
								 Send_vString("wrong number");
								 _delay_ms(500);
								 LCD_vClear_Screen();
								 Send_vString("press 1 to");
								 LCD_Movecursor(2,1);
								 Send_vString("set clock");
							 }
							    else
							    {
								    LCD_vSend_char(minute[counter]);
								    counter = 0 ;
								    _delay_ms(500);
								    LCD_vClear_Screen();
								    Send_vString("second = ");
										do
										{
											second[counter] = keypad_u8check_press();
										}while(second[counter]==NOT_PRESSED);
										if(second[counter]=='A' || second[counter]=='=' || second[counter]=='+' || second[counter]=='-' || second[counter]=='/' || second[counter]=='*')
										{
											LCD_Movecursor(1,8);
											LCD_vSend_char(second[counter]);
											_delay_ms(300);
											LCD_vClear_Screen();
											Send_vString("wrong number");
											_delay_ms(500);
											LCD_vClear_Screen();
											Send_vString("press 1 to");
											LCD_Movecursor(2,1);
											Send_vString("set clock");
										}
										else
										{
											_delay_ms(200);
											LCD_Movecursor(1,8);
											LCD_vSend_char(second[counter]);
											counter++ ;
											do
											{
												second[counter] = keypad_u8check_press();
											}while(second[counter]==NOT_PRESSED);
											if(second[counter]=='A' || second[counter]=='=' || second[counter]=='+' || second[counter]=='-' || second[counter]=='/' || second[counter]=='*')
											{
												LCD_vSend_char(second[counter]);
												counter = 0;
												_delay_ms(300);
												LCD_vClear_Screen();
												Send_vString("wrong number");
												_delay_ms(500);
												LCD_vClear_Screen();
												Send_vString("press 1 to");
												LCD_Movecursor(2,1);
												Send_vString("set clock");
											}
											    else
											    {
												    LCD_vSend_char(second[counter]);
													_delay_ms(200);
												    counter = 0 ;
													if(((hour[counter]-48)*10)+(hour[counter+1]-48)>23)
													{
														LCD_vClear_Screen();
														LCD_Movecursor(1,5);
														Send_vString("error");
														LCD_Movecursor(2,1);
														Send_vString("hours exceed 23");
														_delay_ms(500);
														LCD_vClear_Screen();
														Send_vString("press 1 to");
														LCD_Movecursor(2,1);
														Send_vString("set clock");
													}
													else if(((minute[counter]-48)*10)+(minute[counter+1]-48)>59)
													{
															LCD_vClear_Screen();
															LCD_Movecursor(1,5);
															Send_vString("error");
															LCD_Movecursor(2,1);
															Send_vString("minutes exceed 59");
															_delay_ms(500);
															LCD_vClear_Screen();
															Send_vString("press 1 to");
															LCD_Movecursor(2,1);
															Send_vString("set clock");
													}
													else if(((second[counter]-48)*10)+(second[counter+1]-48)>59)
													{
															LCD_vClear_Screen();
															LCD_Movecursor(1,5);
															Send_vString("error");
															LCD_Movecursor(2,1);
															Send_vString("seconds exceed 59");
															_delay_ms(500);
															LCD_vClear_Screen();
															Send_vString("press 1 to");
															LCD_Movecursor(2,1);
															Send_vString("set clock");
													}
													else
													{
															hours_counter = ((hour[counter]-48)*10)+(hour[counter+1]-48);
															minutes_counter = ((minute[counter]-48)*10)+(minute[counter+1]-48);
															seconds_counter = ((second[counter]-48)*10)+(second[counter+1]-48);
															LCD_vClear_Screen();
															Send_vString("press 1 to");
															LCD_Movecursor(2,1);
															Send_vString("set clock");
													}
												
												
			                                	}																
					}						 
			  }
			    				  
		  }			  		  
	  }
	  
    }
										}
								}
							 }
						 }							 																			

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}
