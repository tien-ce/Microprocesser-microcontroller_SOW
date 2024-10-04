/*
 * enable.c
 *
 *  Created on: Sep 30, 2024
 *      Author: thuyh
 */

#include "enable.h"
void set_enable(GPIO_TypeDef* GPIO_enable[],uint16_t GPIO_enable_Pin[], unsigned int index,int size){
switch(index){
case 0:
	HAL_GPIO_WritePin(GPIO_enable[0], GPIO_enable_Pin[0], RESET);
	HAL_GPIO_WritePin(GPIO_enable[1], GPIO_enable_Pin[1], SET);
	break;
case 1:
	HAL_GPIO_WritePin(GPIO_enable[0], GPIO_enable_Pin[0], SET);
	HAL_GPIO_WritePin(GPIO_enable[1], GPIO_enable_Pin[1], RESET);
	break;
default:
	break;
}
/*
 	if(index >size || index <0 ){
		return;
	}
	else {
		for( int i =0 ; i<size; i++){
			if(i!=index){
				HAL_GPIO_WritePin(GPIO_enable[i], GPIO_enable_Pin[i], SET);
			}
			else {
				HAL_GPIO_WritePin(GPIO_enable[i], GPIO_enable_Pin[i], RESET);
			}
		}
	}
 */
}
