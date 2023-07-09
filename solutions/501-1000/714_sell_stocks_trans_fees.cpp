/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
714. Best Time to Buy and Sell Stock with Transaction Fee
Medium
DP
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int tmp = sell;
            sell = max(sell, buy + prices[i]);
            buy = max(buy, tmp - prices[i] - fee);
        }
        return sell;
    }
};