#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "sym_table.h"
#include "exptree.h"
#include "codegen.h"

int nextFreeReg = 0;
int labelTracker = 1;

int getReg(){
	if (nextFreeReg >= 20){
		printf("Register Leak...\n");
		exit(-1);
	}
	return nextFreeReg++;
}

void freeReg(){
	if(nextFreeReg-- <= 0)	{
		printf("nextFreeReg negative\n");
		exit(-1);
	}
}

int getLabel(){
	return labelTracker++;
}

void printheader(){
	fprintf(stdout, "MAGIC\n");
	fprintf(stdout, "2048\n");
	fprintf(stdout, "0\n0\n0\n0\n0\n0\n");
	fprintf(stdout, "START\n");
}

void printfooter(){
	fprintf(stdout, "HALT\n");
}

int codeGen(struct tnode* t){
	int l1, l2, r1, r2, r3;
	switch(t->NODETYPE){
		case INT:
			r1 = getReg();
			fprintf(stdout, "MOV R%d, %d\n", r1, t->VALUE);
			return r1;
			break;
		case BOOL:
			r1 = getReg();
			fprintf(stdout, "MOV R%d, %d\n", r1, t->VALUE);
			return r1;
			break;
		case PLUS:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case SUB:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "SUB R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case DIV:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "DIV R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case MUL:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "MUL R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case EQ:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "EQ R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case GT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "GT R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case LT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "LT R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case ASGN:
			r1 = codeGen(t->Ptr1);
			fprintf(stdout, "MOV [%d], R%d\n", Glookup(t->NAME)->binding, r1);
			return -1;
			break;
		case STMT:
			codeGen(t->Ptr1);
			return codeGen(t->Ptr2);
			break;
		case WRITE:
			r1 = codeGen(t->Ptr1);
			fprintf(stdout, "OUT R%d\n", r1);
			freeReg();
			return -1;
			break;
		case READ:
			r1 = getReg();
			fprintf(stdout, "IN R%d\n", r1);
			fprintf(stdout, "MOV [%d], R%d\n", Glookup(t->NAME)->binding, r1);
			freeReg();
			return -1;
			break;
		case ID:
			r1 = getReg();
			fprintf(stdout, "MOV R%d, [%d]\n", r1, Glookup(t->NAME)->binding);
			return r1;
			break;
		case IF:
			if(t->Ptr3 != NULL){
				r1 = codeGen(t->Ptr1);
				l1 = getLabel(); //Else
				l2 = getLabel(); //Endif
				fprintf(stdout, "JZ R%d, L%d\n", r1, l1);
				codeGen(t->Ptr2);
				fprintf(stdout, "JMP L%d\n", l2);
				fprintf(stdout, "L%d:\n", l1);
				codeGen(t->Ptr3);
				fprintf(stdout, "L%d:\n", l2);
			}
			else{
				r1 = codeGen(t->Ptr1);
				l1 = getLabel(); //Endif
				fprintf(stdout, "JZ R%d, L%d\n", r1, l1);
				codeGen(t->Ptr2);
				fprintf(stdout, "L%d:\n", l1);
			}
			freeReg();
			return -1;
			break;
		case WHILE:
			l1 = getLabel(); //start
			l2 = getLabel(); //end
			fprintf(stdout, "L%d:\n",l1);
			r1 = codeGen(t->Ptr1);
			fprintf(stdout, "JZ R%d, L%d\n", r1, l2);
			codeGen(t->Ptr2);
			fprintf(stdout, "L%d\n", l2);
			freeReg();
			return -1;
			break;
		case ARRVAL:
			r1 = codeGen(t->Ptr2);
			r2 = getReg();
			fprintf(stdout, "MOV R%d, %d\n", r2, (Glookup(t->Ptr1->NAME)->binding));
			fprintf(stdout, "ADD R%d, R%d\n", r1, r2);
			fprintf(stdout, "MOV R%d, [R%d]\n", r1, r1);
			freeReg();
			return r1;
			break;
		case ARRASGN:
			r1 = codeGen(t->Ptr1);
			r2 = getReg();
			fprintf(stdout, "MOV R%d, %d\n", r2, (Glookup(t->NAME)->binding));
			fprintf(stdout, "ADD R%d, R%d\n", r1, r2);
			r3 = codeGen(t->Ptr2);
			fprintf(stdout, "MOV [R%d], R%d\n", r1, r3);
			freeReg();
			freeReg();
			return r1;
			break;
		case ARRREAD:
			r1 = getReg();
			fprintf(stdout, "MOV R%d, %d\n", r1, (Glookup(t->NAME) -> binding));
			r2 = codeGen(t->Ptr1);
			fprintf(stdout, "ADD R%d, R%d\n", r1, r2);
			r3 = getReg();
			fprintf(stdout, "IN R%d\n", r3);
			fprintf(stdout, "MOV [%d], R%d\n", r1, r3);
			freeReg();
			freeReg();
			freeReg();
			return -1;
			break;
		default:
			printf("Something unexpected happenned: %d\n", t->NODETYPE);
			exit(-1);
	}
}
