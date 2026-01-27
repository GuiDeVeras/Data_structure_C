#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

int main(){

	int i = 1, element, position;
	
	Queue *queue;
	
	queue = create_queue();
	
	while (i != 0) {
		printf("1: Add an element at the end\n2: Remove the first element\n3: Consult the first element\n4: Check the size of the queue\n5: Check if the queue is empty\n6: Print the queue\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				insert_elem(queue, element);
				printf("\n");
				break;
			case 2:
				remove_elem(queue);
				break;
			case 3:
				if (consult_queue(queue) != 0) {
					printf("The first element is %d\n\n", consult_queue(queue));
				} else {
					printf("There is no element in the queue\n\n");
				}
				break;
			case 4:
				printf("The queue has %d elements\n\n", size_queue(queue));
				break;
			case 5:
				if (queue_empty(queue) == 1) {
					printf("The queue is empty\n\n");
				} else {
					printf("The queue is not empty\n\n");
				}
				break;
			case 6:
				print_queue(queue);
				printf("\n");
				break;
			case 0:
				free_queue(queue);
				printf("Queue freed\n");
		}
	}
	
	return 0;
}
