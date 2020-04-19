#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int numIslands{0};
        // BFS for all nbrs 
        // For each completed BFS increase numIslands
    
        
        const int rows = grid.size();
        if (rows == 0) {
            return numIslands;
        }
        const int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        
        auto is_valid = [&] (int row, int col) {
            return row >= 0 && row < rows && col >= 0 && col < cols;
        };
        
        vector<pair<int, int>> dir{ {-1,0}, {1,0}, {0, 1}, {0, -1} };
        queue<pair<int, int>> q; 
        // cout << "Start BFS" << std::endl;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // BFS of all the nbrs that form island
                if (!visited[r][c] && grid[r][c] == '1') {
                    visited[r][c] = true;
                    
                    q.push({r, c});
                    //cout << "r = " << r << "c = " << c << std::endl;
                    numIslands++;               
                    while (!q.empty()) {
                        auto node = q.front();
                        int r_cur = node.first;
                        int c_cur = node.second;
                       // cout << "visited r = " << r_cur << "c = " << c_cur << std::endl;
                        //cout << "aaaaa" << endl;
                        q.pop();
                      
                        //cout << "baaaa" << endl;
                        // Queue up all nbrs
                        
                        for (auto d: dir) {
                            int r_nbr = r_cur + d.first;
                            int c_nbr = c_cur + d.second;
                            
                            if (is_valid(r_nbr, c_nbr) && grid[r_nbr][c_nbr] == '1' && !visited[r_nbr][c_nbr]) {
                                q.push(make_pair(r_nbr, c_nbr));
                                visited[r_nbr][c_nbr] = true;
                            }
                         }
                    }
                }
                
            }
        }
        return numIslands;
    }
};

int main() {
   vector<vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

   Solution s;

   cout << "Num Islands = " << s.numIslands(grid) ;
   return 0;
}