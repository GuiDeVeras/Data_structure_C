#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bag.h"

void test_insert_bag () {
	
	bag* b = NULL;
	
	assert(insert_bag (b, 4) == 0);
	
	b = create_bag ();
	
	assert(insert_bag (b, 4) == 1);
	
	assert(insert_bag (b, 4) == 1);
	
	free_bag (b);
}

void test_remove_bag () {

	bag* b = NULL;
	
	assert(remove_bag (b, 4) == 0);
	
	b = create_bag ();
	
	assert(remove_bag (b, 4) == 0);
	
	assert(insert_bag (b, 4) == 1);
	
	assert(remove_bag (b, 4) == 1);
	
	free_bag (b);	
}

void test_consult_bag () {
	
		
	bag* b = NULL;
	
	assert(consult_bag (b, 4) == 0);
	
	b = create_bag ();
	
	assert(consult_bag (b, 4) == 0);
	
	assert(insert_bag (b, 4) == 1);
	
	assert(consult_bag (b, 4) == 1);
	
	free_bag (b);
}
