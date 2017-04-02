%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "exptree.h"
	#include "sym_table.h"
	#include "codegen.h"
	#include "lsym_table.h"
	#include "typetable.h"

	#define YYSTYPE struct tnode*

	int yylex();
	extern FILE *yyin;
	int isGDeclOver = 0;
	int yyerror(char *);
	struct Lsymbol *LST = NULL;
	struct Typetable *var_type;
	int nextLocation = 1;
	extern struct Typetable *VAR_TYPE_INT;
	extern struct Typetable *VAR_TYPE_INTARR;
	extern struct Typetable *VAR_TYPE_BOOLARR;
	extern struct Typetable *VAR_TYPE_BOOL;
	extern struct Typetable *VAR_TYPE_VOID;

%}

%token ID READ ASGN NEWLINE WRITE PLUS MUL MINUS DIV EVAL IF THEN ELSE WHILE DO ENDWHILE ENDIF LT GT EQ NEQ STMT BREAK CONTINUE BEG END DECL ENDDECL INT BOOL MAIN RET ARGS AND OR NOT LE GE BRKP INIT ALLOC DEALLOC TYPE ENDTYPE
%nonassoc GT LT EQ NEQ LE GE
%left PLUS MINUS MUL DIV AND OR NOT


%%

Program : TypeInit TypeDefBlock GDefblock FdefList Mainblock {}
	| TypeDefBlock GDefblock Mainblock {}
     ;

TypeInit : {TypeTableCreate();}

TypeDefBlock  : TYPE TypeDefList ENDTYPE {}
              | %empty {}
              ;

TypeDefList   : TypeDefList TypeDef {}
              | TypeDef {}
              ;

TypeDef       : TypeDefHead '{' FieldDeclList '}'   {
				int size = findSize($3); TInstall($1->name,size,$3);
				}
              ;

TypeDefHead : ID { TInstallId($1->name); $$ = $1;}

FieldDeclList : FieldDeclList FieldDecl {$$ = $2; insertField($1,$2);}
              | FieldDecl {$$ = $1;}
              ;

FieldDecl    : TypeName ID ';' {$$ = Finstall($1, $2->name);}

TypeName :  INT {$$ = strdup("INT");}
			| BOOL {$$ = strdup("BOOL");}
			| ID {$$ = $1->name;}
			;


GDefblock : DECL decllist ENDDECL {isGDeclOver = 1;}
	| DECL ENDDECL {isGDeclOver = 1;}
	;

decllist : decl decllist {}
	| decl {}
	;

decl : type varlist ';' {}
	;

