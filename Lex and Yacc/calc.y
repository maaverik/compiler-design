%{
	#include <stdio.h>
%}

%token DIGIT
%left '+' '-'
%left '*' '/'

%%

start : expr '\n' { printf("Expression value = %d\n",$1);exit(1);}
;
expr: expr '+' expr {$$ = $1 + $3;}
	| expr '-' expr {$$ = $1 - $3;}
	| expr '/' expr {$$ = $1 / $3;}
	| expr '*' expr {$$ = $1 * $3;}
	| '(' expr ')' {$$ = $2;}
	| DIGIT {$$ = $1;}
;

%%

yyerror()
{
	printf("Error");
}
main()
{
	yyparse();
	return 1;
}
