#include <stdio.h>
#include <stdlib.h>
#include "header_node.h"

typedef struct node{
	struct node *next;
	int value;
} Node;

struct header {
	Node *begin;
	Node *end;
	int qtt;
};

List* create_list(){
	List* list = (List*) malloc(sizeof(List));
	if (list != NULL) {
		list->begin = NULL;
		list->end = NULL;
		list->qtt = 0;
	}
	return list;
}

void free_list(List* list){
	if (list != NULL){
		Node* node;
		while ((list->begin) != NULL){
			node = list->begin;
			list->begin = list->begin->next;
			free(node);
		}
		free(list);
	}
}

int list_size(List* list) {
	if(list == NULL) {
		return 0;
	}
	return list->qtt;
}

int list_empty(List* list) {
	if (list == NULL || list->begin == NULL) {
		return 1;
	}
	return 0;
}

int insert_elem_begin(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = list->begin;
	if (list->begin == NULL) {
		list->end = node;
	}
	list->begin = node;
	list->qtt++;
	return 1;
}

int insert_elem_end(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	node->next = NULL;
	if (list->begin == NULL) {
		list->begin = node;
	} else {
		list->end->next = node;
	}
	list->end = node;
	list->qtt++;
	return 1;
}

int insert_elem_ordered(List* list, int value) {
	if (list == NULL) {
		return 0;
	}
	Node* node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
		return 0;
	}
	node->value = value;
	if (list->begin == NULL) {
		node->next = NULL;
		list->end = node;
		list->begin = node;
		list->qtt++;
		return 1;
	} else {
		Node *previous, *current = list->begin;
		while (current != NULL && current->value < value) {
			previous = current;
			current = current->next;
		}
		if (current == list->begin) {
			node->next = list->begin;
			list->begin = node;
			list->qtt++;
			return 1;
		}
		if (current == NULL) {
			node->next = previous->next;
			previous->next = node;
			list->end = node;
		} else {
			node->next = previous->next;
			previous->next = node;
		}
		list->qtt++;
		return 1;
	}
}

int remove_elem_begin(List* list) {
	if (list == NULL || list->begin == NULL) {
		return 0;
	}
	Node *node = list->begin;
	list->begin = node->next;
	free(node);
	if(list->begin == NULL) {
		list->end = NULL;
	}
	list->qtt--;
	return 1;
}

int remove_elem_end(List *list) {
	if (list == NULL || list->begin == NULL) {
		return 0;
	}
	Node *previous, *node = list->begin;
	while (node->next != NULL) {
		previous = node;
		node = node->next;
	}
	if (node == list->begin) {
		list->begin = NULL;
		list->end = NULL;
	} else {
		previous->next = node->next;
		list->end = previous;
	}
	free(node);
	list->qtt--;
	return 1;
}

int remove_elem(List *list, int value) {
	if (list == NULL || list->begin == NULL) {
		return 0;
	}
	Node *previous, *current = list->begin;
	while(current != NULL && current->value != value) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		return 0;
	}
	if (current == list->begin) {
		list->begin = list->begin->next;
		free(current);
		list->qtt--;
		return 1;
	} 
	if (current == list->end ) {
		previous->next = current->next;
		list->end = previous;
	} else {
		previous->next = current->next;
	}
	free(current);
	list->qtt--;
	return 1;
}

int consult_pos(List* list, int pos) {
	if (list == NULL || list->begin == NULL || pos <= 0) {
		return 0;
	}
	int i = 1;
	Node *node = list->begin;
	while (node->next != NULL && i != pos) {
		node = node->next;
		i++;
	}
	if (node->next == NULL && i != pos) {
		return 0;
	}
	return node->value;
}

int consult_elem(List* list, int value) {
	if (list == NULL || list->begin == NULL) {
		return 0;
	}
	int i = 1;
	Node *node = list->begin;
	while (node->next != NULL && node->value != value) {
		node = node->next;
		i++;
	}
	if (node->next == NULL && node->value != value) {
		return 0;
	}
	return i;
}

void print_list(List *list) {
    Node *node = list->begin;
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}
