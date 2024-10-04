/*
 * uart.c
 *
 *  Created on: Sep 26, 2024
 *      Author: thuyh


#include "uart.h"
UART_HandleTypeDef * huart_transmit;
int recive = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	recive = 1;
	huart_transmit = huart;
}
 */
