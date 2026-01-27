#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

struct stack {
	int qtt, value[MAX];
};

Stack* create_stack() {
	Stack* stack;
	stack = (Stack*) malloc(sizeof(Stack));
	if (stack != NULL) {
		stack->qtt = 0;
	}
	return stack;
}

void free_stack(Stack* stack) {
	free(stack);
}

int size_stack(Stack* stack) {
	if (stack == NULL) {
		return -1;
	}
	return stack->qtt;
}

int stack_full(Stack* stack) {
	if (stack == NULL) {
		return -1;
	}
	return (stack->qtt == MAX);
}

int stack_empty(Stack* stack) {
	if (stack == NULL) {
		return -1;
	}
	return (stack->qtt == 0);
}

int insert_elem(Stack* stack, int value) {
	if (stack == NULL || stack_full(stack)) {
		return 0;
	}
	stack->value[stack->qtt] = value;
	stack->qtt++;
	return 1;
}

int remove_elem(Stack* stack) {
	if (stack == NULL || stack_empty(stack)) {
		return 0;
	}
	stack->qtt--;
	return 1;
}

int consult_elem(Stack* stack) {
	if (stack == NULL || stack_empty(stack)) {
		return 0;
	}
	return stack->value[stack->qtt-1];
}

void print_stack(Stack* stack) {
    int i = 0;
    while (i != stack->qtt) {
        if (i == (stack->qtt) - 1) {
        	printf("%d", stack->value[i]);
        	i++;
        	break;
       	}
        printf("%d -> ", stack->value[i]);
        i++;
    }
    if (i == 0) {
    	printf("NULL\n");
    }
}
