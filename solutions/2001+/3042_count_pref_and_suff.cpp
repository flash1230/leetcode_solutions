/* https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
3042. Count Prefix and Suffix Pairs I
Easy
*/
class Solution
{
public:
    int checker(string s1, string s2)
    {
        int n = s2.length();
        int m = s1.length();
        for (int i = 0; i < m; i++)
        {
            if (s1[i] == s2[i] && s1[i] == s2[n - m + i])
                continue;
            else
                return 0;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i].length() > words[j].length())
                    continue;
                else
                    ans += checker(words[i], words[j]);
            }
        }
        return ans;
    }
};