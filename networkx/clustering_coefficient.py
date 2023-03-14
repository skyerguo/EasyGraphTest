import networkx as nx
import numpy as np

f_in = open("../verified_dataset/gowalla/loc-gowalla_edges.txt", 'r')
G = nx.Graph()
G = nx.read_edgelist(f_in)
f_in.close()
print(len(G.nodes))
exit(0)
clustering_all = nx.clustering(G)
sum = 0
cnt = 0
for node in clustering_all.keys():
    if cnt <= 300:
        print(node, clustering_all[node])
    sum += clustering_all[node]
    cnt += 1
print(sum / len(G.nodes))
# print(nx.clustering(G))