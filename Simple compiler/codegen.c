#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "sym_table.h"
#include "lsym_table.h"
#include "exptree.h"
#include "codegen.h"
#include "typetable.h"

char func_name[50];
int nextFreeReg = 0;
int nextLabel = 0;
int func_label = 1;
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

int pushargs(int r1, struct tnode *tmp, int count){
	if (tmp == NULL){
		return count;
	}
	count = pushargs(r1, tmp->Arglist, count+1);
	r1 = codeGen(tmp->Ptr1);
	fprintf(fp, "PUSH R%d\n", r1);
	freeReg();
	return count;
}

void getFieldAddr(int reg1, struct tnode *t){
	fprintf(fp, "ADD R%d,%d\n",reg1, t->VALUE);
	if(t->Ptr1!=NULL){
		fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg1);
		getFieldAddr(reg1, t->Ptr1);
	}
}

void codeGenStart(struct tnode *t, char func[]){
	strcpy(func_name, func);
	if (first_call){
		fp = fopen("./LabelTranslation/out.xsm", "w");
		printheader();
		fprintf(fp, "MOV SP,%d\n",nextFreeLocation);
		fprintf(fp, "MOV BP,%d\n",nextFreeLocation+1);
		fprintf(fp, "JMP MAIN\n");
		funcDecl();
		codeGen(t);
		first_call = 0;
	}
	else{
		funcDecl();
		codeGen(t);
	}
}

void printheader(){
	fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");	//Only start of stack shown, rest done by simulator
}

void funcDecl(){
	if (strcmp("MAIN", func_name) == 0){
		fprintf(fp, "MAIN:\n");
	}
	else{
		fprintf(fp, "F%d:\n", func_label);
		Glookup(func_name)->flabel = func_label;
		func_label++;
	}
	fprintf(fp, "PUSH BP\n");
	fprintf(fp, "MOV BP,SP\n");
	printf("\n%s : size = %d\n\n", func_name, Glookup(func_name)->size);
	fprintf(fp, "ADD SP, %d\n", Glookup(func_name)->size + 1); // pushing empty space for local variables
}

void funcRet(){
	if (strcmp(func_name, "MAIN") != 0){
		fprintf(fp, "SUB SP, %d\n", Glookup(func_name)->size + 1); //pop space for local variables
		fprintf(fp, "POP BP\n");
		fprintf(fp, "RET\n");
	}
	else{
		fprintf(fp, "INT 10\n");
		fclose(fp);
	}
}


