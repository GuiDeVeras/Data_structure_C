#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl_tree.h"

int main () {
	
	test_avltree_empty ();
	printf("test_avltree_empty worked!\n");
	
	test_avltree_height ();
	printf("test_avltree_height worked!\n");
	
	test_total_avltree_nodes ();
	printf("test_total_avltree_nodes worked!\n");
	
	test_pre_order_avltree ();
	printf("test_pre_order_avltree worked!\n");
	
	test_in_order_avltree ();
	printf("test_in_order_avltree worked!\n");
	
	test_post_order_avltree ();
	printf("test_post_order_avltree worked!\n");
	
	test_consult_avltree ();
	printf("test_consult_avltree worked!\n");
	
	test_node_height ();
	printf("test_node_height worked!\n");
	
	test_balancefactor_node ();
	printf("test_balancefactor_node worked!\n");
	
	test_bigger ();
	printf("test_bigger worked!\n");
	
	test_insert_avltree ();
	printf("test_insert_avltree worked!\n");
	
	test_remove_avltree ();
	printf("test_remove_avltree worked!\n");
	
	return 0;
	
}
