/*
 * uart.c
 *
 *  Created on: Jan 2, 2026
 *      Author: vdev
 */


#include <stdint.h>
#include "stm32f4xx.h"

/*
 * step 1: identify the UART peripheral and PORT & GPIO and AF no and CLOCK associated USART2 -> PA2 (TX), PA3 (RX)
 * step 2: set
 */
#define UART_AFNO		7
#define UART_TX_NO		2
#define UART_RX_NO		3
#define GPIOAEN			(1U << 0)
#define UART_BAUDRATE	115200
#define CLK				16000000
#define CR1_TE			(1U<<3)
#define CR1_RE			(1U<<2)

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate);


void uart_init(void)
{
	// always better to clear registers and write skipping for the time being

	/* Identify Bus for port GPIOA is connected to AHB1 bus */
	RCC->AHB1ENR |= GPIOAEN;

	/* Set PA2 to Alternative mode */
	GPIOA->MODER	&=	~(1U << (2 * UART_TX_NO));
	GPIOA->MODER	|=	(1U << ((2 * UART_TX_NO) + 1));
	/* Set PA3 to Alternative mode */
//	GPIOA->MODER	&=	~(1U << (2 * UART_RX_NO));
//	GPIOA->MODER	|=	(1U << ((2 * UART_RX_NO) + 1));
	// AFRL set pin2 gpioA to AF7
	GPIOA->AFR[0] |= (0x7 << GPIO_AFRL_AFSEL2_Pos);

	/* Configure Clock to 1Mhz */
//	RCC->CFGR   |= RCC_CFGR_PPRE1_DIV16;

	/* Enable Clock to USART2 peripheral */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	/* set Baudrate */
	uart_set_baudrate(CLK, UART_BAUDRATE);

	/* Clear and enable Transmit */
	USART2->CR1 = USART_CR1_TE;

	/* Clear and enable USART */
	USART2->CR1 |= USART_CR1_UE;
}

void uart2_write(int ch){
	/* Make sure the transmit data register is empty */
	while(!(USART2->SR & USART_SR_TXE)){}

	/* Write to transmit data register */
	USART2->DR = (ch & 0xFF);
}

char __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate){
	return ((periph_clk + (baudrate / 2U))/baudrate);
}

static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate){
	USART2->BRR = compute_uart_bd(periph_clk, baudrate);
}
