#define MAX 30

void bubble_sort(int *array, int size);

void insertion_sort(int *array, int size);

void selection_sort(int *array, int size);

void merge_sort(int *array, int begin, int end);

void merge(int *array, int begin, int middle, int end);

void quick_sort(int *array, int begin, int end);

int partition(int *array, int begin, int end);

void heap_sort(int *array, int size);

void create_heap(int *array, int i, int f);

//Tests

void test_bubble_sort();

void test_insertion_sort();

void test_selection_sort();

void test_merge_sort();

void test_quick_sort();

void test_heap_sort();
