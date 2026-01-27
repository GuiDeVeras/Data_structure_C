#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequential_list.h"
#include <stdbool.h>
#define MAX 100

int main(void) {

	test_insert_list_final();
	printf("test_insert_list_final worked!\n\n");
	
	test_insert_list_beginning();
	printf("test_insert_list_beginning worked!\n\n");

	test_insert_list_ordered();
	printf("test_insert_list_ordered worked!\n\n");

	test_remove_list_final();
	printf("test_remove_list_final worked!\n\n");
	
	test_remove_list_beginning();
	printf("test_remove_list_beginning worked!\n\n");
	
	test_remove_list();
	printf("test_remove_list worked!\n\n");
	
	test_list_full();
	printf("test_list_full worked!\n\n");
	
	test_list_empty();
	printf("test_list_empty worked\n\n");
	
	test_consult_pos_list();
	printf("test_consult_pos_list worked!\n\n");
	
	test_consult_pos_value();
	printf("test_consult_pos_value worked!\n\n");
	
	test_free_list();
	printf("test_free_list worked!\n");
	
    return 0;
}
