%option noyywrap

%{
	#include <stdlib.h>
	#include <stdio.h>
	#define YYSTYPE struct tnode*
	#include "y.tab.h"
	#include "exptree.h"
	#include "sym_table.h"

	struct Gsymbol *GST = NULL;
%}

%%

"read"  { return READ;}
"write"	{return WRITE;}
"begin" {return BEG;}
"end"   {return END;}
"if" 	{return IF;}
"then" 	{return THEN;}
"else"  {return ELSE;}
"while" {return WHILE;}
"do" 	{return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF;}
"break" {return BREAK;}
"continue" {return CONTINUE;}

[=]     { return ASGN;}
[+]		{return PLUS;}
[*] 	{return MUL;}
[);(] 	{return *yytext;}
[ \t\n] 	{}
"<" 	{return LT;}
">" 	{return GT;}
"==" 	{return EQ;}
[a-zA-Z_][a-zA-Z_0-9]*   { char *temp=malloc(sizeof(char)*(strlen(yytext)+1));
	strcpy(temp, yytext);
	yylval = TreeCreate(-1, ID, -1, temp, NULL, NULL, NULL, NULL);
	Ginstall(temp, NUM, sizeof(int));
	return ID;}
[0-9]+  { yylval = TreeCreate(-1, NUM, atoi(yytext), NULL, NULL, NULL, NULL, NULL); return NUM;}

%%
