#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "static_stack.h"

int main(){
	
	test_insert_elem();
	printf("test_insert_elem worked!\n");

	test_remove_elem();
	printf("test_remove_elem worked!\n");
	
	test_consult_elem();
	printf("test_consult_elem worked!\n");

	test_size_stack();
	printf("test_size_stack worked!\n");
	
	return 0;
	
}
