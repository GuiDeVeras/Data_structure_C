#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_deque.h"

void test_size_deque () {
	
	deque* dq = NULL;

	assert(size_deque (dq) == 0);

	dq = create_deque ();
	
	assert(size_deque (dq) == 0);
	
	assert(insert_begin(dq, 1) == 1);
	
	assert(size_deque (dq) == 1);
	
	free_deque (dq);
	
}

void test_empty_deque () {
	
	deque* dq = NULL;

	assert(empty_deque (dq) == 1);

	dq = create_deque ();
	
	assert(empty_deque (dq) == 1);
	
	assert(insert_begin(dq, 1) == 1);
	
	assert(empty_deque (dq) == 0);
	
	free_deque (dq);
	
}

void test_consult_begin () {
	
	int value;
	deque* dq = NULL;

	assert(consult_begin (dq, &value) == 0);

	dq = create_deque ();
	
	assert(consult_begin (dq, &value) == 0);
	
	assert(insert_begin(dq, 1) == 1);
	assert(insert_begin(dq, 2) == 1);
	
	assert(consult_begin (dq, &value) == 1);
	assert(value == 2);
	
	free_deque (dq);
}

void test_consult_end () {
	
	int value = 0;
	deque* dq = NULL;

	assert(consult_end (dq, &value) == 0);

	dq = create_deque ();
	
	assert(consult_end (dq, &value) == 0);
	
	assert(insert_begin(dq, 1) == 1);
	assert(insert_begin(dq, 2) == 1);
	
	assert(consult_end (dq, &value) == 1);
	assert(value == 1);
	
	free_deque (dq);
}

void test_insert_begin () {
	
	int value;
	deque* dq = NULL;

	assert(insert_begin (dq, 4) == 0);

	dq = create_deque ();
	
	assert(insert_begin (dq, 4) == 1);
	
	assert(consult_begin (dq, &value) == 1);
	assert(value == 4);
	
	assert(insert_begin (dq, 5) == 1);
	assert(consult_begin (dq, &value) == 1);
	assert(value == 5);
	
	free_deque (dq);
}

void test_insert_end () {
	
	int value;
	deque* dq = NULL;

	assert(insert_end (dq, 4) == 0);

	dq = create_deque ();
	
	assert(insert_end (dq, 4) == 1);
	
	assert(consult_end (dq, &value) == 1);
	assert(value == 4);
	
	assert(insert_end (dq, 5) == 1);
	assert(consult_end (dq, &value) == 1);
	assert(value == 5);
	
	free_deque (dq);
}

void test_remove_begin () {

	int value;
	deque* dq = NULL;

	assert(remove_begin (dq) == 0);

	dq = create_deque ();
	
	assert(remove_begin (dq) == 0);
	
	assert(insert_begin (dq, 4) == 1);
	assert(remove_begin (dq) == 1);
	
	assert(consult_begin (dq, &value) == 0);
	
	assert(insert_begin (dq, 4) == 1);
	assert(insert_begin (dq, 5) == 1);
	assert(remove_begin (dq) == 1);
	assert(consult_begin (dq, &value) == 1);
	assert(value == 4);
	
	free_deque (dq);	
}

void test_remove_end () {
	
	int value;
	deque* dq = NULL;

	assert(remove_end (dq) == 0);

	dq = create_deque ();
	
	assert(remove_end (dq) == 0);
	
	assert(insert_end (dq, 4) == 1);
	assert(remove_end (dq) == 1);
	
	assert(consult_end (dq, &value) == 0);
	
	assert(insert_end (dq, 4) == 1);
	assert(insert_end (dq, 5) == 1);
	assert(remove_end (dq) == 1);
	assert(consult_end (dq, &value) == 1);
	assert(value == 4);
	
	free_deque (dq);
}
