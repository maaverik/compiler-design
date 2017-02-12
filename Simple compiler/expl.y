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

%token ID READ ASGN NEWLINE WRITE PLUS MUL SUB DIV EVAL IF THEN ELSE WHILE DO ENDWHILE ENDIF LT GT EQ NEQ SLIST BREAK CONTINUE BEG END DECL ENDDECL INT BOOL
%nonassoc GT LT EQ NEQ
%left PLUS
%left MUL
%left SUB
%left DIV



%%

Program : decls main {}
		| main {}
     ;

decls : DECL decllist ENDDECL {}
	;
decllist : decl decllist {}
	| decl {}
	;
decl : INT ID ';' {	Ginstall($2->NAME, INT, sizeof(int));}

	| BOOL ID ';' {	Ginstall($2->NAME, BOOL, sizeof(int));}

	| INT ID '[' INT ']' ';'{ Ginstall($2->NAME, BOOL, sizeof(int)*$4->VALUE); }
	;
main : BEG slist END {evaluate($2); exit(1);}
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

		| IF '(' expr ')' THEN slist ENDIF ';' {
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, NULL);
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
		| ID '[' expr ']' ASGN expr ';'	{
       		$$ = TreeCreate(-1, ARRASGN, -1, $1->NAME, NULL, $3, $6, NULL);
 		}

		;

expr: expr PLUS expr {$$ = makeOperatorNode(PLUS, INT, $1, $3);}

	 | expr MUL expr {$$ = makeOperatorNode(MUL, INT, $1, $3);}

	 | expr SUB expr {$$ = makeOperatorNode(SUB, INT, $1, $3);}

	 | expr DIV expr {$$ = makeOperatorNode(DIV, INT, $1, $3);}

	 | '(' expr ')'	{$$ = TreeCreate(-1, EVAL, -1, NULL, NULL, $2, NULL, NULL);}

	 | INT {$$ = $1;}

	 | BOOL {$$ = $1;}

	 | ID {$$ = $1;}

	 | ID '[' expr ']'	{ $$ = makeOperatorNode(ARRVAL, INT, $1, $3); }

	 | expr LT expr {
		 $$ = makeOperatorNode(LT, BOOL, $1, $3);
	 }

	 | expr GT expr {
		 $$ = makeOperatorNode(GT, BOOL, $1, $3);
	 }

	 | expr EQ expr {
		 $$ = makeOperatorNode(EQ, BOOL, $1, $3);
	 }
	 ;

	 | expr NEQ expr {
		 $$ = makeOperatorNode(NEQ, BOOL, $1, $3);
	 }
	 ;

%%

int yyerror(char *s){
	printf("Error: %s\n", s);
	return -1;
}

int main(int argc, char **argv){
	FILE *fp;
	fp = fopen(argv[1],"r");
	yyin = fp;
	yyparse();
	return 1;
}
