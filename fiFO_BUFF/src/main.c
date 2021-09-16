/*
 ============================================================================
 Name        : LIFO_BUFF.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include"stdlib.h"
#include "fifo.h"
#include "fifo.h"
element_type buffer1 [5];


int main() {
	element_type i ,temp=0;
	FIFI_buf_t uart_lifo;
	if(FIFI_int(&uart_lifo,buffer1,5)==FIFI_no_erroe)
		printf("fifo int  \n ");
	for (i=0;i<5;i++){
		if (FIFI_add_item(&uart_lifo, i)==(FIFI_no_erroe))
			printf("fifo done  %x \n ",i);
		else
			printf("fifo faild");
	}
	FIFI_printf(&uart_lifo);
	if (FIFI_get_item(&uart_lifo,&temp )==(FIFI_no_erroe))
		printf("lifo de done   %x \n ",temp);
	if (FIFI_get_item(&uart_lifo,&temp )==(FIFI_no_erroe))
		printf("lifo de done   %x \n ",temp);
	FIFI_printf(&uart_lifo);

	return 0;
}
