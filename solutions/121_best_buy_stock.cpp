/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
121. Best Time to Buy and Sell Stock
Easy
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minimum = prices[0];
        for(int i =1; i<prices.size();i++) {
            ans = max(ans, prices[i] - minimum);
            minimum = min(prices[i], minimum);
        }
        return ans;
    }
};