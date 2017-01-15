%option noyywrap

%{
	#include "y.tab.h"
	#include <stdlib.h>
	#include <stdio.h>
%}

%%

[a-z]    { yylval.character = yytext[0]; return ID;}
[0-9]+   { yylval.integer = atoi(yytext); return NUM;}
"read"   { return READ;}
[=]      { return ASGN;}
[+]		 {return PLUS;}
[*] 	 {return MUL;}
"write"	 {return WRITE;}
[")""("";"] {return *yytext;}
[\n] 	 {return NEWLINE;}
[ \t] {}
"if" {return IF;}
"then" {return THEN;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF};
"<" {return LT;}
">" {return GT;}
"==" {return EQ;}

%%
