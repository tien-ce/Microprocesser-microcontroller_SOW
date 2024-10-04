/*
 * input_processing.c
 *
 *  Created on: Sep 27, 2024
 *      Author: thuyh
 */
#include "input_processing.h"
#define N0_OF_BUTTONS 1
enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND };
enum ButtonState buttonState[N0_OF_BUTTONS] = {BUTTON_RELEASED}; //  Trang thai hien tai : Nut dang nha
void fsm_for_input_processing (  ) {
	for(int i = 0 ; i< N0_OF_BUTTONS ; i++ ){
		switch(buttonState[i]){
		case BUTTON_RELEASED:
			if(is_button_pressed(i)){
				buttonState[i] = BUTTON_PRESSED;
				//TODO
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_PRESSED;
			}
			else {
				if(is_button_pressed_1s(i)){
					buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
			}
			// TODO
			break;
		}
	}
}

