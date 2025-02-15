/*
 * timer.h
 *
 * Created: 4/13/2024 10:19:16 PM
 *  Author: sohila mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_
void timer0_CTC_init_interrupt();
void timer0_wave_fastPWM();
void timer0_wave_phasecorrectPWM();
void timer2_overflow_init_interrupt();
#endif /* TIMER_H_ */