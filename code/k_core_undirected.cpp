#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include<ext/pb_ds/priority_queue.hpp>

const int Maxn = 916428 + 5;
const int Maxm = 5105039 + 5;

using namespace std;

int N, M;
int max_deg = 0;
int head[Maxn], deg[Maxn], core[Maxn], bin[Maxn], pos[Maxn], vert[Maxn];
bool vis[Maxn];

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E[Maxm];

int edge_number = 0;
bool if_directed = false;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
    deg[u]++;
    max_deg = max(max_deg, deg[u]);
}
#define get_edge_from_node(p,u) for(register int p = head[u]; p; p = E[p].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        add_edge(u, v);
        if (!if_directed)
            add_edge(v, u);
    }
}


void core_decomposition() {
    // 基数排序
    for(int i = 0; i < N; ++i)
        ++bin[deg[i]];
    //此时bin[i]表示度数为i的点有多少个

    int start = 0;
    for(int i = 0; i < max_deg + 1; ++i){
        int num = bin[i];
        bin[i] = start;
        start += num;
    }
    //此时bin[i]表示度数为i的第一个点
 
    for(int i = 0; i < N; ++i){
        pos[i] = bin[deg[i]];
        vert[pos[i]] = i;
        ++bin[deg[i]];
    }
    //此时bin[i]表示度数为i+1的第一个点，所以后面要进行左移操作
 
    for(int i = max_deg; i > 0; --i){
        bin[i] = bin[i - 1];
    }
    bin[0] = 0;
 
    for(int i = 0; i < N; ++i){
        int v = vert[i];
        core[v] = deg[v];
        get_edge_from_node(p, v) {
            int u = E[p].toward;
            if (deg[u] > deg[v]) {
                int w = vert[bin[deg[u]]];
                if(u != w){
                    swap(vert[pos[u]],vert[pos[w]]);
                    swap(pos[u],pos[w]);
                }
                ++bin[deg[u]];
                --deg[u];
            }
        }
    }
}

void output() {
    for (int i = 0; i < N; ++i) 
        printf("%d ", core[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    core_decomposition();
    
    // output();

    return 0;
}