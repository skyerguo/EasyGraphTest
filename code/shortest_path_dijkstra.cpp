#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include<ext/pb_ds/priority_queue.hpp>

const int Maxn = 200005;
const int Maxm = 2000005;

using namespace std;

int N, M;
int head[Maxn], dis[Maxn];
bool vis[Maxn];

struct Edge_weighted{
    int toward, next, weight;
};
Edge_weighted E[Maxm];

struct compare_node {
	compare_node(){} 
    compare_node(int _x, int _d) {x = _x; d = _d;}
	int x, d;	
	bool operator < (const compare_node &rhs) const {
		return d > rhs.d;
	}
};

int edge_number = 0;
bool if_undirected = false;
inline void add_edge(const int &u, const int &v, const int &w) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    E[edge_number].weight = w;
    head[u] = edge_number;
}
#define getE(p,u) for(register int p = head[u]; p; p = E[p].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    // scanf(" %d %d %d", &N, &M, &S);
    int u, v, w;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d %d", &u, &v, &w);
        // scanf(" %d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        if (if_undirected)
            add_edge(v, u, w);
    }
}

__gnu_pbds::priority_queue<compare_node> q;
void dijkstra(const int &S) {
    memset(dis, 0x7f, sizeof(int) * N);
    memset(vis, false, sizeof(bool) * N);
    while (!q.empty()) q.pop();

    dis[S] = 0; 
    q.push(compare_node(S, 0));

    while(!q.empty()) {
        int u=q.top().x;
        q.pop();
        if (vis[u]) 
            continue;
        vis[u] = true;

        for(register int p = head[u]; p; p = E[p].next) {
            int v = E[p].toward;
            if (dis[v] > dis[u] + E[p].weight) {
                dis[v] = dis[u] + E[p].weight;
                q.push(compare_node(v, dis[v]));
            }
        }
    }
}

FILE* output_file = fopen("../results/a.out", "w");
void output() {
    for (int j = 0; j < N; ++j)
        fprintf(output_file, "%d\n", dis[j]);
    fprintf(output_file, "\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    for (int i = 0; i < N; ++i) {
        dijkstra(i);
        // output();
    }
    return 0;
}