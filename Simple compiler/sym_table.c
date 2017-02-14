#include "sym_table.h"
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern struct Gsymbol *GST;

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

void Ginstall(char* name, int type, int size) {
 	struct Gsymbol *i;

 	if (GST == NULL) {
 		GST = malloc(sizeof(struct Gsymbol));
 		i = GST;
 	}
 	else {
 		i = GST;
 		while(i->next != NULL)
 			i = i->next;

 		i->next = malloc(sizeof(struct Gsymbol));
 		i = i->next;
 	}

 	i->name = name;
 	i->type = type;
 	i->size = size;

 	if(type == INT || type == BOOL || type == INTARR || type == BOOLARR)		// integer
 		i->binding = malloc(sizeof(int));
 	else
 		printf("Wrong type\n");
}
