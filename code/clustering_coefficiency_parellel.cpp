#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

double clustering_coefficient(vector<vector<int>>& adj_list, int num_nodes) {
    double coeff_sum = 0;
    #pragma omp parallel for reduction(+:coeff_sum)
    for (int i = 0; i < num_nodes; i++) {
        int num_neighbors = adj_list[i].size();
        if (num_neighbors < 2) continue;
        int num_links = 0;
        for (int j = 0; j < num_neighbors; j++) {
            int neighbor = adj_list[i][j];
            for (int k = j+1; k < num_neighbors; k++) {
                if (find(adj_list[neighbor].begin(), adj_list[neighbor].end(), adj_list[i][k]) != adj_list[neighbor].end())
                    num_links++;
            }
        }
        coeff_sum += (double)num_links / ((double)num_neighbors * (double)(num_neighbors - 1));
    }
    return coeff_sum / num_nodes;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " graph_file" << endl;
        return 1;
    }
    string graph_file = argv[1];

    // Read graph from file
    ifstream infile(graph_file);
    int num_nodes, num_edges;
    infile >> num_nodes >> num_edges;
    vector<vector<int>> adj_list(num_nodes);
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        infile >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    infile.close();

    double start_time = omp_get_wtime();
    double coeff = clustering_coefficient(adj_list, num_nodes);
    double end_time = omp_get_wtime();
    cout << "Clustering Coefficient: " << coeff << endl;
    cout << "Elapsed time: " << end_time - start_time << " seconds" << endl;

    return 0;
}
