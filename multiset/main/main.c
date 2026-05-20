#include <stdio.h>
#include <stdlib.h>
#include "bag.h"

int main(){

	int i = 1, element, position, x;
	
	bag* b = NULL;
	
	b = create_bag();
	
	while (i != 0) {
		printf("1: Add an element\n2: Remove an element\n3: Search an element\n4: Print the elements of the multibag\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!insert_bag(b, element)) {
					printf("The element is in the bag\n\n");
				} else {
					printf("Successfully inserted\n\n");
				}
				printf("\n");
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!remove_bag(b, element)) {
					printf("The element isn't in the bag\n\n");
				} else {
					printf("Successfully removed\n\n");
				}
				break;
			case 3:
				printf("\nElement: ");
				scanf("%d", &element);
				if (consult_bag(b, element)) printf("The element is in the bag\n\n");
				else printf("The element isn't in the bag\n\n");
				break;
			case 4:
				for (begin_bag (b); !end_bag (b); next_bag (b)) {
					int x;
					get_item_bag (b, &x);
					printf("%d ", x);
				}
				printf("\n\n0");
				break;
			case 0:
				free_bag(b);
				printf("Bag freed\n");
		}
	}
	
	return 0;
}
