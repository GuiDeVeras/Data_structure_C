#include <stdio.h>
#include <stdlib.h>
#include "tree_llrb.h"
#define RED 1
#define BLACK 0

struct node {
	int value;
	int colour;
	struct node *left;
	struct node *right;
};

int colour (struct node* H) {
	if (H == NULL) return BLACK;
	else return H->colour;
}

void colour_change (struct node* H) {
	H->colour = !H->colour;
	if (H->left != NULL) H->left->colour = !H->left->colour;
	if (H->right != NULL) H->right->colour = !H->right->colour;
}

struct node* Lrotation (struct node* A) {
	struct node* B = A->right;
	A->right = B->left;
	B->left = A;
	B->colour = A->colour;
	A->colour = RED;
	return B;
}

struct node* Rrotation (struct node* A) {
	struct node* B = A->left;
	A->left = B->right;
	B->right = A;
	B->colour = A->colour;
	A->colour = RED;
	return B;
}

struct node* moveLRed (struct node* H) {
	colour_change (H);
	if (colour(H->right->left) == RED)  {
		H->right = Rrotation (H->right);
		colour_change (H);
	}
	return H;
}

struct node* moveRRed (struct node* H) {
	colour_change (H);
	if (colour(H->left->left) == RED)  {
		H = Rrotation (H);
		colour_change (H);
	}
	return H;
}

struct node* balance(struct node* H){
    if(colour(H->right) == RED) H = Lrotation(H);
    if(H->left != NULL && colour(H->left) == RED && colour(H->left->left) == RED) H = Rrotation(H);
    if(colour(H->left) == RED && colour(H->right) == RED) colour_change(H);
    return H;

}

int insert_tree_llrb (tree_llrb* root, int value) {
	int resp;
	*root = insert_node (*root, value, &resp);
	if ((*root) != NULL) (*root)->colour = BLACK;
	return resp;
}

struct node* insert_node (struct node* H, int value, int *resp) {
	if (H == NULL) {
		struct node *new;
		new = (struct node*) malloc (sizeof(struct node));
		if (new == NULL) {
			*resp = 0;
			return 	NULL;
		}
		new->value = value;
		new->colour = RED;
		new->right = NULL;
		new->left = NULL;
		*resp = 1;
		return new;
	}
	if (value == H->value) *resp = 0;
	else {
		if (value < H->value) H->left = insert_node (H->left, value, resp);
		else H->right = insert_node (H->right, value, resp);
	}
	if (colour(H->right) == RED && colour(H->left) == BLACK) H = Lrotation (H);
	if (colour(H->left) == RED && colour(H->left->left) == RED) H = Rrotation (H);
	if (colour(H->right) == RED && colour(H->left) == RED) colour_change (H);
	
	return H;
}

int remove_tree_llrb (tree_llrb *root, int value) {
	if (consult_tree_llrb (root, value)) {
		struct node* H = *root;
		*root = remove_node (H, value);
		if (*root != NULL) (*root)->colour = BLACK;
		return 1;
	} else return 0;
}

struct node* remove_node (struct node* H, int value) {
	if (value < H->value) {
		if (colour (H->left) == BLACK && colour (H->left->left) == BLACK) H = moveLRed (H);
		H->left = remove_node (H->left, value);
	} else {
		if (colour(H->left) == RED) H = Rrotation (H);
		if (value == H->value && (H->right == NULL)) {
			free (H);
			return NULL;
		}
		if (colour(H->right) == BLACK && colour (H->right->left) == BLACK) H = moveRRed (H);
		if (value == H->value) {
			struct node* x = search_lower (H->right);
			H->value = x->value;
			H->right = remove_lower (H->right);
		} else H->right = remove_node (H->right, value);
	}
	return balance (H);
}

struct node* remove_lower (struct node* H) {
	if (H->left == NULL) {
		free (H);
		return NULL;
	}
	if (colour(H->left) == BLACK && colour(H->left->left) == BLACK) H = moveLRed (H);
	H->left = remove_lower (H->left);
	return balance (H);
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

tree_llrb* create_tree_llrb () {
	tree_llrb* root = (tree_llrb*) malloc(sizeof(tree_llrb));
	if (root != NULL) {
		*root = NULL;
	}
	return root;
}

void free_tree_llrb (tree_llrb *root) {
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

int tree_llrb_empty (tree_llrb *root) {
	if (root == NULL || *root == NULL) {
		return 1;
	}
	return 0;
}

int pre_order_tree_llrb (tree_llrb *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	printf("%d\n", (*root)->value);
	pre_order_tree_llrb(&((*root)->left));
	pre_order_tree_llrb(&((*root)->right));

	return 1;
}

int in_order_tree_llrb (tree_llrb *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}
	in_order_tree_llrb(&((*root)->left));
	printf("%d\n", (*root)->value);
	in_order_tree_llrb(&((*root)->right));
	
	return 1;
}

int post_order_tree_llrb (tree_llrb *root) {
	if (root == NULL || *root == NULL) {
		return 0;
	}

	post_order_tree_llrb(&((*root)->left));
	post_order_tree_llrb(&((*root)->right));
	printf("%d\n", (*root)->value);

	return 1;
}


int consult_tree_llrb (tree_llrb *root, int value) {
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
