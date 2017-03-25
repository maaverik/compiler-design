#include "y.tab.h"
#include "sym_table.h"
#include "exptree.h"
#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>


struct tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct tnode *Arglist, struct tnode *Ptr1, struct tnode *Ptr2, struct tnode *Ptr3){
	struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->TYPE = TYPE;
	temp->NODETYPE = NODETYPE;
	temp->VALUE = VALUE;
	temp->NAME = NAME;
	temp->Arglist = Arglist;
	temp->Ptr1 = Ptr1;
	temp->Ptr2 = Ptr2;
	temp->Ptr3 = Ptr3;
	return temp;
}

struct tnode* makeOperatorNode(int op, int type, struct tnode *l, struct tnode *r){
	struct tnode *temp = TreeCreate(type, op, -1, NULL, NULL, l, r, NULL);
	return temp;
}

int toBool(int x){
	if (x == 1)
		return TRUE;
	else if (x == 0)
		return FALSE;
	else {
		printf("Not 1 or 0\n");
		return -1;
	}
}

int toInt(int x){
	if (x == TRUE)
		return 1;
	else if (x == FALSE)
		return 0;
	else{
		printf("Not TRUE or FALSE\n");
		return -1;
	}
}

/*

int evaluate(struct tnode *t){
	int value, tmp;
	struct tnode *temp;
	switch(t->NODETYPE){
		case INT : return t->VALUE;
			break;
		case BOOL : return t->VALUE;
			break;
		case PLUS : return evaluate(t->Ptr1) + evaluate(t->Ptr2);
			break;
		case MUL : return evaluate(t->Ptr1) * evaluate(t->Ptr2);
			break;
		case SUB : return evaluate(t->Ptr1) - evaluate(t->Ptr2);
			break;
		case DIV : value = evaluate(t->Ptr2);
			if (value != 0)
				return evaluate(t->Ptr1) / value;
			else
				printf("inf\n");
				return -1;
			break;
		case EQ : return toBool(evaluate(t->Ptr1) == evaluate(t->Ptr2));
			break;
		case NEQ : return toBool(evaluate(t->Ptr1) != evaluate(t->Ptr2));
			break;
		case LT : return toBool(evaluate(t->Ptr1) < evaluate(t->Ptr2));
			break;
		case GT : return toBool(evaluate(t->Ptr1) > evaluate(t->Ptr2));
			break;
		case BREAK : return BREAK;
			break;
		case CONTINUE : return CONTINUE;
			break;
		case IF:
			value  = evaluate(t->Ptr1); // 0 or 1
			if (toInt(value)) {
				return evaluate(t->Ptr2);
			}
			else if (t->Ptr3 != NULL){
				return evaluate(t->Ptr3);
			}
			return 0;
			break;
		case WHILE :
			while (toInt(evaluate(t->Ptr1))) {
				tmp = evaluate(t->Ptr2);
				if (tmp == BREAK){
					break;
				}
				else if (tmp == CONTINUE){
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
	    	if (Glookup((temp -> NAME)) == NULL) {
	    	  printf("Unallocated variable %s\n", temp->NAME);
	          exit(-1);
	        }
	    	*(Glookup(temp->NAME)->binding) = value;
	    	return 0;
	    	break;
	    case ID :
	    	 if (Glookup((t -> NAME)) == NULL) {
	    	  printf("Unallocated variable %s\n", t->NAME);
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
				printf("Unallocated variable %s", temp->NAME);
				exit(-1);
			}
			if(Glookup(temp->NAME)->type  != INT){
				printf("Cannot read non-integer variable %s", temp->NAME);
				exit(-1);
			}
	    	printf("Enter a value\n");
	    	if(!scanf("%d", Glookup((temp->NAME))->binding)){
	    		printf("Invalid input\n");
	    		exit(-1);
	    	}
	    	return 0;
	    	break;
	    case WRITE :
	    	temp = t->Ptr1;
	    	value = evaluate(temp);
			if (value == TRUE)
				printf("true\n");
			else if (value == FALSE)
				printf("false\n");
	    	else
		    	printf("%d\n",value);
	    	return 0;
	    	break;
	    case STMT:
	        tmp = evaluate(t->Ptr1);
	        if (tmp == BREAK)
	        	return BREAK;
	        else if (tmp == CONTINUE)
	        	return CONTINUE;
	        return evaluate(t->Ptr2);
	        break;
	  	case ARRASGN:
 			if(Glookup(t->NAME)  == NULL) {
 				printf("Unallocated variable '%s'", t->NAME);
 				exit(-1);
 			}
 			*(Glookup(t->NAME)->binding + evaluate(t->Ptr1)) = evaluate(t->Ptr2);
 			return 0;
 			break;
 		case ARRVAL:
 			value = evaluate(t->Ptr2);
 			return *((Glookup(t->Ptr1->NAME)->binding) + value);
 			break;
 		case ARRREAD:
 			if(Glookup(t->NAME)  == NULL) {
 				printf("Unallocated variable '%s'", t->NAME);
 				exit(0);
 			}
 			value = evaluate(t->Ptr1);
 			scanf("%d", (Glookup(t->NAME) -> binding)+value);
 			return 0;
 			break;

	    default:
	    	printf("Unrecognised case\n");
	    	return -1;
	}
	return -1;
}

*/
