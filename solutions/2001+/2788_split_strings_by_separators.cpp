/* https://leetcode.com/problems/split-strings-by-separator
2788. Split Strings by Separator
Easy
*/
class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        for (string j : words)
        {
            string s = "";
            for (char c : j)
            {
                if (c == separator)
                {
                    if (s.length())
                        ans.push_back(s);
                    s = "";
                }
                else
                    s += c;
            }
            if (s.length())
                ans.push_back(s);
        }
        return ans;
    }
};