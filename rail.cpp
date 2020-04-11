#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) 
{ 
    return (a < b); 
} 
int min_cost(vector<int>&days, vector<int>& costs) {
    int min_cost = 0;

    vector<vector<int> > dp(2);
    for(auto x: days) {
        dp[0].push_back(x);
        dp[1].push_back(0);
    }

    int min_pass_cost = std::min({costs[0], costs[1], costs[2]}, comp);
    
    // pre fill; we know at starting min cost will be min(cost[0], cost[1]...)
    dp[1][0] = min_pass_cost;

    cout << std::endl;
    for (int j = 1; j < days.size(); j++) {
        // The min cost will be min of:
        // dp[1][j - 1] + cost[0]
        // ((dp[0][j] -dp[0][0] ) / 7) * cost[1]  + cost[1]
        // (dp[0][j] -dp[0][0] ) /  30) * cost[2] + cost[2]

        int min1 = dp[1][j - 1] + costs[0];
        int min2 = (((dp[0][j] - dp[0][0]) / 7) * costs[1]) + costs[1];
        int min3 = (((dp[0][j] - dp[0][0]) / 30) * costs[2]) + costs[2];

        dp[1][j] = std::min({min1, min2, min3}, comp);
        cout << "min1 = " << min1 << " min2 = " << min2 << " min3 = " << min3 << endl;
        cout << "cost of day " << dp[0][j] << " is " << dp[1][j] << std::endl;
    }



    return dp[1][dp[1].size() - 1];
}

int main() 
{
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs{2,7,15};

    cout << "min cost = " << min_cost(days, costs) << std::endl;

    return 0;

}