cmake_minimum_required(VERSION 3.18)
project(igraph_connected_component)

find_package(igraph REQUIRED)

add_executable(igraph_connected_component igraph_connected_component.c)
target_link_libraries(igraph_connected_component PUBLIC igraph::igraph)