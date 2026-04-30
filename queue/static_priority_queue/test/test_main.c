#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "static_p_queue.h"

int main() {
	
	test_size_p_queue ();
	printf("test_size_p_queue worked!\n");

	test_p_queue_full ();
	printf("test_p_queue_full worked!\n");

	test_p_queue_empty ();
	printf("test_p_queue_empty worked!\n");
		
	test_insert_p_queue_array ();
	printf("test_insert_p_queue_array worked!\n");

	test_remove_p_queue_array ();
	printf("test_remove_p_queue_array worked!\n");

	test_consult_p_queue_array ();
	printf("test_consult_p_queue_array worked!\n");

	test_insert_p_queue_heap ();
	printf("test_insert_p_queue_heap worked!\n");

	test_remove_p_queue_heap ();
	printf("test_remove_p_queue_heap worked!\n");
	
	return 0;
}
