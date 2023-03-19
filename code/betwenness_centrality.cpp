#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include<ext/pb_ds/priority_queue.hpp>
#define ll long long 

const int Maxn = 129164 + 5;
const int Maxm = 165435 + 5;

using namespace std;

int N, M;
int dis[Maxn];
ll count_path[Maxn], count_path_reverse[Maxn];
double bc[Maxn];
int time_vis[Maxn];
bool vis[Maxn];
bool if_directed = true;

struct Edge_weighted{
    int toward, next, weight;
};
Edge_weighted E[Maxm], E_reverse[Maxm], E_path[Maxm];

struct compare_node {
	compare_node(){} 
    compare_node(int _x, int _d) {x = _x; d = _d;}
	int x, d;	
	bool operator < (const compare_node &rhs) const {
		return d > rhs.d;
	}
};

int head[Maxn];
int edge_number = 0;
inline void add_edge(const int &u, const int &v, const int &w) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    E[edge_number].weight = w;
    head[u] = edge_number;
}
#define get_edge_from_node(p,u) for(int p = head[u]; p; p = E[p].next)

int head_reverse[Maxn];
int edge_number_reverse = 0;
inline void add_edge_reverse(const int &u, const int &v, const int &w) {
    E_reverse[++edge_number_reverse].next = head_reverse[u];
    E_reverse[edge_number_reverse].toward = v;
    E_reverse[edge_number_reverse].weight = w;
    head_reverse[u] = edge_number_reverse;
}
#define get_edge_from_node_reverse(p,u) for(int p = head_reverse[u]; p; p = E_reverse[p].next)

int head_path[Maxn];
int edge_number_path = 0;
inline void add_edge_path(const int &u, const int &v) {
    E_path[++edge_number_path].next = head_path[u];
    E_path[edge_number_path].toward = v;
    head_path[u] = edge_number_path;
}
#define get_edge_from_node_path(p,u) for(int p = head_path[u]; p; p = E_path[p].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    int u, v, w;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        // add_edge_reverse(v, u, w);
    }
}

// int Q[Maxn];
// void update_path(const int &S, const int &T, const int &curr_time) {
//     if (S == T)
//         return;
//     int l = 0, r = 1; 
//     Q[0] = T; time_vis[T] = curr_time; count_path_reverse[T] = 1;
//     while (l < r) {
//         int x = Q[l++]; 
//         get_edge_from_node_reverse(p, x) {
//             int y = E_reverse[p].toward;
//             if (y == S)
//                 continue;
//             if (dis[y] + E_reverse[p].weight == dis[x]) {
//                 if (time_vis[y] != curr_time) {
//                     time_vis[y] = curr_time;
//                     Q[r++] = y;
//                     count_path_reverse[y] = 0;
//                 }
//                 count_path_reverse[y] += count_path_reverse[x];
//                 bc[y] += 1.0 * count_path_reverse[x] * count_path[y] / count_path[T];
//             }
//         }
//     }
// }

int St[Maxn];
float delta[Maxn];
__gnu_pbds::priority_queue<compare_node> q;
void betweenness_dijkstra(const int &S) {
    memset(dis, 0x7f, sizeof(int) * N);
    memset(vis, false, sizeof(bool) * N);
    memset(count_path, 0, sizeof(ll) * N);
    // memset(time_vis, 0, sizeof(int) * N);
    while (!q.empty()) q.pop();
    edge_number_path = 0; head_path[S] = 0;

    // int curr_time = 0;
    dis[S] = 0; count_path[S] = 1; 
    q.push(compare_node(S, 0));
    int cnt_St = 0;

    while(!q.empty()) {
        int u = q.top().x;
        q.pop();
        if (vis[u]) 
            continue;

        St[cnt_St++] = u;
        vis[u] = true;
        // update_path(S, u, ++curr_time);

        get_edge_from_node(p, u) {
            int v = E[p].toward;
            if (dis[v] > dis[u] + E[p].weight) {
                dis[v] = dis[u] + E[p].weight;
                q.push(compare_node(v, dis[v]));
                count_path[v] = count_path[u];
                head_path[v] = 0;
                add_edge_path(v, u);
            }
            else if (dis[v] == dis[u] + E[p].weight) {
                count_path[v] += count_path[u];
                add_edge_path(v, u);
            }
        }
    }

    memset(delta, 0, sizeof(float) * N);
    while (cnt_St > 0) {
        int u = St[--cnt_St];
        float coeff = (1.0 + delta[u]) / count_path[u];
        // get_edge_from_node_reverse(p, u) {
        //     int v = E_reverse[p].toward;
        //     if (dis[v] + E_reverse[p].weight == dis[u]) {
        //         delta[v] += count_path[v] * coeff;
        //     }
        // }
        get_edge_from_node_path(p, u)
            delta[E_path[p].toward] += count_path[E_path[p].toward] * coeff;

        if (u != S)
            bc[u] += delta[u];
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    for (int i = 0; i < N; ++i) 
        betweenness_dijkstra(i);
    
    // for (int i = 0; i < N; ++i) 
    //     cout << i << " " << bc[i] << endl;
    return 0;
}