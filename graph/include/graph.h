typedef struct graph Graph;

Graph *create_graph(int vertices_number, int max_degree, int weighted);

void free_graph (Graph* graph);

int insert_edge (Graph* graph, int origin, int destiny, int digraph, float weight);

int remove_edge (Graph* graph, int origin, int destiny, int digraph);

void depht_search_aux (Graph* graph, int origin, int *visited, int cont);

void depht_search (Graph* graph, int origin, int *visited);

void breadth_search (Graph* graph, int origin, int *visited);

int shortest_path_aux (float *distance, int *visited, int NV);

void shortest_path_search (Graph *graph, int origin, int *previous, float *distance);

//Tests

void test_insert_edge ();

void test_remove_edge ();

void test_depht_search ();

void test_breadth_search ();

void test_shortest_path_search ();
