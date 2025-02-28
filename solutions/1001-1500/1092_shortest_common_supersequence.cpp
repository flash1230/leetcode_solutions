/* https://leetcode.com/problems/shortest-common-supersequence/
1092. Shortest Common Supersequence
Hard
DP
*/
class Solution
{
public:
    string LCS(string str1, string str2)
    {
        int a = str1.length(), b = str2.length();
        vector<vector<int>> dp(a + 1, vector<int>(b + 1));
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (str1[i - 1] == str2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        string res(dp[a][b], ' ');
        int m = dp[a][b] - 1;
        int l = a, k = b;
        while (l > 0 && k > 0)
        {
            if (str1[l - 1] == str2[k - 1])
            {
                res[m] = str1[l - 1];
                m--;
                l--;
                k--;
            }
            else if (dp[l - 1][k] > dp[l][k - 1])
                l--;
            else
                k--;
        }
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2)
    {
        string lc = LCS(str1, str2);
        string ans = "";
        int p1 = 0, p2 = 0;
        int c = 0;
        while (c < lc.length())
        {
            while (p1 < str1.length() && str1[p1] != lc[c])
                ans += str1[p1++];
            p1++;
            while (p2 < str2.length() && str2[p2] != lc[c])
                ans += str2[p2++];
            p2++;
            ans += lc[c++];
        }
        while (p1 < str1.length())
            ans += str1[p1++];
        while (p2 < str2.length())
            ans += str2[p2++];
        return ans;
    }
};