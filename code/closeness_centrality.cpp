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
    int u, v, w;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d %d", &u, &v, &w);
        // 根据closeness的计算逻辑，这里反向加边
        add_edge(v, u, w);
        if (if_undirected)
            add_edge(u, v, w);
    }
}

__gnu_pbds::priority_queue<compare_node> q;
void closeness_dijkstra(const int &S) {
    memset(dis, 0x7f, sizeof(int) * N);
    memset(vis, false, sizeof(bool) * N);
    while (!q.empty()) q.pop();

    int number_connected = 0;
    long long sum_dis = 0;

    dis[S] = 0; 
    q.push(compare_node(S, 0));

    while(!q.empty()) {
        int u=q.top().x;
        q.pop();
        if (vis[u]) 
            continue;
        vis[u] = true;
        number_connected += 1;
        sum_dis += dis[u];

        for(register int p = head[u]; p; p = E[p].next) {
            int v = E[p].toward;
            if (dis[v] > dis[u] + E[p].weight) {
                dis[v] = dis[u] + E[p].weight;
                q.push(compare_node(v, dis[v]));
            }
        }
    }
    // cout << number_connected << " " << sum_dis << endl;

    if (number_connected == 1)
        printf("The closeness of node %d is 0.00\n", S);
    else
        printf("The closeness of node %d is %lf\n", S, 1.0 * (number_connected - 1) * (number_connected - 1) / ((N - 1) * sum_dis));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    for (int i = 0; i < N; ++i) 
        closeness_dijkstra(i);
    return 0;
}