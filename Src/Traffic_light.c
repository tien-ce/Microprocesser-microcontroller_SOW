/*
 * Traffic_light.c
 *
 *  Created on: Sep 2, 2024
 *      Author: thuyh
 */

#include "Traffic_light.h"
int time_green_set = 3;
int time_yellow_set = 2;
int time_red_set = 6;
int time_init = 3;
int time_1 = 5;
int	time_2 = 5;
uint8_t redred ;
int time_red_select ;
int time_green_select;
int time_yellow_select = 0;
/*
# define LED_OFF SET
# define LED_ON RESET
 */
# define LED_OFF RESET
# define LED_ON SET
void traffic_double_display(GPIO_TypeDef * GPIOx1, uint16_t LED_RED1, uint16_t LED_YELLOW1, uint16_t LED_GREEN1,
                            GPIO_TypeDef * GPIOx2, uint16_t LED_RED2, uint16_t LED_YELLOW2, uint16_t LED_GREEN2, int status) {
    switch(status) {
        case GREEN_RED:
        case MAN_GREEN_RED:
            traffic_display(GPIOx1, LED_RED1, LED_YELLOW1, LED_GREEN1, GREEN);
            traffic_display(GPIOx2, LED_RED2, LED_YELLOW2, LED_GREEN2, RED);
            break;
        case YELLOW_RED:
        case MAN_YELLOW_RED:
            traffic_display(GPIOx1, LED_RED1, LED_YELLOW1, LED_GREEN1, YELLOW);
            traffic_display(GPIOx2, LED_RED2, LED_YELLOW2, LED_GREEN2, RED);
            break;
        case RED_GREEN:
        case MAN_RED_GREEN:
            traffic_display(GPIOx1, LED_RED1, LED_YELLOW1, LED_GREEN1, RED);
            traffic_display(GPIOx2, LED_RED2, LED_YELLOW2, LED_GREEN2, GREEN);
            break;
        case RED_YELLOW:
        case MAN_RED_YELLOW:
            traffic_display(GPIOx1, LED_RED1, LED_YELLOW1, LED_GREEN1, RED);
            traffic_display(GPIOx2, LED_RED2, LED_YELLOW2, LED_GREEN2, YELLOW);
            break;
        case INIT:
            HAL_GPIO_WritePin(GPIOx1, LED_RED1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_YELLOW1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_GREEN1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_RED2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_YELLOW2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_GREEN2, LED_OFF);
            break;
        case RED_RED1:
    //	    case RED_RED2:
            traffic_display(GPIOx1, LED_RED1, LED_YELLOW1, LED_GREEN1, RED);
            traffic_display(GPIOx2, LED_RED2, LED_YELLOW2, LED_GREEN2, RED);
            break;
        case SET_TIME_RED:
            HAL_GPIO_WritePin(GPIOx1, LED_YELLOW1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_GREEN1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_YELLOW2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_GREEN2, LED_OFF);
        	if(timer1_flag[2] == 1){
        		HAL_GPIO_TogglePin(GPIOx1, LED_RED1);
        		HAL_GPIO_TogglePin(GPIOx2, LED_RED2);
        		setTimer1(2, 500);
        	}
            break;

        case SET_TIME_YELLOW:
            HAL_GPIO_WritePin(GPIOx1, LED_RED1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_GREEN1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_RED2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_GREEN2, LED_OFF);
        	if(timer1_flag[2] == 1){
        		HAL_GPIO_TogglePin(GPIOx1, LED_YELLOW1);
        		HAL_GPIO_TogglePin(GPIOx2, LED_YELLOW2);
        		setTimer1(2, 500);
        	}
            break;

        case SET_TIME_GREEN:
            HAL_GPIO_WritePin(GPIOx1, LED_RED1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_YELLOW1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_RED2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_YELLOW2, LED_OFF);
        	if(timer1_flag[2] == 1){
        		HAL_GPIO_TogglePin(GPIOx1, LED_GREEN1);
        		HAL_GPIO_TogglePin(GPIOx2, LED_GREEN2);
        		setTimer1(2, 500);
        	}
            break;
        default:
            HAL_GPIO_WritePin(GPIOx1, LED_RED1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_YELLOW1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx1, LED_GREEN1, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_RED2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_YELLOW2, LED_OFF);
            HAL_GPIO_WritePin(GPIOx2, LED_GREEN2, LED_OFF);
        	break;
    }
}
void traffic_display(GPIO_TypeDef * GPIOx, uint16_t LED_RED, uint16_t LED_YELLOW, uint16_t LED_GREEN, State type) {
    switch(type) {
        case RED:
            HAL_GPIO_WritePin(GPIOx, LED_RED, LED_ON);
            HAL_GPIO_WritePin(GPIOx, LED_YELLOW, LED_OFF);
            HAL_GPIO_WritePin(GPIOx, LED_GREEN, LED_OFF);
            break;
        case YELLOW:
            HAL_GPIO_WritePin(GPIOx, LED_RED, LED_OFF);
            HAL_GPIO_WritePin(GPIOx, LED_YELLOW, LED_ON);
            HAL_GPIO_WritePin(GPIOx, LED_GREEN, LED_OFF);
            break;
        case GREEN:
            HAL_GPIO_WritePin(GPIOx, LED_RED, LED_OFF);
            HAL_GPIO_WritePin(GPIOx, LED_YELLOW, LED_OFF);
            HAL_GPIO_WritePin(GPIOx, LED_GREEN, LED_ON);
            break;
        default:
            break;
    }
}
void traffic_init() {
	 redred = (time_yellow_set + time_green_set) == time_red_set ? 0 : 1;
	if (time_1 <= 0 || time_2<=0) {
		time_1 = time_green_set;
		time_2 = time_red_set;
		status = GREEN_RED;
	}
	if (is_button_pressed(0)) {
		status = SET_TIME_RED;
	}



}

