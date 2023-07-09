/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
309. Best Time to Buy and Sell Stock with Cooldown
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
        int buy = -prices[0];
        int sell = 0;
        int cool = 0;
        bool isCool = false;
        for (int i = 0; i < n; i++)
        {
            int tbuy = buy;
            int tsell = sell;
            buy = max(tbuy, cool - prices[i]);
            sell = max(tsell, tbuy + prices[i]);
            cool = max(cool, tsell);
        }
        return sell;
    }
};