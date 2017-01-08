%option noyywrap

/*
	Print number of lines, characters and words
*/

%{
	#include <stdio.h>
	#include <stdlib.h>

	int lines = 0, words = 0, chars = 0;
%}

line "\n"
space " "
char_ .

%%

{line} {
	lines++;
	words++;
}

{space} {
	words++;
}

{char_} {
	chars++;
}



%%

int main(int argc, char **argv)
{
	FILE* fd = fopen(argv[1], "r");
	yyin = fd;
	int token = yylex();
	printf("%d lines, %d words, %d chars\n", lines, words, chars);
	return 0;
}
