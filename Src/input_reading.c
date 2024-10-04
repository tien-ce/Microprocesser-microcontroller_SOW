/*
 * input_reading.c
 *
 *  Created on: Sep 27, 2024
 *      Author: thuyh
 */
#include "main.h"
#define N0_OF_BUTTONS 3 // So luong nut nhan
#define DURATION_FOR_AUTO_INCREASING 100	// 1s
#define BUTTON_IS_PRESSED GPIO_PIN_RESET	// Nut bam dang nhan
#define BUTTON_IS_RELEASED GPIO_PIN_SET		// Nut bam dang tha
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS]; // Bo dem chong nay
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer4[N0_OF_BUTTONS];
static uint8_t flagForButtonPress[N0_OF_BUTTONS]; // flag for button pressed (AN) hon 1 giay
static uint8_t flagForButton_longPress[N0_OF_BUTTONS];
int time_out_input = 500;
void button_reading ( GPIO_TypeDef* GPIOx[] , uint16_t GPIO_Pin[] ) {
	for (int i = 0 ; i< N0_OF_BUTTONS ; i ++ ){
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOx[i], GPIO_Pin[i]);
		if(debounceButtonBuffer3[i] == debounceButtonBuffer2[i] && debounceButtonBuffer2[i] == debounceButtonBuffer1[i]){
			// Het Rung
			if(debounceButtonBuffer4[i]!=debounceButtonBuffer3[i]){
				// Dong bo lai tin hieu
				debounceButtonBuffer4[i]=debounceButtonBuffer3[i];
				if(debounceButtonBuffer4[i] == BUTTON_IS_PRESSED){
					// Vua chuyen sang trang thai nhan
					flagForButtonPress[i] = 1;
					time_out_input = 500;
				}
			}
			else{
				// Dang trong qua trinh nhan de hoac nha
				time_out_input -- ;
				if(time_out_input <= 0 ){
					// Nhan du 5s hoac tha 5s
					time_out_input = 500;
					if(debounceButtonBuffer4[i] == BUTTON_IS_PRESSED){
						// Truong hop la nhan de
						flagForButton_longPress[i] = 1;
					}
				}
			}
		}
	}
}
unsigned int is_button_pressed ( unsigned int index ){
	// Tra ve trang thai nut nhan co dang bat hay khong
	if(index>= N0_OF_BUTTONS){
		return 0;
	}
	if(flagForButtonPress[index] == 1){
		flagForButtonPress[index] = 0;
		return 1;
	}
	return 0;
}
unsigned int is_button_pressed_1s ( unsigned int index ) {
	if(index>= N0_OF_BUTTONS){
		return 0 ;
	}
	if(flagForButton_longPress[index] == 1)
	{
		flagForButton_longPress[index] = 0;
		return 1;
	}
	return 0;
}

