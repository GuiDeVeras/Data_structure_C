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

int list_size(List* li);

int list_full(List* li);

int list_empty(List* li);

int insert_list_final(List* li, Student st);

int insert_list_beginning(List* li, Student st);

int insert_list_ordered(List* li, Student st);

int remove_list_final(List* li);

int remove_list_beginning(List* li);

int remove_list(List* li);

int consult_pos_list(List* li, int pos, Student *st);

int consult_pos_mat(List* li, int mat, Student *st);
