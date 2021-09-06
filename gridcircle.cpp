#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;
// A,B is diagonal end co-ordinate of a 0,0 based rect
// D is radius of circles 
// E[]F[] hold the co-ordinates of each circle 
string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    pair<int, int> start{0, 0}, end{A, B};
    vector<vector<int>> grid(A + 1, vector<int>(B + 1, 0));
    
    // mark any cell inside circle as invalid
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k < C; k++) {
                if (sqrt(pow(E[k] - i, 2) + pow(F[k] - j, 2)) <= D) {
                    grid[i][j] = -1;
                }
            }
        }
    }
    if (grid[0][0] == -1 || grid[A][B] == -1) {
        return {"NO"};
    }
    
    vector<pair<int, int>> dir = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1} };
    auto is_valid = [&](pair<int, int> cell) {
        int x = cell.first;
        int y = cell.second;
        
        if (x < 0 || y < 0 || x > A || y > B || grid[x][y] == -1) {
            return false;
        } 
        
        return true;
    };
    
    bool found{false};
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push(start);
    
    while (!q.empty()) {
        auto node = q.front();
        visited.insert(node);
        q.pop();
        
        if (node == end) {
            found = true;
            break;
        }
        
        for (int i = 0; i < dir.size(); i++) {
            pair<int, int> n = {node.first + dir[i].first, node.second + dir[i].second};
            if (is_valid(n) && !visited.count(n)) {
                q.push(n);
                visited.insert(n);
            }
        }
    }
    
    if (found) {
        return {"YES"};
    }
    
    return {"NO"};
}
