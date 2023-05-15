/* https://leetcode.com/problems/longest-common-subsequence/
1143. Longest Common Subsequence
Medium
DP
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.length();
        int b = text2.length();
        int dp[a+1][b+1];
        for(int i = 0;i<=a;i++) {
            for(int j = 0;j<=b;j++) {
                if(i==0 || j == 0) {
                    dp[i][j] = 0;
                }
                else{
                    if(text1[i-1] == text2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1 ;
                    }
                    else {
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
                    }
                }
            }
        }
        return dp[a][b];
    }
};