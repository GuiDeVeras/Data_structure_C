#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"
#include <assert.h>

void test_insert_elem() {
	
	int i = 0;
	
	Stack *stack;
	
	stack = create_stack();
	
	assert(insert_elem(stack, 2) == 1);
	
	while (stack->qtt <MAX) {
		insert_elem(stack, i);
		i++;
	}
	
	assert(insert_elem(stack, 3) == 0);
	
	free(stack);
}

void test_remove_elem() {

	Stack *stack;
	
	stack = create_stack();
	
	assert(remove_elem(stack) == 0);
	
	insert_elem(stack, 1);
	
	assert(remove_elem(stack) == 1);
	
	free(stack);

}

void test_consult_elem() {

	Stack *stack;
	
	stack = create_stack();
	
	assert(consult_elem(stack) == 0);
	
	insert_elem(stack, 1);
	
	assert(consult_elem(stack) == 1);
	
	free(stack);
	
}

void test_size_stack() {

	Stack *stack;
	
	stack = create_stack();
	
	assert(size_stack(stack) == 0);
	
	insert_elem(stack, 1);
	insert_elem(stack, 8);
	insert_elem(stack, 5);
	
	assert(size_stack(stack) == 3);
	
	free(stack);
	
}
