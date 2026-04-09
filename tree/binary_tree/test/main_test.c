#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"

int main () {
	
	test_binary_tree_empty ();
	printf("test_binary_tree_empty worked!\n");
	
	test_binary_tree_height ();
	printf("test_binary_tree_height worked!\n");
	
	test_total_binary_tree_nodes ();
	printf("test_total_binary_tree_nodes worked!\n");
	
	test_pre_order_binary_tree ();
	printf("test_pre_order_binary_tree worked!\n");
	
	test_in_order_binary_tree ();
	printf("test_in_order_binary_tree worked!\n");
	
	test_post_order_binary_tree ();
	printf("test_post_order_binary_tree worked!\n");
	
	test_insert_binary_tree ();
	printf("test_insert_binary_tree worked!\n");
	
	test_remove_binary_tree ();
	printf("test_remove_binary_tree worked!\n");
	
	test_consult_binary_tree ();
	printf("test_consult_binary_tree worked!\n");
	
	return 0;
	
}
