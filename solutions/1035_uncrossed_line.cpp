/* https://leetcode.com/problems/uncrossed-lines/
1035. Uncrossed Lines
Medium
DP
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n+1][m+1];
        for(int i =0;i<n+1;i++) {
            for(int j =0;j<m+1;j++) {
                dp[i][j]=0;
            }
        }
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};