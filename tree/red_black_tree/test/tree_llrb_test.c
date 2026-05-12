#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree_llrb.h"

void test_tree_llrb_empty () {
	
	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (tree_llrb_empty (root) == 1);
	
	insert_tree_llrb (root, 5);
	
	assert (tree_llrb_empty (root) == 0);
	
	free_tree_llrb (root);
	
}

void test_pre_order_tree_llrb () {
	
	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (pre_order_tree_llrb (root) == 0);
	
	insert_tree_llrb (root, 1);
	
	assert (pre_order_tree_llrb (root) == 1);
	
	free_tree_llrb (root);
	
}

void test_in_order_tree_llrb () {
	
	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (in_order_tree_llrb (root) == 0);
	
	insert_tree_llrb (root, 1);
	
	assert (in_order_tree_llrb (root) == 1);
	
	free_tree_llrb (root);
	
}

void test_post_order_tree_llrb () {
	
	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (post_order_tree_llrb (root) == 0);
	
	insert_tree_llrb (root, 1);
	
	assert (post_order_tree_llrb (root) == 1);
	
	free_tree_llrb (root);
}

void test_consult_tree_llrb () {

	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (consult_tree_llrb (root, 1) == 0);
	
	insert_tree_llrb (root, 1);
	
	assert (consult_tree_llrb (root, 2) == 0);
	
	assert (consult_tree_llrb (root, 1) == 1);
	
	free_tree_llrb (root);	
	
}

void test_insert_tree_llrb () {
	
	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (insert_tree_llrb (root, 1) == 1);
	
	assert (consult_tree_llrb (root, 1) == 1);
	
	assert (insert_tree_llrb (root, 1) == 0);
	
	free_tree_llrb (root);
	
}

void test_remove_tree_llrb () {
	

	tree_llrb* root = NULL;
	root = create_tree_llrb ();
	
	assert (remove_tree_llrb (root, 1) == 0);
	
	assert (insert_tree_llrb (root, 1) == 1);
	
	assert (remove_tree_llrb (root, 2) == 0);
	
	assert (remove_tree_llrb (root, 1) == 1);
	
	assert (consult_tree_llrb (root, 1) == 0);
	
	free_tree_llrb (root);
	
}
