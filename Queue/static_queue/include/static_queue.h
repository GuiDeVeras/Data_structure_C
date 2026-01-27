#define MAX 100

typedef struct queue Queue;

Queue* create_queue();

void free_queue(Queue* queue);

int size_queue(Queue* queue);

int queue_full(Queue* queue);

int queue_empty(Queue* queue);

int insert_elem(Queue* queue, int value);

int remove_elem(Queue* queue);

int consult_queue(Queue* queue);

void print_queue(Queue* queue);

//Tests

void test_insert_elem();

void test_remove_elem();
