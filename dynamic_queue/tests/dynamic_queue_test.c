#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_queue.h"

void test_insert_elem() {
	Queue* queue;
	
	queue = create_queue();
	
	assert(queue_empty(queue) == 1);
	insert_elem(queue, 1);
	assert(queue->begin->value == 1);
	assert(size_queue(queue) == 1);
	
	insert_elem(queue, 4);
	assert(queue->begin->value == 1);
	assert(queue->begin->next->value == 4);
	assert(size_queue(queue) == 2);
	
	insert_elem(queue, 3);
	assert(queue->begin->value == 1);
	assert(queue->begin->next->value == 4);
	assert(queue->begin->next->next->value == 3);
	assert(size_queue(queue) == 3);
	
	free(queue);
}

void test_remove_elem() {
	Queue* queue;
	
	queue = create_queue();
	
	assert(remove_elem(queue) == 0);
	
	assert(queue_empty(queue) == 1);
	insert_elem(queue, 1);
	remove_elem(queue);
	assert(queue_empty(queue) == 1);
	assert(size_queue(queue) == 0);
	
	insert_elem(queue, 4);
	insert_elem(queue, 2);
	remove_elem(queue);
	assert(queue->begin->value == 2);
	assert(size_queue(queue) == 1);
	
	free(queue);
	
}
