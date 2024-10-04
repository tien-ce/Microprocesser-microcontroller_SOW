/*
 * LED.h
 *
 *  Created on: Sep 4, 2024
 *      Author: thuyh
 */
#include "main.h"
#ifndef INS_LED_H_
#define INS_LED_H_

void led_on(GPIO_TypeDef* GPIOx,uint16_t LED);
void led_off(GPIO_TypeDef* GPIOx,uint16_t LED);
void clearAllClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12);
void setNumberOnClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12,uint16_t num);
void clearNumberOnClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12,uint16_t num);
void setAllClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12);
#endif /* INS_LED_H_ */
