/*
 * uart.h
 *
 *  Created on: Jan 1, 2026
 *      Author: vdev
 */
#include "stm32f4xx.h"

#ifndef UART_H_
#define UART_H_

/*
 * step 1: identify the uart peripheral and PORT & GPIO and AF no and CLOCK associated
 * step 2: set
 */

void uart_init(void);
void uart2_write(int ch);

#endif /* UART_H_ */
