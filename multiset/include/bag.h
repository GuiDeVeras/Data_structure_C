typedef struct header bag;

bag* create_bag ();

void free_bag (bag* b);

int insert_bag (bag* b, int value);

int remove_bag (bag* b, int value);

int consult_bag (bag* b, int value);

void begin_bag (bag *b);

int end_bag (bag *b);

void next_bag (bag *b);

void get_item_bag (bag *b, int *value);

//test

void test_insert_bag ();

void test_remove_bag ();

void test_consult_bag ();
