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

int codeGen(struct tnode* t){
	int r1, r2;
	switch(t->NODETYPE){
		case INT:
			r1 = getReg();
			fprintf(stdout, "MOV R%d %d\n", r1, t->VALUE);
			return r1;
			break;
		case BOOL:
			r1 = getReg();
			fprintf(stdout, "MOV R%d %d\n", r1, t->VALUE);
			return r1;
			break;
		case PLUS:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "ADD R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case SUB:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "SUB R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case DIV:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "DIV R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case MUL:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "MUL R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case EQ:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "EQ R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case GT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "GT R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case LT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(stdout, "LT R%d R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case SLIST:
			codeGen(t->Ptr1);
			return codeGen(t->Ptr2);
			break;
		case WRITE:
			r1 = codeGen(t->Ptr1);
			fprintf(stdout, "OUT R%d\n", r1);
			freeReg();
			return 0;
			break;
		case READ:
			if(Glookup(t->NAME) == NULL){
				printf("Unallocated variable '%s'", t->NAME);
				exit(0);
			}
			r1 = getReg();
			fprintf(stdout, "IN R%d\n", r1);
			fprintf(stdout, "MOV [%d] R%d\n", Glookup(t->NAME)->binding, r1);
			freeReg();
			return 0;
			break;
		case ID:
			if(Glookup(t->NAME) == NULL){
				printf("Unallocated variable '%s'", t->NAME);
				exit(0);
			}
			r1 = getReg();
			fprintf(stdout, "MOV R%d [%d]\n", r1, Glookup(t->NAME)->binding);
			return r1;
			break;
		default:
			printf("Something unexpected happenned: %d\n", t->NODETYPE);
			exit(-1);
	}
}
