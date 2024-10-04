/*
 * matrix8x8_led.h
 *
 *  Created on: Sep 21, 2024
 *      Author: thuyh
 */

#ifndef INS_MATRIX8X8_LED_H_
#define INS_MATRIX8X8_LED_H_
#include "main.h"

extern const int MAX_LED_MATRIX;
extern int index_led_matrix;
extern uint8_t matrix_buffer [8];
void updateColLEDMatrix (GPIO_TypeDef* GPIOx,uint16_t Pin0,uint16_t Pin1,uint16_t Pin2,uint16_t Pin3,uint16_t Pin4
		,uint16_t Pin5,uint16_t Pin6,uint16_t Pin7,int index );
void updateRowLEDMatrix (GPIO_TypeDef* GPIOx,uint16_t Pin0,uint16_t Pin1,uint16_t Pin2,uint16_t Pin3,uint16_t Pin4
		,uint16_t Pin5,uint16_t Pin6,uint16_t Pin7,int index );
void updateMatrixBuffer(uint8_t value0, uint8_t value1, uint8_t value2, uint8_t value3,
                        uint8_t value4, uint8_t value5, uint8_t value6, uint8_t value7);
void char_matrix(char ch);
#endif /* INS_MATRIX8X8_LED_H_ */
