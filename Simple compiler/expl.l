%option noyywrap

%{
	#include <stdlib.h>
	#include <stdio.h>
	#define YYSTYPE struct tnode*
	#include "y.tab.h"
	#include "exptree.h"
	#include "sym_table.h"
	#include "typetable.h"

	struct Gsymbol *GST = NULL;
	extern struct Typetable *VAR_TYPE_INT;
	extern struct Typetable *VAR_TYPE_BOOL;
	extern struct Typetable *VAR_TYPE_VOID;

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
"int" 	{return INT;}
"bool"	{return BOOL;}
"true" 	{yylval = TreeCreate(VAR_TYPE_BOOL, BOOL, TRUE, NULL, NULL, NULL, NULL, NULL); return BOOL;}
"false"	{yylval = TreeCreate(VAR_TYPE_BOOL, BOOL, FALSE, NULL, NULL, NULL, NULL, NULL); return BOOL;}
"decl" 	{return DECL;}
"enddecl" {return ENDDECL;}
"main" {return MAIN;}
"return" {return RET;}
"breakpoint" {return BRKP;}
"Initialize" {return INIT;}
"alloc"	{return ALLOC;}
"free" {return FREE;}
"type" 	{return TYP;}
"endtype" {return ENDTYPE;}
"null"	{return TNULL;}

[=]     {return ASGN;}
[+]		{return PLUS;}
[*] 	{return MUL;}
"-"		{return MINUS;}
[/]		{return DIV;}
[);({}] 	{return *yytext;}
[ \t\n] {}
","	{return *yytext;}
("["|"]")	{return *yytext;}
"<" 	{return LT;}
"<=" 	{return LE;}
">=" 	{return GE;}
">" 	{return GT;}
"==" 	{return EQ;}
"!=" 	{return NEQ;}
[a-zA-Z_][a-zA-Z_0-9]*   { char *temp=malloc(sizeof(char)*(strlen(yytext)+1));
	strcpy(temp, yytext);
	yylval = TreeCreate(VAR_TYPE_VOID, ID, -1, temp, NULL, NULL, NULL, NULL);
	return ID;
	}
[0-9]+  { yylval = TreeCreate(VAR_TYPE_INT, INT, atoi(yytext), yytext, NULL, NULL, NULL, NULL); return INT;
	}
"&&"	{return AND;}
"||"	{return OR;}
"!"		{return NOT;}

%%
