#include <stdio.h>
#include <stdlib.h>
#include "mst.h"
#include <assert.h>

int main () {
	
	test_insert_edge ();
	printf("test_insert_edge worked!\n");
	
	test_remove_edge ();
	printf("test_remove_edge worked!\n");
	
	test_prim_graph ();
	printf("test_prim_graph worked!\n");
	
	test_kruskal_graph ();
	printf("test_kruskal_graph worked!\n");
	
	return 0;
	
}
