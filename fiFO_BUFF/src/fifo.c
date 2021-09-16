#include "fifo.h"

#include"stdio.h"
#include "stdlib.h"

FIFI_status FIFI_add_item (FIFI_buf_t *FIFI, element_type item){
	*(FIFI->tail) = item;
		FIFI->count++;
		FIFI->tail++;
		/*Circulation check*/
		if(FIFI->tail == (FIFI->base + FIFI->length * sizeof(element_type)))
			FIFI->tail = FIFI->base;

		return FIFI_no_erroe;

}
FIFI_status FIFI_get_item (FIFI_buf_t *FIFI, element_type *item){
	*item = *(FIFI->head);
		FIFI->count--;
		FIFI->head++;
		if(FIFI->head == (FIFI->base + FIFI->length * sizeof(element_type)))
			FIFI->head = FIFI->base;
		return FIFI_no_erroe;
}
FIFI_status FIFI_int (FIFI_buf_t *FIFI,element_type *buffer, unsigned int length){
if(buffer==NULL)
	return FIFI_null;
FIFI->base=buffer;
FIFI->head=buffer;
FIFI->tail=buffer;
FIFI->count=0;
FIFI->length=length;
return FIFI_no_erroe;

}
void FIFI_printf (FIFI_buf_t *FIFI){
	element_type temp;
		int i;
		if (FIFI->count == 0){
			printf("Queue is empty \n");
		}
		printf("\n====FIFO PRINT====\n");
		temp = *(FIFI->tail);
		for(i=0; i<FIFI->count ;i++ ){
			printf("\t  (%d) \n",temp);
			temp++ ;
		}
		printf("=================\n");
	}
