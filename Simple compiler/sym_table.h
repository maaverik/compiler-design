#define TRUE 5001
#define FALSE 5002
#define ARRASGN 5003
#define ARRVAL 5004
#define INTARR 5005
#define BOOLARR 5006
#define ARRREAD 5007
#define FUNCCALL 5008
#define ARG 5009

struct Gsymbol{
	char *name;               //name of the variable or function
	int type;   //pointer to the Typetable entry of variable type/return type of the function
	int size;                 //size of an array or a user defined type. (The default types have size 1)
	int binding;              //stores the static memory address allocated to the variable
	struct Paramstruct *paramlist; //pointer to the head of the formal parameter list in the case of functions
	int flabel;               //a label for identifying the starting address of the function's code in the memory✛
	struct Gsymbol *next;     //points to the next Global Symbol Table entry
	struct Lsymbol *local;
};

struct Paramstruct{
	char *name;	         		//stores the name of the parameter
	int type;  	//pointer to type table entry of parameter type
	struct Paramstruct *next;	//pointer to the next parameter
};

struct Gsymbol *Glookup(char *name); // Look up for a global identifier

void Ginstall(char *name,int type, int size, struct Paramstruct *paramlist); // Installation
