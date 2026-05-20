#include <stdio.h>
#include <stdlib.h>
#include "bag.h"

struct node {
	int value;
	struct node* next;
};

struct header {
	struct node *begin;
	int qtt;
	struct node *iterator;
};

bag* create_bag () {
	bag* b = (bag*) malloc (sizeof(bag));
	if (b != NULL) {
		b->begin = NULL;
		b->qtt = 0;
		b->iterator = NULL;
	}
	return b;
}

void free_bag (bag* b) {
	if (b != NULL) {
		struct node* node;
		while (b->begin != NULL) {
			node = b->begin;
			b->begin = b->begin->next;
			free (node);
		}
		free (b);
	}
}

int insert_bag (bag* b, int value) {
	if (b == NULL) return 0;
	struct node* node;
	node = (struct node*) malloc(sizeof(struct node));
	if (node == NULL) return 0;
	node->value = value;
	node->next = b->begin;
	b->begin = node;
	b->qtt++;
	return 1;
}

int remove_bag (bag* b, int value) {
	if (b == NULL) return 0;
	int cont = 0;
	struct node *previous;
	struct node *node = b->begin;
	while (node != NULL) {
		if (node->value == value) {
			cont++;
			if (b->begin == node) {
				b->begin = node->next;
				free (node);
				node = b->begin;
			} else {
				previous->next = node->next;
				free (node);
				node = previous->next;
			}
		} else {
			previous = node;
			node = node->next;
		}
	}
	b->qtt = b->qtt - cont;
	return cont;
}

int consult_bag (bag* b, int value) {
	if (b == NULL) return 0;
	struct node *node = b->begin;
	int cont = 0;
	while (node != NULL) {
		if (node->value == value) cont++;
		node = node->next;
	}
	return cont;
}

void begin_bag (bag *b) {
	if (b == NULL) return;
	b->iterator = b->begin;
}

int end_bag (bag *b) {
	if (b == NULL) return 1;
	if (b->iterator == NULL) return 1;
	return 0;
}

void next_bag (bag *b) {
	if (b == NULL) return;
	if (b->iterator != NULL) b->iterator = b->iterator->next;
}

void get_item_bag (bag *b, int *value) {
	if (b == NULL) return;
	if (b->iterator != NULL) *value = b->iterator->value;
}
