/* https://leetcode.com/problems/minimum-length-of-string-after-operations/
3223. Minimum Length of String After Operations
Medium
Map
*/
class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int ans = 0;
        for (int i : freq)
        {
            if (i == 0)
                continue;
            if (i % 2)
                ans += 1;
            else
                ans += 2;
        }
        return ans;
    }
};