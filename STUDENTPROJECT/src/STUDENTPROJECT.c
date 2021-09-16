/*
 ============================================================================
 number        : ssstudentproject.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

struct Sdata {
	unsigned int id;
	char name[40];
	float height;
};

typedef struct ssstudent{
	struct Sdata record;
	struct ssstudent * pNextssstudent;

} ssstudent;

ssstudent * gpFirstssstudent=NULL;

void fill_record(ssstudent * newssstudent){

	char number[40];

	DPRINTF("\nEnter ssstudent ID: ");
	gets(number);
	newssstudent->record.id=atoi(number);

	DPRINTF("\nEnter ssstudent full number: ");
	gets(newssstudent->record.name);

	DPRINTF("\nEnter height: ");
	gets(number);
	newssstudent->record.height=atof(number);
}

void addssstudent(){

	ssstudent *pNewssstudent;
	ssstudent *pLastssstudent=gpFirstssstudent;
	if(gpFirstssstudent==NULL){
		pNewssstudent=(ssstudent *)malloc(sizeof(ssstudent));
		gpFirstssstudent=pNewssstudent;
	}
	else{
		while(pLastssstudent->pNextssstudent)
			pLastssstudent=pLastssstudent->pNextssstudent;

		pNewssstudent=(ssstudent *)malloc(sizeof(ssstudent));
		pLastssstudent->pNextssstudent=pNewssstudent;
	}

	fill_record(pNewssstudent);
	pNewssstudent->pNextssstudent=NULL;
}
int deletessstudent(){
	unsigned int d_id;
	ssstudent * pPreviousssstudent=NULL;
	ssstudent * pSelectedssstudent=gpFirstssstudent;

	DPRINTF("\nEnter the ssstudent ID to be deleted: ");
	scanf("%d",&d_id);

	while(pSelectedssstudent){

		if(pSelectedssstudent->record.id == d_id){

			if(pPreviousssstudent)
				pPreviousssstudent->pNextssstudent=pSelectedssstudent->pNextssstudent;
			else
				gpFirstssstudent=pSelectedssstudent->pNextssstudent;

			free(pSelectedssstudent);

			return 1;
		}
		else{
			pPreviousssstudent=pSelectedssstudent;
			pSelectedssstudent=pSelectedssstudent->pNextssstudent;

		}
	}

	DPRINTF("\ncannot find ssstudent ID");
	return 0;
}
void showssstudent(){

	ssstudent * temp=gpFirstssstudent;
	int i=0;
	if(gpFirstssstudent==NULL)
		DPRINTF("\nEmpty list");
	while(temp){
		i++;
		DPRINTF("\nRecord number %d",i);
		DPRINTF("\nID: %d",temp->record.id);
		DPRINTF("\nnumber: %s",temp->record.name);
		DPRINTF("\nHeight: %f",temp->record.height);
		temp=temp->pNextssstudent;
	}
}
void cleanall(){
	ssstudent *temp=gpFirstssstudent;
	if(gpFirstssstudent==NULL)
		DPRINTF("\nEmpty list");

	while(gpFirstssstudent){
		gpFirstssstudent=temp->pNextssstudent;
		free(temp);
		temp=gpFirstssstudent;
	}
}
void findsstudent(){
	int index,count=0;
	ssstudent *temp=gpFirstssstudent;
	DPRINTF("\nEnter node's index: ");
	scanf("%d",&index);
	while(temp){
		if(index==count){
			DPRINTF("\nNode at index %d",index);
			DPRINTF("\nID: %d",temp->record.id);
			DPRINTF("\nName: %s",temp->record.name);
			DPRINTF("\nHeight: %f",temp->record.height);
			break;
		}
		temp=temp->pNextssstudent;
		count++;
	}
	if(!temp)
		DPRINTF("\nNode not found ");

}
int main() {
	int number;

	while(1){
		DPRINTF("\n============================");
		DPRINTF("\n\tChoose one of the following options ");
		DPRINTF("\n1: Add ssstudent ");
		DPRINTF("\n2: Delete ssstudent ");
		DPRINTF("\n3: View ssstudents ");
		DPRINTF("\n4: Delete all ");
		DPRINTF("\n5:findsstudent  ");
		scanf("%d",&number);
		DPRINTF("\n============================");
		switch(number){
		case 0:
			return 0;
			break;
		case 1:
			addssstudent();
			break;
		case 2:
			deletessstudent();
			break;
		case 3:
			showssstudent();
			break;
		case 4:
			cleanall();
			break;
		case 5:
			findsstudent();
			break;

		default:
			printf("\n Wrong option ");
			break ;
		}
	}
	return 0;
}
