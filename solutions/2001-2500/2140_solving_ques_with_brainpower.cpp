/* https://leetcode.com/problems/solving-questions-with-brainpower
2140. Solving Questions With Brainpower
Medium
DP
*/
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        for(int i = n-1;i>=0;i--) {
            dp[i] = max(dp[i+1], questions[i][0] + dp[min(n, questions[i][1] + 1 + i)]);
        }
        return dp[0];
    } 
};