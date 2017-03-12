%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int temp, flag = 0;
	FILE *fp;
	char *tmp;
	struct ltable *laddr = NULL;
	struct ltable *labtable = NULL;
	int nextAddr = 2048 - 8; //First 8 lines constitute one word each not two
	#include "lab_trans.h"
%}

%%

"L"[0-9]+":"\n  { if(flag==0) { labtable = insertLab(strdup(yytext), nextAddr, labtable);} }

"F"[0-9]+":"\n  { if(flag==0) { labtable = insertLab(strdup(yytext), nextAddr, labtable);} }

"MAIN:"\n  { if(flag==0) { labtable = insertLab(strdup(yytext), nextAddr, labtable);} }

"L"[0-9]+ {
	if(flag == 1){
		laddr = searchLab(yytext, labtable);
		if(laddr==NULL)
			printf("NOLABELSTRING :: %s\n",yytext);
		else
			fprintf(fp, "%d",laddr->addr);
	}
}

"F"[0-9]+ {
	if(flag==1){
		laddr=searchLab(yytext, labtable);
		if(laddr==NULL)
			printf("NOLABELSTRING :: %s\n",yytext);
		else
			fprintf(fp, "%d",laddr->addr);
		}
	}

"MAIN" {
	if(flag==1){
		laddr=searchLab(yytext, labtable);
		if(laddr==NULL)
			printf("NOLABELSTRING :: %s\n",yytext);
		else fprintf(fp, "%d",laddr->addr);
	}
}

\n {
	if(flag==1)
		fprintf(fp,"\n");
	else if(flag==0)
		nextAddr+=2;
}
. { if(flag==1) {fprintf(fp, "%c",*yytext);} }

%%

int yywrap(){
	if(flag == 0){
		yyin = fopen(tmp,"r");
		flag = 1;
		return 0;
	}
	else
		return 1;
}

int main(int argc, char **argv) {
	yyin = fopen(argv[1],"r");
	tmp = argv[1];
	fp=fopen("../xsm_expl/out.xsm","w");
	yylex();
	return 0;
}
