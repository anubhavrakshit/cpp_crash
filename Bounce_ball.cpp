
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    
    int H = A.size();
    int W = A[0].size();
    
    int s_i = B[0];
    int s_j = B[1];
    
    int e_i = C[0];
    int e_j = C[1];
    
    auto is_valid = [&](pair<int, int> pos) {
        int i = pos.first;
        int j = pos.second;
        if (i < 0 || j < 0 || i >= H || j >= W || A[i][j] == 1) {
            return false;
        }
        return true;
    };
    
    // BFS from s_i,s_j to e_i, e_j and need to find 
    struct node {
        pair<int, int> pos;
        int count{0};
        int dir{0};
    };
    queue<node> q;
    
    
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}}; // 0:left, 1:right, 2: down, 3:up
    struct vdir {
      int dir[4] = {};  
    };
    
    // visited has to mark all 4 directions of the visit
    vdir visit[H][W] = {};
    node start = {{s_i, s_j}, 0};
    // mark all dir of start node visited
    for (int i = 0; i < dir.size(); i++) {
        visit[s_i][s_j].dir[i] = 1;
    }
    
    // Get valid nbrs of start
    for (int i = 0; i < dir.size(); i++) {
        node nbr;
        nbr.pos = {start.pos.first + dir[i].first, start.pos.second + dir[i].second};
        nbr.count = 1;
        nbr.dir = i;
        if (is_valid(nbr.pos)) {
            visit[nbr.pos.first][nbr.pos.second].dir[nbr.dir] = 1;
            q.push(nbr);
        }
    }
    
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        
        if (cur.pos.first == e_i && cur.pos.second == e_j) {
            // check if we have to stop
            pair<int, int> npos = {cur.pos.first + dir[cur.dir].first, cur.pos.second + dir[cur.dir].second};
            if (!is_valid(npos)) {
                return cur.count;
            } 
        }
        
        // Try moving in same direction if valid
        pair<int, int> npos = {cur.pos.first + dir[cur.dir].first, cur.pos.second + dir[cur.dir].second};
        if (is_valid(npos)) {
            node nbr;
            nbr.pos = npos;
            nbr.dir = cur.dir;
            nbr.count = cur.count + 1;
            if (!visit[nbr.pos.first][nbr.pos.second].dir[nbr.dir]) {
                visit[nbr.pos.first][nbr.pos.second].dir[nbr.dir] = 1;
                q.push(nbr);
            }
        } else {
            // change direction 
            // Get valid nbrs in all dirs
            for (int i = 0; i < dir.size(); i++) {
                node nbr;
                nbr.pos = {cur.pos.first + dir[i].first, cur.pos.second + dir[i].second};
                nbr.count = cur.count + 1;
                nbr.dir = i;
                if (is_valid(nbr.pos) && !visit[nbr.pos.first][nbr.pos.second].dir[nbr.dir]) {
                    visit[nbr.pos.first][nbr.pos.second].dir[nbr.dir] = 1;
                    q.push(nbr);
                }
            }       
        }
    }
    return -1;
}
