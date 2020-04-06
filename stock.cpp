#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        bool trans_start = false; // Buy a share
        // Greedy choice:if we see positive slope b/w i and i+1 we will buy at i
        // sell at highest price
        int buy_price = 0;
        int sell_price = 0;

        for (int i = 0; i + 1 < prices.size(); i++)
        {
            int j = i + 1;
            assert(j < prices.size());

            if (!trans_start)
            {
                if (prices[j] > prices[i])
                {
                    trans_start = true;
                    buy_price = prices[i];
                    sell_price = prices[j];
                }
            }
            else
            {
                // we will hold if we see a higher price
                if (prices[j] > sell_price)
                {
                    sell_price = prices[j];
                }
                else
                {
                    // sell the share
                    trans_start = false;
                    max_profit += (sell_price - buy_price);
                    sell_price = buy_price = 0;
                }
            }
        }

        // complete trans if the price kept rising till last input
        if (trans_start)
        {
            max_profit += (sell_price - buy_price);
        }
        return max_profit;
    }
};

int main()
{
    int n;
    vector<int> prices;
    while (cin >> n)
    {
        cout << n << "\n";
        prices.push_back(n);
    }

    Solution s;
    cout << "Max Profit = " << s.maxProfit(prices) << "\n";
    return 0;
}