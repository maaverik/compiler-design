#include "y.tab.h"
#include "lsym_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern struct Lsymbol *LST;
int nextLocation = 1;

struct Lsymbol* LInstall(char *name, int type, int size){
	struct Lsymbol *i;

 	if (LST == NULL) {
 		LST = malloc(sizeof(struct Gsymbol));
 		i = LST;
 	}
 	else {
 		i = LST;
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

 	if(type == INT || type == BOOL || type == INTARR || type == BOOLARR){		// integer
 		i->binding = nextLocation;
 		nextLocation += size;
 	}
 	else
 		printf("Wrong type\n");
}

struct Lsymbol* LLookup(struct Lsymbol *LST, char *name){
	struct Lsymbol *tmp = LST;
	while (tmp != NULL){
		if (strcmp(tmp->name, name) == 0){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
