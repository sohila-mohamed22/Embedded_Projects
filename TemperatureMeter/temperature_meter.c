/*
 * temperature_meter.c
 *
 * Created: 4/9/2024 5:41:52 PM
 *  Author: sohila mohamed
 */ 


#include "ADC.h"
#include "LCD.h"
unsigned short temperature , volt ;
int main(void)
{   
	LCD_vClear_Screen();
	ADC_vinit();
	LCD_vInit();
	Send_vString("Temperature: ");
    while(1)
    {
       volt = ADC_u16Read()*2.5;
	   if (volt>=1000)
	   {
		   temperature = (volt-1000)/10 ;
	       if(temperature<10)
	       {
		     LCD_Movecursor(1,13);
		     LCD_vSend_char(temperature+48);
		     LCD_vSend_char(0xDF);
		     LCD_vSend_char('C');
		     LCD_vSend_char(0x20);
	        }
	        else if(temperature<100)
	       { 
		     LCD_Movecursor(1,13);
		     LCD_vSend_char((temperature/10)+48);
		     LCD_vSend_char((temperature%10)+48);
		     LCD_vSend_char(0xDF);
		     LCD_vSend_char('C');
	        }		   		    
        }
		else
		{
			temperature = (1000-volt)/10 ; 
		    if(temperature<10)
		    {
			   LCD_Movecursor(1,13);
			   LCD_vSend_char('-');
			   LCD_vSend_char(temperature+48);
			   LCD_vSend_char(0xDF);
			   LCD_vSend_char('C');
			   LCD_vSend_char(0x20);
		     }
		    else if(temperature<100)
		    {
			    LCD_Movecursor(1,13);
				LCD_vSend_char('-');
				LCD_vSend_char((temperature/10)+48);
			    LCD_vSend_char((temperature%10)+48);
				LCD_vSend_char(0xDF);
				LCD_vSend_char('C');
			}
			
		}
}
	}