#define d 256

typedef struct Hash hash;

hash* create_hash (int table_size);

void free_hash (hash* hsh);

int division_key (int key, int table_size);

int multiplication_key (int key, int table_size);

int fold_key (int key, int table_size);

int string_value (char *str);

int insert_hash_collision (hash* hsh, int value);

int search_hash_collision (hash* hsh, int value, int *aux);

int linear_probing (int pos, int i, int table_size);

int quadratic_probing (int pos, int i, int table_size);

int double_hashing (int h1, int key, int i, int table_size);

int insert_hash_collisionless (hash* hsh, int value);

int search_hash_collisionless (hash* hsh, int value, int *aux);

void Rabin_Karp (char *model, char *text);

//Test

void test_division_key ();

void test_multiplication_key ();

void test_fold_key ();

void test_string_value ();

void test_insert_hash_collision ();

void test_search_hash_collision ();

void test_linear_probing ();

void test_quadratic_probing ();

void test_double_hashing ();

void test_insert_hash_collisionless ();

void test_search_hash_collisionless ();
