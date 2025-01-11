/* https://leetcode.com/problems/construct-k-palindrome-strings/
1400. Construct K Palindrome Strings
Medium
Map
*/
class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (k > s.length())
            return false;
        int odds = 0;
        vector<bool> isEven(26, false);
        for (char c : s)
        {
            isEven[c - 'a'] = !isEven[c - 'a'];
            if (isEven[c - 'a'])
                odds++;
            else
                odds--;
        }
        if (odds > k)
            return false;
        return true;
    }
};