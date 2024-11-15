/*
 * munual.c
 *
 *  Created on: Sep 23, 2024
 *      Author: thuyh
 */
#include "manual.h"
void manual_init(){
	setTimer1(4, TIME_OUT_RESET);
}

void manual_run(){
	if(status >= 8 && status <= 16){
		if(isfistTime ){
			setTimer1(4, TIME_OUT_RESET);
			if(!isAutoToMan){
				isfistTime = 0;
			}
		}
		else{
			if(timer1_flag[4] == 1){
				if(status == SET_TIME_RED){
					time_red_select = time_red_set;
				}
				else if (status == SET_TIME_GREEN){
					time_green_select = time_green_set;
				}
				else if (status == YELLOW){
					time_yellow_select = time_yellow_set;
				}
				status = INIT;
				isfistTime = 1;
			}
		}
	}
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
		break;
	case MAN_YELLOW_RED:
		traffic_mannual_yellow_red();
		break;
	case MAN_RED_GREEN:
		traffic_mannual_red_green();
		break;
	case MAN_RED_YELLOW:
		traffic_mannual_red_yellow();
		break;
	case MAN_RED_RED:
		traffic_mannual_red_red();
		break;
	default :
		break;
	}


}
