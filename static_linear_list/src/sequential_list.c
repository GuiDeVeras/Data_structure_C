#include <stdio.h>
#include <stdlib.h>
#include "sequential_list.h"
#include <assert.h>
#include <stdbool.h>
#define MAX 100

struct list{
	int qtt;
	int value[MAX];
};

List* create_list(){
	List *li;
	li = (List*) malloc (sizeof(struct list));
	if (li != NULL){
		li->qtt = 0;
	}
	return li;
}

void free_list(List* li){
	free(li);
}

int list_size(List* li){
	if (li == NULL){
		return -1;
	} else {
		return li->qtt;
	}
}

int list_full(List* li){
	if (li == NULL){
		return -1;
	}
	return (li->qtt == MAX);
}

int list_empty(List* li){
	if (li == NULL){
		return -1;
	}
	return (li->qtt == 0);
}

int insert_list_final(List* li, int value){
	if (li == NULL || list_full(li)){
		return 0;
	}
	li->value[li->qtt] = value;
	li->qtt++;
	return 1;
}

int insert_list_beginning(List* li, int value){
	if(li == NULL){
		return 0;
	}
	if (list_full(li)){
		return 0;
	}
	int i;
	for (i = li->qtt-1; i >= 0; i--){
		li->value[i+1] = li->value[i];
	}
	li->value[0] = value;
	li->qtt++;
	return 1;
}

int insert_list_ordered(List* li, int value){
	if (li == NULL){
		return 0;
	}
	if (list_full(li)){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->value[i] < value){
		i++;
	}
	for (k = li->qtt-1; k >= i; k--){
		li->value[k+1] = li->value[k];
	}
	li->value[i] = value;
	li->qtt++;
	return 1;
}

int remove_list_final(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtt == 0){
		return 0;
	}
	li->qtt--;
	return 1;
}

int remove_list_beginning(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtt == 0){
		return 0;
	}
	int k = 0;
	for (k = 0; k < li->qtt-1; k++){
		li->value[k] = li->value[k+1];
	}
	li->qtt--;
	return 1;
}

int remove_list(List* li, int value){
	if (li == NULL || li->qtt == 0){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->value[i] != value){
		i++;
	}
	if (i == li->qtt){ //element not found
		return 0;
	}
	for (k = i; k < li->qtt-1; k++){
		li->value[k] = li->value[k+1];
	}
	li->qtt--;
	return 1;
}

int consult_pos_list(List* li, int pos){
	if(li == NULL || pos <= 0 || pos > li->qtt){
		return 0;
	}
	return 1;
}

int consult_pos_value(List* li, int value){
	if (li == NULL){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->value[i] != value){
		i++;
	}
	if (i == li->qtt){ //element not found
		return 0;
	}
	return 1;
}

void print_list(List *li) {
    if (li == NULL || list_empty(li)) {
        printf("The list is empty or doesn't exist.\n");
        return;
    }
	printf("List: ");
	for (int i = 0; i < li->qtt; i++) {
        printf("%d  ", li->value[i]);
    }
}

void test_insert_list_final() {
	List *list;
	
	list = create_list();
	
	insert_list_final(list, 1);
	assert(list != NULL);
	assert(list->value[0] == 1);
	assert(list_size(list) == 1);
	
	insert_list_final(list, 2);
	assert(list->value[0] == 1);
	assert(list->value[1] == 2);
	assert(list_size(list) == 2);
	
	insert_list_final(list, 3);
	assert(list->value[0] == 1);
	assert(list->value[1] == 2);
	assert(list->value[2] == 3);
	assert(list_size(list) == 3);
	
	for (int i = 3; i < MAX; i++) {
		insert_list_final(list, i);
	}
	assert(insert_list_final(list, 3) == 0);
	
	free_list(list);
	
}

void test_insert_list_beginning() {
	List *list;
	
	list = create_list();
	
	insert_list_beginning(list, 1);
	assert(list != NULL);
	assert(list->value[0] == 1);
	assert(list_size(list) == 1);
	
	insert_list_beginning(list, 2);
	assert(list->value[0] == 2);
	assert(list->value[1] == 1);
	assert(list_size(list) == 2);
	
	insert_list_beginning(list, 3);
	assert(list->value[0] == 3);
	assert(list->value[1] == 2);
	assert(list->value[2] == 1);
	assert(list_size(list) == 3);
	
	for (int i = 3; i < MAX; i++) {
		insert_list_final(list, i);
	}
	assert(insert_list_final(list, 3) == 0);
	
	free_list(list);
	
}

