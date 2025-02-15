/*
 * Electronic_voting_machine.c
 *
 * Created: 2/27/2024 5:08:21 PM
 *  Author: sohila mohamed
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "button.h"
#include "LCD.h"
unsigned char counter1 = 0 ;
unsigned char counter2 = 0 ;
unsigned char counter3 = 0 ;
unsigned char counter4 = 0 ;

int main(void)
{
	LCD_vInit();
	button_vinit('B',3);
	button_vinit('B',4);
	button_vinit('B',5);
	button_vinit('B',6);
	button_vinit('B',7);
	LCD_vSend_cmd(CURSOR_OFF_DISPLAY_ON);
	Send_vString("A=0");
	LCD_Movecursor(1,12);
	Send_vString("B=0");
	LCD_Movecursor(2,1);
	Send_vString("C=0");
	LCD_Movecursor(2,12);
	Send_vString("D=0");
    while(1)
    {
	    if(button_u8read('B',3)==1)
	 {
		 counter1++;
		 LCD_Movecursor(1,3);
		 if(counter1<10)
		 {
			 LCD_vSend_char(counter1+48);
		 }
		 else if(counter1<100)
		 {
			LCD_vSend_char((counter1/10)+48); 	
			LCD_vSend_char((counter1%10)+48);	
		 }		
	 }	
	 else if(button_u8read('B',4)==1)
	 {
		  counter2++;
		  LCD_Movecursor(1,14);
		  if(counter2<10)
		  {
			  LCD_vSend_char(counter2+48);
		  }
		  else if(counter2<100)
		  {
			  LCD_vSend_char(counter2/10+48);
			  LCD_vSend_char(counter2%10+48);
		  }
	 }	
	 else if(button_u8read('B',5)==1)
	  {
		  counter3++;
		  LCD_Movecursor(2,3);
		  if(counter3<10)
		  {
			  LCD_vSend_char(counter3+48);
		  }
		  else if(counter3<100)
		  {
			  LCD_vSend_char(counter3/10+48);
			  LCD_vSend_char(counter3%10+48);
		  }
	  }
	   else if(button_u8read('B',6)==1)
	   {
		   counter4++;
		   LCD_Movecursor(2,14);
		   if(counter4<10)
		   {
			   LCD_vSend_char(counter4+48);
		   }
		   else if(counter4<100)
		   {
			   LCD_vSend_char(counter4/10+48);
			   LCD_vSend_char(counter4%10+48);
		   }
	   }
	   else if(button_u8read('B',7)==1)
	   {
		  counter1=counter2=counter3=counter4=0;
		  LCD_vClear_Screen();
		  LCD_Movecursor(1,1);
		  Send_vString("A=0");
		  LCD_Movecursor(1,12);
		  Send_vString("B=0");
		  LCD_Movecursor(2,1);
		  Send_vString("C=0");
		  LCD_Movecursor(2,12);
		  Send_vString("D=0");
	   }
	   _delay_ms(170);
    }
}