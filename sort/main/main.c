#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"
#include <math.h>

int main(){
	
	int array[MAX], o = 1;
		
	while (o != 0) {
		printf("1: Sort an array with randon numbers using bubble sort\n2: Sort an array with randon numbers using insertion sort\n3: Sort an array with randon numbers using selection sort\n4: Sort an array with randon numbers using merge sort\n5: Sort an array with randon numbers using quick sort\n6: Sort an array with randon numbers using heap sort\n0: Stop operations\n\nDecision choosen: ");
		scanf("%d", &o);
		switch (o) {
			case 1:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				bubble_sort(array, MAX);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 2:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				insertion_sort(array, MAX);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 3:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				selection_sort(array, MAX);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 4:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				merge_sort(array, 0, 29);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 5:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				quick_sort(array, 0, 29);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 6:
				printf("Array: ");
				for (int i = 0; i < MAX; i++) {
					array[i] = (rand() % 100) + 1;
					printf("%d ", array[i]);
				}
				heap_sort(array, MAX);
				printf("\nArray: ");
				for (int i = 0; i < MAX; i++) {
					printf("%d ", array[i]);
				}
				printf("\n\n");
				break;
			case 0:
				break;
		}
	}
	
	return 0;
}



