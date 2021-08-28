int Solution::solve(vector<vector<int> > &A) {
    // Get the rotten orange first and do multi BFS 
    // Use gen number of rotten ones
    // Check visited to verify if some orange is not rotten
    
    struct orange {
        pair<int, int> pos; // matrix co-ord
        int age;
        orange(int i, int j, int k) : pos{i, j}, age{k} {};
    };
    
    // Q of all rotten oranges
    queue<orange> rot;
    int H = A.size();
    int W = A[0].size();
    int visit[H][W] = {};
    int nfresh{0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 2) {
                visit[i][j] = 1;
                rot.push({i, j, 0});
            }
            if (A[i][j] == 1) {
                nfresh++;
            }
        }
    }
    
    // rot contains all the initial rotten oranges
    if (rot.size() == 0) {
        return -1;
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto is_valid = [&](int i, int j) {if (i >= 0 && i < H && j >=0 && j < W) {return true;} else {return false;}};
    // BFS on the rotten oranges
    int maxage {INT_MIN};
    
    while (!rot.empty()) {
        orange n = rot.front();
        rot.pop();
        int r = n.pos.first;
        int c = n.pos.second;
        int g = n.age;
        maxage = max(maxage, g);
        // get all nbrs
        for (int i = 0; i < dir.size(); i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (is_valid(nr, nc) && A[nr][nc] == 1 && !visit[nr][nc]) {
                visit[nr][nc] = 1;
                nfresh--;
                rot.push({nr, nc, g + 1});
            }
        }
    }
    
    // unvisited fresh orange
    if (nfresh) {
        return -1;
    }
    
    return maxage;
}
