#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"

typedef struct node {
	int value;
	struct node *next;
} Node;

struct queue {
	Node *begin;
	Node *end; 
	int qtt;
};

Queue* create_queue() {
	Queue *queue = (Queue*) malloc(sizeof(struct queue));
	if (queue != NULL) {
		queue->begin = NULL;
		queue->end = NULL;
		queue->qtt = 0;
	}
	return queue;
}

void free_queue(Queue* queue) {
	if (queue != NULL) {
		Node* node;
		while (queue->begin != NULL) {
			node = queue->begin;
			queue->begin = queue->begin->next;
			free(node);
		}
		free(queue);
	}
}

int size_queue(Queue* queue) {
	if (queue == NULL) {
		return -1;
	}
	return queue->qtt;
}

int queue_empty(Queue* queue) {
	if (queue == NULL) {
		return -1;
	}
	if (queue->qtt == 0 || queue->begin == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int insert_elem(Queue* queue, int value) {
	if (queue == NULL) {
		return 0;
	}
	Node *node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = NULL;
	queue->qtt++;
	if (queue->end == NULL) {
		queue->begin = node;
	} else {
		queue->end->next = node;
	}
	queue->end = node;
	return 1;
}

int remove_elem(Queue* queue) {
	if (queue == NULL || queue->begin == NULL) {
		return 0;
	}
	Node *node = queue->begin;
	queue->begin = queue->begin->next;
	if (queue->begin == NULL) {
		queue->end = NULL;
	}
	queue->qtt--;
	free(node);
	return 1;
}

int consult_queue(Queue* queue){
	if (queue == NULL || queue->begin == NULL) {
		return 0;
	}
	return queue->begin->value;
}

void print_queue(Queue *queue) {
    Node *node = queue->begin;
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}
