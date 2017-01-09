typedef struct tnode{
	int val; //value of for the expression tree
	char *op; //indicates the opertor branch
	struct tnode *left,*right; //left and right branches
}tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

/*To evaluate an expression tree*/
int evaluate(struct tnode *t);

struct tnode* makeLeafNode(int n){
 struct tnode *temp;
 temp = (struct tnode*)malloc(sizeof(struct tnode));
 temp->op = NULL;
 temp->val = n;
 temp->left = NULL;
 temp->right = NULL;
 return temp;
}
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
 struct tnode *temp;
 temp = (struct tnode*)malloc(sizeof(struct tnode));
 temp->op = malloc(sizeof(char));
 *(temp->op) = c;
 temp->left = l;
 temp->right = r;
 return temp;
}
int evaluate(struct tnode *t){
 if(t->op == NULL){
 return t->val;
 }
 else{
 switch(*(t->op)){
 case '+' : return evaluate(t->left) + evaluate(t->right);
 break;
 case '-' : return evaluate(t->left) - evaluate(t->right);
 break;
 case '*' : return evaluate(t->left) * evaluate(t->right);
 break;
 case '/' : return evaluate(t->left) / evaluate(t->right);
 break;
 }
 }
}
