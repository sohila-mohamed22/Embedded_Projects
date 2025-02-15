/*
 * seven_segment.h
 *
 * Created: 2/16/2024 6:15:50 PM
 *  Author: sohila mohamed
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
void seven_seg_vinit(unsigned char port_name);
void seven_seg_vwrite(unsigned char port_name,unsigned char number);
#endif /* SEVEN_SEGMENT_H_ */