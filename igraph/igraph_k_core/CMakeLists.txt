cmake_minimum_required(VERSION 3.18)
project(igraph_k_core)

find_package(igraph REQUIRED)

add_executable(igraph_k_core igraph_k_core.c)
target_link_libraries(igraph_k_core PUBLIC igraph::igraph)