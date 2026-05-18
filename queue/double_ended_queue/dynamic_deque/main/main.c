#include <stdio.h>
#include <stdlib.h>
#include "dynamic_deque.h"

int main(){

	int i = 1, element, position, value;
	
	deque *dq;
	
	dq = create_deque();
	
	while (i != 0) {
		printf("1: Add an element at the end\n2: Remove the first element\n3: Add an element at the begin\n4: Remove the last element\n5: Consult the first element\n6: Consult the last element\n7: Check the size of the deque\n8: Check if the deque is empty\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_end(dq, element);
				printf("\n");
				break;
			case 2:
				remove_begin(dq);
				break;
			case 3:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_begin(dq, element);
				printf("\n");
				break;
			case 4:
				remove_end(dq);
				break;
			case 5:
				if (consult_begin(dq, &value) != 0) {
					printf("The first element is %d\n\n", value);
				} else {
					printf("There is no element in the deque\n\n");
				}
				break;
			case 6:
				if (consult_end(dq, &value) != 0) {
					printf("The last element is %d\n\n", value);
				} else {
					printf("There is no element in the deque\n\n");
				}
				break;
			case 7:
				printf("The deque has %d elements\n\n", size_deque(dq));
				break;
			case 8:
				if (empty_deque(dq) == 1) {
					printf("The deque is empty\n\n");
				} else {
					printf("The deque is not empty\n\n");
				}
				break;
			case 0:
				free_deque(dq);
				printf("Deque freed\n");
		}
	}
	
	return 0;
}
