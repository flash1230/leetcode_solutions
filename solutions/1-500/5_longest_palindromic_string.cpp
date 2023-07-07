/* https://leetcode.com/problems/longest-palindromic-substring/
5. Longest Palindromic Substring
Medium
DP
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        bool dp[n][n];
        int first, len;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                    dp[i][j] = true;
                else if (g == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j])
                {
                    first = i;
                    len = g;
                }
            }
        }
        return s.substr(first, len + 1);
    }
};