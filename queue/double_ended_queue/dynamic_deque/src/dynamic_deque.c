#include <stdio.h>
#include <stdlib.h>
#include "dynamic_deque.h"


struct element {
	struct element* previous;
	int value;
	struct element* next;
};
typedef struct element elem;

struct deque {
	struct element *begin;
	struct element *end;
	int qtt;
};

deque* create_deque () {
	deque* dq = (deque*) malloc(sizeof(deque));
	if (dq != NULL) {
		dq->end = NULL;
		dq->begin = NULL;
		dq->qtt = 0;
	}
	return dq;
}

void free_deque (deque* dq) {
	if (dq != NULL) {
		elem* node;
		while (dq->begin != NULL) {
			node = dq->begin;
			dq->begin = dq->begin->next;
			free (node);
		}
		free (dq);
	}
}

int size_deque (deque *dq) {
	if (dq == NULL) return 0;
	return dq->qtt;
}

int empty_deque (deque *dq) {
	if (dq == NULL || dq->begin == NULL) return 1;
	return 0;
	
}

int consult_begin (deque* dq, int *value) {
	if (dq == NULL || dq->begin == NULL) return 0;
	*value = dq->begin->value;
	return 1;
}

int consult_end (deque* dq, int *value) {
	if (dq == NULL || dq->end == NULL) return 0;
	*value = dq->end->value;
	return 1;
}

int insert_begin (deque* dq, int value) {
	if (dq == NULL) return 0;
	elem *node = (elem*) malloc(sizeof(elem));
	if (node == NULL) return 0;
	node->value = value;
	node->next = dq->begin;
	node->previous = NULL;
	if (dq->begin == NULL) dq->end = node;
	else dq->begin->previous = node;
	dq->begin = node;
	dq->qtt++;
	return 1;
}

int insert_end (deque* dq, int value) {
	if (dq == NULL) return 0;
	elem *node = (elem*) malloc(sizeof(elem));
	if (node == NULL) return 0;
	node->value = value;
	node->previous = dq->end;
	node->next = NULL;
	if (dq->end == NULL) {
		node->previous = NULL;
		dq->begin = node;
	}
	else {
		node->previous = dq->end;
		dq->end->next = node;
	}
	dq->end = node;
	dq->qtt++;
	return 1;
}

int remove_begin (deque* dq) {
	if (dq == NULL || dq->begin == NULL) return 0;
	elem *node = dq->begin;
	dq->begin = dq->begin->next;
	if (dq->begin == NULL) dq->end = NULL;
	else dq->begin->previous = NULL;
	free (node);
	dq->qtt--;
	return 1;
}

int remove_end (deque* dq) {
	if (dq == NULL || dq->begin == NULL) return 0;
	elem *node = dq->end;
	if (node == dq->begin) {
		dq->begin = NULL;
		dq->end = NULL;
	} else {
		node->previous->next = NULL;
		dq->end = node->previous;
	}
	free (node);
	dq->qtt--;
	return 1;
}
