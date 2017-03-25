/** Sample Expression Tree Node Structure **/

struct tnode {

	int TYPE; // Integer, Boolean or Void (for statements)

	/* Must point to the type expression tree for user defined types */
	int NODETYPE;

	/* this field should carry following information:
	* a) operator : (+,*,/ etc.) for expressions
	* b) statement Type : (WHILE, READ etc.) for statements */

	char* NAME; // For Identifiers/Functions

	int VALUE; // for constants

	struct tnode *Arglist; // List of arguments for functions

	struct tnode *Ptr1, *Ptr2, *Ptr3;

	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	struct Gsymbol *Gentry; // For global identifiers/functions

	struct Lsymbol *Lentry; // For Local variables

};


struct tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct tnode *Arglist, struct tnode *Ptr1, struct tnode *Ptr2, struct tnode *Ptr3);

/*Make a leaf tnode and set the value of val field*/
//struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(int op, int type, struct tnode *l, struct tnode *r);

/*To evaluate an expression tree*/
int evaluate(struct tnode *t);

int toBool(int x);