void test_insert_list_ordered() {
	List *list;
	
	list = create_list();
	
	insert_list_ordered(list, 4);
	assert(list != NULL);
	assert(list->value[0] == 4);
	assert(list_size(list) == 1);
	
	insert_list_ordered(list, 1);
	assert(list->value[0] == 1);
	assert(list->value[1] == 4);
	assert(list_size(list) == 2);
	
	insert_list_ordered(list, 7);
	assert(list->value[0] == 1);
	assert(list->value[1] == 4);
	assert(list->value[2] == 7);
	assert(list_size(list) == 3);
	
	for (int i = 3; i < MAX; i++) {
		insert_list_final(list, i);
	}
	assert(insert_list_final(list, 3) == 0);
	
	free_list(list);
	
}

void test_remove_list_final(){
	List *list;
	
	list = create_list();
	
	assert(remove_list_final(list) == 0);
	
	insert_list_final(list, 4);
	remove_list_final(list);
	assert(list_size(list) == 0);
	
	insert_list_final(list, 2);
	insert_list_final(list, 1);
	remove_list_final(list);
	assert(list->value[0] == 2);
	assert(list_size(list) == 1);
	
	insert_list_final(list, 7);
	insert_list_final(list, 1);
	remove_list_final(list);
	assert(list->value[0] == 2);
	assert(list->value[1] == 7);
	assert(list_size(list) == 2);
	
	free_list(list);
}

void test_remove_list_beginning(){
	List *list;
	
	list = create_list();
	
	assert(remove_list_beginning(list) == 0);
	
	insert_list_final(list, 4);
	remove_list_beginning(list);
	assert(list_size(list) == 0);
	
	insert_list_final(list, 2);
	insert_list_final(list, 1);
	remove_list_beginning(list);
	assert(list->value[0] == 1);
	assert(list_size(list) == 1);
	
	insert_list_final(list, 7);
	insert_list_final(list, 3);
	remove_list_beginning(list);
	assert(list->value[0] == 7);
	assert(list->value[1] == 3);
	assert(list_size(list) == 2);
	
	free_list(list);
}

void test_remove_list(){
	List *list;
	
	list = create_list();
	
	assert(remove_list(list, 1) == 0);
	
	insert_list_final(list, 4);
	remove_list(list, 4);
	assert(list_size(list) == 0);
	
	insert_list_final(list, 2);
	insert_list_final(list, 1);
	remove_list(list, 1);
	assert(list->value[0] == 2);
	assert(list_size(list) == 1);
	
	insert_list_final(list, 7);
	insert_list_final(list, 3);
	remove_list(list, 7);
	assert(list->value[0] == 2);
	assert(list->value[1] == 3);
	assert(list_size(list) == 2);
	
	free_list(list);
}

void test_list_full() {
	List *list;
	
	list = create_list();
	
	insert_list_final(list, 4);
	assert(list_full(list) == false);
	
	for (int i = 1; i < MAX; i++) {
		insert_list_final(list, i);
	}
	assert(list_full(list) == true);
	
}

void test_list_empty() {
	List *list;
	
	list = create_list();
	
	assert(list_empty(list) == true);
	
	insert_list_final(list, 4);
	assert(list_empty(list) == false);
	
}

void test_consult_pos_list() {
	List *list;
	
	list = create_list();
	
	assert(consult_pos_list(list, 2) == 0);
	
	insert_list_final(list, 4);
	assert(consult_pos_list(list, 1) == 1);
	
}

void test_consult_pos_value() {
	List *list;
	
	list = create_list();
	
	assert(consult_pos_value(list, 4) == 0);
	
	insert_list_final(list, 3);
	assert(consult_pos_value(list, 1) == 0);
	
	assert(consult_pos_value(list, 3) == 1);
	
}

void test_free_list() {
	List *list;
	
	list = create_list();
	
	insert_list_final(list, 2);
	free_list(list);
	list = NULL;
	assert(list == NULL);
	
}
