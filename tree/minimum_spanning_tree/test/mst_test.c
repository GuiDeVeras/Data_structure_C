#include <stdio.h>
#include <stdlib.h>
#include "mst.h"
#include <assert.h>

void test_insert_edge () {
	
	Graph *graph = NULL;
	
	graph = create_graph(10, 7, 0);
	
	assert(insert_edge(graph, -1, 0, 0, 0) == 0);
	
	assert(insert_edge(graph, 0, -1, 0, 0) == 0);
	
	assert(insert_edge(graph, 11, 0, 0, 0) == 0);
	
	assert(insert_edge(graph, 0, 11, 0, 0) == 0);
	
	assert(insert_edge(graph, 0, 0, 0, 0) == 1);
	
	assert(insert_edge(graph, 0, 1, 0, 0) == 1);
	
	assert(insert_edge(graph, 1, 2, 0, 0) == 1);
	
	free_graph (graph);
}

void test_remove_edge () {
	
	Graph *graph = NULL;
	
	graph = create_graph(10, 7, 0);
	
	assert(remove_edge(graph, 0, 0, 0) == 0);
	
	assert(remove_edge(graph, -1, 0, 0) == 0);
	
	assert(remove_edge(graph, 0, -1, 0) == 0);
	
	assert(remove_edge(graph, 11, 0, 0) == 0);
	
	assert(remove_edge(graph, 0, 11, 0) == 0);
	
	insert_edge(graph, 0, 0, 0, 0);
	
	insert_edge(graph, 0, 1, 0, 0);
	
	insert_edge(graph, 1, 2, 0, 0);
	
	assert(remove_edge(graph, 0, 0, 0) == 1);
	
	assert(remove_edge(graph, 0, 1, 0) == 1);
	
	assert(remove_edge(graph, 1, 2, 0) == 1);
	
	free_graph (graph);
	
}

void test_prim_graph () {
	
	Graph *graph = NULL;
	
	graph = create_graph(6, 6, 1);

	assert(insert_edge(graph, 0, 1, 0, 6) == 1);
	assert(insert_edge(graph, 0, 2, 0, 1) == 1);
	assert(insert_edge(graph, 0, 3, 0, 5) == 1);
	assert(insert_edge(graph, 1, 2, 0, 2) == 1);
	assert(insert_edge(graph, 1, 4, 0, 5) == 1);
	assert(insert_edge(graph, 2, 3, 0, 2) == 1);
	assert(insert_edge(graph, 2, 4, 0, 6) == 1);
	assert(insert_edge(graph, 2, 5, 0, 4) == 1);
	assert(insert_edge(graph, 3, 5, 0, 4) == 1);
	assert(insert_edge(graph, 4, 5, 0, 3) == 1);
	
	int i, parent[6], list[6] = {0, 2, 0, 2, 5, 2};
	
	prim_graph (graph, 0, parent);
	for (i = 0; i < 6; i++) {
		assert(parent[i] == list[i]);
	}
	
	free_graph (graph);
		
}

void test_kruskal_graph () {
	
	Graph *graph = NULL;
	
	graph = create_graph(6, 6, 1);

	assert(insert_edge(graph, 0, 1, 0, 6) == 1);
	assert(insert_edge(graph, 0, 2, 0, 1) == 1);
	assert(insert_edge(graph, 0, 3, 0, 5) == 1);
	assert(insert_edge(graph, 1, 2, 0, 2) == 1);
	assert(insert_edge(graph, 1, 4, 0, 5) == 1);
	assert(insert_edge(graph, 2, 3, 0, 2) == 1);
	assert(insert_edge(graph, 2, 4, 0, 6) == 1);
	assert(insert_edge(graph, 2, 5, 0, 4) == 1);
	assert(insert_edge(graph, 3, 5, 0, 4) == 1);
	assert(insert_edge(graph, 4, 5, 0, 3) == 1);
	
	int i, parent[6], list[6] = {0, 2, 0, 2, 5, 2};
	
	kruskal_graph (graph, 0, parent);
	for (i = 0; i < 6; i++) {
		assert(parent[i] == list[i]);
	}

	free_graph (graph);
}
