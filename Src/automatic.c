/*
 * automatic.c
 *
 *  Created on: Sep 23, 2024
 *      Author: thuyh
 */
#include "automatic.h"

void automatic_init(){
	time_1 = time_init;
	time_2 = time_init;
}

void automatic_run(){
 	switch(status)
	{
	case (INIT):
			traffic_init();
			break;
	case (GREEN_RED):
			// TODO
				traffic_green_red();
			break;
	case (YELLOW_RED):
				traffic_yellow_red();
			break;
	case RED_RED1:
				traffic_red_red1();
			break;

	case (RED_GREEN):
				traffic_red_green();
			break;
	case (RED_YELLOW):
				traffic_red_yellow();
			break;

	default:
		break;
	}

}
