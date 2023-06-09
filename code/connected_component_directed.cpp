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
#define gmin(x, y) x = x < y? x: y

int N, M;
int head[Maxn];
bool has_edge[Maxn];
int dfn[Maxn], low[Maxn], st[Maxn], color[Maxn];
bool in_stack[Maxn];

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E[Maxm], E_res[Maxn];

int edge_number = 0;
bool if_directed = true;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
}
#define get_edge_from_node(p,u) for(register int p = head[u]; p; p = E[p].next)

int edge_number_res = 0;
int head_res[Maxn];
inline void add_edge_res(const int &u, const int &v) {
    E_res[++edge_number_res].next = head_res[u];
    E_res[edge_number_res].toward = v;
    head_res[u] = edge_number_res;
}
#define get_edge_from_node_res(p,u) for(int p = head_res[u]; p; p = E_res[p].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        add_edge(u, v);
        has_edge[u] = true; has_edge[v] = true;
        if (!if_directed)
            add_edge(v, u);
    }
}

int Time = 0, cnt = 0, Tot = 0;
void Tarjan(const int &u) { //有向图
    dfn[u] = low[u] = ++Time; st[++cnt] = u; in_stack[u] = true;
    get_edge_from_node(p, u) {
        int v = E[p].toward;
        if (!dfn[v]) Tarjan(v), gmin(low[u], low[v]); 
        else if (in_stack[v]) gmin(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        for (++Tot; st[cnt] != u; --cnt) {
            add_edge_res(Tot, st[cnt]);
            in_stack[st[cnt]] = false, color[st[cnt]] = Tot;
        }
        add_edge_res(Tot, st[cnt]);
        in_stack[u] = false; color[u] = Tot; --cnt;
    }
}

void output() {
    for (int i = 1; i <= Tot; ++i) {
        cout << "当前连通分量为: " << i << endl;
        get_edge_from_node_res(p, i)
            cout << E_res[p].toward << " ";
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    for (int i = 0; i < N; ++i)
        if (!dfn[i] && has_edge[i])
            Tarjan(i);
    output();
    printf("有向图的连通分量: %d\n", Tot);

    return 0;
}