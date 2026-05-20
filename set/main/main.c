#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include "set.h"

int main(){

	int i = 1, element, position, x;
	
	set* s = NULL;
	
	s = create_set();
	
	while (i != 0) {
		printf("1: Add an element\n2: Remove an element\n3: Search an element\n4: Print the elements\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!insert_set(s, element)) {
					printf("The element is in the set\n\n");
				} else {
					printf("Successfully inserted\n\n");
				}
				printf("\n");
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!remove_set(s, element)) {
					printf("The element isn't in the set\n\n");
				} else {
					printf("Successfully removed\n\n");
				}
				break;
			case 3:
				printf("\nElement: ");
				scanf("%d", &element);
				if (search_set(s, element)) printf("The element is in the set\n\n");
				else printf("The element isn't in the set\n\n");
				break;
			case 4:
				for (begin_set (s); !end_set (s); next_set (s)) {
					get_item_set (s, &x);
					printf("%d ", x);
				}
				printf("\n\n");
				break;
			case 0:
				free_set(s);
				printf("Set freed\n");
		}
	}
	
	return 0;
}
