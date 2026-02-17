/*
 * My Main
 * Date: 23rd Dec 2025
 */

#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>


char _a[1] = {'A'};
char *ptr_a = _a;

int main ()
{
	uart_init();
	while(1){
		printf("This is a working printf\r\n");
//		ITM_SendChar(*ptr_a);
	}
}
