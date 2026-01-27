#include <stdio.h>
#include <stdlib.h>
#include "dynamic_stack.h"
#include <assert.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

Stack* create_stack() {
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	if (stack != NULL) {
		*stack = NULL;
	}
	return stack;
}

void free_stack (Stack* stack) {
	if (stack != NULL) {
		Node* node;
		while ((*stack) != NULL) {
			node = *stack;
			*stack = (*stack)->next;
			free(node);
		}
		free(stack);
	}
}

int size_stack(Stack* stack) {
	if (stack == NULL) {
		return 0;
	}
	int cont = 0;
	Node* node = *stack;
	while (node != NULL) {
		cont++;
		node = node->next;
	}
	return cont;
}

int stack_empty(Stack* stack) {
	if (stack == NULL || (*stack) == NULL) {
		return 1;
	}
	return 0;
}

int insert_elem(Stack* stack, int value) {
	if (stack == NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = (*stack);
	*stack = node;
	return 1;
}

int remove_elem(Stack* stack) {
	if (stack == NULL || (*stack) == NULL) {
		return 0;
	}
	Node* node = *stack;
	*stack = node->next;
	free(node);
	return 1;
}

int consult_elem(Stack* stack) {
	if (stack == NULL || (*stack) == NULL) {
		return 0;
	}
	return (*stack)->value;
}

void print_stack(Stack *stack) {
	Node *node = *stack;
	while (node != NULL) {
		printf("%d -> ", node->value);
		node = node->next;
   	}
	printf("NULL\n");
}
