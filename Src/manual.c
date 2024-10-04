/*
 * munual.c
 *
 *  Created on: Sep 23, 2024
 *      Author: thuyh
 */
#include "manual.h"
void manual_init(){
	setTimer1(2, 500); // Danh cho nhap nhay den khi set thoi gian
}
void manual_run(){
	switch(status){
	case SET_TIME_RED:
		traffic_set_time_red();
		break;
	case SET_TIME_YELLOW:
		traffic_set_time_yellow();
		break;
	case SET_TIME_GREEN:
		traffic_set_time_green();
		break;
	case MAN_GREEN_RED:
		traffic_mannual_green_red();
	case MAN_YELLOW_RED:
		traffic_mannual_yellow_red();
	case MAN_RED_GREEN:
		traffic_mannual_red_green();
	case MAN_RED_YELLOW:
		traffic_mannual_red_yellow();
	default :
		break;
	}

}
