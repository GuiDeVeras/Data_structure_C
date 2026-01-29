#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"
#include <math.h>
#include <assert.h>

void test_bubble_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		arr[i] = (rand() % 100) + 1;
	}
    
	bubble_sort(arr, 6);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_bubble_sort worked!\n");}

void test_insertion_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		arr[i] = (rand() % 100) + 1;
	}
    
	insertion_sort(arr, 6);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_insertion_sort worked!\n");
}

void test_selection_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		arr[i] = (rand() % 100) + 1;
	}
    
	selection_sort(arr, 6);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_selection_sort worked!\n");
}

void test_merge_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		arr[i] = (rand() % 100) + 1;
	}
    
	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_merge_sort worked!\n");
}

void test_quick_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		arr[i] = (rand() % 100) + 1;
	}
    
	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_quick_sort worked!\n");
}

void test_heap_sort() {
	int arr[6];
	int n = 6;
	for (int i = 0; i < 6; i++) {
		array[i] = (rand() % 100) + 1;
	}
    
	heap_sort(arr, 6);

	for (int i = 0; i < n - 1; i++) {
        	assert(arr[i] <= arr[i + 1]);
	}
    
	printf("test_heap_sort worked!\n");
}

