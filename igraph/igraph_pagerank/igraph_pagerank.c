#include <igraph.h>
#include <float.h>

int main(void) {
    igraph_t g;
    igraph_vector_t pagerank;
    igraph_real_t value;

    FILE *input;
    igraph_set_attribute_table(&igraph_cattribute_table);

    input = fopen("a_unweighted_directed.lgl", "r");
    igraph_read_graph_lgl(&g, input, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_DIRECTED);
    fclose(input);

    igraph_vector_init(&pagerank, 0);
    exit(0);

    igraph_pagerank(&g, IGRAPH_PAGERANK_ALGO_PRPACK,
                    &pagerank, &value,
                    igraph_vss_all(), IGRAPH_DIRECTED,
                    /* damping */ 0.85, /* weights */ NULL,
                    NULL /* not needed with PRPACK method */);

    /* Check that the eigenvalue is 1, as expected. */
    if (fabs(value - 1.0) > 32*DBL_EPSILON) {
        fprintf(stderr, "PageRank failed to converge.\n");
        return 1;
    }

    /* Output the result */
    // igraph_vector_print(&pagerank);

    /* Destroy data structure when no longer needed */
    igraph_vector_destroy(&pagerank);
    igraph_destroy(&g);
    return 0;
}
