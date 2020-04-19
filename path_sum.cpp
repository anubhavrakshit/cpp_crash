#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    
    int PathSum(vector<vector<int>>& grid, pair<int, int> src) {
        const int W = grid[0].size();
        const int H = grid.size();
        auto valid = [&] (int r, int c) {return r >=0 && r < H && c >= 0 && c < W;};
        auto sum = [&] (pair<int, int> s, pair<int, int> t) {
                        return  grid[s.first][s.second] + grid[t.first][t.second];
            };
        
        vector<pair<int, int>> dir {{1, 0}, {0, 1}};
        
        if (src.first == H - 1 && src.second == W - 1) {
            //cout << "dest" << endl;
            return grid[H-1][W-1];
        }
        
        int r_sum{INT_MAX};
        
        if (valid(src.first, src.second + 1)) {
            // right
            cout << "go right " << endl;
            r_sum = grid[src.first][src.second] + PathSum(grid, {src.first, src.second + 1});
            cout << "right " << src.first<<" " << src.second << " "<< r_sum << endl;
        }
        int d_sum{INT_MAX};
        if (valid(src.first + 1, src.second)) {
            // down
            cout << "go down" << endl;
            d_sum = grid[src.first][src.second] + PathSum(grid, {src.first + 1, src.second});
            cout << "down " << src.first<<" " << src.second << " "<< d_sum << endl;
        }        
        return min(r_sum, d_sum);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        // start [0,0] dest[m -1, n -1]
        // from (start till end):
        //    dist = min (start->right + minPathSum(right, dest) , start->down + minPathSum(down, dest))
       return PathSum(grid, {0, 0}); 
    }
};

int main() {
   vector<vector<int>> grid {{7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5},{9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6},{8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8},{6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4},{7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4},{9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9},{1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4},{3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2},{1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3},{5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7},{2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7},{0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}};

   Solution s;

   cout << "Min Path Sum = " << s.minPathSum(grid);
   return 0;
}