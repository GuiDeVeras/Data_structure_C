#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
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

void test_depht_search () {
	
	Graph *graph = NULL;
	
	graph = create_graph(10, 7, 0);
	
	int visited[10];
	
	insert_edge (graph, 0, 1, 0, 0);
	
	insert_edge (graph, 1, 2, 0, 0);
	
	insert_edge (graph, 3, 4, 0, 0);
	
	depht_search (graph, 0, visited);
	
	assert(visited[0] == 1);
	
	assert(visited[1] == 2);
	
	assert(visited[2] == 3);
	
	assert(visited[3] == 0);
	
	free_graph(graph);
	
}

void test_breadth_search () {
	
	Graph *graph = NULL;
	
	graph = create_graph(10, 7, 0);
	
	int visited[10];
	
	insert_edge (graph, 0, 1, 0, 0);
	
	insert_edge (graph, 1, 2, 0, 0);
	
	insert_edge (graph, 3, 4, 0, 0);
	
	breadth_search (graph, 0, visited);
	
	assert(visited[0] == 1);
	
	assert(visited[1] == 2);
	
	assert(visited[2] == 3);
	
	assert(visited[3] == 0);
	
	free_graph(graph);
	
}

void test_shortest_path_search () {
	
	Graph *graph = NULL;
	
	graph = create_graph(10, 7, 0);
	
	int previous[10];
	float distance[10];
	
	insert_edge (graph, 0, 1, 0, 0);
	
	insert_edge (graph, 1, 2, 0, 0);
	
	insert_edge (graph, 3, 4, 0, 0);
	
	shortest_path_search (graph, 0, previous, distance);
	
	assert(distance[0] == 0);
	
	assert(distance[1] == 1);
	
	assert(distance[2] == 2);
	
	assert(distance[3] == -1);
	
	free_graph(graph);
	
}
