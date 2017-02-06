%option noyywrap

%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "expl.h"
	#include "y.tab.h"
%}

%%

"read"  { return READ;}
"write"	{return WRITE;}
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
[\n] 	{return NEWLINE;}
[ \t] 	{}
"<" 	{return LT;}
">" 	{return GT;}
"==" 	{return EQ;}
[a-z]   { char *temp; temp=(char *)malloc(2*sizeof(char)); temp[0]=*yytext; temp[1]='\0'; yylval = TreeCreate(-1, ID, -1, temp, NULL, NULL, NULL, NULL); return ID;}
[0-9]+  { yylval = TreeCreate(-1, NUM, atoi(yytext), NULL, NULL, NULL, NULL, NULL); return NUM;}

%%
