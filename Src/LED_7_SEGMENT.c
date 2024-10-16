/*
 * LED_7_SEGMENT.c
 *
 *  Created on: Sep 2, 2024
 *      Author: thuyh
 */
#include "LED7_SEGMENT.h"
void DISPLAY_LED_7_SEGMENT(GPIO_TypeDef* GPIOx,uint16_t LED_7_0,uint16_t LED_7_1,uint16_t LED_7_2,uint16_t LED_7_3,uint16_t LED_7_4
		,uint16_t LED_7_5,uint16_t LED_7_6 ,uint8_t digit){
		switch(digit){
			case 0:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, SET);
					break;
			case 1:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, SET);
					break;
			case 2:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
				    break;
			case 3:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			case 4:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			case 5:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			case 6:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			case 7:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, SET);
					break;
			case 8:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			case 9:
							HAL_GPIO_WritePin(GPIOx, LED_7_0, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_1, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_2, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_3, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
							HAL_GPIO_WritePin(GPIOx, LED_7_5, RESET);
							HAL_GPIO_WritePin(GPIOx, LED_7_6, RESET);
					break;
			default:
								HAL_GPIO_WritePin(GPIOx, LED_7_0, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_1, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_2, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_3, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_4, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_5, SET);
								HAL_GPIO_WritePin(GPIOx, LED_7_6, SET);
				break;
			}

}
void SET_EN_7_SEGMENT(GPIO_TypeDef* GPIOx,uint16_t EN1,uint16_t EN2,uint16_t EN3,uint16_t EN4,int num){
	switch (num){
	case 1:
		HAL_GPIO_WritePin(GPIOA, EN1, RESET);
		HAL_GPIO_WritePin(GPIOA, EN2, SET);
		HAL_GPIO_WritePin(GPIOA, EN3, SET);
		HAL_GPIO_WritePin(GPIOA, EN4, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, EN1, SET);
		HAL_GPIO_WritePin(GPIOA, EN2, RESET);
		HAL_GPIO_WritePin(GPIOA, EN3, SET);
		HAL_GPIO_WritePin(GPIOA, EN4, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, EN1, SET);
		HAL_GPIO_WritePin(GPIOA, EN2, SET);
		HAL_GPIO_WritePin(GPIOA, EN3, RESET);
		HAL_GPIO_WritePin(GPIOA, EN4, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, EN1, SET);
		HAL_GPIO_WritePin(GPIOA, EN2, SET);
		HAL_GPIO_WritePin(GPIOA, EN3, SET);
		HAL_GPIO_WritePin(GPIOA, EN4, RESET);
		break;
	default :
		break;
	}
}

void DISPLAY_LED_7_SEGMENT_PREMIUM(GPIO_TypeDef* GPIOx1[], uint16_t LED1_Pin[], int digit){
    switch(digit){
        case 0:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], RESET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], SET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], SET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], SET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], SET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], SET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], RESET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], SET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], SET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], SET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], SET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], SET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], SET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], RESET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], SET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], SET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], SET);
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], RESET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], RESET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], RESET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], RESET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], RESET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], RESET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], RESET);
            break;
        default:
            HAL_GPIO_WritePin(GPIOx1[0], LED1_Pin[0], SET);
            HAL_GPIO_WritePin(GPIOx1[1], LED1_Pin[1], SET);
            HAL_GPIO_WritePin(GPIOx1[2], LED1_Pin[2], SET);
            HAL_GPIO_WritePin(GPIOx1[3], LED1_Pin[3], SET);
            HAL_GPIO_WritePin(GPIOx1[4], LED1_Pin[4], SET);
            HAL_GPIO_WritePin(GPIOx1[5], LED1_Pin[5], SET);
            HAL_GPIO_WritePin(GPIOx1[6], LED1_Pin[6], SET);
            break;
    }
}



