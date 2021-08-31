#include <iostream>
#include <vector>
using namespace std;
int solve(int A, int B) {
    
    int digits = A;
    int sum = B;
    int dp[1001][10001] = {};
    int mod = 1000000007;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1; // only 1 way to get the given sum
    }
    
    for (int i = 2; i <= digits; i++) {
            int max_i_sum = 9 * i;
            for (int j = 1; j <= max_i_sum; j++) {
                long num_ways {0};
                // dp[2][1]  -- dp[1][1] + 0
                // dp[2][2]  -- dp[1][2] + 0; dp[1][1] + 1; 
                // dp[2][3]  -- dp[1][3] + 0; dp[1][2] + 1; dp[1][1] + 2
                
                // dp[2][9]  -- dp[1][9] + 0, dp[1][8] + 1, dp[1][7] + 2
                // dp[2][10] -- dp[1][10], dp[1][9] + 1, dp[1][8] + 2,     dp[1][1] + 9
                // dp[2][11] -- dp[1][11], , dp[1][9] + 2, dp[1][8] + 3, ..dp[1][2] + 9
                // dp[2][12] -- dp[1][9] + 3, dp[1][8] + 4, dp[1][7] + 5, dp[1][3] + 9
                // dp[2][17] -- dp[1][9] + 8; dp[1][8] + 9;
                
                for (int q = j; q >= max(1, j - 9);  q--) {
                    num_ways += dp[i - 1][q];
                }
                dp[i][j] = num_ways % mod;
            }
    }
    
    return dp[A][B];
}