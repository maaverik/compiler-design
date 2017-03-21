#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "sym_table.h"
#include "exptree.h"
#include "codegen.h"

int nextFreeReg = 0;
int nextLabel = 0;
int func_label = 0;
extern int nextFreeLocation;
int first_call = 1;
FILE *fp;

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
	return nextLabel++;
}

void codeGenStart(struct tnode *t, char caller[]){
	if (first_call){
		fp = fopen("./LabelTranslation/out.xsm", "w");
		printheader();
		fprintf(fp, "MOV SP,%d\n",nextFreeLocation);
		funcDecl(caller);
		codeGen(t);
		//funcRet(caller);
		first_call = 0;
	}
	else{
		funcDecl(caller);
		codeGen(t);
		//funcRet(caller);
	}
	if (strcmp("MAIN", caller)){
		// return of main should write INT 10 instead of RET
		fclose(fp);
	}
}

void printheader(){
	fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");	//Only start of stack shown, rest done by simulator
}

void funcDecl(char caller[]){
	if (strcmp("MAIN", caller)){
		fprintf(fp, "MAIN:\n");
		Glookup("MAIN")->flabel = -1;
	}
	else{
		fprintf(fp, "F%d:\n", func_label);
		Glookup(caller)->flabel = func_label;
		func_label++;
	}
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP,SP\n");
	struct Lsymbol *l = Glookup(caller)->local;
	int r1 = getReg();
	int size = 0;
	while (l != NULL){
		size++;
		l = l->next;
	}
	fprintf(fp, "ADD SP, %d\n", size); // pushing empty space for local variables
	freeReg();
}

void funcRet(caller){
	struct Lsymbol *l = Glookup(caller)->local;
	int r1 = getReg();
	int size = 0;
	while (l != NULL){
		size++;
		l = l->next;
	}
	fprintf(fp, "SUB SP, %d\n", size);
	freeReg();
	fprintf(fp, "POP BP\n");
}


