import networkx as nx
import numpy as np

def generate_adj_matrix_graph(relation_file_path, nodes_number):
    import re
    A = np.zeros((nodes_number, nodes_number), int)
    f_in = open(relation_file_path, "r")
    for line in f_in:
        user_list = re.split(' |\t',line.strip())
        ## 双向边
        A[int(user_list[1])][int(user_list[0])] = 1
        A[int(user_list[0])][int(user_list[1])] = 1
    f_in.close()

    return A

# adj_matrix = generate_adj_matrix_graph("../verified_dataset/erdos_500/500.edgelist", 500)
f_in = open("../verified_dataset/bio/bio.edgelist", 'r')
G = nx.Graph()
G = nx.read_edgelist(f_in)
f_in.close()
print(nx.clustering(G))