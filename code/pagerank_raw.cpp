#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1632803 + 5;
const int Maxm = 30622564 + 5;

int N, M;
int head[Maxn], outDegree[Maxn];

struct Edge_weighted{
    int toward, next;
};
Edge_weighted E[Maxm];

int edge_number = 0;
inline void add_edge(const int &u, const int &v) {
    E[++edge_number].next = head[u];
    E[edge_number].toward = v;
    head[u] = edge_number;
    outDegree[u]++;
}
#define get_edge_from_node(p,u) for(int p = head[u]; p; p = E[p].next)

struct Page {
	Page(){} 
    Page(const double &_newPR, const double &_oldPR) {newPR = _newPR; oldPR = _oldPR;}

    double newPR, oldPR;
}page[Maxn];

void input(const char *file_name) {
    FILE* input_file = fopen(file_name, "r");
    fscanf(input_file, " %d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; ++i) {
        fscanf(input_file, " %d %d", &u, &v);
        add_edge(u, v);
    }
    for (int i = 0; i < N; ++i)
        page[i] =  Page(0, 1.0 / N);
}


void PageRank(double alpha=0.85, int max_iterator=500, double threshold=1e-6)
{
    int cnt = 0; //统计迭代几轮
	int shouldStop = 0; //根据oldPR与newPR的差值 判断是否停止迭代
    // 开始迭代
    while(!shouldStop)
    {
        shouldStop = 1;
        double res = 0;
        for(int i = 0; i < N; ++i) {
            if (outDegree[i] == 0) {
                res += page[i].oldPR;
                continue;
            }
            double tmpPR = (page[i].oldPR / outDegree[i]) * alpha;
            get_edge_from_node(p, i)
                page[E[p].toward].newPR += tmpPR;
        }
        double sum = 0;
        for(int i = 0; i < N; ++i)
        {
            page[i].newPR += (1 - alpha) / N + res / N * alpha;
            sum += fabs(page[i].newPR - page[i].oldPR);

            page[i].oldPR = page[i].newPR;
            page[i].newPR = 0;
        }
        
        if (sum > threshold * N)
            shouldStop = 0;
        cnt++;
        if (cnt >= max_iterator)
            break;
    }

    // for(int i = 0; i < N; ++i)
        // printf("%d %.9lf\n", i, page[i].oldPR);
    // printf("%s%d%s\n", "共迭代", cnt, "轮");
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " file_name" << endl;
        return 1;
    }

    input(argv[1]);
    exit(0);
    PageRank();

    return 0;
}