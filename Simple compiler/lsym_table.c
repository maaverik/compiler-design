#include "y.tab.h"
#include "sym_table.h"
#include "lsym_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern struct Lsymbol *LST;
int nextLocation = 1;

struct Lsymbol* Linstall(char *name, int type, int size){
	struct Lsymbol *i;

 	if (LST == NULL) {
 		LST = malloc(sizeof(struct Lsymbol));
 		i = LST;
 	}
 	else {
 		i = LST;
 		while(i->next != NULL){
 			if (name == i -> name){
	 			printf("Variable %s already declared once locally\n", name);
	 			exit(-1);
	 		}
 			i = i->next;
	 	}

 		i->next = malloc(sizeof(struct Lsymbol));
 		i = i->next;
 	}

 	i->name = name;
 	i->type = type;

 	if(type == INT || type == BOOL || type == INTARR || type == BOOLARR){		// integer
 		i->binding = nextLocation;
 		nextLocation += size;
 	}
 	else
 		printf("Wrong type\n");
}

struct Lsymbol* LLookup(char *name){
	struct Lsymbol *tmp = LST;
	while (tmp != NULL){
		if (strcmp(tmp->name, name) == 0){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
