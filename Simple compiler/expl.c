#include "y.tab.h"
#include "expl.h"

int *var[26];

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
	int value;
	char name;
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
		case LT : return evaluate(t->Ptr1) < evaluate(t->Ptr2);
			break;
		case GT : return evaluate(t->Ptr1) > evaluate(t->Ptr2);
			break;
		case IF:
			  	value  = evaluate(t->Ptr1); // 0 or 1
			if (value) {
				evaluate(t->Ptr2);
			}
			return 1;
			break;
		case WHILE :
			value  = evaluate(t->Ptr1);
			while (value) {
				evaluate(t->Ptr2);
				value = evaluate(t->Ptr1);
			}
			return 1;
			break;
		// case EVAL :
	 //    	return evaluate(t->Ptr1);
	 //    	break;
		case ASGN :
			temp = t->Ptr1;
			name = (temp->NAME)[0];
			if (var[name - 'a'] == NULL) {
	        	var[name - 'a'] = (int *) malloc (sizeof(int));
	    	}
	    	value = evaluate(t -> Ptr2);
	    	*var[name - 'a'] = value;
	    	return 0;
	    	break;
	    case ID :
	    	name = (t -> NAME)[0];
	    	 if (var[name - 'a'] == NULL) {
	          exit(-1);
	        }
	        else {
	          return *var[name - 'a'];
	        }
	    	return 0;
	    	break;
	    case READ :
	    	temp = t->Ptr1;
			name = (temp->NAME)[0];
			if (var[name - 'a'] == NULL) {
	        	var[name - 'a'] = (int *) malloc (sizeof(int));
	    	}
	    	printf("Enter a value\n");
	    	scanf("%d", var[name - 'a']);
	    	return 0;
	    	break;
	    case WRITE :
	    	temp = t->Ptr1;
	    	printf("%d\n",evaluate(temp));
	    	return 0;
	    	break;
	    case SLIST:
	        evaluate(t->Ptr1);
	        evaluate(t->Ptr2);
	        return 0;
	}
	return -1;
}
