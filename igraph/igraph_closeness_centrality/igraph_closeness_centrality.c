/* -*- mode: C -*-  */
/*
   IGraph library.
   Copyright (C) 2006-2012  Gabor Csardi <csardi.gabor@gmail.com>
   334 Harvard st, Cambridge MA, 02139 USA

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA

*/

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
    igraph_closeness(&g, &res, NULL, /*all_reachable:*/ false, igraph_vss_all(), IGRAPH_OUT,
                   /* weights= */ &weights, /* normalized= */ true);
    // printf("cent : %f\n", cent);

    igraph_vector_print(&res);

    // igraph_vector_destroy(&weights);
    igraph_vector_destroy(&res);
    igraph_destroy(&g);
    return 0;
}
