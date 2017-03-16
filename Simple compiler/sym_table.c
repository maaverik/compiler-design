#include "y.tab.h"
#include "sym_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern struct Gsymbol *GST;
int nextFreeLocation = 4096;
int func_label = 0;

struct Gsymbol *Glookup(char *name){ // Look up for a global identifier
	struct Gsymbol *tmp = GST;
	while (tmp != NULL){
		if (strcmp(tmp->name, name) == 0){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void Ginstall(char* name, int type, int size, struct Paramstruct *paramlist) {
 	struct Gsymbol *i;

 	if (GST == NULL) {
 		GST = malloc(sizeof(struct Gsymbol));
 		i = GST;
 	}
 	else {
 		i = GST;
 		while(i->next != NULL){
 			if (name == i -> name){
	 			printf("Variable %s already declared once\n", name);
	 			exit(-1);
	 		}
 			i = i->next;
	 	}

 		i->next = malloc(sizeof(struct Gsymbol));
 		i = i->next;
 	}

 	i->name = name;
 	i->type = type;
 	i->size = size;
 	i->paramlist = paramlist;
 	if (paramlist != NULL){
	 	i->binding = -1;
	 	i->flabel = func_label++;
 	}

 	else if(type == INT || type == BOOL || type == INTARR || type == BOOLARR){		// integer
 		i->binding = nextFreeLocation;
 		nextFreeLocation += size;
 	}
 	else
 		printf("Wrong type\n");
}
