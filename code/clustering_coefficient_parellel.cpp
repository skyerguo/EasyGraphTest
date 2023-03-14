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
bool if_undirected = true;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
    s[u].insert(v);
}
#define get_edge_from_node(p,u) for(register int p = head[u]; p; p = E[p].next)
#define get_edge_from_edge(q,p) for(register int q = E[p].next; q; q = E[q].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
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

        get_edge_from_node(p, i) {
            get_edge_from_edge(q, p) {
                if (s[E[p].toward].find(E[q].toward) != s[E[p].toward].end())
                    num_links++;
            }
        }
        coeff_sum += 2 * (double)num_links / ((double)num_neighbors * (double)(num_neighbors - 1));
        // printf("%d %f\n", i, 2 * (double)num_links / ((double)num_neighbors * (double)(num_neighbors - 1)));
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
