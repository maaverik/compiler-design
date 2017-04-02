struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist{
	char *name;              //name of the field
	int fieldIndex;          //the position of the field in the field list
	struct Typetable *type;  //pointer to type table entry of the field's type
	struct Fieldlist *next;  //pointer to the next field
};

void TypeTableCreate(); //Function to initialise the type table entries with primitive types (int,str) and special entries(boolean,null,void).

struct Typetable* TLookup(char *name); // Search through the type table and return pointer to type table entry of type 'name'. Returns NULL if entry is not found.

struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields); // Creates a type table entry for the (user defined) type of 'name' with given 'fields' and returns the pointer to the type table entry. The field list must specify the field index, type and name of each field. TInstall returns NULL upon failure. This routine is invoked when the compiler encounters a type definition in the source program.

struct Fieldlist* FLookup(struct Typetable *type, char *name); // Searches for a field of given 'name' in the 'fieldlist' of the given user-defined type and returns a pointer to the field entry. Returns NULL if the type does not have a field of the name.

sstruct Fieldlist *Finstall(char* Typename, char* name); // Install a field of 'type' and 'name'

int GetSize (Typetable * type); // Returns the amount of memory words required to store a variable of the given type.

struct fieldlist* insertField(struct fieldlist *fld1, struct fieldlist *fld2);

int findSize(fieldlist *fld);
