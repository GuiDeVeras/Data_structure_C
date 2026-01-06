//File sequential_list.h
struct student{
	int registration;
	char name[30];
	float n1,n2,n3;
};

typedef struct student Student;

typedef struct list List;

List* create_list();

void free_list(List* li);
