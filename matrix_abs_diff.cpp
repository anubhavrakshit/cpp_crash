#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find with Path Compression
int dsu_find(vector<int> &parent, int u) {
    if (parent[u] == u) {
        return u;
    }
    
    parent[u] = dsu_find(parent, parent[u]);
    return parent[u];
}

bool dsu_union(vector<int> &parent, int u, int v) {
    if (dsu_find(parent, u) == dsu_find(parent, v)) {
        return false;
    }
    
    parent[dsu_find(parent, u)] = dsu_find(parent, v);
    return true;
}

void dsu_create(vector<int> &parent) {
     // Create DSU of all vertices
    for (int i = 1; i < parent.size(); i++) {
        parent[i] = i;
    }
}

int solve(int A, int B, vector<vector<int> > &C) {

    vector<vector<int> > vw(A, vector<int>(B)); // store vertex, weight
    // Create Look Up table to map each cell to an id
    int time{0};
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            vw[i][j] = time++;
        }
    }
    
    vector<pair<int, int>> dir = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
    auto is_valid = [&](int x, int y) {
        if (x < 0 || y < 0 || x >= A || y >= B) {
            return false;
        }
        return true;
    };
    
    vector<vector<int>> edges;
    // create edges
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
                int u = vw[i][j];
                int cu = C[i][j];
                for (auto d : dir) {
                    int k = i + d.first;
                    int l = j + d.second;
                    if (is_valid(k, l)) {
                        int v = vw[k][l];
                        int cv = C[k][l];
                        int cost = abs(cv - cu);
                        edges.push_back({u, v, cost});
                    }
                }
        }
    }
    
    auto comp = [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    };
    
    // Apply Kruskal MST algo by getting min cost edges 
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent((A * B) + 1);
    dsu_create(parent);
    
    int max_wt{INT_MIN}; // the max cost edge is our answer
    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if (dsu_union(parent, u, v)) {
            max_wt = max(max_wt, w);
        }
    }
    
    return max_wt;
}
