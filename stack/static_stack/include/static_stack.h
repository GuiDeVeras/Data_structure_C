#define MAX 100

typedef struct stack Stack;

Stack* create_stack();

void free_stack(Stack* stack);

int size_stack(Stack* stack);

int stack_full(Stack* stack);

int stack_empty(Stack* stack);

int insert_elem(Stack* stack, int value);

int remove_elem(Stack* stack);

int consult_elem(Stack* stack);

void print_stack(Stack* stack);

//Tests

void test_insert_elem();

void test_remove_elem();

void test_consult_elem();

void test_size_stack();
