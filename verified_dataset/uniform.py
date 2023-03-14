import re
import random
import argparse
import os
import json
import math
import sys

p = argparse.ArgumentParser(description='Analyze the result')
p.add_argument('-i', '--input_file', type=str, default="", dest="inputfile", action="store", help="the name of input file")
p.add_argument('-d', '--input_directory', type=str, default="", dest="inputdirectory", action="store", help="the name of input directory")
p.add_argument('-w', '--weighted', action="store_true", default=False, dest="weighted", help="wether a weighted graph")

args = p.parse_args()

input_file = args.inputfile
output1_weighted_file = args.inputdirectory + '/a.in'
output1_unweighted_file = args.inputdirectory + '/a_unweighted.in'
output2_weighted_file = args.inputdirectory + '/a.lgl'
output2_unweighted_file = args.inputdirectory + '/a_unweighted.lgl'

n = 0
m = 0

if args.weighted:
    edge_list_weighted = {}

if __name__ == '__main__':
    f_in = open(input_file, 'r')
    f_out1_weighted = open(output1_weighted_file, 'w')
    f_out1_unweighted = open(output1_unweighted_file, 'w')
    for line in f_in:
        n = max(n, max(int(re.split(r'[,\s]',line)[0]), int(re.split(r'[,\s]',line)[1])))
    f_in.close()
    n += 1
    
    edge_list_unweighted = [[] for _ in range(n)]
    

    
    f_in = open(input_file, 'r')
    for line in f_in:
        u = int(re.split(r'[,\s]',line)[0])
        v = int(re.split(r'[,\s]',line)[1])
        
        if u in edge_list_unweighted[v] or v in edge_list_unweighted[u] or u == v: ## 去除重边和自环
            continue
        
        m += 1

        edge_list_unweighted[u].append(v)
        edge_list_unweighted[v].append(u)
        
        if args.weighted:
            w = random.randint(1, 100)
            
            if u in edge_list_weighted.keys():
                edge_list_weighted[u].append([v,w])
            else:
                edge_list_weighted[u] = [[v,w]]
                
            
    print(n, m, file=f_out1_unweighted)
    if args.weighted:
        print(n, m, file=f_out1_weighted)
    
    
    f_out2_unweighted = open(output2_unweighted_file, 'w')
    if args.weighted:
        f_out2_weighted = open(output2_weighted_file, 'w')
        
    for i in range(n):
        if not edge_list_unweighted[i]:
            continue
        print("# %i"%i, file=f_out2_unweighted)
        
        if args.weighted:
            if i not in edge_list_weighted.keys():
                continue    
        
        for j in edge_list_unweighted[i]:
            print("%i"%(j), file=f_out2_unweighted)
            print(i, j, file=f_out1_unweighted)
        
        if args.weighted:
            for j in range(len(edge_list_weighted[i])):
                print("%i %i %i"%(i, edge_list_weighted[i][j][0], edge_list_weighted[i][j][1]), file=f_out1_weighted)
                print("%i %i"%(edge_list_weighted[i][j][0], edge_list_weighted[i][j][1]), file=f_out2_weighted)
            
    f_in.close()
    f_out1_unweighted.close()
    if args.weighted:
        f_out1_weighted.close()
            
    f_out2_unweighted.close()
    if args.weighted:
        f_out2_weighted.close()