void traffic_green_red() {

    if (time_1 <= 0) {
        time_1 = time_yellow_set;
        status = YELLOW_RED;
    }
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}

void traffic_yellow_red() {

    if (redred == 1) {
        if (time_1 <= 0) {
            time_1 = time_red_set;
            status = RED_RED1;
        }
    } else {
        if (time_2 <= 0) {
            time_1 = time_red_set;
            time_2 = time_green_set;
            status = RED_GREEN;
        }
    }
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}

void traffic_red_red1() {

    if (time_2 <= 0) {
    	// time_1 = time_red_set;
        time_2 = time_green_set;
        status = RED_GREEN;
    }
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}

void traffic_red_green() {

    if (time_2 <= 0) {
        time_2 = time_yellow_set;
        status = RED_YELLOW;
    }
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}

void traffic_red_yellow() {

	if (time_1 <= 0) {
		time_1 = time_green_set;
		time_2 = time_red_set;
		status = GREEN_RED;
	}
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}
/*
void traffic_red_red2() {

    if (time_1 <= 0) {
        time_1 = time_green_set;
     //   time_2 = time_red_set;
        status = GREEN_RED;
    }
    if (is_button_pressed(0)) {
        status = SET_TIME_RED;
    }

}
*/



void traffic_mannual_green_red(){
	if(timer1_flag[1]  == 1){
		status = GREEN_RED;
	}
	if(is_button_pressed(0)){
		status = SET_TIME_RED;
	}
}
void traffic_mannual_yellow_red(){
	if(timer1_flag[1]  == 1){
		status = YELLOW_RED;
	}
	if(is_button_pressed(0)){
		status = SET_TIME_RED;
	}
}
void traffic_mannual_red_green(){
	if(timer1_flag[1]  == 1){
		status = RED_GREEN;
	}
	if(is_button_pressed(0)){
		status = SET_TIME_RED;
	}
}
void traffic_mannual_red_yellow(){
	if(timer1_flag[1]  == 1){
		status = RED_YELLOW;
	}
	if(is_button_pressed(0)){
		status = SET_TIME_RED;
	}
}
void traffic_set_time_red(){

	if(time_red_select< time_red_set){
		time_red_select = time_red_set;
	}
	if(is_button_pressed(1)){
		// Tang gia tri
		if(time_red_select<100)
		{
			time_red_select ++;
		}
		else {
			time_red_select = time_green_set + time_yellow_set;
		}
	}
	if(is_button_pressed(2)){
		// Chon gia tri
		time_red_set = time_red_select;
	}
	if(is_button_pressed(0)){
		time_yellow_select = time_yellow_set;
		status = SET_TIME_YELLOW;
	}
}

void traffic_set_time_yellow() {

    if (time_yellow_select < 1) {
        time_yellow_select = 1;
    }

    if (is_button_pressed(1)) {
        // Tăng giá trị
        if (time_yellow_select < time_green_set) {
            time_yellow_select++;
        } else {
            time_yellow_select = 0;
        }
    }

    if (is_button_pressed(2)) {
        // Chọn giá trị
        time_yellow_set = time_yellow_select;
    }
    if (is_button_pressed(0)) {
    	time_green_select = time_green_set;
        status = SET_TIME_GREEN;
    }

}

void traffic_set_time_green() {

    if (time_green_select < time_yellow_set) {
        time_green_select = time_yellow_set;
    }

    if (is_button_pressed(1)) {
        // Tăng giá trị
        if (time_green_select + time_yellow_set < time_red_set) {
            time_green_select++;
        } else {
            time_green_select = time_yellow_set;
        }
    }

    if (is_button_pressed(2)) {
        // Chọn giá trị
        time_green_set = time_green_select;
    }

    if (is_button_pressed(0)) {
        time_1 = time_init;
        time_2 = time_init;
        status = INIT;
    }
}


