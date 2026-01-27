//File sequential_list.h

typedef struct list List;

List* create_list();

void free_list(List* li);

int list_size(List* li);

int list_full(List* li);

int list_empty(List* li);

int insert_list_final(List* li, int value);

int insert_list_beginning(List* li, int value);

int insert_list_ordered(List* li, int value);

int remove_list_final(List* li);

int remove_list_beginning(List* li);

int remove_list(List* li, int value);

int consult_pos_list(List* li, int pos);

int consult_pos_reg(List* li, int value);

void print_list(List *li);

void test_insert_list_final();

void test_insert_list_beginning();

void test_insert_list_ordered();

void test_remove_list_final();

void test_remove_list_beginning();

void test_remove_list();

void test_list_full();

void test_list_empty();

void test_consult_pos_list();

void test_consult_pos_value();

void test_free_list();
