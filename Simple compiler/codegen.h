int getReg();

void freeReg();

int getLabel();

void printheader();

void printfooter();

void codeGenStart(struct tnode *t, char caller[]);

int codeGen(struct tnode* t);

void funcDecl();

void funcRet();