int codeGen(struct tnode* t){
	int l1, l2, r1, r2, r3, treg;
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
		case MINUS:
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
		case LE:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "LE R%d, R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case GE:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			fprintf(fp, "GE R%d, R%d\n", r1, r2);
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
		case AND:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			printf("Haven't implemented AND yet\n");
			freeReg();
			return r1;
			break;
		case OR:
			r1 = codeGen(t->Ptr1);
			r2 = codeGen(t->Ptr2);
			printf("Haven't implemented OR yet\n");
			freeReg();
			return r1;
			break;
		case EVAL:
			r1 = codeGen(t->Ptr1);
			return r1;
			break;
		case ASGN:
			if (t->NAME != NULL){	//ID
				r1 = codeGen(t->Ptr2);
				if (LLookup(t->NAME) != NULL){
					r2 = getReg();
					fprintf(fp, "MOV R%d, BP\n", r2);
					fprintf(fp, "ADD R%d, %d\n", r2, LLookup(t->NAME)->binding);
					fprintf(fp, "MOV [R%d], R%d\n", r2, r1);
					freeReg();
				}
				else{
					fprintf(fp, "MOV [%d], R%d\n", Glookup(t->NAME)->binding, r1);
				}
				freeReg();
			}
			else{		//FIELD
				r1 = codeGen(t->Ptr2);
				if (LLookup(t->Ptr1->NAME) != NULL){
					r2 = getReg();
					fprintf(fp, "MOV R%d, BP\n", r2);
					fprintf(fp, "ADD R%d, %d\n", r2, LLookup(t->Ptr1->NAME)->binding);
					fprintf(fp, "MOV R%d, [R%d]\n", r2, r2);
					getFieldAddr(r2, t->Ptr1->Ptr1);
					fprintf(fp, "MOV [R%d], R%d\n", r2, r1);
					freeReg();
				}
				else{
					fprintf(fp, "MOV R%d, %d\n", r2, Glookup(t->Ptr1->NAME)->binding);
					fprintf(fp, "MOV R%d, [R%d]\n", r2, r2);
					getFieldAddr(r2, t->Ptr1->Ptr1);
					fprintf(fp, "MOV [R%d], R%d\n", r2, r1);
				}
				freeReg();
			}
			return 0;
			break;
		case STMT:
			codeGen(t->Ptr1);
			return codeGen(t->Ptr2);
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
			fprintf(fp, "INT 7\n");
			fprintf(fp, "POP R%d\n",r2); //return value
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			freeReg();
			for(r1=nextFreeReg-1;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			break;
		case READ:
			r2 = getReg();
			fprintf(fp, "MOV R%d,0\n",r2);
			if (LLookup(t->NAME) != NULL){
				r1 = getReg();
				fprintf(fp, "MOV R%d, BP\n",r1);
				if (t->NAME != NULL)
					fprintf(fp, "ADD R%d, %d\n", r1, LLookup(t->NAME)->binding);
				else
					fprintf(fp, "ADD R%d,%d\n", r1, LLookup(t->Ptr1->NAME)->binding);
				fprintf(fp, "ADD R%d,R%d\n", r2, r1);
				freeReg();
			}
			else{
				if (t->NAME != NULL)
					fprintf(fp, "ADD R%d,%d\n",r2,Glookup(t->NAME)->binding);
				else
					fprintf(fp, "ADD R%d,%d\n",r2,Glookup(t->Ptr1->NAME)->binding);
			}
			if (t->NAME == NULL){
				fprintf(fp, "MOV R%d,[R%d]\n", r2, r2);
				getFieldAddr(r2, t->Ptr1->Ptr1);
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
			fprintf(fp, "INT 6\n");
			fprintf(fp, "POP R%d\n",r2);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			for(r1=nextFreeReg-1;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			freeReg();
			break;
		case ID:
			if (LLookup(t->NAME) != NULL){
				r1 = getReg();
				r2 = getReg();
				fprintf(fp, "MOV R%d, BP\n",r2);
				fprintf(fp, "ADD R%d, %d\n",r2,  LLookup(t->NAME)->binding);
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
			fprintf(fp, "INT 6\n");
			fprintf(fp, "POP R%d\n",r2);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			fprintf(fp, "POP R%d\n",r1);
			for(r1=nextFreeReg-1;r1>=0;r1--)	//pop all pushed registers
				fprintf(fp, "POP R%d\n",r1);
			freeReg();
			freeReg();
			break;
		case FUNCCALL:
			for(r1=0; r1<nextFreeReg; r1++){
				fprintf(fp, "PUSH R%d\n", r1);
			}
			struct tnode *tmp = t->Arglist;
			r3 = pushargs(r1, tmp, 0);
			fprintf(fp, "PUSH R%d\n", r1);	// space for return value
			fprintf(fp, "CALL F%d\n", Glookup(t->NAME)->flabel);
			r2 = getReg();
			fprintf(fp, "POP R%d\n", r2);	// return value
			fprintf(fp, "SUB SP, %d\n", r3);	//pop space for arguments
			for(r1=nextFreeReg-2; r1>=0; r1--){
				fprintf(fp, "POP R%d\n", r1);
			}
			return r2;
			break;
		case RET:
			r2 = getReg();
			r1 = codeGen(t->Ptr1);
			fprintf(fp, "MOV R%d, BP\n", r2);
			fprintf(fp, "SUB R%d, 2\n", r2);
			fprintf(fp, "MOV [R%d], R%d\n", r2, r1);
			funcRet();
			freeReg();
			return r2;
			break;
		case BRKP:
			fprintf(fp, "BRKP\n");
			break;
		case FIELD:
			r2 = getReg();
			if (LLookup(t->Ptr1->NAME) != NULL){
				fprintf(fp, "MOV R%d, BP\n", r2);
				fprintf(fp, "ADD R%d, %d\n", r2, LLookup(t->Ptr1->NAME)->binding);
				fprintf(fp, "MOV R%d, [R%d]\n", r2, r2);
			}
			else{
				fprintf(fp, "MOV R%d, %d\n", r2, Glookup(t->Ptr1->NAME)->binding);
				fprintf(fp, "MOV R%d, [R%d]\n", r2, r2);
			}
			getFieldAddr(r1, t->Ptr1->Ptr1);
			fprintf(fp, "MOV R%d, [R%d]\n", r1, r1);
			return r1;
			break;
		case INIT:
			treg=0;
			for(treg=0;treg<nextFreeReg;treg++)
				fprintf(fp, "PUSH R%d\n",treg);
			fprintf(fp, "MOV R0,-1\n" );
			fprintf(fp, "PUSH R0\n" );
			fprintf(fp, "ADD SP,4\n" );
			fprintf(fp, "CALL 0\n" );
			fprintf(fp, "SUB SP,5\n" );
			for(treg=nextFreeReg-1;treg>=0;treg--)
				fprintf(fp, "POP R%d\n",treg);
			return 1;
			break;
		case ALLOC:
			treg=0;
			for(treg=0;treg<nextFreeReg;treg++)
				fprintf(fp, "PUSH R%d\n",treg);
			r1 = getReg();
			fprintf(fp, "MOV R%d,-2\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "MOV R%d,8\n",r1);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "ADD SP,3\n");
			fprintf(fp, "CALL 0\n" );
			fprintf(fp, "POP R%d\n",r1 );
			fprintf(fp, "SUB SP,4\n" );
			for(treg=nextFreeReg-2;treg>=0;treg--)
				fprintf(fp, "POP R%d\n",treg);
			return r1;
			break;
		case FREE:
			treg=0;
			for(treg=0;treg<nextFreeReg;treg++)
				fprintf(fp, "PUSH R%d\n",treg);
			if (LLookup(t->NAME) != NULL){
				r1 = getReg();
				r2 = getReg();
				fprintf(fp, "MOV R%d, BP\n",r2);
				fprintf(fp, "ADD R%d, %d\n",r2,  LLookup(t->NAME)->binding);
				fprintf(fp, "MOV R%d, [R%d]\n", r1, r2);
				freeReg();
			}
			else {
				r1 = getReg();
				fprintf(fp, "MOV R%d, [%d]\n", r1, Glookup(t->NAME)->binding);
			}
			r2 = getReg();
			fprintf(fp, "MOV R%d,-3\n",r2);
			fprintf(fp, "PUSH R%d\n",r2);
			fprintf(fp, "PUSH R%d\n",r1);
			fprintf(fp, "ADD SP,3\n");
			fprintf(fp, "CALL 0\n" );
			fprintf(fp, "SUB SP,5\n" );
			freeReg();
			freeReg();
			for(treg=nextFreeReg-1;treg>=0;treg--)
				fprintf(fp, "POP R%d\n",treg);
			return 1;
			break;
		case TNULL:
			r1 = getReg();
			fprintf(fp, "MOV R%d,-9999 \n",r1 );
			return r1;
			break;
		default:
			printf("Something unexpected happenned: %d\n", t->NODETYPE);
			exit(-1);
	}
}
