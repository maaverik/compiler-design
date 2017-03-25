struct Lsymbol{
	char *name;               //name of the variable
	int type;   //pointer to the Typetable entry of variable type
	int binding;              //stores memory address allocated to the variable
	struct Lsymbol *next;     //points to the next Local Symbol Table entry
};

struct Lsymbol* Linstall(char* name, int type, int size);

struct Lsymbol* LLookup(char *name);
