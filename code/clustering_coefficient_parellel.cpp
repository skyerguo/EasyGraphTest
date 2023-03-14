#include <bits/stdc++.h>
#include <omp.h>

const int Maxn = 200005;
const int Maxm = 2000005;

using namespace std;

int N, M;
int head[Maxn];
unordered_set<int> s[Maxn]; 

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E[Maxm];

int edge_number = 0;
bool if_undirected = false;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
    s[u].insert(v);
}
#define get_edge_from_node(p,u) for(register int p = head[u]; p; p = E[p].next)
#define get_edge_from_edge(p,u) for(register int p = E[u].next; p; p = E[p].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    cout << N << " " << M << endl;
    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        add_edge(u, v);
        if (if_undirected)
            add_edge(v, u);
    }
}

double clustering_coefficient() {
    double coeff_sum = 0;
    #pragma omp parallel for reduction(+:coeff_sum)
    for (int i = 0; i < N; i++) {
        int num_neighbors = s[i].size();
        if (num_neighbors < 2) continue;
        int num_links = 0;
        
        get_edge_from_node(j, i) {
            get_edge_from_edge(k, j) {
                if (s[E[j].toward].find(E[k].toward) != s[E[j].toward].end())
                    num_links++;
            }
        }
        // int num_neighbors = adj_list[i].size();
        // if (num_neighbors < 2) continue;
        // int num_links = 0;
        // for (int j = 0; j < num_neighbors; j++) {
        //     int neighbor = adj_list[i][j];
        //     for (int k = j+1; k < num_neighbors; k++) {
        //         if (find(adj_list[neighbor].begin(), adj_list[neighbor].end(), adj_list[i][k]) != adj_list[neighbor].end())
        //             num_links++;
        //     }
        // }
        coeff_sum += (double)num_links / ((double)num_neighbors * (double)(num_neighbors - 1));
    }
    return coeff_sum / N;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    double coeff = clustering_coefficient();
    cout << "Clustering Coefficient: " << coeff << endl;

    return 0;
}
