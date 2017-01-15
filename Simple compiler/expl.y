%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE tnode *
	#include "expl.h"
	#include "expl.c"
	int *var[26];
%}

%union{
  int integer;
  char character;
};

%token 	<character>ID
%token <integer>NUM
%token READ ASGN NEWLINE WRITE PLUS MUL IF THEN WHILE DO ENDWHILE ENDIF THEN LT GT EQ
%nonassoc GT LT EQ
%left PLUS
%left MUL

%type <integer>expr

%%

Program : slist NEWLINE {exit(1);}
     ;
slist : slist stmt
     | stmt
     ;
stmt : ID ASGN expr ';' {
				     	if(var[$1-'a'] == NULL){
				    		var[$1 - 'a'] = malloc(sizeof(int));
						}
						*var[$1-'a'] = $3;
					    }
     | READ '(' ID ')' ';' {
				     	if(var[$3-'a'] == NULL){
				    		var[$3 - 'a'] = malloc(sizeof(int));
						}
						scanf("%d",var[$3-'a']);
					    }
     | WRITE '(' expr ')' ';' {
     					printf("%d\n", $3);
     					}
     | IF '(' THEN slist ENDIF ';' {

     					}
     | WHILE '(' expr ')' DO slist ENDWHILE ';' {

     					}

     ;
expr: expr PLUS expr {$$ = $1 + $3;}
	| expr MUL expr {$$ = $1 * $3;}
	| '(' expr ')' {$$ = $2;}
	| expr LT expr {$$ = $1 < $3;}
	| expr GT expr {$$ = $1 > $3;}
	| expr EQ expr {$$ = $1 == $3;}
	| NUM {$$ = $1;}
	| ID {
            if( var[$1 - 'a'] == NULL)
                printf("unassigned varaiable");
            else
                $$ = *var[$1 - 'a'];
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
