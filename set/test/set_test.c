#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"
#include "avl_tree.h"

void test_insert_set () {
	
	set* s = NULL;
	
	assert(insert_set (s, 4) == 0);
	
	s = create_set ();
	
	assert(insert_set (s, 4) == 1);
	
	assert(insert_set (s, 4) == 0);
	
	free_set (s);
}

void test_remove_set () {

	set* s = NULL;
	
	assert(remove_set (s, 4) == 0);
	
	s = create_set ();
	
	assert(remove_set (s, 4) == 0);
	
	assert(insert_set (s, 4) == 1);
	
	assert(remove_set (s, 4) == 1);
	
	free_set (s);	
}

void test_search_set () {
	
		
	set* s = NULL;
	
	assert(search_set (s, 4) == 0);
	
	s = create_set ();
	
	assert(search_set (s, 4) == 0);
	
	assert(insert_set (s, 4) == 1);
	
	assert(search_set (s, 4) == 1);
	
	free_set (s);
}
