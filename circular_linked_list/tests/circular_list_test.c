#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"
#include <assert.h>

void test_insert_elem_begin() {
	List* list;
	
	list = create_list();
	
	insert_elem_begin(list, 1);
	assert((*list) != NULL);
	assert((*list)->value == 1);
	assert((*list)->next->value == 1);
	assert(list_size(list) == 1);
	
	insert_elem_begin(list, 2);
	assert((*list)->value == 2);
	assert((*list)->next->value == 1);
	assert((*list)->next->next->value == 2);
	assert(list_size(list) == 2);
	
	insert_elem_begin(list, 3);
	assert((*list)->value == 3);
	assert((*list)->next->value == 2);
	assert((*list)->next->next->value == 1);
	assert((*list)->next->next->next->value == 3);
	assert(list_size(list) == 3); 
	
	free_list(list);

}

void test_insert_elem_end() {
	List* list;
	
	list = create_list();
	
	insert_elem_end(list, 1);
	assert((*list) != NULL);
	assert((*list)->value == 1);
	assert((*list)->next->value == 1);
	assert(list_size(list) == 1);
	
	insert_elem_end(list, 2);
	assert((*list)->value == 1);
	assert((*list)->next->value == 2);
	assert((*list)->next->next->value == 1);
	assert(list_size(list) == 2);
	
	insert_elem_end(list, 3);
	assert((*list)->value == 1);
	assert((*list)->next->value == 2);
	assert((*list)->next->next->value == 3);
	assert((*list)->next->next->next->value == 1);
	assert(list_size(list) == 3); 
	
	free_list(list);

}

void test_insert_elem_ordered() {
	List* list;
	
	list = create_list();
	
	insert_elem_ordered(list, 1);
	assert((*list) != NULL);
	assert((*list)->value == 1);
	assert((*list)->next->value == 1);
	assert(list_size(list) == 1);
	
	insert_elem_ordered(list, 3);
	assert((*list)->value == 1);
	assert((*list)->next->value == 3);
	assert((*list)->next->next->value == 1);
	assert(list_size(list) == 2);
	
	insert_elem_ordered(list, 2);
	assert((*list)->value == 1);
	assert((*list)->next->value == 2);
	assert((*list)->next->next->value == 3);
	assert((*list)->next->next->next->value == 1);
	assert(list_size(list) == 3); 
	
	free_list(list);

}

void test_remove_elem_begin() {
	List *list;
	
	list = create_list();
	
	insert_elem_begin(list, 1);
	remove_elem_begin(list);
	assert((*list) == NULL);
	assert(list_size(list) == 0);
	
	insert_elem_begin(list, 1);
	insert_elem_begin(list, 2);
	remove_elem_begin(list);
	assert((*list)->value == 1);
	assert((*list)->next->value == 1);
	assert(list_size(list) == 1);
	
	insert_elem_begin(list, 3);
	insert_elem_begin(list, 4);
	remove_elem_begin(list);
	assert((*list)->value == 3);
	assert((*list)->next->value == 1);
	assert((*list)->next->next->value == 3);
	assert(list_size(list) == 2); 
	
	free_list(list);
	
}

void test_remove_elem_end() {
	List *list;
	
	list = create_list();
	
	insert_elem_begin(list, 1);
	remove_elem_end(list);
	assert((*list) == NULL);
	assert(list_size(list) == 0);
	
	insert_elem_begin(list, 1);
	insert_elem_begin(list, 2);
	remove_elem_end(list);
	assert((*list)->value == 2);
	assert((*list)->next->value == 2);
	assert(list_size(list) == 1);
	
	insert_elem_begin(list, 3);
	insert_elem_begin(list, 4);
	remove_elem_end(list);
	assert((*list)->value == 4);
	assert((*list)->next->value == 3);
	assert((*list)->next->next->value == 4);
	assert(list_size(list) == 2); 
	
	free_list(list);
	
}

void test_remove_elem() {
	List *list;
	
	list = create_list();
	
	insert_elem_begin(list, 1);
	remove_elem(list, 1);
	assert((*list) == NULL);
	assert(list_size(list) == 0);
	
	insert_elem_begin(list, 1);
	insert_elem_begin(list, 2);
	remove_elem(list, 1);
	assert((*list)->value == 2);
	assert((*list)->next->value == 2);
	assert(list_size(list) == 1);
	
	insert_elem_begin(list, 3);
	insert_elem_begin(list, 4);
	remove_elem(list, 3);
	assert((*list)->value == 4);
	assert((*list)->next->value == 2);
	assert((*list)->next->next->value == 4);
	assert(list_size(list) == 2); 
	
	free_list(list);
	
}

void test_consult_pos() {
	List *list;
	
	list = create_list();
	
	assert(consult_pos(list, 4) == 0);
	
	insert_elem_end(list, 3);
	assert(consult_pos(list, 1) == 3);
	
	assert(consult_pos(list, 2) == 0);
	
	insert_elem_end(list, 2);
	assert(consult_pos(list, 2) == 2);
	
	free_list(list);
	
}

void test_consult_elem() {
	List *list;
	
	list = create_list();
	
	assert(consult_pos(list, 4) == 0);
	
	insert_elem_end(list, 3);
	assert(consult_elem(list, 3) == 1);
	
	assert(consult_elem(list, 2) == 0);
	
	insert_elem_end(list, 2);
	assert(consult_elem(list, 2) == 2);
	
	free_list(list);
	
}
