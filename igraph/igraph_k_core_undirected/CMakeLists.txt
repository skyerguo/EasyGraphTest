cmake_minimum_required(VERSION 3.18)
project(igraph_k_core_undirected)

find_package(igraph REQUIRED)

add_executable(igraph_k_core_undirected igraph_k_core_undirected.c)
target_link_libraries(igraph_k_core_undirected PUBLIC igraph::igraph)