#include <stdio.h>
#include <stdlib.h>
#include "static_p_queue.h"

struct p_queue {
	int qtt, value[MAX];
};

P_queue* create_p_queue() {
	P_queue *p_queue = (P_queue*) malloc(sizeof(struct p_queue));
	if (p_queue != NULL) p_queue->qtt = 0;
	return p_queue;
}

void free_p_queue(P_queue* p_queue) {
	free(p_queue);
}

int size_p_queue(P_queue* p_queue) {
	if (p_queue == NULL) return -1;
	return p_queue->qtt;
}

int p_queue_full(P_queue* p_queue) {
	if (p_queue == NULL) return -1;
	if (p_queue->qtt == MAX) return 1;
	else return 0;
}

int p_queue_empty(P_queue* p_queue) {
	if (p_queue == NULL) return -1;
	if (p_queue->qtt == 0) return 1;
	else return 0;
}

int insert_p_queue_array (P_queue* p_queue, int value) {
	if (p_queue == NULL || p_queue->qtt == MAX) return 0;
	int i = p_queue->qtt - 1;
	while (i >= 0 && p_queue->value[i] >= value) {
		p_queue->value[i+1] = p_queue->value[i];
		i--;
	}
	p_queue->value[i+1] = value;
	p_queue->qtt++;
	return 1;
}

int remove_p_queue_array (P_queue* p_queue) {
	if (p_queue == NULL || !(p_queue->qtt)) return 0;
	p_queue->qtt--;
	return 1;
}

int consult_p_queue_array (P_queue* p_queue, int *value) {
	if (p_queue == NULL || !(p_queue->qtt)) return 0;
	*value = p_queue->value[p_queue->qtt - 1];
	return 1;
}

int insert_p_queue_heap (P_queue* p_queue, int value) {
	if (p_queue == NULL || p_queue->qtt == MAX) return 0;
	p_queue->value[p_queue->qtt] = value;
	promote_element (p_queue, p_queue->qtt);
	p_queue->qtt++;
	return 1;
}

void promote_element (P_queue* p_queue, int child) {
	int parent, temp;
	parent = (child - 1) / 2;
	while ((child > 0) && (p_queue->value[parent] <= p_queue->value[child])) {
		
		temp = p_queue->value[child];
		p_queue->value[child] = p_queue->value[parent];
		p_queue->value[parent] = temp;
		
		child = parent;
		parent = (parent -1) / 2;
	}
}

int remove_p_queue_heap (P_queue* p_queue) {
	if (p_queue == NULL || !(p_queue->qtt)) return 0;
	p_queue->qtt--;
	p_queue->value[0] = p_queue->value[p_queue->qtt];
	demote_element (p_queue, 0);
	return 1;
}

void demote_element (P_queue* p_queue, int parent) {
	int temp, child = 2 * parent + 1;
	while (child < p_queue->qtt) {
		if (child < p_queue->qtt - 1) {
			if (p_queue->value[child] < p_queue->value[child + 1]) child++;
		}
		if (p_queue->value[parent] >= p_queue->value[child]) break;
		
		temp = p_queue->value[parent];
		p_queue->value[parent] = p_queue->value[child];
		p_queue->value[child] = temp;
		
		parent = child;
		child = 2 * parent + 1;
	}
}
