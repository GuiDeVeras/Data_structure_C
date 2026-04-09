#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct node {
	int value;
	struct node *left;
	struct node *right;
} ;

binary_tree* create_binary_tree () {
	binary_tree* root = (binary_tree*) malloc(sizeof(binary_tree));
	if (root != NULL) {
		*root = NULL;
	}
	return root;
}

void free_binary_tree (binary_tree *root) {
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

int binary_tree_empty (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 1;
	}
	return 0;
}

int binary_tree_height (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	int left_height = binary_tree_height (&((*root)->left));
	int right_height = binary_tree_height (&((*root)->right));
	if (left_height > right_height) {
		return (left_height + 1);
	} else {
		return (right_height + 1);
	}	
}

int total_binary_tree_nodes (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	int left_height = total_binary_tree_nodes (&((*root)->left));
	int right_height = total_binary_tree_nodes (&((*root)->right));
	return (left_height + right_height + 1);
}

int pre_order_binary_tree (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	printf("%d\n", (*root)->value);
	pre_order_binary_tree(&((*root)->left));
	pre_order_binary_tree(&((*root)->right));

	return 1;
}

int in_order_binary_tree (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	in_order_binary_tree(&((*root)->left));
	printf("%d\n", (*root)->value);
	in_order_binary_tree(&((*root)->right));
	
	return 1;
}

int post_order_binary_tree (binary_tree *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	post_order_binary_tree(&((*root)->left));
	post_order_binary_tree(&((*root)->right));
	printf("%d\n", (*root)->value);

	return 1;
}

int insert_binary_tree (binary_tree *root, int value) {
	if (root == NULL) {
		return 0;
	}
	struct node* new;
	new = (struct node*) malloc(sizeof(struct node));
	if (new == NULL) {
		return 0;
	}
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	if (*root == NULL) {
		*root = new;
	} else {
		struct node* actual = *root;
		struct node* previous = NULL;
		while (actual != NULL) {
			previous = actual;
			if (value == actual->value) {
				free (new);
				return 0;
			}
			if (value > actual->value) {
				actual = actual->right;
			} else {
				actual = actual->left;
			}
		}
		if (value > previous->value) {
			previous->right = new;
		} else {
			previous->left = new;
		}
	}
	return 1;
}

int remove_binary_tree (binary_tree *root, int value) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	struct node* actual = *root;
	struct node* previous = NULL;
	while (actual != NULL) {
		if (value == actual->value) {
			if (actual == *root) {
				*root = remove_actual (actual);
			} else {
				if (previous->right == actual) {
					previous->right = remove_actual (actual);
				} else {
					previous->left = remove_actual (actual);
				}
			}
			return 1;
		}
		previous = actual;
		if (value > actual->value) {
			actual = actual->right;
		} else {
			actual = actual->left;
		}
	}
	return 0;
}

struct node* remove_actual (struct node* actual) {
	struct node *node1, *node2;
	if (actual->left == NULL) {
		node2 = actual->right;
		free (actual);
		return node2;
	}
	node1 = actual;
	node2 = actual->left;
	while (node2->right != NULL) {
		node1 = node2;
		node2 = node2->right;
	}
	if (node1 != actual) {
		node1->right = node2->left;
		node2->left = actual->left;
	}
	node2->right = actual->right;
	free(actual);
	return node2;
}

int consult_binary_tree (binary_tree *root, int value) {
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
