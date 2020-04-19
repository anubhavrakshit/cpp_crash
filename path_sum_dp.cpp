#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int H = grid.size();
        const int W = grid[0].size();
        // create dp to store min path sums from origin
        vector<vector<int>> dp(H, vector<int>(W));

        // Only choice for Col 0 will be to go down from start, so we will pre-fill that
        // Pre fill col 0
        dp[0][0] = grid[0][0];
        for (int i = 1; i < H; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Only choice for Row 0 will be to go right from start, so we will pre-fill that
        // Pre fill row 0
        for (int j = 1; j < W; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        // Now the choice we have to make is to pick either top or the left path
        for (int  r = 1; r < H; r++) {
            for (int c = 1; c < W; c++) {
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + grid[r][c];
            }
        }

       return dp[H - 1][W - 1]; 
    }
};

int main()
{
   vector<vector<int>> grid {{7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5},{9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6},{8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8},{6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4},{7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4},{9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9},{1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4},{3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2},{1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3},{5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7},{2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7},{0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}};

   Solution s;

   cout << "Min Path Sum = " << s.minPathSum(grid);
   return 0;
}