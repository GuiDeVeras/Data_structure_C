#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct node {
	int value;
	int height;
	struct node *left;
	struct node *right;
};

avltree* create_avltree () {
	avltree* root = (avltree*) malloc(sizeof(avltree));
	if (root != NULL) {
		*root = NULL;
	}
	return root;
}

void free_avltree (avltree *root) {
	if (root == NULL) {
		return;
	}
	free_node (*root);
	free (root);
}

void free_node (struct node* node) {
	if (node == NULL) {
		return;
	}
	free_node (node->left);
	free_node (node->right);
	free(node);
	node = NULL;
}

int avltree_empty (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 1;
	}
	return 0;
}

int avltree_height (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	int left_height = avltree_height (&((*root)->left));
	int right_height = avltree_height (&((*root)->right));
	if (left_height > right_height) {
		return (left_height + 1);
	} else {
		return (right_height + 1);
	}	
}

int total_avltree_nodes (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	int left_height = total_avltree_nodes (&((*root)->left));
	int right_height = total_avltree_nodes (&((*root)->right));
	return (left_height + right_height + 1);
}

int pre_order_avltree (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	printf("%d\n", (*root)->value);
	pre_order_avltree(&((*root)->left));
	pre_order_avltree(&((*root)->right));

	return 1;
}

int in_order_avltree (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	in_order_avltree(&((*root)->left));
	printf("%d\n", (*root)->value);
	in_order_avltree(&((*root)->right));
	
	return 1;
}

int post_order_avltree (avltree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	post_order_avltree(&((*root)->left));
	post_order_avltree(&((*root)->right));
	printf("%d\n", (*root)->value);

	return 1;
}

int node_height (struct node* node) {
	if (node == NULL) {
		return -1;
	} else {
		return node->height;
	}
}

int balancefactor_node (struct node* node) {
	if (node == NULL) return 0;
	return node_height (node->left) - node_height (node->right);
}

int bigger (int x, int y) {
	if (x > y) return x;
	return y;
}

int consult_avltree (avltree *root, int value) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	struct node* actual = *root;
	while (actual != NULL) {
		if (value == actual->value) {
			return 1;
		}
		if (value > actual->value) {
			actual = actual->right;
		} else {
			actual = actual->left;
		}
	}
	return 0;
}

void LLrotation (avltree *root) {
	struct node* node;
	node = (*root)->left;
	(*root)->left = node->right;
	node->right = *root;
	(*root)->height = bigger (node_height ((*root)->left), node_height ((*root)->right)) + 1;
	node->height = bigger (node_height (node->left), (*root)->height) + 1;
	*root = node;
}

void RRrotation (avltree *root) {
	struct node* node;
	node = (*root)->right;
	(*root)->right = node->left;
	node->left = *root;
	(*root)->height = bigger (node_height ((*root)->left), node_height ((*root)->right)) + 1;
	node->height = bigger (node_height (node->right), (*root)->height) + 1;
	*root = node;
}

void LRrotation (avltree *root) {
	RRrotation(&(*root)->left);
	LLrotation(root);
}

void RLrotation (avltree *root) {
	LLrotation(&(*root)->right);
	RRrotation(root);
}

int insert_avltree (avltree *root, int value) {
	int res;
	if (*root == NULL) {
		struct node *new;
		new = (struct node*)malloc(sizeof(struct node));
		if (new == NULL) return 0;
		new->value = value;
		new->height = 0;
		new->left = NULL;
		new->right = NULL;
		*root = new;
		return 1;
	}
	struct node *actual = *root;
	if (value < actual->value) {
		if ((res=insert_avltree(&(actual->left), value))) {
			if (balancefactor_node (actual) >= 2) {
				if (value < (*root)->left->value) LLrotation(root);
				else LRrotation(root);
			}
		}
	} else if (value > actual->value) {
		if ((res=insert_avltree(&(actual->right), value))) {
			if (balancefactor_node (actual) <= -2) {
				if (value > (*root)->right->value) RRrotation(root);
				else RLrotation(root);
			}
		}
	} else {
		return 0;
	}
	actual->height = bigger (node_height(actual->left), node_height(actual->right)) + 1;
	return res;
}

int remove_avltree (avltree *root, int value) {
	if (*root == NULL) {
		return 0;
	}
	int res;
	if (value < (*root)->value) {
		if ((res = remove_avltree (&(*root)->left, value)) == 1) {
			if (balancefactor_node (*root) >= 2) {
				if (node_height ((*root)->right->left) <= node_height ((*root)->right->right)) RRrotation(root);
				else RLrotation(root);
			}
		}
	} else if ((*root)->value < value) {
		if ((res = remove_avltree (&(*root)->right, value)) == 1) {
			if (balancefactor_node (*root) >= 2) {
				if (node_height ((*root)->left->right) <= node_height ((*root)->left->left)) LLrotation(root);
				else LRrotation(root);
			}
		}
	} else {
		if (((*root)->left == NULL || (*root)->right == NULL)) {
			struct node *oldnode = (*root);
			if ((*root)->left != NULL) *root = (*root)->left;
			else *root = (*root)->right;
			free(oldnode);
		} else {
			struct node* temp = search_lower ((*root)->right);
			(*root)->value = temp->value;
			remove_avltree(&(*root)->right, (*root)->value);
			if (balancefactor_node (*root) >= 2) {
				if (node_height ((*root)->left->right) <= node_height ((*root)->left->left)) LLrotation(root);
				else LRrotation(root);
			}
		}
		return 1;
	}
	return res;
}

struct node* search_lower (struct node* actual) {
	struct node *node1 = actual;
	struct node *node2 = actual->left;
	while (node2 != NULL) {
		node1 = node2;
		node2 = node2->left;
	}
	return node1;
}
