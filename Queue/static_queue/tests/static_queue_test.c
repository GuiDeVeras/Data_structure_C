#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "static_queue.h"

void test_insert_elem() {
	Queue* queue;
	
	queue = create_queue();
	
	assert(queue_empty(queue) == 1);
	insert_elem(queue, 1);
	assert(queue->value[0] == 1);
	assert(size_queue(queue) == 1);
	
	insert_elem(queue, 4);
	assert(queue->value[1] == 4);
	assert(size_queue(queue) == 2);
	
	insert_elem(queue, 3);
	assert(queue->value[2] == 3);
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
	assert(queue->value[1] == 2);
	assert(size_queue(queue) == 1);
	
	free(queue);
	
}
