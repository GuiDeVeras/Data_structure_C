#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamic_deque.h"

int main() {
	
	test_size_deque ();
	printf("test_size_deque worked!\n");

	test_empty_deque ();
	printf("test_empty_deque worked!\n");

	test_consult_begin ();
	printf("test_consult_begin worked!\n");

	test_consult_end ();
	printf("test_consult_end worked!\n");

	test_insert_begin ();
	printf("test_insert_begin worked!\n");

	test_insert_end ();
	printf("test_insert_end worked!\n");

	test_remove_begin ();
	printf("test_remove_begin worked!\n");

	test_remove_end ();
	printf("test_remove_end worked!\n");
	
	return 0;
	
}
