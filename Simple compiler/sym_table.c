#include "y.tab.h"
#include "sym_table.h"
#include "lsym_table.h"
#include "typetable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern struct Gsymbol *GST;
int nextFreeLocation = 4096;

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

void Ginstall(char* name, struct Typetable *type, int size, struct Paramstruct *paramlist) {
 	struct Gsymbol *i;

 	if (GST == NULL) {
 		GST = malloc(sizeof(struct Gsymbol));
 		i = GST;
 	}
 	else {
 		i = GST;
 		while(i->next != NULL){
 			if (name == i -> name){
	 			printf("Variable %s already declared once globally\n", name);
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
	 	i->flabel = -1;
 	}

 	i->binding = nextFreeLocation;
 	nextFreeLocation += size;
}
