/* https://leetcode.com/problems/stone-game-ii/
1140. Stone Game II
Medium
DP Game Theory
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sufSum(n);
        sufSum[n-1]=piles[n-1];
        for(int i = n-2; i>=0;i--)
        {
            sufSum[i]=piles[i]+sufSum[i+1];
        }
        vector<vector<int>> dp(n, vector<int>(n,0));
        return solve(sufSum, dp, 0, 1);
    }
    int solve(vector<int>& sum, vector<vector<int>>& dp, int i, int m ) {
        if(i==sum.size()) {
            return 0;
        }
        if(i+2*m >=sum.size()) {
            return sum[i];
        }
        if(dp[i][m] != 0 ){
            return dp[i][m];
        }
        int ans = 0;
        for(int x=1; x<=2*m;x++) {
            ans = max(ans, sum[i] - solve(sum, dp, i+x, max(m,x)));
        }
        dp[i][m] = ans;
        return ans;
    }
};