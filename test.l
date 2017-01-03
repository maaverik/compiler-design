%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
%}


number [0-9]+           
op [-|+|*|/|^|=]    


%%

{number} {printf("Found : %d\n",atoi(yytext));
		  printf("Number of digits = %d",yyleng);}
{op} {//printf("Found : %c\n", *(yytext));
	  return *(yytext);}

%%

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	char c = yylex();
	printf("Found: %c\n",c);
	return 1;
}
