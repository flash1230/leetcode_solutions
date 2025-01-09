/* https://leetcode.com/problems/counting-words-with-a-given-prefix/
2185. Counting Words With a Given Prefix
Easy
*/
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;
        for (string s : words)
        {
            if (pref.length() > s.length())
                continue;
            int i = 0;
            for (; i < pref.length(); i++)
            {
                if (pref[i] != s[i])
                    break;
            }
            if (i == pref.length())
                ans++;
        }
        return ans;
    }
};