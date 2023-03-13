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

args = p.parse_args()

input_file = args.inputfile
output_file = args.inputdirectory + '/a.in'
output2_file = args.inputdirectory + '/a.lgl'

n = 0
m = 0

edge_list = {}

if __name__ == '__main__':
    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')
    for line in f_in:
        m += 1
        n = max(n, max(int(re.split(r'\s',line)[0]), int(re.split(r'\s',line)[1])))
    f_in.close()
    print(n, m, file=f_out)
    
    f_in = open(input_file, 'r')
    for line in f_in:
        u = int(re.split(r'\s',line)[0])
        v = int(re.split(r'\s',line)[1])
        w = random.randint(1, 100)
        print(u, v, w, file=f_out)
        if u in edge_list.keys():
            edge_list[u].append([v,w])
        else:
            edge_list[u] = [[v,w]]
    f_in.close()
    f_out.close()
    
    f_out2 = open(output2_file, 'w')
    for i in range(n + 1):
        if i not in edge_list.keys():
            continue
        print("# %i"%i, file=f_out2)
        for j in range(len(edge_list[i])):
            print("%i %i"%(edge_list[i][j][0], edge_list[i][j][1]), file=f_out2)
    f_out2.close()