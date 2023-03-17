#include <igraph.h>

int main(void) {
    igraph_t g;
    igraph_vector_int_t component_sizes;

    FILE *input;
    igraph_set_attribute_table(&igraph_cattribute_table);

    input = fopen("a_unweighted_directed.lgl", "r");
    igraph_read_graph_lgl(&g, input, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_DIRECTED);
    fclose(input);

    igraph_vector_int_init(&component_sizes, 0);
    igraph_connected_components(&g, NULL, &component_sizes, NULL, IGRAPH_STRONG);

    // igraph_vector_int_print(&component_sizes);
    printf("component number: %ld\n", igraph_vector_size(&component_sizes));

    // printf(
    //     "Fraction of vertices in giant component: %g\n",
    //     ((double) igraph_vector_int_max(&component_sizes)) / igraph_vcount(&g)
    // );

    /* Clean up data structures when no longer needed */

    igraph_vector_int_destroy(&component_sizes);
    igraph_destroy(&g);
    return 0;
}