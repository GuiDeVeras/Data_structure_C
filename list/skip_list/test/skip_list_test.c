#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "skip_list.h"

void test_search_skip_list () {
	
	skip_list *sl =  NULL;
	
	assert(search_skip_list(sl, 2) == 0);
	
	sl = create_skip_list (3, 0.5);
	
	assert(search_skip_list(sl, 2) == 0);
	
	assert(insert_skip_list (sl, 2) == 1);
	
	assert(search_skip_list(sl, 2) == 1);
	
	free_skip_list (sl);
	
}

void test_insert_skip_list () {
	
	skip_list *sl =  NULL;
	
	assert(insert_skip_list(sl, 2) == 0);
	
	sl = create_skip_list (3, 0.5);
	
	assert(insert_skip_list (sl, 2) == 1);
	
	assert(insert_skip_list (sl, 3) == 1);
	
	free_skip_list (sl);
	
}

void test_remove_skip_list () {
	
	skip_list *sl =  NULL;
	
	assert(remove_skip_list(sl, 2) == 0);
	
	sl = create_skip_list (3, 0.5);
	
	assert(remove_skip_list(sl, 2) == 0);
	
	assert(insert_skip_list (sl, 2) == 1);
	
	assert(remove_skip_list(sl, 2) == 1);
	
	free_skip_list (sl);
	
}
