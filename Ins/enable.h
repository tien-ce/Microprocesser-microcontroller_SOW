/*
 * enable.h
 *
 *  Created on: Sep 30, 2024
 *      Author: thuyh
 */

#ifndef INS_ENABLE_H_
#define INS_ENABLE_H_

#include "global.h"
void set_enable(GPIO_TypeDef* GPIO_enable[],uint16_t GPIO_enable_Pin[], unsigned int index,int size);
void enable_init(GPIO_TypeDef* GPIO_enable[],uint16_t GPIO_enable_Pin[], unsigned int duration);
void enable_run(GPIO_TypeDef* GPIO_enable[],uint16_t GPIO_enable_Pin[], unsigned int duration);
#endif /* INS_ENABLE_H_ */
