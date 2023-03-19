#include <igraph.h>
#include <math.h>

int main(void) {

    igraph_t g;
    igraph_vector_t weights;
    igraph_vector_t res;

    FILE *input;
    igraph_set_attribute_table(&igraph_cattribute_table);

    input = fopen("a_weighted_directed.lgl", "r");
    igraph_read_graph_lgl(&g, input, 0, IGRAPH_ADD_WEIGHTS_YES, IGRAPH_DIRECTED);
    fclose(input);

    igraph_vector_init(&weights, 0);
    if(igraph_cattribute_has_attr(&g,IGRAPH_ATTRIBUTE_EDGE,"weight")) 
        EANV(&g, "weight", &weights);
    else 
        printf("The Graph does not have attribute of weight \n");

    igraph_vector_init(&res, 0);
    igraph_betweenness(&g, &res, igraph_vss_all(),
                     IGRAPH_DIRECTED, /* weights= */ &weights);

    // igraph_vector_print(&res);

    igraph_vector_destroy(&weights);
    igraph_vector_destroy(&res);
    igraph_destroy(&g);
    return 0;
}
