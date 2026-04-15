#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

int main(){

	int i = 1, element, position;
	
	avltree* root;
	
	root = create_avltree();
	
	while (i != 0) {
		printf("1: Add an element\n2: Remove an element\n3: Consult the height of the tree\n4: Check the size of the tree\n5: Check if the tree is empty\n6: Consult if an element is in the tree\n7: Print the tree pre order\n8: Print the tree in order\n9: Print the tree post order\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &i);
		switch (i) {
			case 1:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!insert_avltree(root, element)) {
					printf("The element is in the tree\n\n");
				} else {
					printf("Successfully inserted\n\n");
				}
				printf("\n");
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d", &element);
				if (!remove_avltree(root, element)) {
					printf("The element isn't in the tree\n\n");
				} else {
					printf("Successfully removed\n\n");
				}
				break;
			case 3:
				printf("The tree height is %d\n\n", avltree_height(root));
				break;
			case 4:
				printf("The tree has %d elements\n\n", total_avltree_nodes(root));
				break;
			case 5:
				if (avltree_empty(root) == 1) {
					printf("The tree is empty\n\n");
				} else {
					printf("The tree is not empty\n\n");
				}
				break;
			case 6:
				printf("\nElement: ");
				scanf("%d", &element);
				if (consult_avltree(root, element)) {
					printf("The element is in the tree\n\n");
				} else {
					printf("The element isn't in the tree\n\n");
				}
				break;
			case 7: 
				if (!pre_order_avltree(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 8: 
				if (!in_order_avltree(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 9: 
				if (!post_order_avltree(root)) printf("The tree is empty\n");
				printf("\n");
				break;
			case 0:
				free_avltree(root);
				printf("Tree freed\n");
		}
	}
	
	return 0;
}
