/*
 * My Main
 * Date: 23rd Dec 2025
 */

#include "stm32f4xx.h"



/* Select UART peripheral: PA2 - USART2 TX and PA3 - USART2 RX */
/* Identify Bus for port  GPIOA is connected to AHB1 bus */

/* USER LED is connected to PC13 */
#define GPIOCEN		(1U << 2)
#define PORTNO
#define LED_PIN_NO	13
#define PIN13		(1 << LED_PIN_NO)
#define LED_PIN		PIN13

int main ()
{
	/* Enable clock access to GPIOC */
	RCC-> AHB1ENR |= GPIOCEN;

	/* Set PC13 to Output mode */
	GPIOC->MODER	|=	(1U << (2 * LED_PIN_NO));
	GPIOC->MODER	|=	(1U << ((2 * LED_PIN_NO) + 1));

	while(1){
		/* Toggle GPIO */
		GPIOC->ODR ^= LED_PIN;
		/* DELAY */
	}
}
