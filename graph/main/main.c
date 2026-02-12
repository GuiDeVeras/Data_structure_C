#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
	
	int weighted, vertices_number, max_degree, i = 1, o = 1, origin, destiny, digraph;
	float weight;
	
	while (o != 0) {
		
		i = 1;
		printf("The graph is weighted? (1 for YES, 0 for NO)\n");
		printf("Vertices number:\n");
		printf("Max degree:\n");
		scanf("%d %d %d", &weighted, &vertices_number, &max_degree);
		
		int visited[vertices_number], previous[vertices_number];
		float distance[vertices_number];
		Graph *graph = NULL;
		graph = create_graph(vertices_number, max_degree, weighted);
		
		while (i != 0) {
			printf("0: Change the graph\n1: Add an edge\n2: Remove an edge\n3: Depht search\n4: Breadth search\n5: Shortest path search\n\nDecision choosen: ");
			scanf("%d", &i);
			switch (i) {
				case 1:
					printf("Origin: ");
					scanf("%d", &origin);
					printf("Destiny: ");
					scanf("%d", &destiny);
					printf("Digraph (1 for YES, 0 for NO): ");
					scanf("%d", &digraph);
					printf("Weight: ");
					scanf("%f", &weight);
					insert_edge(graph, origin, destiny, digraph, weight);
					printf("\n");
					break;
				case 2:
					printf("Origin: ");
					scanf("%d", &origin);
					printf("Destiny: ");
					scanf("%d", &destiny);
					printf("Digraph (1 for YES, 0 for NO): ");
					scanf("%d", &digraph);
					remove_edge(graph, origin, destiny, digraph);
					printf("\n");
					break;
				case 3:
					printf("Origin: ");
					scanf("%d", &origin);
					depht_search (graph, origin, visited);
					for (int j = 0; j < vertices_number; j++) {
						if (j != vertices_number - 1) {
							printf("%d ", visited[j]);
						} else {
							printf("%d\n", visited[j]);
						}
					}
					break;
				case 4:
					printf("Origin: ");
					scanf("%d", &origin);
					breadth_search (graph, origin, visited);
					for (int j = 0; j < vertices_number; j++) {
						if (j != vertices_number - 1) {
							printf("%d ", visited[j]);
						} else {
							printf("%d\n", visited[j]);
						}
					}
					break;
				case 5:
					printf("Origin: ");
					scanf("%d", &origin);
					shortest_path_search (graph, origin, previous, distance);
					for (int j = 0; j < vertices_number; j++) {
						if (j != vertices_number - 1) {
							printf("%.1f ", distance[j]);
						} else {
							printf("%.1f\n", distance[j]);
						}
					}
					break;
				case 0:
				printf("Graph freed\n\n");
			}
		}
		free_graph(graph);
		printf("Do you want to continue? (1 for YES, 0 for NO)\n");
		scanf("%d", &o);
		if (o == 1) {
			printf("\n");
		}
	}
	return 0;
	
}
