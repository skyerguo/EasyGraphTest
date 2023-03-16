#include <igraph.h>

int main(void) {
    igraph_t g;
    igraph_vector_int_t cores;

    FILE *input;
    igraph_set_attribute_table(&igraph_cattribute_table);

    input = fopen("a_unweighted_undirected.lgl", "r");
    igraph_read_graph_lgl(&g, input, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_UNDIRECTED);
    fclose(input);

    igraph_vector_int_init(&cores, 0);

    igraph_coreness(&g, &cores, IGRAPH_ALL);
    // igraph_vector_int_print(&cores);

    igraph_vector_int_destroy(&cores);
    igraph_destroy(&g);
    return 0;
}