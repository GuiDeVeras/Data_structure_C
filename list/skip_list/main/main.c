#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"
#include <assert.h>

int main(){

	int max_level, o = 1;
	float current_level;
	
	while (o != 0) {
	
		int i = 1, element;
		
		printf("List's max level: ");
		scanf("%d", &max_level);
		printf("List's current level: ");
		scanf("%f", &current_level);
		printf("\n");
		
		skip_list *sl = NULL;
		
		sl = create_skip_list(max_level, current_level);
		
		while (i != 0) {
			printf("1: Add an element\n2: Remove an element\n0: Stop operations\n\nDecision choosen: ");
			scanf("%d", &i);
			switch (i) {
				case 1:
					printf("\nElement: ");
					scanf("%d", &element);
					if (!insert_skip_list(sl, element)) printf("The element is already in the list\n");
					printf("\n");
					break;
				case 2:
					printf("\nElement: ");
					scanf("%d", &element);
					if (!remove_skip_list(sl, element)) printf("The element is not in the list\n");
					printf("\n");
					break;
				
				case 0:
					free_skip_list(sl);
					printf("List freed\n");
			}
		}
		printf("Do you want to continue? (1 for YES, 0 for NO)\n");
		scanf("%d", &o);
		if (o == 1) printf("\n");
	}
	
	return 0;
}
