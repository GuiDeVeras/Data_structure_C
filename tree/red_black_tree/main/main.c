#include <stdio.h>
#include <stdlib.h>
#include "tree_llrb.h"

int main(){

	int i = 1, element, position;
	
	tree_llrb* root;
	
	root = create_tree_llrb();
	
	while (i != 0) {
		printf("1: Add an element\n2: Remove an element\n3: Check if the tree is empty\n4: Consult if an element is in the tree\n5: Print the tree pre order\n6: Print the tree in order\n7: Print the tree post order\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!insert_tree_llrb(root, element)) {
					printf("The element is in the tree\n\n");
				} else {
					printf("Successfully inserted\n\n");
				}
				printf("\n");
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!remove_tree_llrb(root, element)) {
					printf("The element isn't in the tree\n\n");
				} else {
					printf("Successfully removed\n\n");
				}
				break;
			case 3:
				if (tree_llrb_empty(root) == 1) {
					printf("The tree is empty\n\n");
				} else {
					printf("The tree is not empty\n\n");
				}
				break;
			case 4:
				printf("\nElement: ");
				scanf("%d", &element);
				if (consult_tree_llrb(root, element)) {
					printf("The element is in the tree\n\n");
				} else {
					printf("The element isn't in the tree\n\n");
				}
				break;
			case 5: 
				if (!pre_order_tree_llrb(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 6: 
				if (!in_order_tree_llrb(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 7: 
				if (!post_order_tree_llrb(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 0:
				free_tree_llrb(root);
				printf("Tree freed\n");
		}
	}
	
	return 0;
}
