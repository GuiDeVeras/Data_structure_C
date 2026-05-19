typedef struct skip_list skip_list;

skip_list* create_skip_list (int max_level, float p);

struct node* new_node (int key, int level);

void free_skip_list (skip_list* sl);

int search_skip_list (skip_list *sl, int key);

int insert_skip_list (skip_list *sl, int key);

int level_draw (skip_list *sl);

int remove_skip_list (skip_list *sl, int key);

//test

void test_search_skip_list ();

void test_insert_skip_list ();

void test_remove_skip_list ();
