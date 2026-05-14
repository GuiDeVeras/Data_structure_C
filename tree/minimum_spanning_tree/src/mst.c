#include <stdio.h>
#include <stdlib.h>
#include "mst.h"

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


void prim_graph (Graph *graph, int origin, int *parent) {
	int i, j, destiny, first, nv = graph->vertices_number;
	double lower_weight;
	for (i = 0; i < nv; i++) parent[i] = -1;
	parent[origin] = origin;
	while (1) {
		first = 1;
		for (i = 0; i < nv; i++) {
			if (parent[i] != -1) {
				for (j = 0; j < graph->degree[i]; j++) {
					if (parent[graph->edge[i][j]] == -1) {
						if (first) {
							lower_weight = graph->weight[i][j];
							origin = i;
							destiny = graph->edge[i][j];
							first = 0;
						} else {
							if (lower_weight > graph->weight[i][j]) {
								lower_weight = graph->weight[i][j];
								origin = i;
								destiny = graph->edge[i][j];
							}
						}
					}
				}
			}
		}
		if (first == 1) break;
		parent[destiny] = origin;
	}
}

void kruskal_graph (Graph *graph, int origin, int *parent) {
	int i, j, destiny, first, nv = graph->vertices_number;
	double lower_weight;
	int *tree = (int*) malloc(nv * sizeof(int));
	for (i = 0; i < nv; i++) {
		tree[i] = i;
		parent[i] = -1;
	}
	parent[origin] = origin;
	while (1) {
		first = 1;
		for (i = 0; i < nv; i++) {
				for (j = 0; j < graph->degree[i]; j++) {
					if (tree[i] != tree[graph->edge[i][j]]) {
						if (first) {
							lower_weight = graph->weight[i][j];
							origin = i;
							destiny = graph->edge[i][j];
							first = 0;
						} else {
							if (lower_weight > graph->weight[i][j]) {
								lower_weight = graph->weight[i][j];
								origin = i;
								destiny = graph->edge[i][j];
							}
						}
					}
				}
		}
		if (first == 1) break;
		if (parent[origin] == -1) parent[origin] = destiny;
		else parent[destiny] = origin;
		for (i = 0; i < nv; i++) {
			if (tree[i] == tree[destiny]) tree[i] = tree[origin];
		}
	}
	free (tree);
}

