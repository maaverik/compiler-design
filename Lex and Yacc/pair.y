%{
	#include <stdio.h>
%}

%token DIGIT

%%

start : pair '\n' {printf("\nComplete");exit(1); }
;
pair: num ',' num { printf("pair(%d,%d)",$1,$3); }
;
num: DIGIT { $$=$1; }
	;

%%

yyerror()
{
	printf("Error");
}
int main(){
	yyparse();
	return 1;
}
