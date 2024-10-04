/*
 * input_reading.h
 *
 *  Created on: Sep 27, 2024
 *      Author: thuyh
 */

#ifndef INS_INPUT_READING_H_
#define INS_INPUT_READING_H_
#include "main.h"
#include "global.h"
 void button_reading ( GPIO_TypeDef* GPIOx[] , uint16_t GPIO_Pin[] ) ;
 unsigned int is_button_pressed ( unsigned int index );
 unsigned int is_button_pressed_1s ( unsigned int index ) ;
#endif /* INS_INPUT_READING_H_ */
