#include <stdio.h>
#include <stdlib.h>
#include "static_p_queue.h"

int main(){

	int i = 1, element, position, decision, value;
	
	P_queue *p_queue;
	
	p_queue = create_p_queue();
	
	printf("0: Sorted array\n1: Binary heap	\n");
	scanf("%d", &decision);
	while (i != 0) {
		if (decision) {
			printf("1: Add an element\n2: Remove the first element\n3: Consult the first element\n4: Check the size of the queue\n5: Check if the queue is empty\n6: Check if the queue is full\n0: Stop operations\n\nDecision choosen: ");
			scanf("%d", &i);
			switch (i) {
				case 1:
					printf("\nElement: ");
					scanf("%d", &element);
					insert_p_queue_heap(p_queue, element);
					printf("\n");
					break;
				case 2:
					remove_p_queue_heap(p_queue);
					break;
				case 3:
					if (consult_p_queue_array(p_queue, &value) != 0) printf("The first element is %d\n\n", value);
					else printf("There is no element in the queue\n\n");
					break;
				case 4:
					printf("The queue has %d elements\n\n", size_p_queue(p_queue));
					break;
				case 5:
					if (p_queue_empty(p_queue) == 1) printf("The queue is empty\n\n");
					else printf("The queue is not empty\n\n");
					break;
				case 6:
					if (p_queue_full(p_queue)) printf("The queue is full\n\n");
					else printf("The queue is not full\n\n");
					break;
				case 0:
					free_p_queue(p_queue);
					printf("Queue freed\n");
			}
		} else {
			printf("1: Add an element\n2: Remove the first element\n3: Consult the first element\n4: Check the size of the queue\n5: Check if the queue is empty\n6: Print the queue\n0: Stop operations\n\nDecision choosen: ");
			scanf("%d", &i);
			switch (i) {
				case 1:
					printf("\nElement: ");
					scanf("%d", &element);
					insert_p_queue_array(p_queue, element);
					printf("\n");
					break;
				case 2:
					remove_p_queue_array(p_queue);
					break;
				case 3:
					if (consult_p_queue_array(p_queue, &value) != 0) printf("The first element is %d\n\n", value);
					else printf("There is no element in the queue\n\n");
					break;
				case 4:
					printf("The queue has %d elements\n\n", size_p_queue(p_queue));
					break;
				case 5:
					if (p_queue_empty(p_queue) == 1) printf("The queue is empty\n\n");
					else printf("The queue is not empty\n\n");
					break;
				case 6:
					if (p_queue_full(p_queue)) printf("The queue is full\n\n");
					else printf("The queue is not full\n\n");
					break;
				case 0:
					free_p_queue(p_queue);
					printf("Queue freed\n");
			}
		}
	}
	return 0;
}