int codeGen(struct tnode* t){
	int l1, l2, r1, r2, r3;
	if (t == NULL){
		printf("NULL\n");
		return 0;
	}
	switch(t->NODETYPE){
		case INT:
			r1 = getReg();
			fprintf(fp, "MOV R%d,%d\n",r1,t->VALUE );
			return r1;
			break;
		case PLUS:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case SUB:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "SUB R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case DIV:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "DIV R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case MUL:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "MUL R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case EQ:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "EQ R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case GT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "GT R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case LT:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "LT R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case NEQ:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "NE R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case ASGN:
			r1 = codeGen(t->Ptr2);
			if (LLookup(t->NAME) != NULL){
				r2 = getReg();
				fprintf(fp, "MOV R%d, BP\n", r2);
				fprintf(fp, "ADD R%d, %d\n", r2, LLookup(t->NAME)->binding);
				fprintf(fp, "MOV [R%d], R%d\n", r2, r1);
			}
			else{
				fprintf(fp, "MOV [%d], R%d\n", Glookup(t->NAME)->binding, r1);
			}
			freeReg();
			return 0;
			break;
		case STMT:
			codeGen(t->Ptr1);
			codeGen(t->Ptr2);
			return 1;
			break;
		case WRITE:
			r2 = codeGen(t->Ptr1);
			for(r1=0;r1<nextFreeReg;r1++)	//push all registers in use
				fprintf(fp, "PUSH R%d\n",r1);
			r1 = getReg();
			fprintf(fp, "MOV R%d,\"Write\"\n", r1);
			fprintf(fp, "PUSH R%d\n",r1 );
			fprintf(fp, "MOV R%d,-2\n", r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,SP\n",r1 );
			fprintf(fp, "SUB R%d,2\n",r1 );
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "CALL 0\n");
			fprintf(fp, "POP R%d\n",r2); //return value
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			for(r1=nextFreeReg-2;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			freeReg();
			break;
		case READ:
			r2 = getReg();
			fprintf(fp, "MOV R%d,0\n",r2);
			if (LLookup(t->NAME) != NULL){
				r1 = getReg();
				fprintf(fp, "MOV R%d, BP\n",r1);
				fprintf(fp, "ADD R%d, %d\n", r1, LLookup(t->NAME)->binding);
				fprintf(fp, "ADD R%d,R%d\n", r2, r1);
				freeReg();
			}
			else{
				fprintf(fp, "ADD R%d,%d\n",r2,Glookup(t->NAME)->binding);
			}
			r1 = getReg();
			for(r1=0;r1<nextFreeReg;r1++)		//push all registers in use
				fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,\"Read\"\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,-1\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r2);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "CALL 0\n");
			fprintf(fp, "POP R%d\n",r2);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			for(r1=nextFreeReg-2;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			freeReg();
			break;
		case ID:
			if (LLookup(t->Ptr1->NAME) != NULL){
				r1 = getReg();
				r2 = getReg();
				fprintf(fp, "MOV R%d, BP\n",r2);
				fprintf(fp, "ADD R%d, %d\n",r2,  Llookup(t->NAME)->binding);
				fprintf(fp, "MOV R%d, [R%d]\n", r1, r2);
				freeReg();
				return r1;
			}
			else {
				r1 = getReg();
				fprintf(fp, "MOV R%d, [%d]\n", r1, Glookup(t->NAME)->binding);
				return r1;
			}
			break;
		case IF:
			if(t->Ptr3 != NULL){
				r1 = codeGen(t->Ptr1);
				l1 = getLabel(); //Else
				l2 = getLabel(); //Endif
				fprintf(fp, "JZ R%d, L%d\n", r1, l1);
				codeGen(t->Ptr2);
				fprintf(fp, "JMP L%d\n", l2);
				fprintf(fp, "L%d:\n", l1);
				codeGen(t->Ptr3);
				fprintf(fp, "L%d:\n", l2);
			}
			else{
				r1 = codeGen(t->Ptr1);
				l1 = getLabel(); //Endif
				fprintf(fp, "JZ R%d, L%d\n", r1, l1);
				codeGen(t->Ptr2);
				fprintf(fp, "L%d:\n", l1);
			}
			freeReg();
			return -1;
			break;
		case WHILE:
			l1 = getLabel(); //start
			l2 = getLabel(); //end
			fprintf(fp, "L%d:\n",l1);
			r1 = codeGen(t->Ptr1);
			fprintf(fp, "JZ R%d, L%d\n", r1, l2);
			codeGen(t->Ptr2);
			fprintf(fp, "JMP L%d\n",l1);
			fprintf(fp, "L%d:\n", l2);
			freeReg();
			return 0;
			break;
		case ARRVAL:
			r1 = codeGen(t->Ptr2);
			r2 = getReg();
			fprintf(fp, "MOV R%d, %d\n", r2, (Glookup(t->Ptr1->NAME)->binding));
			fprintf(fp, "ADD R%d, R%d\n", r1, r2);
			fprintf(fp, "MOV R%d, [R%d]\n", r1, r1);
			freeReg();
			return r1;
			break;
		case ARRASGN:
			r1 = codeGen(t->Ptr1);
			r2 = getReg();
			fprintf(fp, "MOV R%d, %d\n", r2, (Glookup(t->NAME)->binding));
			fprintf(fp, "ADD R%d, R%d\n", r1, r2);
			r3 = codeGen(t->Ptr2);
			fprintf(fp, "MOV [R%d], R%d\n", r1, r3);
			freeReg();
			freeReg();
			return r1;
			break;
		case ARRREAD:
			r2 = codeGen(t->Ptr1);
			fprintf(fp, "ADD R%d,%d\n",r2,Glookup(t->NAME)->binding);
			r1 = getReg();
			for(r1=0;r1<nextFreeReg;r1++)		//push all registers in use
				fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,\"Read\"\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,-1\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r2);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "CALL 0\n");
			fprintf(fp, "POP R%d\n",r2);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			for(r1=nextFreeReg-2;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			freeReg();
			break;
		case FUNCCALL:

			break;
		case RETURN:

			break;

		default:
			printf("Something unexpected happenned: %d\n", t->NODETYPE);
			exit(-1);
	}
}
