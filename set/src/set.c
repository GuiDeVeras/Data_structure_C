#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "avl_tree.h"

struct set {
	avltree* tree;
	int qtt;
	struct iterator *iter;
};

set* create_set() {
	set* s = (set*) malloc(sizeof(set));
	if (s != NULL) {
		s->tree = create_avltree();
		s->qtt = 0;
		s->iter = NULL;
	}
	return s;
}

void free_set (set* s) {
	if (s != NULL) {
		free_avltree (s->tree);
		struct iterator* node;
		while (s->iter != NULL) {
			node = s->iter;
			s->iter = s->iter->next;
			free (node);
		}
		free (s);
	}
}

int insert_set (set* s, int value) {
	if (s == NULL) return 0;
	if (insert_avltree (s->tree, value)) {
		s->qtt++;
		return 1;
	} else return 0;
}

int remove_set (set* s, int num) {
	if (s == NULL) return 0;
	if (remove_avltree (s->tree, num)) {
		s->qtt--;
		return 1;
	} else return 0;
}

int search_set (set* s, int value) {
	if (s == NULL) return 0;
	return consult_avltree (s->tree, value);
}

void begin_set (set *s) {
	if (s == NULL) return;
	s->iter = NULL;
	iterator_avltree (s->tree, &(s->iter));
}

int end_set (set *s) {
	if (s == NULL) return 1;
	if (s->iter == NULL) return 1;
	return 0;
}

void next_set (set *s) {
	if (s == NULL) return;
	if (s->iter != NULL) {
		struct iterator *node = s->iter;
		s->iter = s->iter->next;
		free (node);
	}
}

void get_item_set (set *s, int *value) {
	if (s == NULL) return;
	if (s->iter != NULL) *value = s->iter->value;
}

set* union_set (set* A, set* B) {
	if (A == NULL || B == NULL) return NULL;
	int x;
	set *C = create_set();
	for (begin_set(A); !end_set(A); next_set(A)) {
		get_item_set (A, &x);
		insert_set (C, x);
	}
	for (begin_set(B); !end_set(B); next_set(B)) {
		get_item_set (B, &x);
		insert_set (C, x);
	}
	return C;
}

set* intersection_set (set *A, set *B) {
	if (A == NULL || B == NULL) return NULL;
	int x;
	set *C = create_set();
	if (A->qtt < B->qtt) {
		for (begin_set (A); !end_set (A); next_set (A)) {
			get_item_set (A, &x);
			if (search_set (B, x)) insert_set (C, x);
		}
	} else {
		for (begin_set (B); !end_set (B); next_set (B)) {
			get_item_set (B, &x);
			if (search_set (A, x)) insert_set (C, x);
		}
	}
	return C;
}
