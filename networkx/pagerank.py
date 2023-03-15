import networkx as nx

filename = "../verified_dataset/pgp_sampled/a_unweighted_directed.in"
G = nx.DiGraph()
with open(filename) as f_in:
    flag = 1
    for line in f_in:
        if flag:
            flag = 0
            continue
        head, tail = [int(x) for x in line.split()]
        G.add_edge(head, tail)

pr = nx.pagerank(G, max_iter=100, alpha=0.85)
for node in sorted(pr.keys()):
    print(node, "%.9f"%(pr[node]))
