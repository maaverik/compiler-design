%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

%}

%token DIGIT LETTER SPACE

%%

variable: LETTER alphanum SPACE {printf("Valid identifier\n"); exit(1);};
alphanum: LETTER alphanum | DIGIT alphanum | DIGIT | LETTER;

%%

int yyerror(char *s){
	printf("Invalid identifier\n");
	return 0;
}

int yylex(){
	char c;
	c = getchar();
	if(isdigit(c)){
        return DIGIT;
    }
    else if(c == ' ' || c == '\n' || c == '\t'){
        return SPACE;
    }
    else if(isalpha(c)){
        return LETTER;
    }
    else{
    	printf("Invalid identifier\n");
    	exit(0);
    }
}

int main(){
	yyparse();
	return 1;
}
