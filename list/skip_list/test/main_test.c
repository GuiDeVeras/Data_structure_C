#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "skip_list.h"

int main() {

	test_search_skip_list ();
	printf("test_search_skip_list worekd!\n");

	test_insert_skip_list ();
	printf("test_insert_skip_list worekd!\n");

	test_remove_skip_list ();	
	printf("test_remove_skip_list worekd!\n");
	
	return 0;
}
