#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool comp(int a, int b) 
{ 
    return (a < b); 
} 
int min_cost(vector<int>&days, vector<int>& costs) {

    int dp[366]{};

    // Calculate for min cost if you travel each day
    // Cost will stay unchanged if you did not travel on that day as per days<>
    // Also take care of 7 and 30 day passes 
    // If you had purchased a 7 day pass cost with cost[1] + dp[i - 7]

    for (int i = 1; i < 366; i++) {
        if (find(days.begin(),days.end(), i) == days.end()) {
            dp[i] = dp[i - 1];
        } else {
            int min1 = dp[i - 1] + costs[0];
            int min2 = dp[max(i - 7, 0)] + costs[1];
            int min3 = dp[max(i - 30, 0)] + costs[2];
            dp[i] = min({min1, min2, min3}, comp);
            cout << "\nday = " << i << " min1 = " << min1 << " min2 = " << min2 << " min3 = " << min3 << std::endl;
        }

    }


    return dp[365];
}

int main() 
{
    vector<int> days{1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
    vector<int> costs{3, 13, 45};

    cout << "min cost = " << min_cost(days, costs) << std::endl;

    return 0;

}