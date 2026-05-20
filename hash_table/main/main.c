#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

int main(){

	int i = 1, element, position, aux, table_size, o = 1, decision;
	char *model, *text, buffer[1000];
	
	while (o != 0) {
		
		printf("Do you want a hash table or use the Rabin_Karp algorithm?\n1 for hash table, 0 for RK algorithm: ");
		scanf("%d", &decision);
		
		if (decision == 1) {
			printf("\n\nWhat will be the size of the hash table?\n");
			scanf("%d", &table_size);
			
			hash *hsh = create_hash(table_size);
			
			while (i != 0) {
				printf("1: Add an element without collision treatment\n2: Consult an element without collision treatment\n3: Add an element with collision treatment\n4: Consult an element with collision treatment\n0: Stop operations\n\nDecision choosen: ");
				scanf("%d", &i);
				switch (i) {
					case 1:
						printf("\nElement: ");
						scanf("%d", &element);
						if (insert_hash_collision(hsh, element) == -1) {
							printf("The position is occupied\n\n");
						}
						printf("\n");
						break;
					case 2:
						printf("\nElement: ");
						scanf("%d", &element);
						if (search_hash_collision(hsh, element, &aux) == 1) {
							printf("The element is in the hash table\n\n");
						} else if (search_hash_collision(hsh, element, &aux) == -1) {
							printf("The position is occupied\n\n");
						} else {
							printf("The element is not in the hash table\n\n");
						}
						break;
					case 3:
						printf("\nElement: ");
						scanf("%d", &element);
						insert_hash_collisionless(hsh, element);
						printf("\n");
						break;
					case 4:
						printf("\nElement: ");
						scanf("%d", &element);
						if (search_hash_collisionless(hsh, element, &aux) == 1) {
							printf("The element is in the hash table\n\n");
						} else {
							printf("The element is not in the hash table\n\n");
						}
						break;
					case 0:
						free_hash(hsh);
						printf("Hash freed\n");
				}
			
			}
		} else {
			int size_s;
			
			printf("\n\nWhat is the model?\n");
			scanf("%999s", buffer);
			size_s = strlen(buffer) + 1;
    			model = (char *) malloc(size_s * sizeof(char));
			strcpy(model, buffer);
			
			printf("What is the text?\n");
			scanf("%999s", buffer);
			size_s = strlen(buffer) + 1;
    			text = (char *) malloc(size_s * sizeof(char));
    			strcpy(text, buffer);
    			
    			Rabin_Karp (model, text);

    			free(model);
    			free(text);
    			
		}
		printf("\nDo you want to continue?\n1 for YES 0 for NO: ");
    		scanf("%d", &o);
	}
	
	return 0;
}
