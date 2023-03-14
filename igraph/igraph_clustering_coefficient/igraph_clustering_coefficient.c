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
   MERCHANTABILITY or FI
   TNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA

*/

#include <igraph.h>

int main(void) {
    igraph_t g;
    igraph_real_t res;

    FILE *input;
    FILE *f;
    igraph_set_attribute_table(&igraph_cattribute_table);

    // input = fopen("a_unweighted.lgl", "r");
    // igraph_read_graph_lgl(&g, input, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_UNDIRECTED);
    // fclose(input);
    f = fopen("bio.edgelist", "r");
    igraph_read_graph_edgelist(&g, f, 0, IGRAPH_UNDIRECTED);

    igraph_transitivity_undirected(&g, &res, IGRAPH_TRANSITIVITY_NAN);
    printf("res: %f\n", res);

    igraph_destroy(&g);
    return 0;
}
