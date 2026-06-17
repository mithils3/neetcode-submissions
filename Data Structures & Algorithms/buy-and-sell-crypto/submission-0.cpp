#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        size_t left = 0;          // buy day
        int profit = 0;
        for (size_t right = 1; right < prices.size(); ++right)
        {
            if (prices[right] > prices[left])
                profit = max(profit, prices[right] - prices[left]);
            else
                left = right;     // cheaper buy point found — move buy up
        }
        return profit;
    }
};