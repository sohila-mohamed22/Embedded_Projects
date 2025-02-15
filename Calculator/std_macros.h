/*
 * std_macros.h
 *
 * Created: 10/6/2023 10:05:52 PM
 *  Author: sohila mohamed
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define SET_BIT(reg,bit) reg |=(1<<bit)
#define CLEAR_BIT(reg,bit) reg &=~(1<<bit)
#define TOG_BIT(reg,bit) reg ^=(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#endif /* STD_MACROS_H_ */