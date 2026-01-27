#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <assert.h>

int main(){

	int i = 1, element;
	
	List *list;
	
	list = create_list();
	
	while (i != 0) {
		printf("1: Add an element at the beginning\n2: Add an element at the end\n3: Add an element in an ascending order\n4: Remove the first element\n5: Remove the last element\n6: Remove and a certain element\n7: Consult if an element is in the list\n8: Check the size of the list\n9: Check if the list is empty\n10: Print the list\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_elem_begin(list, element);
				printf("\n");
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_elem_final(list, element);
				printf("\n");
				break;
			case 3:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_elem_ordered(list, element);
				printf("\n");
				break;
			case 4:
				remove_elem_begin(list);
				break;
			case 5:
				remove_elem_end(list);
				break;
			case 6:
				printf("\nElement: ");
				scanf("%d", &element);
				remove_elem(list, element);
				printf("\n");
				break;
			case 7:
				printf("\nElement: ");
				scanf("%d", &element);
				if (consult_elem(list, element) != 0) {
					printf("The element is on the position %d\n\n", consult_elem(list, element));
				} else {
					printf("The element is not in the list\n\n");
				}
				break;
			case 8:
				printf("The list has %d elements\n\n", list_size(list));
				break;
			case 9:
				if (list_empty(list) == 0) {
					printf("The list is empty\n\n");
				} else {
					printf("The list is not empty\n\n");
				}
				break;
			case 10:
				print_list(list);
				printf("\n");
				break;
			case 0:
				free_list(list);
				printf("List freed\n");
		}
	}
	
	return 0;
}
