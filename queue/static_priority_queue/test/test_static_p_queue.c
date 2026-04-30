#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "static_p_queue.h"

void test_size_p_queue () {
	P_queue *p_queue;
	p_queue = create_p_queue();
	
	assert(size_p_queue (p_queue) == 0);
	insert_p_queue_array (p_queue, 1);
	assert(size_p_queue (p_queue) == 1);
	insert_p_queue_array (p_queue, 10);
	assert(size_p_queue (p_queue) == 2);
	
	free_p_queue (p_queue);
}

void test_p_queue_full () {
	P_queue *p_queue;
	p_queue = create_p_queue();
	
	assert(p_queue_full (p_queue) == 0);
	for (int i = 0; i < MAX; i++) {
		insert_p_queue_array (p_queue, i);
	}
	assert(p_queue_full (p_queue) == 1);
	
	free_p_queue (p_queue);
}

void test_p_queue_empty () {
	P_queue *p_queue;
	p_queue = create_p_queue();
	
	assert(p_queue_empty (p_queue) == 1);
	insert_p_queue_array (p_queue, 1);
	assert(p_queue_empty (p_queue) == 0);
	
	free_p_queue (p_queue);
}



void test_insert_p_queue_array() {
	P_queue *p_queue;
	
	p_queue = create_p_queue();
	
	assert(insert_p_queue_array(p_queue, 1) == 1);
	assert(p_queue->value[0] == 1);
	assert(size_p_queue(p_queue) == 1);
	
	assert(insert_p_queue_array(p_queue, 4) == 1);
	assert(p_queue->value[1] == 4);
	assert(size_p_queue(p_queue) == 2);
	
	assert(insert_p_queue_array(p_queue, 3) == 1);
	assert(p_queue->value[1] == 3);
	assert(size_p_queue(p_queue) == 3);
	
	free_p_queue(p_queue);
}

void test_remove_p_queue_array() {
	P_queue *p_queue;
	
	p_queue = create_p_queue();
	
	assert(remove_p_queue_array(p_queue) == 0);
	
	insert_p_queue_array(p_queue, 1);
	assert(remove_p_queue_array(p_queue) == 1);
	assert(p_queue_empty(p_queue) == 1);
	assert(size_p_queue(p_queue) == 0);
	
	insert_p_queue_array(p_queue, 4);
	insert_p_queue_array(p_queue, 2);
	assert(remove_p_queue_array(p_queue) == 1);
	assert(p_queue->value[0] == 2);
	assert(size_p_queue(p_queue) == 1);
	
	free_p_queue(p_queue);
	
}

void test_consult_p_queue_array () {
	P_queue *p_queue;
	p_queue = create_p_queue();
	
	int value;
	
	assert(consult_p_queue_array (p_queue, &value) == 0);
	insert_p_queue_array(p_queue, 2);
	assert(consult_p_queue_array (p_queue, &value) == 1);
	assert(value == 2);
	
	free_p_queue (p_queue);
}

void test_insert_p_queue_heap () {
	P_queue *p_queue;
	
	p_queue = create_p_queue();
	
	assert(p_queue_empty(p_queue) == 1);
	assert(insert_p_queue_heap(p_queue, 1) == 1);
	assert(p_queue->value[0] == 1);
	assert(size_p_queue(p_queue) == 1);
	
	assert(insert_p_queue_heap(p_queue, 4) == 1);
	assert(p_queue->value[0] == 4);
	assert(size_p_queue(p_queue) == 2);
	
	assert(insert_p_queue_heap(p_queue, 3) == 1);
	assert(p_queue->value[2] == 3);
	assert(size_p_queue(p_queue) == 3);
	
	free_p_queue(p_queue);
}

void test_remove_p_queue_heap () {
	P_queue *p_queue;
	
	p_queue = create_p_queue();
	
	assert(remove_p_queue_heap(p_queue) == 0);
	
	insert_p_queue_heap(p_queue, 1);
	assert(remove_p_queue_heap(p_queue) == 1);
	assert(p_queue_empty(p_queue) == 1);
	assert(size_p_queue(p_queue) == 0);
	
	insert_p_queue_heap(p_queue, 4);
	insert_p_queue_heap(p_queue, 2);
	assert(remove_p_queue_heap(p_queue) == 1);
	assert(p_queue->value[0] == 2);
	assert(size_p_queue(p_queue) == 1);
	
	free_p_queue(p_queue);
}
