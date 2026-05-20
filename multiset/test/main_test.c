#include <stdio.h>
#include <stdlib.h>
#include "bag.h"

int main () {
	
	test_insert_bag ();
	printf("test_insert_bag worked!\n");

	test_remove_bag ();
	printf("test_remove_bag worked!\n");

	test_consult_bag ();
	printf("test_consult_bag worked!\n");
	
	return 0;
}
