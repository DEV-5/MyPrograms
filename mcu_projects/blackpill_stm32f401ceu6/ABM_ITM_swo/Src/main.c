/*
 * My Main
 * Date: 23rd Dec 2025
 */

#include "stm32f4xx.h"
#include "stdio.h"


char __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}

/* Select UART peripheral: PA2 - USART2 TX and PA3 - USART2 RX */
/* Identify Bus for port  GPIOA is connected to AHB1 bus */

/* USER LED is connected to PC13 */

char _a[1] = {'A'};
char *ptr_a = _a;

int main ()
{
	while(1){
		printf("This is a working printf\r\n");
//		ITM_SendChar(*ptr_a);
	}
}
