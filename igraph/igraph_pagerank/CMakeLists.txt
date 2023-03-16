cmake_minimum_required(VERSION 3.18)
project(igraph_pagerank)

find_package(igraph REQUIRED)

add_executable(igraph_pagerank igraph_pagerank.c)
target_link_libraries(igraph_pagerank PUBLIC igraph::igraph)