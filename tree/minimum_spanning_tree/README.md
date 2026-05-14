# Project's struct
- `mst.h`: Definition of the pointer "tree", the type of data stored and function prototypes.
- `mst.c`: Definition of the data type "tree" and implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `mst_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.


The purpose of this project is to learn the applications of minimum spanning tree.
	
	
• Minimum spanning tree: Consists in finding the set of edges with lower cost that connects every node of a graph.

• Graph's characteristics: Undirected, connected and weighted.
			   The spanning tree is a subgraph that have every vertex "V" and have "V-1" edges.
			   
• Prim's algorithm: Consider a initial node "orig" for the spanning tree's construction. The node is the tree's first node. For each iteration, search the edge of lower weight that connects a tree's node to one that isn't on the tree. Add that node in the tree and repeat. This process ends when every node are on the tree or when is not possible to find a edge that satisfact every condition

• Efficiency: graph with V nodes and E edges:
		The implementation is not optimized. O(VE). Because "E" is proportional to "V^2", your cost is "O(V^3)"
		The efficiency of this algorithm depends on the way used to find the edge with lower weight. Using a priority queue to find the edge, the cost can be recuced to O(E log V)
		
• Kruskal's algorithm: Each node is a independent tree (florest). For each iteration, search for the edge with lower weight that connects two different trees. The tree's node selected now are part of one tree. Repeat the process. The process ends when every node are part of the same tree or when is not possible to find a edge that satisfact every condition.

• Efficiency: graph with V nodes and E edges:
		The implementation is not optimized. O(VE). Because "E" is proportional to "V^2", your cost is "O(V^3)"
		The efficiency of this algorithm depends on the way used to find the edge with lower weight. Using a data structure "Union&Find" to find the edge, the cost can be recuced to O(E log V)
