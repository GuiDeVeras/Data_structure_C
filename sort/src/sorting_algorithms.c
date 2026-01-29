#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"
#include <math.h>
#include <assert.h>

int array[MAX];

void bubble_sort(int *array, int size) {
	int i, start, aux, end = size;
	do {
		start = 0;
		for (i = 0; i < end-1; i++) {
			if (array[i] > array[i+1]) {
				aux = array[i];
				array[i] = array[i+1];
				array[i+1] = aux;
				start = i;
			}
		}
		end--;
	} while (start != 0);
}

void insertion_sort(int *array, int size) {
	int i, j, aux;
	for (i = 1; i < size; i++) {
		aux = array[i];
		for (j = i; (j > 0) && (aux < array[j - 1]); j--) {
			array[j] = array[j - 1];
		}
	array[j] = aux;
	}
}

void selection_sort(int *array, int size) {
	int i, j, lower, swap;
	for (i = 0; i < size-1; i ++) {
		lower = i;
		for (j = i+1; j < size; j++) {
			if (array[j] < array[lower]) {
				lower = j;
			}
		}
		if (i != lower) {
			swap = array[i];
			array[i] = array[lower];
			array[lower] = swap;
		}
	}
}

void merge_sort(int *array, int begin, int end) {
	int middle;
	if (begin < end) {
		middle = floor((begin + end) / 2);
		merge_sort(array, begin, middle);
		merge_sort(array, middle+1, end);
		merge(array, begin, middle, end);
	}
}

void merge(int *array, int begin, int middle, int end) {
	int *temp, p1, p2, size, i, j, k;
	int end1 = 0, end2= 0;
	size = end - begin + 1;
	p1 = begin;
	p2 = middle+1;
	temp = (int *) malloc(size*sizeof(int));
	if (temp != NULL) {
		for (i = 0; i < size; i++) {
			if (!end1 && !end2) {
				if (array[p1] < array[p2]) {
					temp[i] = array[p1++];
				} else {
					temp[i] = array[p2++];
				}
				if (p1 > middle) {
					end1 = 1;
				}
				if (p2 > end) {
					end2 = 1;
				}
			} else {
				if (!end1) {
					temp[i] = array[p1++];
				} else {
					temp[i] = array[p2++];
				}
			}
		}
		for (j = 0, k = begin; j < size; j++, k++) {
			array[k] = temp[j];
		}
	}
	free(temp);
}

void quick_sort(int *array, int begin, int end) {
	int pivet;
	if (end > begin) {
		pivet = partition(array, begin, end);
		quick_sort(array, begin, pivet-1);
		quick_sort(array, pivet+1, end);
	}
}

int partition(int *array, int begin, int end) {
	int left, right, pivet, aux;
	left = begin;
	right = end;
	pivet = array[begin];
	while (left < right) {
		while (array[left] <= pivet) {
			left++;
		}
		while (array[right] > pivet) {
			right--;
		}
		if (left < right) {
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
			
		}
	}
	array[begin] = array[right];
	array[right] = pivet;
	return right;
}

void heap_sort(int *array, int size) {
	int i, aux;
	for (i = (size - 1) / 2; i >= 0; i--) {
		create_heap(array, i, size-1);
	}
	for (i = size - 1; i >= 1; i--) {
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;
		create_heap(array, 0, i-1);
	}
}

void create_heap(int *array, int i, int f) {
	int aux = array[i];
	int j = i * 2  + 1;
	while (j <= f) {
		if (j < f) {
			if (array[j] < array[j + 1]) {
				j++;
			}
		}
		if (aux < array[j]) {
			array[i] = array[j];
			i = j;
			j = 2* i + 1;
		} else {
			j = f + 1;
		}
	}
	array[i] = aux;
}
