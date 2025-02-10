/* https://leetcode.com/problems/clear-digits/
3174. Clear Digits
Easy
*/
class Solution
{
public:
    string clearDigits(string s)
    {
        string ans;
        for (char c : s)
        {
            if (isdigit(c) && ans.length() > 0)
                ans.pop_back();
            else
                ans += c;
        }
        return ans;
    }
};