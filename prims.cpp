#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


int dfs(int u, vector<vector<pair<int, int>>> &adjl, set<int> &conn) {
     int nc{0};
     conn.insert(u);
     for (auto nbr : adjl[u]) {
        if (conn.find(nbr.first) == conn.end()) {
            nc += dfs(nbr.first, adjl, conn);
        }
    }
    return 1 + nc;
}
void build_mst(vector<vector<pair<int, int>>> &adjl, int s, set<pair<int, int>> &mst) {
        struct pq_node {
            int w;            // weight
            pair<int, int> e; // parent child edge
        };
        
        // min q 
        struct Compare {
          int operator () (pq_node& node1, pq_node& node2) {
              return node1.w > node2.w;
          }  
        };
        
        priority_queue<pq_node, vector<pq_node>, Compare> pq;
        
        // Nodes which are part of spanning tree
        set<int> tree;

       tree.insert(s); 
       // Push all edges of source node
        for (auto n : adjl[s]) {
            pq_node tmp;
            tmp.w = n.second;
            tmp.e = {s, n.first};
            pq.push(tmp);
        }
        
        while (!pq.empty()) {
            // Get the least wgt edge
            auto lwe = pq.top();
            pq.pop();
            if (tree.find(lwe.e.second) != tree.end()) {
                continue;
            }
            mst.insert({lwe.e.first, lwe.e.second});
            cout << "u = " << lwe.e.first << " v = " << lwe.e.second << " wgt = " << lwe.w << endl; 
            tree.insert(lwe.e.second);
            for (auto nbr : adjl[lwe.e.second]) {
                if (tree.find(nbr.first) == tree.end()) {
                    pq_node tmp;
                    tmp.w = nbr.second;
                    tmp.e = {lwe.e.second, nbr.first};
                    pq.push(tmp);
                }
            }
        }
}

void build_mst1(vector<vector<pair<int, int>>> &adjl, int s, set<pair<int, int>> &mst) {
    // max node is 3e5 + 1
    int MAXN = 3e5 + 2;
    vector<int> cost(MAXN, INT_MAX); // cost of vertex, initially all is INF
    vector<bool> tree(MAXN, false);  // is vertex part of spanning tree ?
    vector<int> parent(MAXN, 0);     // parent of the vertex
    
    // Need a min priority q to hold {cost, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
    // lets set the cost of source to 0
    cost[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto node = pq.top();
        int u = node.second;
        pq.pop();
        
        // if already in mst we can skip
        if (tree[u]) {
            continue;
        }
        
        // add vertex to tree
        tree[u] = 1;
        // update mst to hold this edge
        mst.insert({parent[u], u});
        cout << "Edge " << parent[u] << " - " << u << endl;
        for (auto nbr : adjl[u]) {
            int v = nbr.first; 
            int w = nbr.second;
            // If not already in tree and cost is cheaper
            if (!tree[v] && w < cost[v]) {
                cost[v] = w;
                parent[v] = u;
                pq.push({cost[v], v});
            }
        }
    } 
}

vector<int> solve(int A, vector<vector<int> > &B) {
    
    set<pair<int, int>> mst; // edges that form MST
    
    // Create adj list 
    vector<vector<pair<int, int>>> adjl(A + 1); // node, edge wt 
    for (auto ew : B) {
        int u = ew[0];
        int v = ew[1];
        int w = ew[2];
    
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }
    
    set<int> conn;
    int num_cc{0};
    
    // for all connected components
    for (int i = 1; i <= A; i++) {
        if (conn.find(i) != conn.end()) {
            continue;
        } else {
            // figure out all connected components
            int nc = dfs(i, adjl, conn);
            cout << "Num conn comp = " << nc << endl;
            build_mst1(adjl, i, mst);
        }
    }
    
    // Figure out the edges in input which are also in mst set
    vector<int> ans;
    for (auto ew : B) {
        // try both edge formats
        if (mst.find({ew[0], ew[1]}) != mst.end()) {
            ans.push_back(1);
        } else  if (mst.find({ew[1], ew[0]}) != mst.end()) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }
    
    return ans;
}

int main() {
    int A{0};
    cin >> A;
    int num_edges{0};
    cin >> num_edges;
    vector<vector<int>> edgew(num_edges, vector<int>(3));
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgew[i][0] = u;
        edgew[i][1] = v;
        edgew[i][2] = w;
    }

    solve(A, edgew);
    return 0;
}