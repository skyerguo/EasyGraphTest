cmake_minimum_required(VERSION 3.18)
project(igraph_betweenness_centrality)

find_package(igraph REQUIRED)

add_executable(igraph_betweenness_centrality igraph_betweenness_centrality.c)
target_link_libraries(igraph_betweenness_centrality PUBLIC igraph::igraph)