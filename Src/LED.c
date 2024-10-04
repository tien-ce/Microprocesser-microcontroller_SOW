/*
 * LED.c
 *
 *  Created on: Sep 4, 2024
 *      Author: thuyh
 */

#include "LED.h"
void led_on(GPIO_TypeDef* GPIOx,uint16_t LED){
	HAL_GPIO_WritePin(GPIOx, LED, RESET);
}
void led_off(GPIO_TypeDef* GPIOx,uint16_t LED){
	HAL_GPIO_WritePin(GPIOx, LED, SET);
}
void clearAllClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12){
	HAL_GPIO_WritePin(GPIOx, LED_1, SET);
	HAL_GPIO_WritePin(GPIOx, LED_2, SET);
	HAL_GPIO_WritePin(GPIOx, LED_3, SET);
	HAL_GPIO_WritePin(GPIOx, LED_4, SET);
	HAL_GPIO_WritePin(GPIOx, LED_5, SET);
	HAL_GPIO_WritePin(GPIOx, LED_6, SET);
	HAL_GPIO_WritePin(GPIOx, LED_7, SET);
	HAL_GPIO_WritePin(GPIOx, LED_8, SET);
	HAL_GPIO_WritePin(GPIOx, LED_9, SET);
	HAL_GPIO_WritePin(GPIOx, LED_10, SET);
	HAL_GPIO_WritePin(GPIOx, LED_11, SET);
	HAL_GPIO_WritePin(GPIOx, LED_12, SET);
}
void setAllClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12){
	HAL_GPIO_WritePin(GPIOx, LED_1, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_2, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_3, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_4, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_5, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_6, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_7, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_8, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_9, RESET);
	HAL_GPIO_WritePin(GPIOx, LED_10,RESET);
	HAL_GPIO_WritePin(GPIOx, LED_11,RESET);
	HAL_GPIO_WritePin(GPIOx, LED_12,RESET);
}
void setNumberOnClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12,uint16_t num){
	if(num<0)
	{
		setAllClock(GPIOx, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10, LED_11, LED_12);
	return;
	}
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOx, LED_12, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOx, LED_1, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOx, LED_2, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOx, LED_3, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOx, LED_4, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOx, LED_5, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOx, LED_6, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOx, LED_7, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOx, LED_8, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOx, LED_9, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOx, LED_10, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOx, LED_11, RESET);
		break;
	default:
		setNumberOnClock(GPIOx, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10, LED_11, LED_12, num%12);
		break;
	}
}
void clearNumberOnClock(GPIO_TypeDef* GPIOx,uint16_t LED_1,uint16_t LED_2,uint16_t LED_3,uint16_t LED_4,uint16_t LED_5,uint16_t LED_6,uint16_t LED_7
		,uint16_t LED_8,uint16_t LED_9,uint16_t LED_10,uint16_t LED_11,uint16_t LED_12,uint16_t num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOx, LED_12, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOx, LED_1, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOx, LED_2, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOx, LED_3, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOx, LED_4, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOx, LED_5, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOx, LED_6, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOx, LED_7, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOx, LED_8, SET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOx, LED_9, SET);
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOx, LED_10, SET);
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOx, LED_11, SET);
		break;
	default:
		break;
	}
}
