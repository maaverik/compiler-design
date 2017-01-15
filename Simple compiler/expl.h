/** Sample Expression Tree Node Structure **/

struct Tnode {

	int TYPE; // Integer, Boolean or Void (for statements)

	/* Must point to the type expression tree for user defined types */

	int NODETYPE;

	/* this field should carry following information:

	* a) operator : (+,*,/ etc.) for expressions

	* b) statement Type : (WHILE, READ etc.) for statements */

	char* NAME; // For Identifiers/Functions

	int VALUE; // for constants

	Tnode *ArgList; // List of arguments for functions

	Tnode *Ptr1, *Ptr2, *Ptr3;

	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	Gsymbol *Gentry; // For global identifiers/functions

	Lsymbol *Lentry; // For Local variables

}

struct Tnode *TreeCreate(TYPE,NODETYPE,VALUE,NAME,ArgList,Ptr1, Ptr2, Ptr3);
