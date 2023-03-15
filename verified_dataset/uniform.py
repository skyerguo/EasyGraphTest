import re
import random
import argparse
import os
import json
import math
import sys

p = argparse.ArgumentParser(description='Analyze the result')
p.add_argument('-i', '--input_file', type=str, default="", dest="inputfile", action="store", help="the name of input file")
p.add_argument('-r', '--input_directory', type=str, default="", dest="inputdirectory", action="store", help="the name of input directory")
p.add_argument('-w', '--weighted', action="store_true", default=False, dest="weighted", help="wether a weighted graph")
p.add_argument('-d', '--directed', action="store_true", default=False, dest="directed", help="wether a directed graph")
p.add_argument('-e', '--edgelist', action="store_true", default=False, dest="edgelist", help="wether a remake the raw edgelist")

args = p.parse_args()

input_file = args.inputfile
if args.weighted:
    weight_item = "weighted"
else:
    weight_item = "unweighted"
    
if args.directed:
    direct_item = "directed"
else:
    direct_item = "undirected"

n = 0
m = 0

node_hash = {}

if args.weighted:
    edge_list_weighted = {}

if __name__ == '__main__':
    f_in = open(input_file, 'r')
    
    # f_out1_weighted = open(output1_weighted_file, 'w')
    # f_out1_unweighted = open(output1_unweighted_file, 'w')
    f_out1 = open(args.inputdirectory + '/a_' + weight_item + '_' + direct_item + '.in', 'w')
    for line in f_in:
        # n = max(n, max(int(re.split(r'[,\s]',line)[0]), int(re.split(r'[,\s]',line)[1])))
        u = int(re.split(r'[,\s]',line)[0])
        v = int(re.split(r'[,\s]',line)[1])
        if u not in node_hash.keys():
            node_hash[u] = n
            n += 1
        if v not in node_hash.keys():
            node_hash[v] = n
            n += 1
    f_in.close()
    
    edge_list_unweighted = [[] for _ in range(n)]
    
    f_in = open(input_file, 'r')
    for line in f_in:
        u = node_hash[int(re.split(r'[,\s]',line)[0])]
        v = node_hash[int(re.split(r'[,\s]',line)[1])]
        
        if v in edge_list_unweighted[u] or u == v: ## 去除重边和自环
            continue
        if (not args.directed) and u in edge_list_unweighted[v]: ## 无向图去除重边
            continue
        
        m += 1

        edge_list_unweighted[u].append(v)
        if not args.directed:
            edge_list_unweighted[v].append(u)
        
        if args.weighted:
            w = random.randint(1, 100)
            if u in edge_list_weighted.keys():
                edge_list_weighted[u].append([v,w])
            else:
                edge_list_weighted[u] = [[v,w]]
                    
    print(n, m, file=f_out1)
    
    f_out2 = open(args.inputdirectory + '/a_' + weight_item + '_' + direct_item + '.lgl', 'w')
    if args.edgelist:
        f_out3 = open(args.inputdirectory + '/edges.list', 'w')
    for i in range(n):
        if not edge_list_unweighted[i]:
            continue
        print("# %i"%i, file=f_out2)
        
        if not args.weighted:
            for j in edge_list_unweighted[i]:
                print(i, j, file=f_out1)
                print("%i"%(j), file=f_out2)
                if args.edgelist:
                    print(i, j, file=f_out3)
        else:
            if args.weighted:
                for j in range(len(edge_list_weighted[i])):
                    print("%i %i %i"%(i, edge_list_weighted[i][j][0], edge_list_weighted[i][j][1]), file=f_out1)
                    print("%i %i"%(edge_list_weighted[i][j][0], edge_list_weighted[i][j][1]), file=f_out2)
                
    f_in.close()
    f_out1.close()
    f_out2.close()
    if args.edgelist:
        f_out3.close()