#include <bits/stdc++.h>
#include <omp.h>

const int Maxn = 196591 + 10;
const int Maxm = 950327 * 2 + 10;

using namespace std;

int N, M;
int head[Maxn], neightbors_number[Maxn];
unordered_set<int> s[Maxn];

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E[Maxm];

int edge_number = 0;
bool is_directed = true;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
    s[u].insert(v);
}
#define get_edge_from_node(p,u) for(int p = head[u]; p; p = E[p].next)
#define get_edge_from_edge(q,p) for(int q = E[p].next; q; q = E[q].next)

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        add_edge(u, v);
        if (!is_directed) 
            add_edge(v, u);
    }
    for (int i = 0; i < N; ++i) 
        neightbors_number[i] = s[i].size();
}

void clustering_coefficient() {
    float coeff_sum = 0;
    // #pragma omp parallel for reduction(+:coeff_sum)
    for (int i = 0; i < N; i++) {
        if (neightbors_number[i] < 2) continue;
        int num_links = 0;
        // if (i == 220) {
        //     cout << s[i].size();
        //     exit(0);
        // }
        get_edge_from_node(p, i) {
            int j = E[p].toward;
            if (neightbors_number[j] > neightbors_number[i]) {
                get_edge_from_edge(q, p) {
                    if (s[j].find(E[q].toward) != s[j].end())
                        num_links++;
                }
            }
            else {
                get_edge_from_node(q, j) {
                    int k = E[q].toward;
                    if (s[i].find(k) != s[i].end())
                        num_links++;
                }
            }
        }
        if (i <= 300)
            printf("%d %f\n", i, 2 * float(num_links) / (neightbors_number[i] * (neightbors_number[i] - 1)));
        coeff_sum += float(num_links) / (neightbors_number[i] * (neightbors_number[i] - 1));
    }
    cout << "Clustering Coefficient: " << 2 * coeff_sum / N << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    if (strcmp(argv[2], "false") == 0)
        is_directed = false;
    else
        is_directed = true;
    input(argv[1]);
    clustering_coefficient();

    return 0;
}
