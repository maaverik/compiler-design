%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}

singlecomment "//".*
multicomment "/*"(.|\n)*"*/"
nomatch .*
%%

{singlecomment}|{multicomment} {
	printf("Comments : %s", yytext);
}

{nomatch} {}

%%

int main(int argc, char **argv) {
	FILE* fd = fopen(argv[1], "r");
	yyin = fd;
	yylex();
	return 0;
}
