/* https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
1312. Minimum Insertion Steps to Make a String Palindrome
Hard
DP
*/
class Solution {
public:
    int lps(string s) {
        int n = s.length();
        int dp[n][n];
        for(int g=0;g<n;g++) {
            for(int i = 0, j =g;j<n;i++,j++) {
                if(g==0) {
                    dp[i][j] = 1;
                }
                else if(g==1) {
                    dp[i][j] = s[i] == s[j] ? 2 : 1;
                }
                else {
                    if(s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        return s.length()-lps(s);
    }
};