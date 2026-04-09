#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"

void test_binary_tree_empty () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (binary_tree_empty (root) == 1);
	
	insert_binary_tree (root, 5);
	
	assert (binary_tree_empty (root) == 0);
	
	free_binary_tree (root);
	
}

void test_binary_tree_height () {
	
	binary_tree* root = create_binary_tree ();
	
	assert (binary_tree_height (root) == 0);
	
	insert_binary_tree (root, 5);
	
	assert (binary_tree_height (root) == 1);
	
	insert_binary_tree (root, 3);
	insert_binary_tree (root, 10);
	
	assert (binary_tree_height (root) == 2);
	
	free_binary_tree (root);
	
}

void test_total_binary_tree_nodes () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (total_binary_tree_nodes (root) == 0);
	
	insert_binary_tree (root, 5);
	
	assert (total_binary_tree_nodes (root) == 1);
	
	insert_binary_tree (root, 3);
	insert_binary_tree (root, 10);
	
	assert (total_binary_tree_nodes (root) == 3);
	
	free_binary_tree (root);
		
}

void test_pre_order_binary_tree () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (pre_order_binary_tree (root) == 0);
	
	insert_binary_tree (root, 1);
	
	assert (pre_order_binary_tree (root) == 1);
	
	free_binary_tree (root);
	
}

void test_in_order_binary_tree () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (in_order_binary_tree (root) == 0);
	
	insert_binary_tree (root, 1);
	
	assert (in_order_binary_tree (root) == 1);
	
	free_binary_tree (root);
	
}

void test_post_order_binary_tree () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (post_order_binary_tree (root) == 0);
	
	insert_binary_tree (root, 1);
	
	assert (post_order_binary_tree (root) == 1);
	
	free_binary_tree (root);
}

void test_insert_binary_tree () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (insert_binary_tree (root, 1) == 1);
	
	assert (insert_binary_tree (root, 1) == 0);
	
	assert (insert_binary_tree (root, 2) == 1);
	
	free_binary_tree (root);
	
}

void test_remove_binary_tree () {
	
	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (remove_binary_tree (root, 1) == 0);
	
	insert_binary_tree (root, 1);
	
	assert (remove_binary_tree (root, 2) == 0);
	
	assert (remove_binary_tree (root, 1) == 1);
	
	free_binary_tree (root);
	
	
}

void test_consult_binary_tree () {

	binary_tree* root = NULL;
	root = create_binary_tree ();
	
	assert (consult_binary_tree (root, 1) == 0);
	
	insert_binary_tree (root, 1);
	
	assert (remove_binary_tree (root, 2) == 0);
	
	assert (remove_binary_tree (root, 1) == 1);
	
	free_binary_tree (root);	
	
}
