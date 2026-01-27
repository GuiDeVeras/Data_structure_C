#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <assert.h>

struct element{
	struct element *next;
	int value;
};

typedef struct element Elem;

List* create_list(){
	List* list = (List*) malloc(sizeof(List));
	if (list != NULL) {
		*list = NULL;
	}
	return list;
}

void free_list(List* list){
	if (list != NULL){
		Elem* node;
		while ((*list) != NULL){
			node = *list;
			*list = (*list)->next;
			free(node);
		}
		free(list);
	}
}

int list_size(List* list) {
	if(list == NULL) {
		return 0;
	}
	int cont = 0;
	Elem* node = *list;
	while (node != NULL) {
		cont++;
		node = node->next;
	}
	return cont;
}

int list_empty(List* list) {
	if(list == NULL || *list == NULL) {
		return 1;
	}
	return 0;
}

int insert_elem_begin(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Elem* node = (Elem*) malloc(sizeof(Elem));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = (*list);
	*list = node;
	return 1;
}

int insert_elem_final(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Elem* node = (Elem*) malloc(sizeof(Elem));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = NULL;
	if ((*list) == NULL) {
		*list = node;
	} else {
		Elem *aux = *list;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = node;
	}
	return 1;
}

int insert_elem_ordered(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Elem* node = (Elem*) malloc(sizeof(Elem));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	if (list_empty(list)) {
		node->next = (*list);
		*list = node;
		return 1;
	} else {
		Elem *previous, *current = *list;
		while (current != NULL && current->value < value) {
			previous = current;
			current = current->next;
		}
		if (current == *list) {
			node->next = *list;
			*list = node;
		} else {
			node->next = previous->next;
			previous->next = node;
		}
		return 1;
	}
}

int remove_elem_begin(List* list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Elem *node = *list;
	*list = node->next;
	free(node);
	return 1;
}

int remove_elem_end(List *list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Elem *previous, *node = *list;
	while (node->next != NULL) {
		previous = node;
		node = node->next;
	}
	if (node == (*list)) {
		*list = node->next;
	} else {
		previous->next = node->next;
	}
	free(node);
	return 1;
}

int remove_elem(List *list, int value) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Elem *previous, *node = *list;
	while(node != NULL && node->value != value) {
		previous = node;
		node = node->next;
	}
	if (node == NULL) {
		return 0;
	}
	if (node == *list) {
		*list = node->next;
	} else {
		previous->next = node->next;
	}
	free(node);
	return 1;
}

int consult_elem(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Elem *node = *list;
	int i = 0;
	while (node != NULL && (*list)->next->value != value) {
		node = node->next;
		i++;
	}
	if (node == NULL) {
		return 0;
	} else {
		return i;
	}
}

void print_list(List *list) {
    Elem *node = *list;
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}
