import networkx as nx

filename = "../verified_dataset/pgp_sampled/a_weighted_directed.in"
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
        
    
bc = nx.betweenness_centrality(G,normalized=False,weight='weight',endpoints=False)
for node in sorted(bc.keys()):
    print(node, "%.9f"%(bc[node]))
