%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE struct tnode*
	#include "expl.c"

%}

//%union{
//  int integer;
//  char character;
//};

%token ID
%token NUM
%token READ ASGN NEWLINE WRITE PLUS MUL EVAL IF THEN WHILE DO ENDWHILE ENDIF LT GT EQ
%nonassoc GT LT EQ
%left PLUS
%left MUL


%%

Program : slist NEWLINE {printf("%d\n",evaluate($1));exit(1);}
     ;
slist : slist stmt
     | stmt
     ;
stmt: ID ASGN expr ';'	{
			$$ = TreeCreate(-1, ASGN, -1, NULL, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';'	{
			$$ = TreeCreate(-1, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(-1, EVAL, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, NULL);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			$$ = TreeCreate(-1, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}
		;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3);}

	 | '(' expr ')'		{$$ = TreeCreate(-1, EVAL, -1, NULL, NULL, $2, NULL, NULL);}

	 | NUM			{$$ = $1;}

	 | ID {$$ = $1;}

	 | expr LT expr {
		 $$ = makeOperatorNode(LT, $1, $3);
	 }

	 | expr GT expr {
		 $$ = makeOperatorNode(GT, $1, $3);
	 }

	 | expr EQ expr {
		 $$ = makeOperatorNode(EQ, $1, $3);
	 }
	 ;

%%

int yyerror(char const *s){
	printf("Error");
}

int main(){
	yyparse();
	return 1;
}
