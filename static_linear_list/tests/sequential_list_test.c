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
	
	int x = list_size(li);
	
	int x = list_full(li);
	
	int x = list_empty(li);
	
	int x = insert_list_final(li, student_data);
	
	int x = insert_list_beginning(li, student_data);
	
	int x = insert_list_ordered(li, student_data);
	
	int x = int remove_list_final(li);

	int x = remove_list_beginning(li);

	int x = remove_list(li, student_registration);

	int x = consult_pos_list(li, position, &student_data);
	
	int consult_pos_mat(li, position, &student_data);
}
