%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE struct tnode*
	extern FILE *yyin;
	#include "exptree.c"

	int yylex();
	int yyerror(char *);
%}

//%union{
//  int integer;
//  char character;
//};

%token ID
%token NUM
%token READ ASGN NEWLINE WRITE PLUS MUL EVAL IF THEN ELSE WHILE DO ENDWHILE ENDIF LT GT EQ SLIST BREAK CONTINUE BEG END INT DECL ENDDECL
%nonassoc GT LT EQ
%left PLUS
%left MUL


%%

Program : decls main {exit(1);}
		| main {exit(1);}
     ;

decls : DECL decllist ENDDECL {}
	;
decllist : decl decllist {}
		| decl {}
	;
decl : INT ID ';' {
			Ginstall($2->NAME, NUM, sizeof(int));
		}
	;
main : BEG slist END {evaluate($2);}
	;

slist : slist stmt {$$ = TreeCreate(-1, SLIST, -1, NULL, NULL, $1, $2, NULL);}
     | stmt {$$ = $1;}
     ;
stmt: ID ASGN expr ';'	{
			$$ = TreeCreate(-1, ASGN, -1, NULL, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';'	{
			$$ = TreeCreate(-1, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(-1, WRITE, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ELSE slist ENDIF ';' {
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, $8);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			$$ = TreeCreate(-1, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}
		| BREAK ';' {
			$$ = TreeCreate(-1, BREAK, -1, NULL, NULL, NULL, NULL, NULL);
		}
		| CONTINUE ';' {
			$$ = TreeCreate(-1, CONTINUE, -1, NULL, NULL, NULL, NULL, NULL);
		}

		;

expr: expr PLUS expr {
		$$ = makeOperatorNode(PLUS, $1, $3);
	}
	 | expr MUL expr {$$ = makeOperatorNode(MUL, $1, $3);}

	 | '(' expr ')'	{$$ = TreeCreate(-1, EVAL, -1, NULL, NULL, $2, NULL, NULL);}

	 | NUM {$$ = $1;}

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

int yyerror(char *s){
	printf("Error\n");
	return -1;
}

int main(int argc, char **argv){
	FILE *fp;
	fp = fopen(argv[1],"r");
	yyin = fp;
	yyparse();
	return 1;
}
