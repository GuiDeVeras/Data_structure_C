typedef struct node* avltree;

avltree* create_avltree ();

void free_avltree (avltree *root);

void free_node (struct node* node);

int avltree_empty (avltree *root);

int avltree_height (avltree *root);

int total_avltree_nodes (avltree *root);

int pre_order_avltree (avltree *root);

int in_order_avltree (avltree *root);

int post_order_avltree (avltree *root);

int consult_avltree (avltree *root, int value);

int node_height (struct node* node);

int balancefactor_node (struct node* node);

int bigger (int x, int y);

void LLrotation (avltree *root);

void RRrotation (avltree *root);

void LRrotation (avltree *root);

void RLrotation (avltree *root);

int insert_avltree (avltree *root, int value);

int remove_avltree (avltree *root, int value);

struct node* search_lower (struct node* actual);

//Tests

void test_avltree_empty ();

void test_avltree_height ();

void test_total_avltree_nodes ();

void test_pre_order_avltree ();

void test_in_order_avltree ();

void test_post_order_avltree ();

void test_consult_avltree ();

void test_node_height ();

void test_balancefactor_node ();

void test_bigger ();

void test_LLrotation ();

void test_RRrotation ();

void test_LRrotation ();

void test_RLrotation ();

void test_insert_avltree ();

void test_remove_avltree ();
