# Project's struct
- `tree_llrb.h`: Definition of the pointer "tree", the type of data stored and function prototypes.
- `tree_llrb.c`: Definition of the data type "tree" and implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `tree_llrb_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.


The purpose of this project is to learn the applications of red-black tree.
	
	
• Red-black tree: the node have a colour that can be red or black

• Properties: 	Every node is red or black. The root is always black. Every leaf (NULL) is black. If a node is red, than their children will be black (i.e., there isn't cosnecutive red nodes). For each node, every path to the leaves beneath it contain the same number os black nodes
		Allows local rebalancing. Only the part affected by the insertion or remotion is rebalanced. Uses rotations and colour adjustment in the rebalancing. These operations correct the violated properties.
		The red-black tree try to maintain itself like an almost perfect binary tree. The cost of any algorithm is O(logN)

• Left-leaning red-black tree: If a node is red, than it will be the left child of your parent. This property gives the left-leaning aspect. Your implementation correspond to a tree 2-3 implementation (not a binary tree). 
		In a 2-3 tree, each internal node can store 1 or 2 values and, depending on the values stored quantity, have 2 (one value) or 3 (two values) children.
		Works like a search binary tree. In case of 3 subtrees, the middle one have the elements higher than the first, but lower thant the second parent's value
