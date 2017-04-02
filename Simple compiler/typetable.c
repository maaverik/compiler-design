#include "typetable.h"

struct Typetable *ttable; // this is the current type table that is
struct Typetable *temp;
struct Fieldlist *current_flist;

struct Typetable *VAR_TYPE_INT = NULL;
struct Typetable *VAR_TYPE_INTARR = NULL;
struct Typetable *VAR_TYPE_BOOLARR = NULL;
struct Typetable *VAR_TYPE_BOOL = NULL;
struct Typetable *VAR_TYPE_VOID = NULL;


void TypeTableCreate(){
  // add "bool"
  ttable = (struct Typetable *)malloc(sizeof(struct Typetable));
  ttable -> name = (char *)malloc(sizeof(char)*20);
  strcpy(ttable -> name, "INT");
  ttable -> size = 1;
  ttable -> fields = NULL;
  ttable -> next = NULL;
  VAR_TYPE_BOOL = ttable;

  // add integer
  struct Typetable *new_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  new_ttable -> name = (char *) malloc(sizeof(char) * 20);
  strcpy(new_ttable -> name, "BOOL");
  ttable -> size = 1;
  new_ttable -> fields = NULL;
  new_ttable -> next = ttable;
  ttable = new_ttable;
  VAR_TYPE_INT = ttable;

  //add intarr
  struct Typetable *new_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  new_ttable -> name = (char *) malloc(sizeof(char) * 20);
  strcpy(new_ttable -> name, "INTARR");
  ttable -> size = 1;
  new_ttable -> fields = NULL;
  new_ttable -> next = ttable;
  ttable = new_ttable;
  VAR_TYPE_INTARR = ttable;

  //add boolarr
  struct Typetable *new_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  new_ttable -> name = (char *) malloc(sizeof(char) * 20);
  strcpy(new_ttable -> name, "BOOLARR");
  ttable -> size = 1;
  new_ttable -> fields = NULL;
  new_ttable -> next = ttable;
  ttable = new_ttable;
  VAR_TYPE_BOOLARR = ttable;
}

struct Typetable* TLookup(char *name){
  temp = ttable;
  while (temp != NULL) {
    if (strcmp(temp -> name, name) == 0) {
      return temp;
    }
    temp = temp -> next;
  }
  return NULL;
}

void TInstallId(char *name){
  if(TLookup(name)!=NULL){
    printf("Typename %s already exists\n", name);
    exit(-1);
  }
  temp = (struct Typetable*)malloc(sizeof(struct Typetable));
  temp->name = name;
  temp->fields = NULL;
  temp->next = ttable;
  ttable = temp;
  return;
}

struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields){
   if(size>8){
     printf("Field size exceeded\n");
     exit(-1);
   }
   temp = TLookup(name);
   temp -> fields = fields;
   temp->size=size;
   return ttable;
}

struct Fieldlist* FLookup(struct Typetable *type, char *name){
  struct Fieldlist *fieldlist = type -> fields;
  while (fieldlist != NULL) {
    if (strcmp(fieldlist -> name, name)  == 0) {
      return fieldlist;
    }
    fieldlist = fieldlist -> next;
  }
  return NULL;
}

struct Fieldlist *Finstall(char* Typename, char* name) {
  struct Fieldlist *temp = (struct Fieldlist *) malloc(sizeof(struct Fieldlist));
  temp -> name = (char *) malloc(sizeof(char) * 20);
  strcpy(temp -> name, name);
  temp->next=NULL;
  temp->fieldIndex=1;
  struct Fieldlist *t = TLookup(Typename);
  if(t == NULL){
    printf("Field type is undefined\n");
    exit(-1);
  }
  temp->type = t;
  return temp;
}

struct fieldlist* insertField(struct fieldlist *fld1, struct fieldlist *fld2){
  struct fieldlist* temp = fld1;
  while(temp != NULL){
    if(strcmp(temp->name,fld2->name)==0){
      printf("Field already declared\n");
      exit(-1);
    }
    temp=temp->next;
  }
  fld2->next=fld1;
  fld2->fieldIndex=fld1->fieldIndex+1;
  return fld2;
}

int GetSize (typetable * type){
  return type->size;
}

int findSize(fieldlist *fld){
  return fld->fieldIndex;
}
