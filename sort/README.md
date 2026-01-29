# Project's struct
- `dynamic_stack.h`: Definition of the data type stored in the stack and function prototypes.
- `dynamic_stack.c`: Definition of the data types "stack", implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `dynamic_stack_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.

The purpose of this project is to learn the applications of sorting methods.
	
- `Bubble sort`: Compare par of elements and swap them if disordered. This process repeat until any swaps are needed (ordered elements).
	Performance
	- Best cenario: O(N)
	- Worst cenario: O(N²)
	- Not recommended for large datastes
	
- `Insertion sort`: Just like the sorting of cards. Get an element at a time and places it in the right position, always leaving the elements sorted.
	Performance
	- Best cenario: O(N)
	- Worst cenario: O(N²)
	- Efficient for small datasets
	- Stable: doesn't change the order of equal elements
	- Capable of sorting the data as it's received (real time)
	
- `Selection sort`: At each step, search for the lower element of the array and places it in the first position. Discard the first position of the array and repeat the process for the second position. This is done for each position.
	Performance
	- Best cenario: O(N²)
	- Worst cenario: O(N²)
	- Inefficient for large datasets
	- Stable: doesn't change the order of equal elements
	
- `Merge sort`: Divide-and-conquer. Divide, recursively, the dataset until each subset has one elements. Combine two subset to obtain a larger and sorted set. This process repeats until exist only one set
	Performance
	- Best cenario: O(N log N)
	- Worst cenario: O(N log N)
	- Stable: doesn't change the order of equal elements
	- Disadvantages: recursive and uses an auxiliar vector over the sorting
	
- `Quick sort`: Divide-and-conquer. Partition: an element is choosen as the pivet. The data is rearranged  (lower values are placed before the pivet and higher, after). Sort recursively the two partitions.
	Performance
	- Best cenario: O(N log N)
	- Worst cenario (rare): O(N²)
	- Stable: doesn't change the order of equal elements
	- Disadvantages: how to choose the pivet?
	
- `Heap sort`: Heap: an array that simulates a complete binary tree (with the exception of the last level). Every element "parent" has two elements as "childs".
	- "parent" (i) -> "childs": (2 * i +1) and (2 * i + 2)
	Performance
	- Best Scenario: O(Nlog N).
	- Worst Scenario: O(N log N)
	- Memory: In-place. It doesn't need extra memory, which is a big advantage on merge sort.
