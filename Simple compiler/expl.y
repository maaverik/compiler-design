%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exptree.h"
	#include "sym_table.h"
	#include "codegen.h"
	#include "lsym_table.h"

	#define YYSTYPE struct tnode*

	extern FILE *yyin;

	int yylex();
	int yyerror(char *);
	struct Lsymbol *LST = NULL;
	int var_type;
%}

%token ID READ ASGN NEWLINE WRITE PLUS MUL SUB DIV EVAL IF THEN ELSE WHILE DO ENDWHILE ENDIF LT GT EQ NEQ STMT BREAK CONTINUE BEG END DECL ENDDECL INT BOOL MAIN RETURN
%nonassoc GT LT EQ NEQ
%left PLUS SUB
%left MUL DIV


%%

Program : GDefblock FdefList Mainblock {}
     ;

GDefblock : DECL decllist ENDDECL {}
	;

decllist : decl decllist {}
	| decl {}
	;

decl : type varlist ';' {}
	;

type : INT { var_type = INT;}
	| BOOL {var_type = BOOL;}

varlist : varlist ',' var {}
	| var {};

var : ID '[' INT ']' {
		if (Glookup($1->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		if ($3->TYPE != INT) {
			printf("Type error in int array declaration.\n");
			exit(-1);
		}
		if (var_type == INT)
			Ginstall($1->NAME, INTARR, 1*$3->VALUE, NULL);
		else
			Ginstall($1->NAME, BOOLARR, 1*$3->VALUE, NULL);
	}
	| ID {
		if (Glookup($1->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall($1->NAME, var_type, 1, NULL);
	}
	| ID '(' arglist ')' ';' {
		if (Glookup($1->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall($1->NAME, var_type, -1, (struct Paramstruct*)$3);
	}
	;

FdefList : Fdef {}
	| FdefList Fdef {}
	;

Fdef : type ID '(' arglist ')' '{' LDefBlock Body '}' {
		//Ginstall($2->NAME, var_type, -1, $3);
		struct Paramstruct *p = Glookup($2->NAME)->paramlist;
		struct tnode *t = $4;
		while (t != NULL && p != NULL){
			if (t->TYPE != p->type){
				printf("Argument types don't match\n");
				exit(0);
			}
			t = t->Ptr1;
			p = p->next;
		}
		if (t != NULL || p != NULL){
			printf("Incorrect number of arguments\n");
			exit(0);
		}
		int argBinding = -3;
		p = Glookup($2->NAME)->paramlist;
		while(p != NULL){		// Adding parameters to local symbol table
			Linstall(p->name, p->type, 1);
			LLookup(p->name)->binding = argBinding;
			argBinding--;
		}
		Glookup($2->NAME)->local = LST;
		codeGenStart($8, $2->NAME);
		LST = NULL;
	}
	;

arglist : arglist ',' arg {((struct Paramstruct*)$1)->next=((struct Paramstruct*)$3);}
	| arg {$$ = $1;}
	| %empty {$$ = NULL;}
	;

arg : type ID {
		struct Paramstruct *p = malloc(sizeof(struct Paramstruct));
		p->name = $2->NAME;
		p->type = var_type;
		p->next = NULL;
		$$ = (struct tnode*)p;
	}
	;

LDefBlock : DECL LDefList ENDDECL 	{}
	| DECL ENDDECL				{}
	;

LDefList :  LDefList LDecl {}
	| LDecl {}
	;

LDecl : type LIdList ';' {}
	;

LIdList : LIdList ',' LId {}
	| LId {}
	;

LId : ID { Linstall($1->NAME,var_type,1); }
	;

Mainblock : INT MAIN '(' ')' '{' LDefBlock Body '}' {
		Ginstall("MAIN", INT, -1, NULL);
		codeGenStart($7, "MAIN");
		exit(0);
	}
	;

Body : BEG slist RetStmt END {
		$$ = TreeCreate(-1, STMT, -1, NULL, NULL, $2, $3, NULL);
	}
	;

slist : slist stmt {
		if($1->TYPE != -1 || $2->TYPE != -1){
			printf("Type error\n");
			exit(-1);
		}
		$$ = TreeCreate(-1, STMT, -1, NULL, NULL, $1, $2, NULL);
	}
    | stmt {
     	if($1->TYPE != -1){
     		printf("Type error\n");
			exit(-1);
     	}
     	$$ = $1;
    }
    ;

stmt: 	ID ASGN expr ';' {
			if(Glookup($1->NAME) == NULL){
				printf("Unallocated variable '%s'", $1->NAME);
				exit(0);
			}
			if(Glookup($1->NAME)->paramlist != NULL){
				printf("Cannot assign to function '%s'", $1->NAME);
				exit(0);
			}
			if(Glookup($1->NAME)->type != $3->TYPE){
				printf("type error: =\n");
				exit(0);
			}
			$$ = TreeCreate(-1, ASGN, -1,  $1->NAME, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';' {
			if(Glookup($3->NAME) == NULL){
				printf("Unallocated variable '%s'", $3->NAME);
				exit(0);
			}
			$$ = TreeCreate(-1, READ, -1, $3->NAME, NULL, $3, NULL, NULL);
		}

		| READ '(' ID '[' expr ']' ')' ';' 	{
			if(Glookup($3->NAME) == NULL){
				printf("Unallocated variable '%s'", $3->NAME);
				exit(0);
			}
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
			if(Glookup($1->NAME) == NULL){
				printf("Unallocated variable '%s'", $1->NAME);
				exit(0);
			}
			if(!(Glookup($1->NAME)->type == INTARR || $3->TYPE == INT || $6->TYPE == INT) && !(Glookup($1->NAME)->type == BOOLARR || $3->TYPE == INT || $6->TYPE == BOOL)){
				printf("type error: []=\n");
				exit(0);
	 		}
			$$ = TreeCreate(-1, ARRASGN, -1, $1->NAME, NULL, $3, $6, NULL);
 		}
 		| ID '(' Args ')' ';' {
 			if (ID->paramlist == NULL){
 				printf("Not a function\n");
 				exit(0);
 			}
 			struct Paramstruct *p = $1->paramlist;
 			struct tnode *t = $3;
 			while (t != NULL && p != NULL){
 				if (t->type != p->type){
 					printf("Argument types don't match\n");
 					exit(0);
 				}
 				t = t->ArgList;
 				p = p->next;
 			}
 			if (t != NULL || p != NULL){
 				printf("Incorrect number of arguments\n");
 				exit(0);
 			}
 			$$ = TreeCreate(-1, FUNCCALL, -1, $1->NAME, $3, NULL, NULL, NULL);
 		}
		;

Args: expr ',' Args {$1->ArgList = $3;}
	| expr { $$ = S1;}
	| %empty {$$ = NULL;}
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

RetStmt : RETURN expr { $$ = TreeCreate(-1, RETURN, -1, NULL, NULL, $2, NULL, NULL); }
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
