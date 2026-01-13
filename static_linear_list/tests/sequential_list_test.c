#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequential_list.h"

int main(){
	
	int x, position = 1, registration = 174931;

	Student student_data;
	student_data.registration = 291754;
	strcpy(student_data.name, "Guilherme de Veras");
	student_data.n1 = 8.2;
	student_data.n2 = 8.7;
	student_data.n3 = 9.9;
	
	Student student_data_2;
	student_data_2.registration = 284105;
	strcpy(student_data_2.name, "Henry de Veras");
	student_data_2.n1 = 2.1;
	student_data_2.n2 = 3.9;
	student_data_2.n3 = 5.0;
	
	Student student_data_3;
	student_data_3.registration = 174931;
	strcpy(student_data_3.name, "Roger vei");
	student_data_2.n1 = 0.0;
	student_data_2.n2 = 3.1;
	student_data_2.n3 = 1.2;
	
	Student student_data_4;
	student_data_4.registration = 174931;
	
	List *li;
	
	li = create_list();
	
	if (li == NULL) {
		printf("Error: Fail when assign memory to the list.\n");
		return 1;
	}
	printf("Success: List created.\n");

	printf("List size: %d.\n", list_size(li));
	
	printf("Verifying if the list is empty.\n");
	if (list_empty(li)){
		printf("The list is empty.\n");
	}
	
	printf("Adding a student to the list.\n");
	insert_list_final(li, student_data);	
	print_list(li);
	
	printf("Adding a student to the first position.\n");
	insert_list_beginning(li, student_data_2);
	print_list(li);
	
	printf("Adding a student in ascending order.\n");
	insert_list_ordered(li, student_data_3);
	print_list(li);

	printf("Searching who is the student in the first position.\n");
	if (consult_pos_list(li, position, &student_data)){
		printf("The student in this position is %s.\n", student_data.name);
	} else {
		printf("There isn't a student in this posiiton.\n");
	}
	
	printf("Searching if the student 4° with the registration 174931 is in the list.\n");
	if (consult_pos_reg(li, registration, &student_data_4)){
		printf("It is in the list.\n");
	} else {
		printf("It isn't in the list.\n");
	}
	
	printf("Removing the last student.\n");
	remove_list_final(li);
	print_list(li);

	printf("Removing the first student.\n");
	remove_list_beginning(li);
	print_list(li);

	printf("Removing the student with the registration 284105.\n");
	remove_list(li, 284105);
	print_list(li);

	printf("Freeing the list.\n");
	free_list(li);
	printf("Success: List freed.\n");
}
