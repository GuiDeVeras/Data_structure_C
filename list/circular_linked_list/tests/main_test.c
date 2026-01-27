#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

int main() {
	
	test_insert_elem_begin();
	printf("test_insert_elem_begin worked!\n");
	
	test_insert_elem_end();
	printf("test_insert_elem_end worked!\n");
	
	test_insert_elem_ordered();
	printf("test_insert_elem_ordered worked!\n");
	
	test_remove_elem_begin();
	printf("test_remove_elem_begin worked!\n");
	
	test_remove_elem_end();
	printf("test_remove_elem_end worked!\n");
	
	test_remove_elem();
	printf("test_remove_elem worked!\n");
	
	test_consult_pos();
	printf("test_consult_pos worked!\n");
	
	test_consult_elem();
	printf("test_consult_elem worked!\n");

}
