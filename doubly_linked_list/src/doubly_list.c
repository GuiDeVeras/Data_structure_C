#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

typedef struct Node {
	struct Node *previous;
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
	if (list != NULL) {
		Node* node;
		while ((*list) != NULL) {
			node = *list;
			*list = (*list)->next;
			free(node);
		}
		free(list);
	}
}

int list_size(List* list) {
	if (list == NULL) {
		return 0;
	}
	int cont = 0;
	Node* node = *list;
	while (node != NULL) {
		cont++;
		node = node->next;
	}
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
	node->next = (*list);
	node->previous = NULL;
	if (*list != NULL) {
		(*list)->previous = node;
	}
	*list = node;
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
	node->next = NULL;
	if((*list) == NULL) {
		node->previous = NULL;
		*list = node;
	} else {
		Node *aux = *list;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = node;
		node->previous = aux;
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
	if(list_empty(list)) {
		node->next = NULL;
		node->previous = NULL;
		*list = node;
		return 1;
	} else {
		Node *previous, *current = *list;
		while (current != NULL && current->value < value) {
			previous = current;
			current = current->next;
		}
		if (current == *list) {
			node->previous = NULL;
			(*list)->previous = node;
			node->next = (*list);
			*list = node;
		} else {
			node->next = previous->next;
			node->previous = previous;
			previous->next = node;
			if (current != NULL) {
				current->previous = node; 
			}
		}
		return 1;
	}
}

int remove_elem_begin(List* list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Node *node = *list;
	*list = node->next;
	if (node->next != NULL) {
		node->next->previous = NULL;
	}
	free(node);
	return 1;
}

int remove_elem_end(List* list) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Node *node = *list;
	while (node->next != NULL) {
		node = node->next;
	}
	if (node->previous == NULL) {
		*list = node->next;
	} else {
		node->previous->next = NULL;
	}
	free(node);
	return 1;
}

int remove_elem(List* list, int value) {
	if (list == NULL || (*list) == NULL) {
		return 0;
	}
	Node *node = *list;
	while (node != NULL && node->value != value) {
		node = node->next;
	}
	if (node == NULL) {
		return 0;
	}
	if (node->previous == NULL) {
		*list = node->next;
	} else {
		node->previous->next = node->next;
	}
	if (node->next != NULL) {
		node->next->previous = node->previous;
	}
	free(node);
	return 1;
}

int consult_elem_pos(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	int i = 1;
	Node *node = *list;
	while (node != NULL && node->value != value) {
		node = node->next;
		i++;
	}
	if (node == NULL) {
		return 0;
	}
	return i;
}

void print_list(List *list) {
    Node *node = *list;
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}
