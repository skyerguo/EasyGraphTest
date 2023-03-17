import networkx as nx

filename = "../verified_dataset/test/a_weighted_directed.in"
G = nx.DiGraph()
distances = []
with open(filename) as f_in:
    flag = 1
    for line in f_in:
        if flag:
            flag = 0
            continue
        u, v, w = [int(x) for x in line.split()]
        G.add_edge(u, v, weight=w)
        # distances.append(w)
        
    
# g_distance_dict = {(e1, e2): 1 / weight for e1, e2, weight in G.edges(data='weight')}
cc = nx.closeness_centrality(G,distance='weight')
for node in sorted(cc.keys()):
    print(node, "%.9f"%(cc[node]))
