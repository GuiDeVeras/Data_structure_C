typedef struct node* tree_llrb;

tree_llrb* create_tree_llrb ();

int colour (struct node* H);

void colour_change (struct node* H);

struct node* Lrotation (struct node* A);

struct node* Rrotation (struct node* A);

struct node* moveLRed (struct node* H);

struct node* moveRRed (struct node* H);

struct node* balance(struct node* H);

int insert_tree_llrb (tree_llrb* root, int value);

struct node* insert_node (struct node* H, int value, int *resp);

int remove_tree_llrb (tree_llrb *root, int value);

struct node* remove_node (struct node* H, int value);

struct node* remove_lower (struct node* H);

void free_tree_llrb (tree_llrb *root);

void free_node (struct node* node);

int tree_llrb_empty (tree_llrb *root);

int pre_order_tree_llrb (tree_llrb *root);

int in_order_tree_llrb (tree_llrb *root);

int post_order_tree_llrb (tree_llrb *root);

int consult_tree_llrb (tree_llrb *root, int value);

struct node* search_lower (struct node* actual);

//Tests

void test_insert_tree_llrb ();

void test_remove_tree_llrb ();

void test_tree_llrb_empty ();

void test_pre_order_tree_llrb ();

void test_in_order_tree_llrb ();

void test_post_order_tree_llrb ();

void test_consult_tree_llrb ();

