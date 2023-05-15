/* https://leetcode.com/problems/word-break/
139. Word Break
Medium
DP
*/
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string to_check = s.substr(j, i - j);
                if (dp[j] && (find(wordDict.begin(), wordDict.end(), to_check) != wordDict.end()))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};