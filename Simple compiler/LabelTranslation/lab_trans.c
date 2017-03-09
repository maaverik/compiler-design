#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab_trans.h"

struct ltable* searchLab(char *name, struct ltable *labtable){
	struct ltable *tmp;
	tmp = labtable;
	while(tmp!=NULL){
		if(strcmp(tmp->name,name) == 0)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}


struct ltable* insertLab(char *name, int nextAddr, struct ltable *labtable){
	struct ltable *tmp;
	tmp = (struct ltable*)malloc(sizeof(struct ltable));
	int len=strlen(name);
	name[len-2]='\0';
	tmp->name = name;
	tmp->addr = nextAddr;
	tmp->next = NULL;
	if(labtable == NULL)
		labtable = tmp;
	else{
		tmp->next = labtable;
		labtable = tmp;
	}
	return labtable;
}
