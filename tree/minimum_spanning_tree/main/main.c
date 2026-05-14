#include <stdio.h>
#include <stdlib.h>
#include "mst.h"

int main() {
	
	int weighted = 1, vertices_number, max_degree, i = 1, o = 1, origin, destiny, digraph = 0;
	float weight;
	
	while (o != 0) {
		
		i = 1;
		printf("Vertices number:\n");
		scanf("%d", &vertices_number);
		printf("Max degree:\n");
		scanf("%d", &max_degree);
		
		int parent[vertices_number];
		int visited[vertices_number], previous[vertices_number];
		float distance[vertices_number];
		Graph *graph = NULL;
		graph = create_graph(vertices_number, max_degree, weighted);
		
		while (i != 0) {
			printf("0: Change the graph\n1: Add an edge\n2: Remove an edge\n3: Prim algorithm\n4: Kruskal algorithm\n\nDecision choosen: ");
			scanf("%d", &i);
			switch (i) {
				case 1:
					printf("Origin: ");
					scanf("%d", &origin);
					printf("Destiny: ");
					scanf("%d", &destiny);
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
					kruskal_graph (graph, 0, parent);
					for (int i = 0; i < vertices_number; i++) printf("%d: %d\n", parent[i], i);
					break;
				case 4:
					prim_graph (graph, 0, parent);
					for (int i = 0; i < vertices_number; i++) printf("%d: %d\n", parent[i], i);
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
