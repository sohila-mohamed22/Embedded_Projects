/*
 * calculator.c
 *
 * Created: 4/5/2024 1:55:28 AM
 *  Author: sohila mohamed
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "key_pad.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
label:	keypad_vinit();
        LCD_vInit();
	    unsigned char arr[6]={NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED};
		unsigned char counter = 0 ;	
		signed short res ;
	while(1)
	{
     do 
	 {
		 arr[counter]=keypad_u8check_press();
	 }while(arr[counter]==NOT_PRESSED); 
	 if(arr[counter]=='-'||arr[counter]=='+')
	 {
		 LCD_vSend_char(arr[counter]);
         counter++;
		 do
		 {
			 arr[counter]=keypad_u8check_press();
		 }while(arr[counter]==NOT_PRESSED);
		 if(arr[counter]=='=')
		 {
			LCD_vClear_Screen();
			LCD_Movecursor(1,4);
			Send_vString("error");
			LCD_vClear_Screen();
			goto label; 
		 }
		 else if(arr[counter]=='-'||arr[counter]=='+')
		 {
		     if(arr[counter]=='=')
			 {
				 LCD_vClear_Screen();
				 LCD_Movecursor(1,4);
				 Send_vString("error");
				 _delay_ms(300);
				 LCD_vClear_Screen();
				 goto label;
			 } 
		     else if(arr[counter]=='A')
		     {
			    LCD_vClear_Screen();
		     }	
		    else
		    {
			   counter++;
			   do
			   {
				 arr[counter]=keypad_u8check_press();
			   }while(arr[counter]==NOT_PRESSED);	 
			   if(arr[counter]=='=')
			   {
					 LCD_vClear_Screen();
					 LCD_Movecursor(1,4);
					 Send_vString("error");
					 _delay_ms(300);
					 LCD_vClear_Screen();
					goto label;
			   }
		   }			 			   
		else if(arr[counter]=='A')
		{
			 LCD_vClear_Screen();
		}
		 else
		 {
			 counter++;
			 do
			 {
				 arr[counter]=keypad_u8check_press();
			 }while(arr[counter]==NOT_PRESSED);
			 if(arr[counter]=='=')
			 {
				 switch(arr[counter-2])
				 {
					 case'+':
					 LCD_Movecursor(2,16);
					 LCD_vSend_char(arr[counter-1]);
					 break;
					 case'-':
					 LCD_Movecursor(2,15);
					 LCD_vSend_char('-');
					 LCD_vSend_char(arr[counter-1]);
					 break;
				 }
				 _delay_ms(300);
				 goto label;					 
			 }				 
		 }
		}			 
		 }				 			 
		 }
		 
	 }
	 else if(arr[counter]=='A')
	 {
		 LCD_vClear_Screen();
	 }
	 else
	 {
		 LCD_vSend_char(arr[counter]);
		 _delay_ms(300);
		 counter++;
	 }	
     do
	  {
		  arr[counter]=keypad_u8check_press();
	   }while(arr[counter]==NOT_PRESSED);
	   LCD_vSend_char(arr[counter]);
	   _delay_ms(300);
	   if(arr[counter]=='*'||arr[counter]=='/'||arr[counter]=='-'||arr[counter]=='+'||arr[counter]=='=')
	   {
		  counter++;
		 do
		 {
		   arr[counter]=keypad_u8check_press();
		 }while(arr[counter]==NOT_PRESSED);
         LCD_vSend_char(arr[counter]);
		 _delay_ms(300);
	    if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='*'||arr[counter]=='/'||arr[counter]=='-'||arr[counter]=='+')
		{
			LCD_vClear_Screen();
			LCD_Movecursor(1,4);
			Send_vString("error");
			_delay_ms(500);
			LCD_vClear_Screen();
			goto label ;
		}
		else
		{
			counter++;
			_delay_ms(300);
		}
	    do
	    {
		    arr[counter]=keypad_u8check_press();
	     }while(arr[counter]==NOT_PRESSED);	
		 LCD_vSend_char(arr[counter]);
		 if(arr[counter]=='=')
		 {
			 switch(arr[counter-2])
			 {
				 case'+':
				 res = (arr[counter-3]-48)+(arr[counter-1]-48);
				 LCD_vSend_char(res+48);
				 break;
				 case'-':
				 res = (arr[counter-3]-48)-(arr[counter-1]-48);
				if((arr[counter-3]-48)<(arr[counter-1]-48))
				{
				   LCD_vSend_char('-');
				   LCD_vSend_char((-res)+48);
				}
				else
				{
				 LCD_vSend_char(res+48);
				}				 
				 break;
				 case'*':
				 res = (arr[counter-3]-48)*(arr[counter-1]-48);
				 if(res<10)
				 {
					 LCD_vSend_char(res+48);
				 }
				 else if (res>=10&&res<100)
				 {
					 LCD_vSend_char((res/10)+48);
					 LCD_vSend_char((res%10)+48);
				 }					 
				 break;
				 case'/':
				 if((arr[counter-1]-48)==0)
				 {
					 LCD_vClear_Screen();
					 Send_vString("    error");
					 _delay_ms(400);
					 LCD_vClear_Screen();
					 goto label ;
				 }
				 res = (arr[counter-3]-48)/(arr[counter-1]-48);
				 LCD_vSend_char(res+48);			 
				 break;	
				 default:
				 break;
			 }	
			 _delay_ms(500);
			 goto label ;			 				
	    }
		else 
		{
			_delay_ms(300);
			counter++;
		}
	    do
		 {
		     arr[counter]=keypad_u8check_press();
		  }while(arr[counter]==NOT_PRESSED);
		  LCD_vSend_char(arr[counter]);	
		  if(arr[counter]=='=')
		  {
			 switch(arr[counter-3])
			  {
				 case'+':
				  res = (arr[counter-4]-48)+((arr[counter-1]-48)*10)+(arr[counter-2]-48);
				  if (res>=10&&res<100)
				  {
					   LCD_vSend_char((res/10)+48);
					   LCD_vSend_char((res%10)+48);
				  }
				  else if(res<10)
				  {
					   LCD_vSend_char(res+48);
				  }
				  break;
				  case'-':
				  res = -((arr[counter-4]-48)-(((arr[counter-2]-48)*10)+(arr[counter-1]-48)));
				  LCD_vSend_char('-');
				  if (res>=10&&res<100)
				  {
					   LCD_vSend_char((res/10)+48);
					   LCD_vSend_char((res%10)+48);
				  }
				  else if(res<10)
				  {
					    LCD_vSend_char(res+48);
				  }
				  break;
				  case'*':
				  res = (arr[counter-4]-48)*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				  if(res>=100&&res<1000)
				  {
					  LCD_vSend_char((res/100)+48);
					  LCD_vSend_char(((res/10)%10)+48);
					  LCD_vSend_char((res%10)+48);
				  }
				  else if (res>=10&&res<100)
				  {
					  LCD_vSend_char((res/10)+48);
					  LCD_vSend_char((res%10)+48);
				  }
				  else if(res<10)
				  {
					  LCD_vSend_char(res+48);
				  }
				  break;
				  case'/':
				  if((arr[counter-1]-48)==0&&(arr[counter-2]-48)==0)
				  {
					  LCD_vClear_Screen();
					  LCD_Movecursor(1,4);
					  Send_vString("error");
					  _delay_ms(400);
					  LCD_vClear_Screen();
					  goto label ;
				  }
				  res = (arr[counter-4]-48)/((arr[counter-1]-48)*10)/(arr[counter-2]-48);
				  LCD_vSend_char(res+48);
				   break;
				   default:
				   break;
			  	 }
			  	_delay_ms(500);
			  	goto label ;
		  	 }		
		 }
		 		
	   else
	    {
		     counter++;
		     _delay_ms(300);
	    }
	   do
	    {
		   arr[counter]=keypad_u8check_press();
		}while(arr[counter]==NOT_PRESSED);
	    LCD_vSend_char(arr[counter]);
		if(arr[counter]=='-'||arr[counter]=='+'||arr[counter]=='*'||arr[counter]=='/')
		{
			counter++;
		    do
		    {
			   arr[counter]=keypad_u8check_press();
		     }while(arr[counter]==NOT_PRESSED);
		     LCD_vSend_char(arr[counter]);
			 _delay_ms(300);
			 if(arr[counter]=='='||arr[counter]=='-'||arr[counter]=='+'||arr[counter]=='*'||arr[counter]=='/')
			 {
				 LCD_vClear_Screen();
				 LCD_Movecursor(1,4);
				 Send_vString("error");
				 _delay_ms(500);
				 LCD_vClear_Screen();
				 goto label ; 
			 }
			 else
			 {
				 counter++;
				 _delay_ms(300);
			 }
			 do
			 {
				  arr[counter]=keypad_u8check_press();
			 }while(arr[counter]==NOT_PRESSED);
			 LCD_vSend_char(arr[counter]);
			 if(arr[counter]=='=')
			 {
				 switch(arr[counter-2])
				{
					case'+':
				    res = (arr[counter-1]-48)+((arr[counter-4]-48)*10)+(arr[counter-3]-48);
					if (res>=10&&res<100)
				    {
					     LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					}
				    else if(res<10)
					{
						 LCD_vSend_char(res+48);
					}
				    break;
				    case'-':
				    res = (arr[counter-1]-48)-(((arr[counter-4]-48)*10)+(arr[counter-3]-48));
					 if (res>=10&&res<100)
					{
						 LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					}
				    else if(res<10)
				    {
						 LCD_vSend_char(res+48);
					}
					break;
				    case'*':
					res = (arr[counter-1]-48)*(((arr[counter-4]-48)*10)+(arr[counter-3]-48));
				    if(res>=100&&res<1000)
					{
						 LCD_vSend_char((res/100)+48);
						 LCD_vSend_char(((res/10)%10)+48);
						 LCD_vSend_char((res%10)+48);
				    }
					else if (res>=10&&res<100)
					{
						 LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					 }
					else if(res<10)
					 {
						 LCD_vSend_char(res+48);
					 }
					 break;
					 case'/':
					 if((arr[counter-1]-48)==0&&(arr[counter-2]-48)==0)
					 {
						 LCD_vClear_Screen();
						 LCD_Movecursor(1,4);
						 Send_vString("error");
						 _delay_ms(400);
						 LCD_vClear_Screen();
						 goto label ;
					 }
					 res = (((arr[counter-4]-48)*10)+(arr[counter-3]-48))/(arr[counter-4]-48);
					 LCD_vSend_char(res+48);
					 break;
					 default:
					 break;
				   }
				   _delay_ms(500);
				 goto label ;
					 }
			else
			{
				counter++;
				_delay_ms(300);
			}
			 do
			 {
				 arr[counter]=keypad_u8check_press();
			 }while(arr[counter]==NOT_PRESSED);
			LCD_vSend_char(arr[counter]);	
		   if(arr[counter]=='=')
	    	{
			    switch(arr[counter-3])
			    {
					 case'+':
					 res = ((arr[counter-2]-48)*10)+(arr[counter-1]-48)+((arr[counter-5]-48)*10)+(arr[counter-4]-48);
					 if (res>=10&&res<100)
					 {
						 LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					 }
					 else if(res<10)
					 {
						 LCD_vSend_char(res+48);
					 }
					 break;
					 case'-':
					 res = ((arr[counter-2]-48)*10)+(arr[counter-1]-48)-((arr[counter-5]-48)*10)+(arr[counter-4]-48);
					 if((((arr[counter-2]-48)*10)+(arr[counter-1]-48))>(((arr[counter-5]-48)*10)+(arr[counter-4]-48)))
					 {
						 res = - res ;
						 LCD_vSend_char('-');
					 }
					 if (res>=10&&res<100)
					 {
						 LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					 }
					 else if(res<10)
					 {
						 LCD_vSend_char(res+48);
					 }
					 break;
					 case'*':
				     res = ((arr[counter-2]-48)*10)+(arr[counter-1]-48)*((arr[counter-5]-48)*10)+(arr[counter-4]-48);
					 if(res>=100&&res<1000)
					 {
						 LCD_vSend_char((res/100)+48);
						 LCD_vSend_char(((res/10)%10)+48);
						 LCD_vSend_char((res%10)+48);
					 }
					else if (res>=10&&res<100)
					 {
						 LCD_vSend_char((res/10)+48);
						 LCD_vSend_char((res%10)+48);
					 }
					 else if(res<10)
					 {
						 LCD_vSend_char(res+48);
					 }
					 break;
					 case'/':
					 if(((arr[counter-2]-48)*10)+(arr[counter-1]-48)==0)
					 {
						 LCD_vClear_Screen();
						 LCD_Movecursor(1,4);
						 Send_vString("error");
						 _delay_ms(400);
						 LCD_vClear_Screen();
						 goto label ;
					 }
					 res = ((arr[counter-2]-48)*10)+(arr[counter-1]-48)/((arr[counter-5]-48)*10)+(arr[counter-4]-48);
					LCD_vSend_char(res+48);
					 break;
					 default:
					 break;
					 }
					_delay_ms(500);
					 goto label ;
					 }
				
			} 
			 }
		}				 			  	 	  	
			  		  		  		  
 
		
