#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

int main(){

	int i = 1, element, position;
	
	Stack *stack;
	
	stack = create_stack();
	
	while (i != 0) {
		printf("1: Add an element at the beginning\n2: Remove the first element\n3: Consult the first element\n4: Check the size of the stack\n5: Check if the stack is empty\n6: Print the stack\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_elem(stack, element);
				printf("\n");
				break;
			case 2:
				remove_elem(stack);
				break;
			case 3:
				if (consult_elem(stack) != 0) {
					printf("The first element is %d\n\n", consult_elem(stack));
				} else {
					printf("There is no element in the stack\n\n");
				}
				break;
			case 4:
				printf("The stack has %d elements\n\n", size_stack(stack));
				break;
			case 5:
				if (stack_empty(stack) == 1) {
					printf("The stack is empty\n\n");
				} else {
					printf("The stack is not empty\n\n");
				}
				break;
			case 6:
				print_stack(stack);
				printf("\n");
				break;
			case 0:
				free_stack(stack);
				printf("Stack freed\n");
		}
	}
	
	return 0;
}
