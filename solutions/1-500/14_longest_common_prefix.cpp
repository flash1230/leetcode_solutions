/* https://leetcode.com/problems/longest-common-prefix/
14. Longest Common Prefix
Easy
*/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        string ans = "";
        for (int i = 0;; i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] == '\0')
                    return ans;
                char ch;
                if (j == 0)
                    ch = strs[j][i];
                else
                {
                    if (ch != strs[j][i])
                        return ans;
                    if (j == strs.size() - 1)
                        ans += ch;
                }
            }
        }
        return ans;
    }
};