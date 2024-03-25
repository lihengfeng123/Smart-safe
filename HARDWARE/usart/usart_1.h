#ifndef __USART_1_H
#define	__USART_1_H

#include "stm32f10x.h"
#include <stdio.h>
#include "usart_config.h"


void USART_1_init(void);
static void NVIC_Configuration(void);
int fputc_1(int ch, FILE *f);
int fgetc_1(FILE *f);

#endif /* __USART_H */
