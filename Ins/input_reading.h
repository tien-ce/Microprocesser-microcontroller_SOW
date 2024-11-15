/*
 * input_reading.h
 *
 *  Created on: Sep 27, 2024
 *      Author: thuyh
 */

#ifndef INS_INPUT_READING_H_
#define INS_INPUT_READING_H_
#include "global.h"
#define N0_OF_BUTTONS 3           // Số lượng nút nhấn

extern uint8_t Button1_flag[N0_OF_BUTTONS];
extern uint8_t double_click_flag[N0_OF_BUTTONS];
unsigned int is_button_double_clicked(unsigned int index);
 void getKeyInput ( GPIO_TypeDef* GPIOx[] , uint16_t GPIO_Pin[] ) ;
 unsigned int is_button_pressed ( unsigned int index );
 unsigned int is_button_pressed_1s ( unsigned int index ) ;
#endif /* INS_INPUT_READING_H_ */
