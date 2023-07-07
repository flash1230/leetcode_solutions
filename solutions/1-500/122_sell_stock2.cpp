/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
122. Best Time to Buy and Sell Stock II
Medium
DP
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};