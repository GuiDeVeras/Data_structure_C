#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

typedef struct Node {
	struct Node *next;
	int value;
} Node;

List* create_list() {
	List* list = (List*) malloc(sizeof(List));
	if (list != NULL) {
		*list = NULL;
	return list;
	}
}

void free_list(List* list) {
	if (list != NULL && (*list) != NULL) {
		Node* node = *list, *aux;
		while ((*list) != node->next) {
			aux = node;
			node = node->next;
			free(aux);
		}
		free(node);
		free(list);
	}
}

int list_size(List* list) {
	if (list == NULL || *list == NULL) {
		return 0;
	}
	int cont = 0;
	Node* node = *list;
	do {
		cont++;
		node = node->next;
	} while (node != (*list));
	return cont;
}

int list_empty(List* list) {
	if (list == NULL || *list == NULL) {
		return 1;
	}
	return 0;
}

int insert_elem_begin(List* list, int value){
	if (list== NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	if ((*list) == NULL) {
		*list = node;
		node->next = node;
	} else {
		Node *aux = *list;
		while (aux->next != (*list)) {
			aux = aux->next;
		}
		aux->next = node;
		node->next = *list;
		*list = node;
	}
	return 1;
}

int insert_elem_end(List* list, int value) {
	if (list== NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	if ((*list) == NULL) {
		*list = node;
		node->next = node;
	} else 
	if((*list) == NULL) {
		*list = node;
	} else {
		Node *aux = *list;
		while (aux->next != (*list)) {
			aux = aux->next;
		}
		aux->next = node;
		node->next = *list;
	}
	return 1;
}

int insert_elem_ordered(List* list, int value) {
	if (list== NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	if((*list) == NULL) {
		*list = node;
		node->next = node;
		return 1;
	} else {
		if ((*list)->value > value) {
			Node *current = *list;
			while (current->next != (*list)) {
				current = current->next;
				node->next = *list;
				current->next = node;
				*list = node;
				return 1;
			}
		}
		Node *previous = *list, *current = (*list)->next;
		while (current != (*list) && current->value < value) {
			previous = current;
			current = current->next;
		}
		previous->next  = node;
		node->next = current;
		return 1;
	}
} 

int remove_elem_begin(List* list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	if ((*list) == (*list)->next) {
		free(*list);
		*list = NULL;
		return 1;
	}
	Node *current = *list;
	while (current->next != (*list)) {
		current = current->next;
	}
	Node *node = *list;
	current->next = node->next;
	*list = node->next;
	free(node);
	return 1;
}

int remove_elem_end(List* list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	if ((*list) == (*list)->next) {
		free(*list);
		*list = NULL;
		return 1;
	}
	Node *previous, *node = *list;
	while (node->next != (*list)) {
		previous = node;
		node = node->next;
	}
	previous->next = node->next;
	free(node);
	return 1;
}

int remove_elem(List* list, int value) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Node *node = *list;
	if (node->value == value) {
		free(*list);
		*list = NULL;
		return 1;
	}
	Node *previous = node;
	node = node->next;
	while (node != (*list) && node->value != value) {
		previous = node;
		node = node->next;
	}
	if (node == *list) {
		return 0;
	}
	previous->next = node->next;
	free(node);
	return 1;
}

int consult_pos(List* list, int pos) {
	if (list == NULL || (*list) == NULL || pos <= 0) {
		return 0;
	}
	int i = 1;
	Node *node = *list;
	while (node->next != (*list) && i != pos) {
		node = node->next;
		i++;
	}
	if (node->next == (*list) && i != pos) {
		return 0;
	}
	return node->value;
}

int consult_elem(List* list, int value) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	int i = 1;
	Node *node = *list;
	while (node->next != (*list) && node->value != value) {
		node = node->next;
		i++;
	}
	if (node->next == (*list) && node->value != value) {
		return 0;
	}
	return i;
}

void print_list(List *list) {
    Node *node = *list;
    do {
        printf("%d -> ", node->value);
        node = node->next;
    } while (node->next != (*list));
    printf("Loop\n");
}
