typedef struct deque deque;

deque* create_deque ();

void free_deque (deque* dq);

int size_deque (deque *dq);

int empty_deque (deque *dq);

int consult_begin (deque* dq, int *value);

int consult_end (deque* dq, int *value);

int insert_begin (deque* dq, int value);

int insert_end (deque* dq, int value);

int remove_begin (deque* dq);

int remove_end (deque* dq);

//test

void test_size_deque ();

void test_empty_deque ();

void test_consult_begin ();

void test_consult_end ();

void test_insert_begin ();

void test_insert_end ();

void test_remove_begin ();

void test_remove_end ();
