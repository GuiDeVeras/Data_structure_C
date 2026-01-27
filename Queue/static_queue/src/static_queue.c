#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"
#include <assert.h>

struct queue {
	int begin, end, qtt, value[MAX];
};

Queue* create_queue() {
	Queue *queue = (Queue*) malloc(sizeof(struct queue));
	if (queue != NULL) {
		queue->begin = 0;
		queue->end = 0;
		queue->qtt = 0;
	}
	return queue;
}

void free_queue(Queue* queue) {
	free(queue);
}

int size_queue(Queue* queue) {
	if (queue == NULL) {
		return -1;
	}
	return queue->qtt;
}

int queue_full(Queue* queue) {
	if (queue == NULL) {
		return -1;
	}
	if (queue->qtt == MAX) {
		return 1;
	} else {
		return 0;
	}
}

int queue_empty(Queue* queue) {
	if (queue == NULL) {
		return -1;
	}
	if (queue->qtt == 0) {
		return 1;
	} else {
		return 0;
	}
}

int insert_elem(Queue* queue, int value) {
	if (queue == NULL || queue_full(queue)) {
		return 0;
	}
	queue->value[queue->end] = value;
	queue->end = (queue->end+1)%MAX;
	queue->qtt++;
}

int remove_elem(Queue* queue) {
	if (queue == NULL || queue_empty(queue)) {
		return 0;
	}
	queue->begin = (queue->begin+1)%MAX;
	queue->qtt--;
	return 1;
}

int consult_queue(Queue* queue){
	if (queue == NULL || queue_empty(queue)) {
		return 0;
	}
	return queue->value[queue->begin];
}

void print_queue(Queue* queue) {
    int i = 0;
    while (i != queue->qtt) {
        if (i == (queue->qtt) - 1) {
        	printf("%d", queue->value[i]);
        	i++;
        	break;
       	}
        printf("%d -> ", queue->value[i]);
        i++;
    }
    if (i == 0) {
    	printf("NULL\n");
    }
}
