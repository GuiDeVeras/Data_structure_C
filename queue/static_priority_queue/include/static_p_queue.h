#define MAX 100
typedef struct p_queue P_queue;

P_queue* create_p_queue();

void free_p_queue (P_queue* p_queue);

int insert_p_queue_array (P_queue* p_queue, int value);

int remove_p_queue_array (P_queue* p_queue);

int size_p_queue (P_queue* p_queue);

int p_queue_full (P_queue* p_queue);

int p_queue_empty (P_queue* p_queue);

int consult_p_queue_array (P_queue* p_queue, int *value);

int insert_p_queue_heap (P_queue* p_queue, int value);

void promote_element (P_queue* p_queue, int child);

int remove_p_queue_heap (P_queue* p_queue);

void demote_element (P_queue* p_queue, int parent);

//Test

void test_size_p_queue ();

void test_p_queue_full ();

void test_p_queue_empty ();

void test_insert_p_queue_array ();

void test_remove_p_queue_array ();

void test_consult_p_queue_array ();

void test_insert_p_queue_heap ();

void test_remove_p_queue_heap ();
