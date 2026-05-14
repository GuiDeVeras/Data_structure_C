typedef struct graph Graph;

Graph *create_graph(int vertices_number, int max_degree, int weighted);

void free_graph (Graph* graph);

int insert_edge (Graph* graph, int origin, int destiny, int digraph, float weight);

int remove_edge (Graph* graph, int origin, int destiny, int digraph);

void prim_graph (Graph *graph, int origin, int *parent);

void kruskal_graph (Graph *graph, int origin, int *parent);

//Tests

void test_insert_edge ();

void test_remove_edge ();

void test_prim_graph ();

void test_kruskal_graph ();
