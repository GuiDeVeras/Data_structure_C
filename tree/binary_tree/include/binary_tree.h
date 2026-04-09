typedef struct node* binary_tree;

binary_tree* create_binary_tree ();

void free_binary_tree (binary_tree *root);

void free_node (struct node* node);

int binary_tree_empty (binary_tree *root);

int binary_tree_height (binary_tree *root);

int total_binary_tree_nodes (binary_tree *root);

int pre_order_binary_tree (binary_tree *root);

int in_order_binary_tree (binary_tree *root);

int post_order_binary_tree (binary_tree *root);

int insert_binary_tree (binary_tree *root, int value);

int remove_binary_tree (binary_tree *root, int value);

struct node* remove_actual (struct node* actual);

int consult_binary_tree (binary_tree *root, int value);

//Test

void test_binary_tree_empty ();

void test_binary_tree_height ();

void test_total_binary_tree_nodes ();

void test_pre_order_binary_tree ();

void test_in_order_binary_tree ();

void test_post_order_binary_tree ();

void test_insert_binary_tree ();

void test_remove_binary_tree ();

void test_consult_binary_tree ();
