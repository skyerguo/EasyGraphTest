cmake_minimum_required(VERSION 3.18)
project(igraph_shortest_path)

find_package(igraph REQUIRED)

add_executable(igraph_shortest_path igraph_shortest_path.c)
target_link_libraries(igraph_shortest_path PUBLIC igraph::igraph)