#ifndef _FIFI_
#define _FIFI_
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define element_type uint8_t
typedef struct {
	unsigned int length;
	element_type *base;
	element_type *head;
	element_type *tail;
	unsigned int count;
}FIFI_buf_t;

typedef enum {
	FIFI_no_erroe,
	FIFI_full,
	FIFI_empty,
	FIFI_null

}FIFI_status;

FIFI_status FIFI_add_item (FIFI_buf_t *FIFI, element_type item);
FIFI_status FIFI_get_item (FIFI_buf_t *FIFI, element_type *item);
FIFI_status FIFI_int (FIFI_buf_t *FIFI,element_type *buffer, unsigned int length);
void FIFI_printf (FIFI_buf_t *FIFI);
FIFI_status FIFI_fullt(FIFI_buf_t *FIFI);


#endif
