# Project's struct
- `binary_tree.h`: Definition of the pointer "tree", the type of data stored and function prototypes.
- `binary_tree.c`: Definition of the data type "tree" and implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `binary_tree_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.


The purpose of this project is to learn the applications of tree.
	
	
• Tree: A special type of graph. Any pair of vertices is linked with only one edge. Connected graph (there is exactly only one path between any two of their vertices) and acyclic

• Vertex: Also know as node. Every entity represented in a graph.

• Edge: It's associated with two vertex and make their connection.
	
• Parent: It's the immediate antecessor of a vertex

• Child: It's the immediate successor of a vertex

• Root: It's the vertex that doens't have a "parent"

• Leaf: Any vertex that doens't have "children"

• Internal nodes: Any vertex that has at least a "child"

• Path: It's a sequence of vertex in a way that always exist an edge linking the previous vertex with the next.
	• Simple path: Any of the vertex in the path repeat itself.
	• Path Lenght: It's the number of edges the path uses.

• Subtree: Given a vertex, each of its "child" is the "root" of a new "subtree"

• Degree: It's the vertex subtrees's number
	
• Height: Also know as "depth". It's the length of the longest path from the root to one of its leaves

• Level: In a tree, the vertices are classified as levels. The level is the number of nodes between the vertex and the root

• Full binary tree: Each node (vertex) has 0 or 2 subtrees. No node has only child. Internal nodes (non-leaves) always has 2 children

• Complete binary tree: It's strictly binary and its leaves are on the same level. The node number of a complete binary tree is 2^h-1, in which "h" is the tree's height 

• Almost complete binary tree: The height difference between any subtree's node is at most one. If the tree height is "D", each leaf will be at level "D" or "D-1"
