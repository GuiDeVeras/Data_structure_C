#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <assert.h>

int main() {
	
	test_insert_edge ();
	printf("test_insert_edge worked!\n");
	
	test_remove_edge ();
	printf("test_remove_edge worked!\n");
	
	test_depht_search ();
	printf("test_depht_search worked!\n");
	
	test_breadth_search ();
	printf("test_breadth_search worked!\n");
	
	test_shortest_path_search ();
	printf("test_shortest_path_search worked!\n");
	
	return 0;
	
}
