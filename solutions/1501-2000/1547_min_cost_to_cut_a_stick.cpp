/* https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
1547. Minimum Cost to Cut a Stick
Hard
DP
*/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        int l = cuts.size();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for(int i=0;i+2<l;i++) {
            dp[i][i+2] = cuts[i+2]-cuts[i];
        }
        for(int diff =3;diff<l;diff++) {
            for(int i=0;i+diff<l;i++) {
                int tem = INT_MAX;
                for(int j = i+1;j<i+diff;j++) {
                    tem = min(tem, dp[i][j] + dp[j][i+diff] );
                }
                dp[i][i+diff] = cuts[i+diff]+tem-cuts[i];
            }
        }
        return dp[0][l-1];
    }
};