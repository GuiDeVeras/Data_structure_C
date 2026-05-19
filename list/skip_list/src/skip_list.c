#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"

struct node {
	int key;
	struct node **next;
};

struct skip_list {
	int max_level;
	float p;
	int level;
	struct node *begin;
};

skip_list* create_skip_list (int max_level, float p) {
	skip_list *sl = (skip_list*) malloc(sizeof(skip_list));
	if (sl != NULL) {
		sl->max_level = max_level;
		sl->p = p;
		sl->level = 0;
		sl->begin = new_node (-1, max_level);
	}
	return sl;
}

struct node* new_node (int key, int level) {
	struct node* new = malloc(sizeof(struct node));
	if (new != NULL) {
		new->key = key;
		new->next = malloc ((level+1)* sizeof(struct node*));
		int i;
		for (i = 0; i < (level+1); i++) new->next[i] = NULL;
	}
	return new;
}

void free_skip_list (skip_list* sl) {
	if (sl == NULL) return;
	struct node *node, *actual;
	actual = sl->begin->next[0];
	while (actual != NULL) {
		node = actual;
		actual = actual->next[0];
		free (node->next);
		free (node);
	}
	free (sl->begin);
	free (sl);
}

int search_skip_list (skip_list *sl, int key) {
	if (sl == NULL) return 0;
	struct node *actual = sl->begin;
	int i;
	for (i = sl->level; i >= 0; i--) {
		while (actual->next[i] != NULL && actual->next[i]->key < key) actual = actual->next[i];
	}
	actual = actual->next[0];
	if (actual != NULL && actual->key == key) return 1;
	return 0;
}

int insert_skip_list (skip_list *sl, int key) {
	if (sl == NULL) return 0;
	int i;
	struct node *actual = sl->begin;
	struct node **aux;
	aux = malloc ((sl->max_level+1) * sizeof(struct node*));
	for (i = 0; i <= sl->max_level; i++) aux[i] = NULL;
	for (i = sl->level; i >= 0; i--) {
		while (actual->next[i] != NULL && actual->next[i]->key < key) actual = actual->next[i];
		aux[i] = actual;
	}
	actual = actual->next[0];
	if (actual == NULL || actual->key != key) {
		int new_level = level_draw (sl);
		struct node* new = new_node (key, new_level);
		if (new == NULL) {
			free (aux);
			return 0;
		}
		if (new_level > sl->level) {
			for (i = sl->level+1; i <= new_level; i++) aux[i] = sl->begin;
			sl->level = new_level;
		}
		for (i = 0; i<= new_level; i++) {
			new->next[i] = aux[i]->next[i];
			aux[i]->next[i] = new;
		}
		free (aux);
		return 1;
	}
	
	free(aux);
	return 0;
}

int level_draw (skip_list *sl) {
	float r = (float)rand()/RAND_MAX;
	int level = 0;
	while (r < sl->p && level < sl->max_level) {
		level++;
		r = (float)rand()/RAND_MAX;
	}
	return level;
}

int remove_skip_list (skip_list *sl, int key) {
	if (sl == NULL) return 0;
	int i;
	struct node* actual = sl->begin;
	struct node **aux;
	aux = malloc ((sl->max_level+1) * sizeof(struct node*));
	for (i = 0; i <= sl->max_level; i++) aux[i] = NULL;
	for (i = sl->level; i >= 0; i--) {
		while (actual->next[i] != NULL && actual->next[i]->key < key) actual = actual->next[i];
		aux[i] = actual;
	}
	actual = actual->next[0];
	if (actual != NULL && actual->key == key) {
		for (i = 0; i <= sl->level; i++) {
			if (aux[i]->next[i] != actual) break;
			aux[i]->next[i] = actual->next[i];
		}
		while (sl->level > 0 && sl->begin->next[sl->level] == NULL) sl->level--;
		free(actual->next);
		free(actual);
		free(aux);
		return 1;
	}
	free(aux);
	return 0;
}
