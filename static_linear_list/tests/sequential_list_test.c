#include <stdio.h>
#include <stdlib.h>
#include "sequential_list.h"

int main(){
	List *li;

	li = create_list();
	
	if (li == NULL) {
		printf("Error: Fail when assign memory to the list.\n");
		return 1;
	}
	printf("Success: List created.\n");

	free_list(li);
	printf("Success: List freed.\n");
}
