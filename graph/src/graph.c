#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph {
	int weighted;
	int vertices_number;
	int max_degree;
	int** edge;
	float** weight;
	int* degree;
};

Graph *create_graph(int vertices_number, int max_degree, int weighted) {
	Graph *graph = (Graph*) malloc(sizeof(struct graph));
	if (graph != NULL) {
		int i;
		graph->vertices_number = vertices_number;
		graph->max_degree = max_degree;
		graph->weighted = (weighted != 0)?1:0;
		graph->degree = (int*)calloc(vertices_number,sizeof(int));
		graph->edge = (int**)malloc(vertices_number*sizeof(int*));
		for (i = 0; i < vertices_number; i++) {
			graph->edge[i] = (int*)malloc(max_degree*sizeof(int));
		}
		if (graph->weighted) {
			graph->weight = (float**)malloc(vertices_number*sizeof(float*));
			for (i = 0; i < vertices_number; i++) {
				graph->weight[i] = (float*)malloc(max_degree*sizeof(float));
			}
		}
	}
	return graph;
}

void free_graph (Graph* graph) {
	if (graph != NULL) {
		int i;
		for (i = 0; i<graph->vertices_number; i++) {
			free(graph->edge[i]);
		}
		free(graph->edge);
		if (graph->weighted) {
			for (i = 0; i<graph->vertices_number; i++) {
				free(graph->weight[i]);
			}
			free(graph->weight);
		}
		free(graph->degree);
		free(graph);
	}
}

int insert_edge (Graph* graph, int origin, int destiny, int digraph, float weight) {
	if (graph == NULL || origin < 0|| origin >= graph->vertices_number || destiny < 0|| destiny >= graph->vertices_number) {
		return 0;
	}
	graph->edge[origin][graph->degree[origin]] = destiny;
	if (graph->weighted) {
		graph->weight[origin][graph->degree[origin]] = weight;
	}
	graph->degree[origin]++;
	if (digraph == 0) {
		insert_edge(graph, destiny,origin, 1, weight);
	}
	return 1;
}
	
int remove_edge (Graph* graph, int origin, int destiny, int digraph) {
	if (graph == NULL || origin < 0|| origin >= graph->vertices_number || destiny < 0|| destiny >= graph->vertices_number) {
		return 0;
	}
	int i = 0;
	while (i<graph->degree[origin] && graph->edge[origin][i] != destiny) {
		i++;
	}
	if (i == graph->degree[origin]) {
		return 0;
	}
	graph->degree[origin]--;
	graph->edge[origin][i] = graph->edge[origin][graph->degree[origin]];
	if (graph->weighted) {
		graph->weight[origin][i] = graph->weight[origin][graph->degree[origin]];
	}
	if (digraph == 0) {
		remove_edge (graph, destiny, origin, 1);
	}
	return 1;
}

void depht_search_aux (Graph* graph, int origin, int *visited, int cont) {
	int i;
	visited[origin] = cont;
	for (i = 0; i < graph->degree[origin]; i++) {
		if (!visited[graph->edge[origin][i]]) {
			depht_search_aux(graph, graph->edge[origin][i], visited, cont+1);
		}
	}
}

void depht_search (Graph* graph, int origin, int *visited) {
	int i, cont = 1;
	for (i = 0; i < graph->vertices_number; i++) {
		visited[i] = 0;
	}
	depht_search_aux (graph, origin, visited, cont);
}

void breadth_search (Graph* graph, int origin, int *visited) {
	int i, vert, NV, cont = 1, *queue, queue_start = 0, queue_end = 0;
	for (i = 0; i < graph->vertices_number; i++) {
		visited[i] = 0;
	}
	NV = graph->vertices_number; 
	queue = (int*) malloc(NV * sizeof(int));
	queue_end++;
	queue[queue_end] = origin;
	visited[origin] = cont;
	while (queue_start != queue_end) {
		queue_start = (queue_start + 1) % NV;
		vert = queue[queue_start];
		cont++;
		for (i = 0; i < graph->degree[vert]; i++) {
			if (!visited[graph->edge[vert][i]]) {
				queue_end = (queue_end + 1) % NV;
				queue[queue_end] = graph->edge[vert][i];
				visited[graph->edge[vert][i]] = cont;
			}
		}
	}
	free(queue);
}

int shortest_path_aux (float *distance, int *visited, int NV) {
	int i, lower = -1, first = 1;
	for (i = 0; i < NV; i++) {
		if (distance[i] >= 0 && visited[i] == 0) {
			if (first) {
				lower = i;
				first = 0;
			} else {
				if (distance[lower] > distance[i]) {
					lower = i;
				}
			}
		}
	}
	return lower;
}

void shortest_path_search (Graph *graph, int origin, int *previous, float *distance) {
	int i, cont, NV, ind, *visited, u;
	cont = NV = graph->vertices_number;
	visited = (int*) malloc(NV * sizeof(int));
	for (i = 0; i < NV; i++) {
		previous[i] = -1;
		distance[i] = -1;
		visited[i] = 0;
	}
	distance[origin] = 0;
	while (cont > 0) {
		u = shortest_path_aux (distance, visited, NV);
		if (u == -1) {
			break;
		}
		visited[u] = 1;
		cont--;
		if (graph->weighted == 1) {
			for (i = 0; i < graph->degree[u]; i++) {
				ind = graph->edge[u][i];
				if (distance[ind] < 0) {
					distance[ind] = distance[u] + graph->weight[u][i];
					previous[ind] = u;
				} else {
					if (distance[ind] > distance[u] + graph->weight[u][i]) {
						distance[ind] = distance[u] + graph->weight[u][i];
						previous[ind] = u;
					}
				}
			}
		} else {
			for (i = 0; i < graph->degree[u]; i++) {
				ind = graph->edge[u][i];
				if (distance[ind] < 0) {
					distance[ind] = distance[u] + 1;
					previous[ind] = u;
				} else {
					if (distance[ind] > distance[u] + 1) {
						distance[ind] = distance[u] + 1;
						previous[ind] = u;
					}
				}
			}
		}
	}
	free (visited);
}

