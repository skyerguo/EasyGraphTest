#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2000005;

using namespace std;

int N, M, Tot;
int parent[Maxn], rank_node[Maxn], color[Maxn];
bool has_edge[Maxn];

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E_res[Maxn];

int edge_number_res = 0;
int head_res[Maxn];
inline void add_edge_res(const int &u, const int &v) {
    E_res[++edge_number_res].next = head_res[u];
    E_res[edge_number_res].toward = v;
    head_res[u] = edge_number_res;
}
#define get_edge_from_node_res(p,u) for(int p = head_res[u]; p; p = E_res[p].next)

int getfa(const int & x) {
    int r,k,t;
    r=x;
    while(parent[r]!=r)
        r=parent[r];
    k=r;
    r=x;
    while(parent[r]!=k) {
        t=parent[r];
        parent[r]=k;
        r=t;
    }
    return k;
}
 
//合并操作
inline void union_node(const int &u, const int &v) {
    int x = getfa(u), y = getfa(v);    //先找到两个根节点
    if (rank_node[x] <= rank_node[y])
        parent[x] = y;
    else
        parent[y] = x;
    if (rank_node[x] == rank_node[y] && x != y)
        rank_node[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    memset(rank_node, 0, sizeof(int) * N);
    memset(has_edge, false, sizeof(bool) * N);
    for (int i = 0; i < N; ++i)
        parent[i] = i;

    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        has_edge[u] = true; has_edge[v] = true;
        union_node(u,v);
    }
}

void output() {
    for (int i = 0; i < N; ++i) {
        int fx = getfa(i);
        add_edge_res(fx, i);
    }
    for (int i = 1; i <= Tot; ++i) {
        cout << "当前连通分量为: " << i << endl;
        get_edge_from_node_res(p, color[i])
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
    Tot = 0;
	for(int i = 0; i < N; ++i) {
        if (!has_edge[i])
            continue;
		int fx = getfa(i);
		if(fx == i)
			color[++Tot] = fx;
	}
    output();
	printf("无向连通图的连通分量: %d\n", Tot);
    return 0;
}