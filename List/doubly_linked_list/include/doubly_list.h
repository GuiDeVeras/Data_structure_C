typedef struct Node* List;

List* create_list();

void free_list(List* list);

int list_size(List* list);

int list_empty(List* list);

int insert_elem_begin(List* list, int value);

int insert_elem_end(List* list, int value);

int insert_elem_ordered(List* list, int value);

int remove_elem_begin(List* list);

int remove_elem_end(List* list);

int remove_elem(List* list, int value);

int consult_elem_pos(List* list, int value);

void print_list(List *list);

//Test 

void test_insert_elem_begin();

void test_insert_elem_end();

void test_insert_elem_ordered();

void test_remove_elem_begin();

void test_remove_elem_end();

void test_remove_elem();

void test_consult_elem_pos();

