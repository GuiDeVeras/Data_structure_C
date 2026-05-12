#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree_llrb.h"

int main () {
	
	test_tree_llrb_empty ();
	printf("test_tree_llrb_empty worked!\n");
	
	test_pre_order_tree_llrb ();
	printf("test_pre_order_tree_llrb worked!\n");
	
	test_in_order_tree_llrb ();
	printf("test_in_order_tree_llrb worked!\n");
	
	test_post_order_tree_llrb ();
	printf("test_post_order_tree_llrb worked!\n");
	
	test_consult_tree_llrb ();
	printf("test_consult_tree_llrb worked!\n");
	
	test_insert_tree_llrb ();
	printf("test_insert_tree_llrb worked!\n");
	
	test_remove_tree_llrb ();
	printf("test_remove_tree_llrb worked!\n");
	
	return 0;
	
}
