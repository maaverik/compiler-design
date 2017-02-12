#include "y.tab.h"
#include "exptree.h"
#include "sym_table.c"

//int *var[26];

struct tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct tnode *ArgList, struct tnode *Ptr1, struct tnode *Ptr2, struct tnode *Ptr3){
	struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->TYPE = TYPE;
	temp->NODETYPE = NODETYPE;
	temp->VALUE = VALUE;
	temp->NAME = NAME;
	temp->ArgList = ArgList;
	temp->Ptr1 = Ptr1;
	temp->Ptr2 = Ptr2;
	temp->Ptr3 = Ptr3;
	return temp;
}

struct tnode* makeOperatorNode(int c,struct tnode *l,struct tnode *r){
	struct tnode *temp = TreeCreate(-1, c, -1, NULL, NULL, l, r, NULL);
	return temp;
}


int evaluate(struct tnode *t){
	int value, tmp;
	struct tnode *temp;
	switch(t->NODETYPE){
		case NUM : return t->VALUE;
			break;
		case PLUS : return evaluate(t->Ptr1) + evaluate(t->Ptr2);
			break;
		case MUL : return evaluate(t->Ptr1) * evaluate(t->Ptr2);
			break;
		case EQ : return evaluate(t->Ptr1) == evaluate(t->Ptr2);
			break;
		case NEQ : return evaluate(t->Ptr1) != evaluate(t->Ptr2);
			break;
		case LT : return evaluate(t->Ptr1) < evaluate(t->Ptr2);
			break;
		case GT : return evaluate(t->Ptr1) > evaluate(t->Ptr2);
			break;
		case BREAK : return BREAK;
			break;
		case CONTINUE : return CONTINUE;
			break;
		case IF:
			value  = evaluate(t->Ptr1); // 0 or 1
			if (value) {
				return evaluate(t->Ptr2);
			}
			else if (t->Ptr3 != NULL){
				return evaluate(t->Ptr3);
			}
			return 0;
			break;
		case WHILE :
			while (evaluate(t->Ptr1)) {
				tmp = evaluate(t->Ptr2);
				if (tmp == BREAK){
					printf("broken\n");
					break;
				}
				else if (tmp == CONTINUE){
					printf("cont\n");
					continue;
				}
			}
			return 0;
			break;
		case EVAL :
	    	return evaluate(t->Ptr1);
	    	break;
		case ASGN :
			temp = t->Ptr1;
	    	value = evaluate(t -> Ptr2);
	    	*(Glookup(temp->NAME)->binding) = value;
	    	return 0;
	    	break;
	    case ID :
	    	 if (Glookup((t -> NAME)) == NULL) {
	          exit(-1);
	        }
	        else {
	          return *(Glookup((t -> NAME))->binding);
	        }
	    	return 0;
	    	break;
	    case READ :
	    	temp = t->Ptr1;
			if(Glookup(temp->NAME)  == NULL){
				printf("Unallocated variable");
				exit(0);
			}
	    	printf("Enter a value\n");
	    	scanf("%d", Glookup((temp->NAME))->binding);
	    	return 0;
	    	break;
	    case WRITE :
	    	temp = t->Ptr1;
	    	printf("%d\n",evaluate(temp));
	    	return 0;
	    	break;
	    case SLIST:
	        tmp = evaluate(t->Ptr1);
	        if (tmp == BREAK)
	        	return BREAK;
	        else if (tmp == CONTINUE)
	        	return CONTINUE;
	        return evaluate(t->Ptr2);
	}
	return -1;
}