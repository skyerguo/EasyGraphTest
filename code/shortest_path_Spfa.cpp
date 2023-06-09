#include <bits/stdc++.h>

using namespace std;

const int Maxn = 200005;
const int Maxm = 2000005;

using namespace std;

int N, M;
int head[Maxn], dis[Maxn], Q[Maxn];
bool vis[Maxn];

struct Edge_weighted{
    int toward, next, weight;
};
Edge_weighted E[Maxm];

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

void Spfa(const int &S)
{
    memset(dis, 0x7f, sizeof(int) * N);
    memset(vis, false, sizeof(bool) * N);
	int l = 0, r = 1; 
	Q[0] = S; vis[S] = true; dis[S] = 0;
    while (l != r) {
    	if (r != 0 && dis[Q[l]] >= dis[Q[r - 1]]) 
    		swap(Q[l], Q[r - 1]);
        int u = Q[l++]; 
        if (l >= N) l -= N; 
        vis[u] = false;

        getE(p, u) {
            int v=E[p].toward; 
            if (dis[v]>dis[u]+E[p].weight) {
                dis[v]=dis[u]+E[p].weight; 
                if (!vis[v]) {
                    vis[v]=true;
                    if (l == 0 || dis[v] >= dis[Q[l]])
						Q[r++]=v;
					else
						Q[--l]=v;
                    if (r >= N) r -= N;
                }
            }
        }
	}	
}

FILE* output_file = fopen("../results/b.out", "w");
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
        Spfa(i);
        // output();
    }
    return 0;
}
