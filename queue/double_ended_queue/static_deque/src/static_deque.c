#include <stdio.h>
#include <stdlib.h>
#include "static_deque.h"

struct deque {
	int begin, end, qtt;
	int values[MAX];
};

deque* create_deque () {
	deque *dq;
	dq = (deque*) malloc(sizeof(struct deque));
	if (dq != NULL) {
		dq->begin = 0;
		dq->end = 0;
		dq->qtt = 0;
	}
	return dq;
}

void free_deque (deque* dq) {
	free (dq);
}

int size_deque (deque *dq) {
	if (dq == NULL) return -1;
	return dq->qtt;
}

int empty_deque (deque *dq) {
	if (dq == NULL) return -1;
	if (dq->qtt == 0) return 1;
	return 0;
}

int consult_begin (deque* dq, int *value) {
	if (dq == NULL || dq->qtt == 0) return 0;
	*value = dq->values[dq->begin];
	return 1;
}

int consult_end (deque* dq, int *value) {
	if (dq == NULL || dq->qtt == 0) return 0;
	int pos = dq->end -1;
	if (pos < 0) pos = MAX-1;
	*value = dq->values[pos];
	return 1;
}

int insert_begin (deque *dq, int value) {
	if (dq == NULL || dq->qtt == MAX) return 0;
	dq->begin--;
	if (dq->begin < 0) dq->begin = MAX-1;
	dq->values[dq->begin] = value;
	dq->qtt++;
	return 1;
}

int insert_end (deque *dq, int value) {
	if (dq == NULL || dq->qtt == MAX) return 0;
	dq->values[dq->end] = value;
	dq->end = (dq->end+1) % MAX;
	dq->qtt++;
	return 1;
}

int remove_begin (deque *dq) {
	if (dq == NULL || dq->qtt == 0) return 0;
	dq->begin = (dq->begin+1) % MAX;
	dq->qtt--;
	return 1;
}

int remove_end (deque *dq) {
	if (dq == NULL || dq->qtt == 0) return 0;
	dq->end--;
	if (dq->end < 0) dq->end = MAX-1;
	dq->qtt--;
	return 1;
}
