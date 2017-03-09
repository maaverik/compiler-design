
struct ltable{
	char *name;
	int addr;
	struct ltable *next;
};

struct ltable* insertLab(char *name, int nextAddr, struct ltable *labtable);

struct ltable* searchLab(char *name, struct ltable *labtable);
