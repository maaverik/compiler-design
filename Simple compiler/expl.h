/** Sample Expression Tree Node Structure **/

struct Gsymbol{
  char *name;               //name of the variable or function
  struct Typetable *type;   //pointer to the Typetable entry of variable type/return type of the function
  int size;                 //size of an array or a user defined type. (The default types have size 1)
  int binding;              //stores the static memory address allocated to the variable
  struct Paramstruct *paramlist;//pointer to the head of the formal parameter list in the case of functions
  int flabel;               //a label for identifying the starting address of the function's code in the memory✛
  struct Gsymbol *next;     //points to the next Global Symbol Table entry
};

struct tnode {

	int TYPE; // Integer, Boolean or Void (for statements)

	/* Must point to the type expression tree for user defined types */
	int NODETYPE;

	/* this field should carry following information:
	* a) operator : (+,*,/ etc.) for expressions
	* b) statement Type : (WHILE, READ etc.) for statements */

	char* NAME; // For Identifiers/Functions

	int VALUE; // for constants

	struct tnode *ArgList; // List of arguments for functions

	struct tnode *Ptr1, *Ptr2, *Ptr3;

	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	struct Gsymbol *Gentry; // For global identifiers/functions

	//Lsymbol *Lentry; // For Local variables

};


struct tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct tnode *ArgList, struct tnode *Ptr1, struct tnode *Ptr2, struct tnode *Ptr3);

/*Make a leaf tnode and set the value of val field*/
//struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(int c,struct tnode *l,struct tnode *r);

/*To evaluate an expression tree*/
int evaluate(struct tnode *t);
