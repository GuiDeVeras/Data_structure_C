# Project's struct
- `graph.h`: Definition of the pointer "graph" and function prototypes.
- `graph.c`: Definition of the data type "graph", implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `graph_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.


The purpose of this project is to learn the applications of graph.
	
• Graph: A set of vertex and a set of edges that conect with any pair of vertex.
	• Vertice: Every entity represented in a graph. Two vertex are adjacent if existi an edge between then.
	• Edge: Also know as "arc". It's associated with two vertex and make their connection.
	
• Directed Graphs (Digraph): There is an orientation regarding the direction of the arest. If an edge connects "A" and "B", it's correct to say it points from "A" to "B", but not the opposite.

• Undirected Graphs: There isn't any orientation regarding the direction of the arest. It can go from "A" to "B" or from "B" to "A".

• Degree: It's the number of edges that connects to it. In case of digraphs, there is:
	• In-degree: edges that arrives at the vertex.
	• Out-degree: edges that left from the vertex.
	
• Self loop: It's an edge called "self loop" if their starting vertex is the same vertex of arrival, in other words, the edge connect the vertex to itself

• Path: It's a sequence of vertex in a way that always exist an edge linking the previous vertex with the next.
	• Simple path: Any of the vertex in the path repeat itself.
	• Path Lenght: It's the number of edges the path uses.
	
• Cycle: It's path thats start and end in the same vertex. A self loop is a one lenght cycle

• Acyclic graph: Doens't contain simple cycles (in which every vertex appear only one time)

• Multiples edges: Also know as multigraph. It's a graph that conceals more than one edge linking with the same vertex pair. In this case, the edges are called "parallel"

• Trivial graph: It's a graph with one vertex and without edges.

• Simple graph: It's a undirected graph, without self loops and withou parallel

• Complete graph: It's a simple graph in which each vertex is linked with every other vertex.

• Regular graph: It's a graph in which every vertex has the same degree

• Subgraph: A graph "Gs(Vs, As)" is called "subgraph" of "G(V, A)" if Vs is contained in "V" amd "As" is contained in "A"

• Bipartite graph: It's a graph whose vertex can be spltited in two sets. In this case, the edges link the vertex that from are differents sets, nerve caring about the vertex of the same set

• Connected graph: Exists a path exiting any vertex to until it found another vertex from the graph

• Unconected graph: Doens't exists a path linking two selected vertex

• Isomorphic graph: Two graphs, "G1(V1, A1)" and "G2(V2, A2)", are called "isomorphic" if exist a function which maps the vertices and edges in a way that the two graphs becomes coincident 

• Weighted graph: It's a graph that has "wieghts" associated with each edge

• Hamiltonian graph: It's a graph that has one path which visits each "node" only one time. It detection is an ardous task

• Hamiltonian cycle: It's a cycle which visits each "node" only one time

• Eulerian graph: It's a graph that has a "cycle" which visits each "edge" only one time

• Adjacency matrix: a matrix NxN is used for storing a graph, in which N is the number of vertices. Highly computacional cost, O(N²). An edge is represented with a "mark" in the position (i, j) of the matrix. The edge link i to j

• Adjacency list: a collection of N linked lists (or arrays) is used for storing a graph, in which N is the number of vertices. Highly efficient for storage, O(V+E). An edge is represented by adding vertex j to the list associated with vertex i. The list for vertex i contains all vertices j such that an edge links i to j.

• Depth-first search: Leaving from a initial vertex, it explores as many as possible of each of its branches before backtracking. It can be used for finding linked elements and strongly linked, topological sorting in a graph, solving puzzels (labyrinth)

• Breadth-first search: Leaving from a initial vertex, it explores every neighboring vertices. After, for each vertex alone, it repeats this process, visiting the unexplored vertices. It can be used for finding linked elements, finding every vertex linked with only one element, finding the smallest path between two vertices, test bipartition in graphs

• Shortest-path search: Leaving from an initial vertex, calculate the smallest distance from this vertex to every others (as long as there is a path between then)
	• Dijkstra algorithm: Solve this problem for "directed" or "undirected" graphs with "non-negative" edges weight 
