%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	int ints = 0, floats = 0;
%}

int_ [0-9]+
float_ [0-9]+[.][0-9]+
nomatch .*

%%

{int_} {
	ints++;
}
{float_} {
	floats++;
}

{nomatch} {}

%%

int main(int argc, char **argv) {
	FILE* fd = fopen(argv[1], "r");
	yyin = fd;
	yylex();
	printf("%d ints, %d floats\n", ints, floats);
	return 0;
}
