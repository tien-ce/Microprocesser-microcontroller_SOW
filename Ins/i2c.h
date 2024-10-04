/*
 * i2c.h
 *
 *  Created on: Sep 26, 2024
 *      Author: thuyh

#include "main.h"
#ifndef INS_I2C_H_
#define INS_I2C_H_
extern int i2c_flag;
extern I2C_HandleTypeDef* hi2c_transmit;

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef * hi2c);
#endif /* INS_I2C_H_ */
 */
