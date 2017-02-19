%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE struct tnode*
	extern FILE *yyin;
	#include "exptree.c"

	int yylex();
	int yyerror(char *);

	int var_type;
%}

//%union{
//  int integer;
//  char character;
//};

%token ID READ ASGN NEWLINE WRITE PLUS MUL SUB DIV EVAL IF THEN ELSE WHILE DO ENDWHILE ENDIF LT GT EQ NEQ SLIST BREAK CONTINUE BEG END DECL ENDDECL INT BOOL
%nonassoc GT LT EQ NEQ
%left PLUS SUB
%left MUL DIV



%%

Program : decls main {}
		| main {}
     ;

decls : DECL decllist ENDDECL {}
	;
decllist : decl decllist {}
	| decl {}
	;
decl : type varlist ';' {}
	;

type : INT { var_type = INT;}
	| BOOL {var_type = BOOL;}

varlist : varlist ',' ID {Ginstall($3->NAME, INT, sizeof(int));}
	| varlist ',' ID '[' INT ']' {
		if ($5->TYPE != INT) {
			printf("Type error in array declaration.\n");
			exit(-1);
		}
		if (var_type == INT)
			Ginstall($3->NAME, INTARR, sizeof(int)*$5->VALUE);
		else
			Ginstall($3->NAME, BOOLARR, sizeof(int)*$5->VALUE);
	}
	| ID '[' INT ']' {
		if ($3->TYPE != INT) {
			printf("Type error in int array declaration.\n");
			exit(-1);
		}
		if (var_type == INT)
			Ginstall($1->NAME, INTARR, sizeof(int)*$3->VALUE);
		else
			Ginstall($1->NAME, BOOLARR, sizeof(int)*$3->VALUE);
	}
	| ID {Ginstall($1->NAME, var_type, sizeof(int));}
	;

main : BEG slist END {evaluate($2); exit(1);}
	;

slist : slist stmt {
		if($1->TYPE != -1 || $2->TYPE != -1){
			printf("Type error\n");
			exit(-1);
		}
		$$ = TreeCreate(-1, SLIST, -1, NULL, NULL, $1, $2, NULL);
	}
    | stmt {
     	if($1->TYPE != -1){
     		printf("Type error\n");
			exit(-1);
     	}
     	$$ = $1;
    }
    ;
stmt: 	ID ASGN expr ';'	{

			if(Glookup($1->NAME)->type != $3->TYPE){
				printf("type error: =\n");
				exit(0);
			}
			$$ = TreeCreate(-1, ASGN, -1, NULL, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';' {
			$$ = TreeCreate(-1, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| READ '(' ID '[' expr ']' ')' ';' 	{
			if($5->TYPE != INT) {
				printf("type error: ARRREAD[expr]");
				exit(0);
			}
			if(Glookup($3->NAME)->type != INTARR && Glookup($3->NAME)->type != BOOLARR)	{
				printf("type error: ARRREAD");
				exit(0);
			}
	 	 	$$ = TreeCreate(-1, ARRREAD, 0, $3->NAME, NULL, $5, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(-1, WRITE, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ELSE slist ENDIF ';' {
			if($3->TYPE != BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if($6->TYPE != -1){
				printf("type error: THEN\n");
				exit(0);
			}
			if($8->TYPE != -1){
				printf("type error: ELSE\n");
				exit(0);
			}
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, $8);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			if($3->TYPE != BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if($6->TYPE != -1){
				printf("type error: THEN\n");
				exit(0);
			}
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, NULL);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			if($3->TYPE != BOOL){
				printf("type error: WHILE\n");
				exit(0);
			}
			if($6->TYPE != -1){
				printf("type error: DO\n");
				exit(0);
			}
			$$ = TreeCreate(-1, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}

		| BREAK ';' {
			$$ = TreeCreate(-1, BREAK, -1, NULL, NULL, NULL, NULL, NULL);
		}

		| CONTINUE ';' {
			$$ = TreeCreate(-1, CONTINUE, -1, NULL, NULL, NULL, NULL, NULL);
		}

		| ID '[' expr ']' ASGN expr ';'	{
			if(!(Glookup($1->NAME)->type == INTARR || $3->TYPE == INT || $6->TYPE == INT) && !(Glookup($1->NAME)->type == BOOLARR || $3->TYPE == INT || $6->TYPE == BOOL)){
				printf("type error: []=\n");
				exit(0);
	 		}
			$$ = TreeCreate(-1, ARRASGN, -1, $1->NAME, NULL, $3, $6, NULL);
 		}
		;

expr: expr PLUS expr {
		if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: +\n");
			exit(0);
		}
		$$ = makeOperatorNode(PLUS, INT, $1, $3);
	}

	 | expr MUL expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: *\n");
			exit(0);
		}
		$$ = makeOperatorNode(MUL, INT, $1, $3);
	}

	 | expr SUB expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: -\n");
			exit(0);
		}
		$$ = makeOperatorNode(SUB, INT, $1, $3);
	}

	 | expr DIV expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: /\n");
			exit(0);
		}
		$$ = makeOperatorNode(DIV, INT, $1, $3);
	}

	 | '(' expr ')'	{$$ = TreeCreate(-1, EVAL, -1, NULL, NULL, $2, NULL, NULL);}

	 | INT {$$ = $1;}

	 | BOOL {$$ = $1;}

	 | ID {
	 	if (Glookup($1->NAME) == NULL){
	 		printf("Undeclared variable %s\n", $1->NAME);
	 		exit(-1);
	 	}
	 	$1->TYPE = Glookup($1->NAME)->type;
	 	$$ = $1;
	 }

	 | ID '[' expr ']'	{
	 	if($3->TYPE != INT){
	 		printf("type error: []\n");
			exit(0);
	 	}
	 	if (Glookup($1->NAME) == NULL){
	 		printf("Undeclared variable %s\n", $1->NAME);
	 		exit(-1);
	 	}
	 	if(Glookup($1->NAME)->type == INTARR){
	 		$$ = makeOperatorNode(ARRVAL, INT, $1, $3);
	 	}
	 	else if(Glookup($1->NAME)->type == BOOLARR){
	 		$$ = makeOperatorNode(ARRVAL, BOOL, $1, $3);
	 	}
	 	else {
	 		printf("Type error array lookup");
	 		exit(-1);
	 	}

	 }

	 | expr LT expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: <\n");
			exit(0);
		}
		 $$ = makeOperatorNode(LT, BOOL, $1, $3);
	 }

	 | expr GT expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: >\n");
			exit(0);
		}
		 $$ = makeOperatorNode(GT, BOOL, $1, $3);
	 }

	 | expr EQ expr {
	 	if(!(($1->TYPE == INT && $3->TYPE == INT) || ($1->TYPE == BOOL && $3->TYPE == BOOL))){
			printf("type error: ==\n");
			exit(0);
		}
		 $$ = makeOperatorNode(EQ, BOOL, $1, $3);
	 }
	 ;

	 | expr NEQ expr {
	 	if($1->TYPE != INT || $3->TYPE != INT){
			printf("type error: !=\n");
			exit(0);
		}
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
