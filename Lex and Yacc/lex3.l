%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}

space [\t\n]
word A[a-zA-Z][a-zA-Z]
nomatch .*
%%

{word}{space}+ {
	printf("Words are %s\n", yytext);
}

{nomatch} {}

%%

int main(int argc, char **argv) {
	FILE* fd = fopen(argv[1], "r");
	yyin = fd;
	yylex();
	return 0;
}
