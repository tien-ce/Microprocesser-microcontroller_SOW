/*
 * LED7_SEGMENT.h
 *
 *  Created on: Sep 2, 2024
 *      Author: thuyh
 */
#include "main.h"
#ifndef ___LED7_SEGMENT_H_
#define ___LED7_SEGMENT_H_
void DISPLAY_LED_7_SEGMENT(GPIO_TypeDef* GPIOx,uint16_t LED_7_0,uint16_t LED_7_1,uint16_t LED_7_2,uint16_t LED_7_3,uint16_t LED_7_4
		,uint16_t LED_7_5,uint16_t LED_7_6 ,uint8_t digit);
void SET_EN_7_SEGMENT(GPIO_TypeDef* GPIOx,uint16_t EN1,uint16_t EN2,uint16_t EN3,uint16_t EN4,int num);
void DISPLAY_LED_7_SEGMENT_PREMIUM(GPIO_TypeDef* GPIOx1[], uint16_t LED1_Pin[],int digit);
#endif /* INC_LED7_SEGMENT_H_ */
