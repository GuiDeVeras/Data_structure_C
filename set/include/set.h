typedef struct set set;

set* create_set();

void free_set (set* s);

int insert_set (set* s, int value);

int remove_set (set* s, int num);

int search_set (set* s, int value);

void begin_set (set *s);

int end_set (set *s);

void next_set (set *s);

void get_item_set (set *s, int *value);

set* union_set (set* A, set* B);

set* intersection_set (set *A, set *B);

//test

void test_insert_set ();

void test_remove_set ();

void test_search_set ();
