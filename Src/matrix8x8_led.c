/*
 * matrix8x8_led.c
 *
 *  Created on: Sep 21, 2024
 *      Author: thuyh
 */

#include "matrix8x8_led.h"
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 8;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

void updateColLEDMatrix (GPIO_TypeDef* GPIOx,uint16_t Pin0,uint16_t Pin1,uint16_t Pin2,uint16_t Pin3,uint16_t Pin4
		,uint16_t Pin5,uint16_t Pin6,uint16_t Pin7,int index ) {
    switch (index) {
        case 0:
        	HAL_GPIO_WritePin(GPIOx, Pin0, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 1:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 2:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 3:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 4:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 5:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 6:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, RESET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, SET);
            break;
        case 7:
        	HAL_GPIO_WritePin(GPIOx, Pin0, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin1, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin2, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin3, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin4, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin5, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin6, SET);
        	HAL_GPIO_WritePin(GPIOx, Pin7, RESET);
            break;
        default:
            break;
    }
}
void updateRowLEDMatrix (GPIO_TypeDef* GPIOx,uint16_t Pin0,uint16_t Pin1,uint16_t Pin2,uint16_t Pin3,uint16_t Pin4
		,uint16_t Pin5,uint16_t Pin6,uint16_t Pin7,int index ){
/*	int value;
	if(index >= 8|| index<0){
		value = 0x00;
	}
    if(index<=7){
    	 value = matrix_buffer[index];
    }
    */
    int value =  matrix_buffer[index%8];
    HAL_GPIO_WritePin(GPIOx, Pin0, !(value & 0x01) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin1, !(value & 0x02) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin2, !(value & 0x04) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin3, !(value & 0x08) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin4, !(value & 0x10) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin5, !(value & 0x20) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin6, !(value & 0x40) ? SET : RESET);
    HAL_GPIO_WritePin(GPIOx, Pin7, !(value & 0x80) ? SET : RESET);
}
void updateMatrixBuffer(uint8_t value0, uint8_t value1, uint8_t value2, uint8_t value3,
                        uint8_t value4, uint8_t value5, uint8_t value6, uint8_t value7) {
    matrix_buffer[0]  = value0;
    matrix_buffer[1]  = value1;
    matrix_buffer[2] = value2;
    matrix_buffer[3] = value3;
    matrix_buffer[4] = value4;
    matrix_buffer[5] = value5;
    matrix_buffer[6] = value6;
    matrix_buffer[7] = value7;
}
void char_matrix(char ch) {
    switch(ch) {
        case 'A':
            updateMatrixBuffer(0x00, 0x7E, 0x09, 0x09, 0x09, 0x09, 0x7E, 0x00);
            break;
        case '2':
        	updateMatrixBuffer( 0x79, 0x89,0x89, 0x89, 0x89, 0x89,0x89, 0x8F );
            break;
        case 'S':
            updateMatrixBuffer(0x46, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x72);
            break;
        case 'T':
            updateMatrixBuffer(0x03, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x03, 0x03);
            break;
        case 'E':
            updateMatrixBuffer(0xFF, 0xFF, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB);
            break;
        case 'P':
            updateMatrixBuffer(0xFF, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x06);
            break;
        case 'H':
            updateMatrixBuffer(0xFF, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xFF);
            break;
        case 'D':
            updateMatrixBuffer(0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x7E);
            break;
        default:
            // Handle undefined character case
            break;
    }
}

