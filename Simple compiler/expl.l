%option noyywrap

%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
%}

%%

[a-z]   { char *temp; temp=(char *)malloc(2*sizeof(char)); temp[0]=*yytext; temp[1]='\0'; yylval = TreeCreate(-1, ID, -1, temp, NULL, NULL, NULL, NULL); return ID;}
[0-9]+  { yylval = TreeCreate(-1, NUM, atoi(yytext), NULL, NULL, NULL, NULL, NULL); return NUM;}
"read"  { return READ;}
[=]     { return ASGN;}
[+]		{return PLUS;}
[*] 	{return MUL;}
"write"	{return WRITE;}
[)(;] 	{return *yytext;}
[\n] 	{return NEWLINE;}
[ \t] 	{}
"if" 	{return IF;}
"then" 	{return THEN;}
"while" {return WHILE;}
"do" 	{return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF;}
"<" 	{return LT;}
">" 	{return GT;}
"==" 	{return EQ;}

%%
