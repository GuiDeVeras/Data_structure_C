#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl_tree.h"

void test_avltree_empty () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (avltree_empty (root) == 1);
	
	insert_avltree (root, 5);
	
	assert (avltree_empty (root) == 0);
	
	free_avltree (root);
	
}

void test_avltree_height () {
	
	avltree* root = create_avltree ();
	
	assert (avltree_height (root) == 0);
	
	insert_avltree (root, 5);
	
	assert (avltree_height (root) == 1);
	
	insert_avltree (root, 3);
	insert_avltree (root, 10);
	
	assert (avltree_height (root) == 2);
	
	free_avltree (root);
	
}

void test_total_avltree_nodes () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (total_avltree_nodes (root) == 0);
	
	insert_avltree (root, 5);
	
	assert (total_avltree_nodes (root) == 1);
	
	insert_avltree (root, 3);
	insert_avltree (root, 10);
	
	assert (total_avltree_nodes (root) == 3);
	
	free_avltree (root);
		
}

void test_pre_order_avltree () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (pre_order_avltree (root) == 0);
	
	insert_avltree (root, 1);
	
	assert (pre_order_avltree (root) == 1);
	
	free_avltree (root);
	
}

void test_in_order_avltree () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (in_order_avltree (root) == 0);
	
	insert_avltree (root, 1);
	
	assert (in_order_avltree (root) == 1);
	
	free_avltree (root);
	
}

void test_post_order_avltree () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (post_order_avltree (root) == 0);
	
	insert_avltree (root, 1);
	
	assert (post_order_avltree (root) == 1);
	
	free_avltree (root);
}

void test_consult_avltree () {

	avltree* root = NULL;
	root = create_avltree ();
	
	assert (consult_avltree (root, 1) == 0);
	
	insert_avltree (root, 1);
	
	assert (consult_avltree (root, 2) == 0);
	
	assert (consult_avltree (root, 1) == 1);
	
	free_avltree (root);	
	
}

void test_node_height () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (node_height (*root) == -1);
	
	insert_avltree (root, 1);
	
	assert (node_height (*root) == 0);
	
	insert_avltree (root, 2);
	
	assert (node_height (*root) == 1);
	
	assert (node_height ((*root)->right) == 0);
	
	free_avltree (root);
	
}

void test_balancefactor_node () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (balancefactor_node (*root) == 0);
	
	insert_avltree (root, 1);
	
	assert (balancefactor_node (*root) == 0);
	
	insert_avltree (root, 2);
	
	assert (balancefactor_node (*root) == 1);
	
	assert (balancefactor_node ((*root)->right) == 0);
	
	free_avltree (root);		
}

void test_bigger () {

	assert (bigger (1, 2) == 2);

}

void test_insert_avltree () {

	avltree* root = NULL;
	root = create_avltree ();
	
	assert (insert_avltree (root, 1) == 1);
	
	assert (consult_avltree (root, 1) == 1);
	
	assert (insert_avltree (root, 1) == 0);
	
	free_avltree (root);
	
}

void test_remove_avltree () {
	
	avltree* root = NULL;
	root = create_avltree ();
	
	assert (remove_avltree (root, 1) == 0);
	
	assert (insert_avltree (root, 1) == 1);
	
	assert (remove_avltree (root, 2) == 0);
	
	assert (remove_avltree (root, 1) == 1);
	
	assert (consult_avltree (root, 1) == 0);
	
	free_avltree (root);
	
}