type :  INT { var_type = TLookup(strdup("INT"));}
	 | BOOL { var_type = TLookup(strdup("BOOL"));}
	 | ID { var_type = TLookup($1->name);}
	 ;

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
		if (var_type == VAR_TYPE_INT)
			Ginstall($1->NAME, VAR_TYPE_INTARR, 1*$3->VALUE, NULL);
		else
			Ginstall($1->NAME, VAR_TYPE_BOOLARR, 1*$3->VALUE, NULL);
	}
	| ID {
		if (Glookup($1->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall($1->NAME, var_type, 1, NULL);
	}
	| ID '(' arglist ')' {
		if (Glookup($1->NAME) != NULL){
			printf("Already declared\n");
			exit(-1);
		}
		Ginstall($1->NAME, var_type, -1, (struct Paramstruct*)$3);
	}
	;

FdefList : FdefList Fdef {}
	| Fdef {}
	;

Fdef : type ID '(' arglist ')' '{' LDefBlock Body '}' {
		if (var_type == NULL){
			printf("Type is not defined\n");
			exit(-1);
		}
		if (Glookup($2->NAME) == NULL){
			printf("%s not defined\n", $2->NAME);
			exit(-1);
		}
		struct Paramstruct *p = Glookup($2->NAME)->paramlist;
		struct Paramstruct *t = (struct Paramstruct *)$4;
		while (t != NULL && p != NULL){
			if (t->type != p->type){
				printf("Argument types don't match 1\n");
				exit(0);
			}
			if (strcmp(t->name, p->name) != 0){
				printf("Argument names don't match\n");
				exit(0);
			}
			t = t->next;
			p = p->next;
		}
		if (t != NULL || p != NULL){
			printf("Incorrect number of arguments 1\n");
			exit(0);
		}

		int argBinding = -3;
		p = (struct Paramstruct*)$4;
		while(p != NULL){		// Adding parameters to local symbol table
			LLookup(p->name)->binding = argBinding;
			argBinding--;
			p = p->next;
		}

		struct Lsymbol *l = LST;
		int size = 0;
		while (l != NULL){
			if (l->binding < 0){
				l = l->next;
				continue;
			}
			size++;
			l = l->next;
		}
		Glookup($2->NAME)->size = size;
		Glookup($2->NAME)->local = LST;
		codeGenStart($8, $2->NAME);
		LST = NULL;
		nextLocation = 1;
	}
	;

arglist : arg ',' arglist {
		if (isGDeclOver){
			Linstall(((struct Paramstruct*)$1)->name, ((struct Paramstruct*)$1)->type, 1);
			nextLocation = 1;
		}
		((struct Paramstruct*)$1)->next=((struct Paramstruct*)$3);
		$$ = $1;
	}
	| arg {
		if (isGDeclOver){
			Linstall(((struct Paramstruct*)$1)->name, ((struct Paramstruct*)$1)->type, 1);
			nextLocation = 1;
		}
		$$ = $1;
	}
	| %empty {$$ = NULL;}
	;

arg : type ID {
		if (var_type == NULL){
			printf("Type is not defined\n");
			exit(-1);
		}
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

LId : ID {
		if (LLookup($1->NAME) != NULL){
			printf("Already declared %s", $1->NAME);
			exit(-1);
		}
		Linstall($1->NAME,var_type,1);
	}
	;

Mainblock : INT MAIN '(' ')' '{' LDefBlock Body '}' {
		Ginstall("MAIN", VAR_TYPE_INT, -1, NULL);
		struct Lsymbol *l = LST;
		int size = 0;
		while (l != NULL){
			if (l->binding < 0){
				l = l->next;
				continue;
			}
			size++;
			l = l->next;
		}
		Glookup("MAIN")->size = size;
		Glookup("MAIN")->local = LST;
		codeGenStart($7, "MAIN");
		LST = NULL;
		nextLocation = 1;
		exit(0);
	}
	;

Body : BEG slist RetStmt END {
		$$ = TreeCreate(VAR_TYPE_VOID, STMT, -1, NULL, NULL, $2, $3, NULL);
	}
	;

slist : slist stmt {
		if($1->TYPE != -1 || $2->TYPE != -1){
			printf("Type error\n");
			exit(-1);
		}
		$$ = TreeCreate(VAR_TYPE_VOID, STMT, -1, NULL, NULL, $1, $2, NULL);
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
			if(Glookup($1->NAME) == NULL && LLookup($1->NAME) == NULL){
				printf("Unallocated variable '%s in asgn'\n", $1->NAME);
				exit(0);
			}
			if(LLookup($1->NAME) == NULL && Glookup($1->NAME)->paramlist != NULL){
				printf("Cannot assign to function '%s'\n", $1->NAME);
				exit(0);
			}
			if(LLookup($1->NAME) == NULL && Glookup($1->NAME)->type != $3->TYPE){
				printf("type error: =\n");
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1,  $1->NAME, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';' {
			if(Glookup($3->NAME ) == NULL && LLookup($3->NAME) == NULL){
				printf("Unallocated variable '%s' in read\n", $3->NAME);
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, $3->NAME, NULL, $3, NULL, NULL);
		}

		| READ '(' ID '[' expr ']' ')' ';' 	{
			if(Glookup($3->NAME) == NULL && LLookup($3->NAME) == NULL){
				printf("Unallocated variable '%s' in readarr\n", $3->NAME);
				exit(0);
			}
			if($5->TYPE != INT) {
				printf("type error: ARRREAD[expr]");
				exit(0);
			}
			if(Glookup($3->NAME)->type != VAR_TYPE_INTARR && Glookup($3->NAME)->type != VAR_TYPE_BOOLARR)	{
				printf("type error: ARRREAD");
				exit(0);
			}
	 	 	$$ = TreeCreate(VAR_TYPE_VOID, ARRREAD, 0, $3->NAME, NULL, $5, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ELSE slist ENDIF ';' {
			if($3->TYPE != BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if($6->TYPE != VAR_TYPE_VOID){
				printf("type error: THEN\n");
				exit(0);
			}
			if($8->TYPE != VAR_TYPE_VOID){
				printf("type error: ELSE\n");
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, NULL, $3, $6, $8);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			if($3->TYPE != BOOL){
				printf("type error: IF\n");
				exit(0);
			}
			if($6->TYPE != VAR_TYPE_VOID){
				printf("type error: THEN\n");
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, NULL, $3, $6, NULL);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			if($3->TYPE != BOOL){
				printf("type error: WHILE\n");
				exit(0);
			}
			if($6->TYPE != VAR_TYPE_VOID){
				printf("type error: DO\n");
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}

		| BREAK ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, BREAK, -1, NULL, NULL, NULL, NULL, NULL);
		}

		| CONTINUE ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, CONTINUE, -1, NULL, NULL, NULL, NULL, NULL);
		}

		| ID '[' expr ']' ASGN expr ';'	{
			if(Glookup($1->NAME) == NULL && LLookup($1->NAME) == NULL){
				printf("Unallocated variable '%s' in asgnarr\n", $1->NAME);
				exit(0);
			}
			if(!(Glookup($1->NAME)->type == VAR_TYPE_INTARR || $3->TYPE == VAR_TYPE_INT || $6->TYPE == VAR_TYPE_INT) && !(Glookup($1->NAME)->type == VAR_TYPE_BOOLARR || $3->TYPE == VAR_TYPE_INT || $6->TYPE == VAR_TYPE_BOOL)){
				printf("type error: []=\n");
				exit(0);
	 		}
			$$ = TreeCreate(VAR_TYPE_VOID, ARRASGN, -1, $1->NAME, NULL, $3, $6, NULL);
 		}
 		| ID '(' Args ')' ';' {
 			struct Paramstruct *p = Glookup($1->NAME)->paramlist;
			struct tnode *t = $3;
			printf("Func: %s\n", $1->NAME);
			while (t != NULL && p != NULL){
				printf("Val : %d\n", t->Ptr1->VALUE);
				if (t->TYPE != p->type){
					printf("Argument types don't match 2\n");
					exit(0);
				}
				t = t->Arglist;
				p = p->next;
			}
 			if (t != NULL || p != NULL){
 				printf("Incorrect number of arguments 2\n");
 				exit(0);
 			}
 			$$ = TreeCreate(VAR_TYPE_VOID, FUNCCALL, -1, $1->NAME, $3, NULL, NULL, NULL);
 		}
 		| BRKP ';' {$$ = TreeCreate(VAR_TYPE_VOID, BRKP, -1, NULL, NULL, NULL, NULL, NULL);}
		| INIT '(' ')' {}
		| ID ASGN ALLOC '(' ')' {}
		| FIELD ASGN ALLOC '(' ')' {}
		| DEALLOC '(' ID ')' {}
		| DEALLOC '(' FIELD ')' {}
		| READ '(' FIELD ')' {}
		;


Args: Args ',' expr {$$ = TreeCreate($3->TYPE, ARGS, -1, NULL, $1, $3, NULL, NULL);}
	| expr { $$ = TreeCreate($1->TYPE, ARGS, -1, NULL, NULL, $1, NULL, NULL);}
	| %empty {$$ = NULL;}
	;

expr: expr PLUS expr {
		if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: +\n");
			exit(0);
		}
		$$ = makeOperatorNode(PLUS, VAR_TYPE_INT, $1, $3);
	}

	 | expr MUL expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: *\n");
			exit(0);
		}
		$$ = makeOperatorNode(MUL, VAR_TYPE_INT, $1, $3);
	}

	 | expr MINUS expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: -\n");
			exit(0);
		}
		$$ = makeOperatorNode(MINUS, VAR_TYPE_INT, $1, $3);
	}
	 | MINUS expr {
	 	if($2->TYPE != VAR_TYPE_INT){
			printf("type error: unary -\n");
			exit(0);
		}
		$$ = makeOperatorNode(MINUS, VAR_TYPE_INT, 0, $2);
	}

	 | expr DIV expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: /\n");
			exit(0);
		}
		$$ = makeOperatorNode(DIV, VAR_TYPE_INT, $1, $3);
	}
	 | '(' expr ')'	{$$ = TreeCreate($2->TYPE, EVAL, -1, NULL, NULL, $2, NULL, NULL);}
	 | INT {$$ = $1;}
	 | BOOL {$$ = $1;}
	 | ID {
	  	if (LLookup($1->NAME) != NULL)
	 		$1->TYPE = LLookup($1->NAME)->type;
	 	else if (Glookup($1->NAME) != NULL)
	 		$1->TYPE = Glookup($1->NAME)->type;
	 	else{
	 		printf("Undeclared variable %s\n", $1->NAME);
	 		exit(-1);
	 	}
	 	$$ = $1;
	 }
	 | ID '[' expr ']'	{
	 	if($3->TYPE != INT){
	 		printf("type error: []\n");
			exit(0);
	 	}
	 	if (Glookup($1->NAME) != NULL){
	 		if(Glookup($1->NAME)->type == VAR_TYPE_INTARR){
		 		$$ = makeOperatorNode(ARRVAL, VAR_TYPE_INT, $1, $3);
		 	}
		 	else if(Glookup($1->NAME)->type == VAR_TYPE_BOOLARR){
		 		$$ = makeOperatorNode(ARRVAL, VAR_TYPE_BOOL, $1, $3);
	 		}
	 	}
	 	else{
	 		printf("Undeclared array %s\n", $1->NAME);
	 		exit(-1);
	 	}
	 }
	 | expr LT expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: <\n");
			exit(0);
		}
		 $$ = makeOperatorNode(LT, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr GT expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 $$ = makeOperatorNode(GT, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr GE expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 $$ = makeOperatorNode(GE, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr LE expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: >\n");
			exit(0);
		}
		 $$ = makeOperatorNode(LE, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr EQ expr {
	 	if(!(($1->TYPE == VAR_TYPE_INT && $3->TYPE == VAR_TYPE_INT) || ($1->TYPE == VAR_TYPE_BOOL && $3->TYPE == VAR_TYPE_BOOL))){
			printf("type error: ==\n");
			exit(0);
		}
		 $$ = makeOperatorNode(EQ, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr NEQ expr {
	 	if($1->TYPE != VAR_TYPE_INT || $3->TYPE != VAR_TYPE_INT){
			printf("type error: !=\n");
			exit(0);
		}
		 $$ = makeOperatorNode(NEQ, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr AND expr {
	 	if($1->TYPE != VAR_TYPE_BOOL || $3->TYPE != VAR_TYPE_BOOL){
			printf("type error: &&\n");
			exit(0);
		}
		 $$ = makeOperatorNode(AND, VAR_TYPE_BOOL, $1, $3);
	 }
	 | expr OR expr {
	 	if($1->TYPE != VAR_TYPE_BOOL || $3->TYPE != VAR_TYPE_BOOL){
			printf("type error: ||\n");
			exit(0);
		}
		 $$ = makeOperatorNode(OR, VAR_TYPE_BOOL, $1, $3);
	 }
	 | NOT expr {
	 	if($3->TYPE != VAR_TYPE_BOOL){
			printf("type error: ||\n");
			exit(0);
		}
		 $$ = makeOperatorNode(OR, VAR_TYPE_BOOL, $1, $3);
	 }
	 | ID '(' Args ')' {
 			struct Paramstruct *p = Glookup($1->NAME)->paramlist;
			struct tnode *t = $3;
			while (t != NULL && p != NULL){
				if (t->TYPE != p->type){
					printf("Argument types don't match 3\n");
					exit(0);
				}
				t = t->Arglist;
				p = p->next;
			}
 			if (t != NULL || p != NULL){
 				printf("Incorrect number of arguments 3\n");
 				if (t != NULL)
 					printf("t\n");
 				else
 					printf("p\n");
 				exit(0);
 			}
 			$$ = TreeCreate(Glookup($1->NAME)->type, FUNCCALL, -1, $1->NAME, $3, NULL, NULL, NULL);
 		}
 	 | FIELD {}
	 ;

FIELD     : ID '.' ID { $$->type = $3->type; }
          | FIELD '.' ID { $$->type = $3->type; }
          ;

RetStmt : RET expr ';'{ $$ = TreeCreate($2->TYPE, RET, -1, NULL, NULL, $2, NULL, NULL); }
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
